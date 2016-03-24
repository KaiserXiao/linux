attr_stack.c: In function ‘thread_fun1’:
attr_stack.c:10:2: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument 2 has type ‘pthread_t’ [-Wformat=]
  printf("I`m thread 0x%x\n",pthread_self());
  ^
attr_stack.c:14:2: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t’ [-Wformat=]
  printf("First thread stack size is %d\n",stacksize);
  ^
attr_stack.c:17:2: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t’ [-Wformat=]
  printf("Second thread stack size is %d\n",stacksize);
  ^
