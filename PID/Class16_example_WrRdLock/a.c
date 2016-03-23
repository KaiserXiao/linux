WrRdLock.c:9:1: error: expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘void’
 void *thread_fun1(void *arg)
 ^
WrRdLock.c: In function ‘thread_fun2’:
WrRdLock.c:30:25: error: ‘rwlock’ undeclared (first use in this function)
  pthread_rwlock_rdlock(&rwlock); 
                         ^
WrRdLock.c:30:25: note: each undeclared identifier is reported only once for each function it appears in
WrRdLock.c: In function ‘main’:
WrRdLock.c:43:28: error: ‘rwlock’ undeclared (first use in this function)
  err=pthread_rwlock_init (&rwlock,NULL);
                            ^
WrRdLock.c:49:33: error: ‘thread_fun1’ undeclared (first use in this function)
  err=pthread_create(&tid1, NULL,thread_fun1,NULL);
                                 ^
