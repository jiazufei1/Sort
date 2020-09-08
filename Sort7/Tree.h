#include"Struct.h"
#ifndef TREE_H_
#define TREE_H_
//创建树
TNode*init_Tree(void);
//遍历
void print_Tree(TNode*tree, int method);
//统计树中度为零的节点个数
int countD0(TNode*tree);
//统计树中度为一的节点个数
int countD1(TNode*tree);
//统计树中度为二的节点个数
int countD2(TNode*tree);
//统计树中节点个数
int countNode(TNode*tree);
//统计树中节点数据总和
int countNodeData(TNode*tree);
#endif /* TREE_H_ */
