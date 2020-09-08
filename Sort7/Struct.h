#ifndef STRUCT_H_
#define STRUCT_H_
#define MAX_SIZE 100

typedef struct SeqList {
	int data[MAX_SIZE];
	int length;
} SList;

typedef struct LinkListNode {
	int data;
	struct LinkListNode *prep, *next;
} LNode;

typedef struct Linklist {
	int length;
	LNode *head, *tail;
} LList;

typedef LList Stack;
typedef LList Queue;

typedef struct TreeNode {
	int data;
	struct TreeNode *parent, *lChild, *rChild;
} TNode;

#endif /* STRUCT_H_ */
