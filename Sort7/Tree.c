#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"
TNode*createNode(int data) {
	TNode*p = (TNode*) malloc(sizeof(TNode));
	if (p) {
		p->data = data;
		p->parent = NULL;
		p->lChild = NULL;
		p->rChild = NULL;
	}
	return p;
}
void add_Child(TNode*tree, int lr, int *data) {
	TNode*p = NULL;
	switch (lr) {
	case 'l':
		if (data) {
			p = createNode(*data);
			tree->lChild = p;
			p->parent = tree;
			printf("已插入左子节点\n");
		} else {
			printf("左子节点为空\n");
		}
		break;
	case 'r':
		if (data) {
			p = createNode(*data);
			tree->rChild = p;
			p->parent = tree;
			printf("已插入右子节点\n");
		} else {
			printf("右子节点为空\n");
		}
		break;
	default:
		printf("参数不正确\n");
	}
}
void printNodeInfo(TNode*p) {
	printf("当前节点信息:\n");
	printf("当前节点指针：\t%p\n", p);
	printf("父节点指针：\t%p\n", p->parent);
	printf("左子节点指针：\t%p\n", p->lChild);
	printf("右子节点指针：\t%p\n", p->rChild);
	printf("数据：\t\t%d\n", p->data);
}
//创建树
//返回值：树的根结点的指针
TNode*init_Tree() {
	printf("请输入根结点的数据\n");
	fflush(stdout);
	int ch = 0;
	scanf("%d", &ch);
	TNode*p = createNode(ch);
	TNode*t = p;
	if (p) {
		while (1) {
			printf("\n");
			if (p->parent) {
				printf("1:\t移动到父节点\n");
			}
			if (p->lChild) {
				printf("2:\t移动到左子节点\n");
			} else {
				printf("3:\t创建左子节点\n");
			}
			if (p->rChild) {
				printf("4:\t移动到右子节点\n");
			} else {
				printf("5:\t创建右子节点\n");
			}
			printf("6:\t输出当前节点信息\n");
			printf("0:\t创建结束\n");
			fflush(stdout);
			scanf("%d", &ch);
			switch (ch) {
			case 1:
				if (p->parent) {
					p = p->parent;
				} else {
					printf("父节点为空，无法移动\n");
				}
				break;
			case 2:
				if (p->lChild) {
					p = p->lChild;
				} else {
					printf("左子节点为空，无法移动\n");
				}
				break;
			case 3:
				if (p->lChild) {
					printf("左子节点不为空，无法创建\n");
				} else {
					printf("请输入结点的数据\n");
					fflush(stdout);
					scanf("%d", &ch);
					add_Child(p, 'l', &ch);
				}
				break;
			case 4:
				if (p->rChild) {
					p = p->rChild;
				} else {
					printf("右子节点为空，无法移动\n");
				}
				break;
			case 5:
				if (p->rChild) {
					printf("右子节点不为空，无法创建\n");
				} else {
					printf("请输入结点的数据\n");
					fflush(stdout);
					scanf("%d", &ch);
					add_Child(p, 'r', &ch);
				}
				break;
			case 6:
				printNodeInfo(p);
				break;
			case 0:
				return t;
			default:
				printf("输入错误，请重新输入\n");
				break;
			}
		}
		return p;
	} else {
		printf("创建失败\n");
		return NULL;
	}
}
//访问方法
void visit(TNode*node) {
	printf("%d\t", node->data);
}
//先序遍历
void fVisit(TNode*node) {
	if (node) {
		visit(node);
		fVisit(node->lChild);
		fVisit(node->rChild);
	}
}
//中序遍历
void mVisit(TNode*node) {
	if (node) {
		mVisit(node->lChild);
		visit(node);
		mVisit(node->rChild);
	}
}
//后序遍历
void lVisit(TNode*node) {
	if (node) {
		lVisit(node->lChild);
		lVisit(node->rChild);
		visit(node);

	}
}
void print_Tree(TNode*tree, int method) {
	switch (method) {
	case 1:
		printf("先序遍历：\t");
		fVisit(tree);
		printf("\n");
		break;
	case 2:
		printf("中序遍历：\t");
		mVisit(tree);
		printf("\n");
		break;
	case 3:
		printf("后序遍历：\t");
		lVisit(tree);
		printf("\n");
		break;
	default:
		printf("参数错误\n");
		break;
	}
}
//统计树中度为零的节点个数
//参数tree：树的指针
int countD0(TNode*tree) {
	if (tree) {
		if (tree->lChild || tree->rChild) {
			return countD0(tree->lChild) + countD0(tree->rChild);
		} else {
			return 1;
		}
	} else {
		return 0;
	}
	return 0;
}
//统计树中度为一的节点个数
//参数tree：树的指针
int countD1(TNode*tree) {
	if (tree) {
		if (!tree->lChild && !tree->rChild) {
			return 0;
		}
		if (tree->lChild && tree->rChild) {
			return countD1(tree->lChild) + countD1(tree->rChild);
		}
		if (tree->lChild && !tree->rChild) {
			return countD1(tree->lChild) + 1;
		}
		if (!tree->lChild && tree->rChild) {
			return countD1(tree->rChild) + 1;
		}
	} else {
		return 0;
	}
	return 0;
}
//统计树中度为二的节点个数
//参数tree：树的指针
int countD2(TNode*tree) {
	if (tree) {
		if (tree->lChild && tree->rChild) {
			return countD2(tree->lChild) + countD2(tree->rChild) + 1;
		} else {
			return countD2(tree->lChild) + countD2(tree->rChild);
		}
	} else {
		return 0;
	}
	return 0;
}
//统计树中节点个数
//参数tree：树的指针
int countNode(TNode*tree) {
	if (tree) {
		return countNode(tree->lChild) + countNode(tree->rChild) + 1;
	} else {
		return 0;
	}
	return 0;
}
//统计树中节点数据总和
//参数tree：树的指针
int countNodeData(TNode*tree) {
	if (tree) {
		return countNodeData(tree->lChild) + countNodeData(tree->rChild)
				+ tree->data;
	} else {
		return 0;
	}
	return 0;
}
