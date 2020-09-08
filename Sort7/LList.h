#ifndef LLIST_H_
#define LLIST_H_
#include"Struct.h"
//创建链表
LList*init_LList();
//输出链表
void print_LList(LList*list);
//插入
void insert_LList(LList*list, int index, int data);
//头插法
void insert_LList_head(LList*list, int data);
//尾插法
void insert_LList_tail(LList*list, int data);
//根据位置删除数据
void delete_LList_index(LList*list, int index, int *data);
//头删法
void delete_LList_head(LList*list, int *data);
//尾删法
void delete_LList_tail(LList*list, int *data);
#endif /* LLIST_H_ */
