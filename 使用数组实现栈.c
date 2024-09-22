#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
//这俩设置为全局变量,不需要在函数中传参
void Push(int x)
{
	//判断是否溢出
	if (top == MAX_SIZE - 1)//eg:一共三个空，序号已经排到第三个了就插不进去了;其实此时还没溢出，只是不能再插入了
	{
		printf("Error: Man! What can I say! stack OverFlow!\n");
		return;
	}
	top++;//先自增一个序号
	A[top] = x;//把x放到自增后序号对应的坑位中
	//A[++top]=x;这样写也可
}

void Pop()
{
	if (top == -1)//空栈了
	{
		printf("Error: Man! What can I say! No element to POP!\n");//没有元素可以弹出了
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