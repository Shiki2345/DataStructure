#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
//��������Ϊȫ�ֱ���,����Ҫ�ں����д���
void Push(int x)
{
	//�ж��Ƿ����
	if (top == MAX_SIZE - 1)//eg:һ�������գ�����Ѿ��ŵ��������˾Ͳ岻��ȥ��;��ʵ��ʱ��û�����ֻ�ǲ����ٲ�����
	{
		printf("Error: Man! What can I say! stack OverFlow!\n");
		return;
	}
	top++;//������һ�����
	A[top] = x;//��x�ŵ���������Ŷ�Ӧ�Ŀ�λ��
	//A[++top]=x;����дҲ��
}

void Pop()
{
	if (top == -1)//��ջ��
	{
		printf("Error: Man! What can I say! No element to POP!\n");//û��Ԫ�ؿ��Ե�����
		return;
	}
	top--;
}

void Top()
{
	return A[top];
}

void Print()
{
	int i;
	printf("Stack: ");
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}


int main() {
	Push(2); 
	Print();
	Push(5); 
	Print();
	Push(10); 
	Print();
	Pop();
	Print();
	Push(12); 
	Print();
}