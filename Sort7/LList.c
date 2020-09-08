#include<stdio.h>
#include<stdlib.h>
#include"LList.h"
//创建双链表
//返回值：双链表的头节点指针
//返回NULL表示初始化失败
LList*init_LList() {
	//1。申请空间
	LList*p = (LList*) malloc(sizeof(LList));
	//2。判断是否成功
	if (p) {
		//3。初始化长度
		printf("创建成功\n");
		p->length = 0;
		//4。初始化头尾指针
		p->head = NULL;
		p->tail = NULL;
	} else {
		printf("创建失败\n");
	}
	return p;
}
//输出双链表中的元素
//参数list：双链表的指针
void print_LList(LList*list) {
	if (list) {
		printf("长度为：\t%d\n", list->length);
		if (list->length) {
			LNode*p = list->head;
			printf("元素：\t");
			while (p) {
				printf("%d\t", p->data);
				p = p->next;
			}
			printf("\n");
		} else {
			printf("元素为空\n");
		}
	} else {
		printf("参数为空，无法输出\n");
	}
}
//插入数据
//参数list：要操作的双链表指针
//参数index：插入的位置
//参数data：插入的数据
void insert_LList(LList*list, int index, int data) {
	if (list) {
		if (index <= 0 || index > list->length + 1) {
			printf("插入位置不合法\n");
		} else {
			LNode*node = (LNode*) malloc(sizeof(LNode));
			if (node) {
				node->data = data;
				node->prep = NULL;
				node->next = NULL;
				if (list->length) {
					if (index == 1) {
						list->head->prep = node;
						node->next = list->head;
						list->head = node;
					} else if (index == list->length + 1) {
						list->tail->next = node;
						node->prep = list->tail;
						list->tail = node;
					} else {
						LNode*p1 = list->head, *p2 = NULL;
						int i = 0;
						for (i = 1; i < index - 1; i++) {
							p1 = p1->next;
						}
						p2 = p1->next;
						p1->next = node;
						node->next = p2;
						p2->prep = node;
						node->prep = p1;
					}
				} else {
					list->head = node;
					list->tail = node;
				}
				list->length++;
				printf("操作成功，在%d位置上插入了数据%d\n", index, data);
			} else {
				printf("创建节点失败\n");
			}
		}
	} else {
		printf("参数为空，无法输出\n");
	}
}
//头插法
//参数list：要操作的双链表指针
//参数data：插入的数据
void insert_LList_head(LList*list, int data) {
	printf("使用头插法插入数据%d\n", data);
	insert_LList(list, 1, data);
}
//尾插法
//参数list：要操作的双链表指针
//参数data：插入的数据
void insert_LList_tail(LList*list, int data) {
	printf("使用尾插法插入数据%d\n", data);
	insert_LList(list, list->length + 1, data);
}
//根据位置删除数据
//参数list：要操作的双链表指针
//参数index：删除的位置
//参数data：删除的数据的指针
void delete_LList_index(LList*list, int index, int *data) {
	if (list) {
		if (index <= 0 || index > list->length) {
			printf("删除位置不合法\n");
		} else {
			LNode*p = NULL;
			if (list->length == 1) {
				p = list->head;
				list->head = NULL;
				list->tail = NULL;
			} else if (index == 1) {
				p = list->head;
				list->head = p->next;
				p->next->prep = NULL;
			} else if (index == list->length) {
				p = list->tail;
				list->tail = p->prep;
				p->prep->next = NULL;
			} else {
				p = list->head;
				int i = 0;
				for (i = 1; i < index; i++) {
					p = p->next;
				}
				p->prep->next = p->next;
				p->next->prep = p->prep;
			}
			if (data) {
				*data = p->data;
			} else {
				printf("data指针为空，无法保存数据\n");
			}
			free(p);
			printf("操作成功，在%d位置上删除了数据\n", index);
			list->length--;
		}
	} else {
		printf("参数为空，无法输出\n");
	}
}
//头删法
//参数list：要操作的双链表指针
//参数data：删除的数据的指针
void delete_LList_head(LList*list, int *data) {
	delete_LList_index(list, 1, data);
	printf("使用头删法删除数据\n");
}
//尾删法
//参数list：要操作的双链表指针
//参数data：删除的数据的指针
void delete_LList_tail(LList*list, int *data) {
	delete_LList_index(list, list->length, data);
	printf("使用尾删法删除数据\n");
}
