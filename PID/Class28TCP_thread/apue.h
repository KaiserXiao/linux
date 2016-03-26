#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include  <fcntl.h>   /* For O_* constants */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
