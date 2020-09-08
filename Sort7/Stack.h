#include"Struct.h"
#ifndef STACK_H_
#define STACK_H_
//初始化栈
Stack*init_Stack();
//输出栈中的元素
void print_Stack(Stack*stack);
//进栈
void insert_Stack(Stack*stack, int data);
//出栈
void delete_Stack(Stack*stack, int*data);
#endif /* STACK_H_ */
