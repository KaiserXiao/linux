attr_key.c: In function ‘thread_fun1’:
attr_key.c:9:26: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  pthread_setspecific(key,(void *)a);
                          ^
attr_key.c:11:2: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘void *’ [-Wformat=]
  printf("Thread One Key->data is %d\n",pthread_getspecific(key));
  ^
attr_key.c: In function ‘thread_fun2’:
attr_key.c:19:26: warning: cast to pointer from integer of different size [-Wint-to-pointer-cast]
  pthread_setspecific(key,(void *)a);
                          ^
attr_key.c:20:2: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘void *’ [-Wformat=]
  printf("Thread Two Key->data is %d\n",pthread_getspecific(key));
  ^
attr_key.c: In function ‘main’:
attr_key.c:45:2: warning: passing argument 1 of ‘pthread_key_delete’ makes integer from pointer without a cast [enabled by default]
  pthread_key_delete(&key);
  ^
In file included from apue.h:3:0,
                 from attr_key.c:1:
/usr/include/pthread.h:1127:12: note: expected ‘pthread_key_t’ but argument is of type ‘pthread_key_t *’
 extern int pthread_key_delete (pthread_key_t __key) __THROW;
            ^
