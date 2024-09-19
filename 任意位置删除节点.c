#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
}Node;

//头节点声明
struct Node* head;//global

void Insert(int data)//尾插法！在链表最后插入一个整数
{
	struct Node*temp=(struct Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;

	//若链表为空则新节点成为头节点
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		//找到链表最后一个节点
		struct Node* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		//将最后一个节点的next指向新节点
		current->next = temp;
	}
}

void Print()//打印链表中的全部元素
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Delete(int n)//删除位置n处的节点
{
	struct Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next;//头指针现在指向第二个节点
		free(temp1);
		return;
	}

	for (int i = 0; i < n - 2; i++)//也就是(int i=1;i<n-1;i++)
	{
		temp1 = temp1->next;
	}//temp1 指向第(n-1)个节点
	struct Node* temp2 = temp1->next;//第几个节点
	temp1->next = temp2->next;//第n+1个节点
	free(temp2);
}

int main() {
	head = NULL;//beginning:empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);//now the list:2,4,6,5
	Print();

	int n;
	printf("Enter a position\n");
	scanf("%d" ,& n);
	Delete(n);
	Print();
}