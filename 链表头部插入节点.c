#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;//ָ����һ���ڵ��ָ��
}Node;

//ͷ�ڵ�ָ������
struct Node* head;//global variable,can be accessed anywhere
//head = NULL;//empty list


void Insert(int x) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if (head != NULL)temp->next = head;
	head = temp;
}
void Print() {
	struct Node* temp = head;//ͷ�ڵ�ĵ�ַ
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");

}

int main()
{
	printf("How many numbers?\n");
	int n, i, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter the number\n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
}
