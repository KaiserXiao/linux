﻿  { time ./Test_fgetc a.c fgetc.c ; } >d.c 2>&1
  { time ./Test_read a.c read.c ; } >>d.c 2>&1
////这两句是shell里面用来重定向time 的输出，要掌握起来
////说明一下：
////文件流fopen与fgetc的调压system call 比较少
////故在sys内核运行的时间要少
////但每次都只有读取一个字节，用户的时间要比
////open与read等系统调用函数的时间要多
