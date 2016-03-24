attr.c: In function ‘thread_fun1’:
attr.c:7:2: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t’ [-Wformat=]
  printf("I`m thread 0x%x\n",pthread_self());
  ^
attr.c: In function ‘thread_fun2’:
attr.c:14:2: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t’ [-Wformat=]
  printf("I`m thread 0x%x\n",pthread_self());
  ^
