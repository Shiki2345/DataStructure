#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
}Node;

//头节点声明
struct Node* head;

void Insert(int data, int n)//第一个是要插入的内容，第二个是在链表中的插入位置
{
	struct Node*temp1=(struct Node*)malloc(sizeof(struct Node));
	//Node* temp1 = new Node();   C++语法
	temp1->data = data;
	temp1->next = NULL;
	
	if (n == 1)//检查插入位置是否为链表的开头
	{
		temp1->next = head;//新节点的下一个指针指向当前的头节点
		head = temp1;//更新头节点为新插入的节点
		return;
	}
	//若插入位置不是链表开头，则寻找插入位置的前一个节点
	struct Node* temp2 = head;//从头节点开始，遍历到插入位置的前一个节点
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;//移动到下一个节点
	}
	//将新节点插入到链表中
	temp1->next = temp2->next;//新节点的下一个指针指向temp2的下一个节点
	temp2->next = temp1;//temp2的下一个指针指向新节点
}

void Print() {
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main() {
	head = NULL;//empty list
	Insert(2, 1);//List:2  空链表只能在序号1的地方插入
	Insert(3, 2);//List:2,3
	Insert(4, 1);//List:4,2,3
	Insert(5, 2);//List:4,5,2,3
	Print();
}