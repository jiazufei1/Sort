#include"Struct.h"
#ifndef QUEUE_H_
#define QUEUE_H_
//初始化队列
Queue*init_Queue();
//输出队列中的元素
void print_Queue(Queue*queue);
//入队
void insert_Queue(Queue*queue, int data);
//出队
void delete_Queue(Queue*queue, int*data);
#endif /* QUEUE_H_ */
