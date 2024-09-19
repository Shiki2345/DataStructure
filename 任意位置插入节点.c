#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
}Node;

//ͷ�ڵ�����
struct Node* head;

void Insert(int data, int n)//��һ����Ҫ��������ݣ��ڶ������������еĲ���λ��
{
	struct Node*temp1=(struct Node*)malloc(sizeof(struct Node));
	//Node* temp1 = new Node();   C++�﷨
	temp1->data = data;
	temp1->next = NULL;
	
	if (n == 1)//������λ���Ƿ�Ϊ����Ŀ�ͷ
	{
		temp1->next = head;//�½ڵ����һ��ָ��ָ��ǰ��ͷ�ڵ�
		head = temp1;//����ͷ�ڵ�Ϊ�²���Ľڵ�
		return;
	}
	//������λ�ò�������ͷ����Ѱ�Ҳ���λ�õ�ǰһ���ڵ�
	struct Node* temp2 = head;//��ͷ�ڵ㿪ʼ������������λ�õ�ǰһ���ڵ�
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;//�ƶ�����һ���ڵ�
	}
	//���½ڵ���뵽������
	temp1->next = temp2->next;//�½ڵ����һ��ָ��ָ��temp2����һ���ڵ�
	temp2->next = temp1;//temp2����һ��ָ��ָ���½ڵ�
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
	Insert(2, 1);//List:2  ������ֻ�������1�ĵط�����
	Insert(3, 2);//List:2,3
	Insert(4, 1);//List:4,2,3
	Insert(5, 2);//List:4,5,2,3
	Print();
}