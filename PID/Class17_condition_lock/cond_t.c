#include "apue.h"

#define BUFFER_SIZE	5	//产品库存大小
#define PRODUCT_CNT	30	//产品生产总数

struct product_cons
{
	int buffer[BUFFER_SIZE];	//生产产品值
	pthread_mutex_t lock;		//互斥锁
	int readpos,writepos;		//读写位置
	pthread_cond_t notempty;	//条件变量，非空
	pthread_cond_t notfull;		//非满
}buffer;

void init (struct product_cons *p)
{
	pthread_mutex_init(&p->lock,NULL);	//初始化互斥锁，Class14
	
	pthread_cond_init(&p->notempty,NULL);
	pthread_cond_init(&p->notfull,NULL);	//初始化条件变量
	
	p->readpos=0;				//读写位置初始化
	p->writepos=0;				
}

void finish(struct product_cons *p)
{
	pthread_mutex_destroy(&p->lock);	
	pthread_cond_destroy(&p->notempty);
	pthread_cond_destroy(&p->notfull);
	p->readpos=0;
	p->writepos=0;
}

//储存一个数据到buf中
void put(struct product_cons *p,int data  )
{
	printf("Now PUTs!!\n");
	//上互斥锁
	pthread_mutex_lock(&p->lock);
	
	if((p->writepos+1)%BUFFER_SIZE==p->readpos)
	{
		printf("producer wait for not full\n");
		//等待一个非满状态，形参为，条件变量，互斥量
		pthread_cond_wait(&p->notfull,&p->lock);
	}
	p->buffer[p->writepos]=data;
	p->writepos ++;
	
	if(p->writepos>=BUFFER_SIZE)
		p->writepos=0;
	//释放一个信号
	pthread_cond_signal(&p->notempty);
	//解锁
	pthread_mutex_unlock(&p->lock);

}


//从buf中移除一个数据
int get(struct product_cons *p)
{
	int data;
	printf("Now Gets!!!\n");
	pthread_mutex_lock(&p->lock);
	//printf("p->readpos is %d\np->writepos is %d\n",
	//			p->readpos,p->writepos);	
	
	//p->readpos==p->writrepos在程序的最后会出现一种情况
	//因为p->readpos刚好在最后被置为0
	//而p->writepos也刚好在最后置为0，
	//会一直等待非空的出现，程序陷入死循环
	//p->writepos==0只有一种情况，他已经满了，已经非空
	//很明显，这么粗暴的处理还是不行的，只有整个程序重新构思
	if((p->readpos==p->writepos)&&(p->writepos))
	{
		printf("consumer wait for not empty\n");
		pthread_cond_wait(&p->notempty,&p->lock);
	}
	data=p->buffer[p->readpos];
	p->readpos++;

	if(p->readpos>=BUFFER_SIZE)
		p->readpos=0;

	//释放一个信号
	pthread_cond_signal(&p->notfull);
	//解锁	
	pthread_mutex_unlock(&p->lock);
	
	return data;
}



void *producer(void *data)
{
	int n;
	for (n=1;n<=20;++n)	//生产20个产品
	{
		sleep(1);
		printf("\nPut the %d product ..\n",n);	
		put(&buffer,n);
		printf("Put the %d product success \n",n);
	}
	printf("producer stopped\n");
	return NULL;
}


void *consumer(void *data)
{
	static int cnt =0;
	int num;
	while (1)
	{
		sleep(2);
		printf("\nGet the %d product...\n",num);
		num=get(&buffer);
		printf("get the %d product success\n",num);
		if(++cnt==PRODUCT_CNT)
			break;
	}
	printf("consumer stopped\n");
	return NULL;
}

int main(int argc,char *argv[])
{
	pthread_t th_a,th_b;
	void *retval;

	init(&buffer);
	
	pthread_create(&th_a,NULL,producer,0);
	pthread_create(&th_b,NULL,consumer,0);

	pthread_join(th_a,&retval);
	pthread_join(th_b,&retval);

	finish(&buffer);
	
	return 0;
}


