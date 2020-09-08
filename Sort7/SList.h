#include"Struct.h"
#ifndef SLIST_H_
#define SLIST_H_
//创建顺序表
SList* init_SList();
//输出数据
void print_SList(SList*list);
//插入
void insert_SList(SList*list, int index, int data);
//按位置删除
void delete_SList_index(SList*list, int index, int*data);
//按值删除
void delete_SList_data(SList*list, int*index, int data);
//按位置查找
void search_SList_index(SList*list, int index, int*data);
//按值查找
void search_SList_data(SList*list, int*index, int data);
//修改数据
void change_SList_index(SList*list, int index, int data);
//排序
void sort_SList(SList*list, int method);
#endif /* SLIST_H_ */
