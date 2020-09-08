#include<stdio.h>
#include<stdlib.h>
#include"SList.h"

//创建顺序表
//返回值：顺序表的头指针
//返回NULL表示初始化失败
SList* init_SList() {
	//1。申请空间
	SList*p = (SList*) malloc(sizeof(SList));
	//2。判断是否成功
	if (p) {
		//3。初始化长度
		printf("创建成功\n");
		p->length = 0;
	} else {
		printf("创建失败\n");
	}
	return p;
}
//输出顺序表中的元素
//参数list：顺序表的指针
void print_SList(SList*list) {
	if (list) {
		printf("顺序表的长度为：\t%d\n", list->length);
		if (list->length) {
			int i = 0;
			printf("元素：\t");
			for (i = 0; i < list->length; i++) {
				printf("%d\t", list->data[i]);
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
//参数list：要操作的顺序表指针
//参数index：插入的位置
//参数data：插入的数据
void insert_SList(SList*list, int index, int data) {
	if (list) {
		if (list->length == MAX_SIZE) {
			printf("顺序表已满\n");
		} else {
			if (index < 0 || index > list->length) {
				printf("插入位置不合法\n");
			} else {
				int i = 0;
				for (i = list->length - 1; i >= index; i--) {
					list->data[i + 1] = list->data[i];
				}
				list->data[index] = data;
				list->length++;
				printf("操作成功，在%d位置上插入了数据%d\n", index, data);
			}
		}
	} else {
		printf("指针为空，无法操作\n");
	}
}
//删除数据
//参数list：要操作的顺序表指针
//参数index：删除的位置
//参数data：被删除的数据的指针
void delete_SList_index(SList*list, int index, int*data) {
	if (list) {
		if (list->length == 0) {
			printf("顺序表已空\n");
		} else {
			if (index < 0 || index > list->length) {
				printf("删除位置不合法\n");
			} else {
				if (data) {
					*data = list->data[index];
					printf("%d位置的数据%d已保存到data中\n", index, *data);
				} else {
					printf("data指针为空，无法保存数据\n");
				}
				int i = 0;
				for (i = index; i < list->length; i++) {
					list->data[i] = list->data[i + 1];
				}
				list->length--;
				printf("操作成功，在%d位置上删除了数据\n", index);
			}
		}
	} else {
		printf("指针为空，无法操作\n");
	}
}
//删除数据
//参数list：要操作的顺序表指针
//参数index：被删除的位置的指针
//参数data：删除的数据
void delete_SList_data(SList*list, int*index, int data) {
	if (list) {
		if (list->length == 0) {
			printf("顺序表已空\n");
		} else {
			int i = 0;
			for (i = 0; i < list->length; i++) {
				if (list->data[i] == data) {
					if (index) {
						*index = i;
						printf("数据%d的位置%d已保存到index中\n", data, *index);
					} else {
						printf("index指针为空，无法保存位置\n");
					}
					int j = 0;
					for (j = i; j < list->length; j++) {
						list->data[j] = list->data[j + 1];
					}
					list->length--;
					printf("操作成功，删除了数据%d\n", data);
					return;
				}
			}
			printf("没找到数据%d\n", data);
		}
	} else {
		printf("指针为空，无法操作\n");
	}
}
//查找数据
//参数list：要操作的顺序表指针
//参数index：查找的位置
//参数data：查找到的数据的指针
void search_SList_index(SList*list, int index, int*data) {
	if (list) {
		if (index < 0 || index >= list->length) {
			printf("查找位置不合法\n");
		} else {
			if (data) {
				*data = list->data[index];
				printf("%d位置的数据%d已保存到data中\n", index, *data);
			} else {
				printf("data指针为空，无法保存数据\n");
			}
		}
	} else {
		printf("指针为空，无法操作\n");
	}
}
//查找数据
//参数list：要操作的顺序表指针
//参数index：查找到的位置的指针
//参数data：查找的数据
void search_SList_data(SList*list, int*index, int data) {
	if (list) {
		int i = 0;
		for (i = 0; i < list->length; i++) {
			if (list->data[i] == data) {
				if (index) {
					*index = i;
					printf("数据%d的位置%d已保存到index中\n", data, *index);
				} else {
					printf("index指针为空，无法保存位置\n");
				}
				return;
			}
		}
		printf("没找到数据%d\n", data);
	} else {
		printf("指针为空，无法操作\n");
	}
}
//修改数据
//参数list：要操作的顺序表指针
//参数index：修改的位置
//参数data：修改的数据
void change_SList_index(SList*list, int index, int data) {
	if (list) {
		if (index < 0 || index >= list->length) {
			printf("修改位置不合法\n");
		} else {
			list->data[index] = data;
			printf("已将%d位置的数据修改为%d\n", index, data);
		}
	} else {
		printf("指针为空，无法操作\n");
	}
}
//交换两个数的值
//参数a，b：两个数的指针
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//查找最大，最小元素的位置
//参数array：要操作的数组
//参数length：数组的长度
//参数max：最大数的指针
//参数min：最小数的指针
void search_max_and_min(int array[], int length, int*max, int*min) {
	if (array) {
		if (length) {
			if (max && min) {
				int imax = array[0], imin = array[0];
				*max = 0;
				*min = 0;
				int i = 0;
				for (i = 1; i < length; i++) {
					if (array[i] > imax) {
						imax = array[i];
						*max = i;
					}
					if (array[i] < imin) {
						imin = array[i];
						*min = i;
					}
				}
			} else {
				printf("max或min指针为空，无法操作\n");
			}
		} else {
			printf("数组长度为0，无法查找\n");
		}
	} else {
		printf("数组指针为空，无法操作\n");
	}
}
//普通冒泡排序
//参数array：将要排序的数组
//参数length：数组的长度
void bubble_sort_normal(int array[], int length) {
	int i = 0, j = 0;
	for (i = 0; i < length - 1; i++) {
		for (j = 0; j < length - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}
//递归冒泡排序
//参数array：将要排序的数组
//参数length：数组的长度
void bubble_sort_recursion(int array[], int length) {
	int i = 0;
	for (i = 0; i < length - 1; i++) {
		if (array[i] > array[i + 1]) {
			swap(&array[i], &array[i + 1]);
		}
		bubble_sort_recursion(array, length - 1);
	}
}
//普通选择排序
//参数array：将要排序的数组
//参数length：数组的长度
void selection_sort_normal(int array[], int length) {
	if (length <= 1) {
		return;
	} else {
		int i = 0;
		for (i = 0; i < length; i++) {
			int max = 0, min = 0;
			search_max_and_min(array + i, length - i, &max, &min);
			if (array[i] > array[min + i]) {
				swap(&array[i], &array[min + i]);
			}
		}
	}
}
//递归选择排序
//参数array：将要排序的数组
//参数length：数组的长度
void selection_sort_recursion(int array[], int length) {
	if (length <= 1) {
		return;
	} else {
		int max = 0, min = 0;
		search_max_and_min(array, length, &max, &min);
		if (array[0] > array[min]) {
			swap(&array[0], &array[min]);
		}
		selection_sort_recursion(array + 1, length - 1);
	}
}
//顺序表排序
//参数list：顺序表的指针
//参数method：排序的方法
void sort_SList(SList*list, int method) {
	if (list) {
		switch (method) {
		case 1:
			bubble_sort_normal(list->data, list->length);
			printf("使用普通冒泡法排序\n");
			break;
		case 2:
			bubble_sort_recursion(list->data, list->length);
			printf("使用递归冒泡法排序\n");
			break;
		case 3:
			selection_sort_normal(list->data, list->length);
			printf("使用普通选择法排序\n");
			break;
		case 4:
			selection_sort_recursion(list->data, list->length);
			printf("使用递归选择法排序\n");
			break;
		default:
			printf("参数不正确，不排序\n");
		}
	} else {
		printf("数组指针为空，无法操作\n");
	}
}
