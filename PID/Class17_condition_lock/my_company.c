#include "apue.:h"

整个函数分为

1 初始化
2 Action_Sheng
3 Action_Xiao
4 main
5 结束

需要
1 生产总数
2 消费总数
3 库存数

库存=生产-消费？
比如我生产了12个
消费了5个
库存还有？
5个
而生产最多也10个 
不可能到12个


也就是说

1
只有当
消费+最大库存 大于  生产
才能生产

if
Xiao+KuMax>Sheng
then
Action_Sheng

这里就决定了Sheng-Xiao<KuMax

2
只要库存不为0
就可以消费
if
 Ku>0
then
Action_Xiao

3
库存是由
Sheng-Xiao=ku
决定的吗？
是的，因为Sheng-Xiao<KuMax
已经限定了Sheng和Xiao的数据
不可能超过KuMax
完美解决这个问题

改：
问题的修改需要很多时间，
等学完了再说吧
