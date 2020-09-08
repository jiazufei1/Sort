#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"LList.h"
//初始化队列
//返回值：队列的指针
Queue*init_Queue() {
	return init_LList();
}
//输出队列中的元素
//参数queue：队列的指针
void print_Queue(Queue*queue) {
	print_LList(queue);
}
//入队
void insert_Queue(Queue*queue, int data) {
	insert_LList_tail(queue, data);
}
//出队
void delete_Queue(Queue*queue, int*data) {
	delete_LList_head(queue, data);
}
