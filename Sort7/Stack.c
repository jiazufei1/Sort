#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#include"LList.h"
//初始化栈
//返回值：栈的指针
Stack*init_Stack() {
	return init_LList();
}
//输出栈中的元素
//参数stack：栈的指针
void print_Stack(Stack*stack) {
	print_LList(stack);
}
//进栈
void insert_Stack(Stack*stack, int data) {
	insert_LList_head(stack, data);
}
//出栈
void delete_Stack(Stack*stack, int*data) {
	delete_LList_head(stack, data);
}

