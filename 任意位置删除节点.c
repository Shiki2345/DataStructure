#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
}Node;

//ͷ�ڵ�����
struct Node* head;//global

void Insert(int data)//β�巨��������������һ������
{
	struct Node*temp=(struct Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;

	//������Ϊ�����½ڵ��Ϊͷ�ڵ�
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		//�ҵ��������һ���ڵ�
		struct Node* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		//�����һ���ڵ��nextָ���½ڵ�
		current->next = temp;
	}
}

void Print()//��ӡ�����е�ȫ��Ԫ��
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Delete(int n)//ɾ��λ��n���Ľڵ�
{
	struct Node* temp1 = head;
	if (n == 1)
	{
		head = temp1->next;//ͷָ������ָ��ڶ����ڵ�
		free(temp1);
		return;
	}

	for (int i = 0; i < n - 2; i++)//Ҳ����(int i=1;i<n-1;i++)
	{
		temp1 = temp1->next;
	}//temp1 ָ���(n-1)���ڵ�
	struct Node* temp2 = temp1->next;//�ڼ����ڵ�
	temp1->next = temp2->next;//��n+1���ڵ�
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