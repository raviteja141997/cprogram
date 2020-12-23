#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[size];
int top=-1;
void push();
void display();
void pop();
int main()
{
	int choice=0;
	while(1)
	{
		//printf("main   top===%d\n",top);
		printf("enter your choice  \n");
		printf("1.push\n2.display\n3.pop\n0.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				display();
				break;
			case 3:
				pop();
				break;
			default:
				exit(0);
		}
	}

}

void push()
{
	if(top>=size-1)
	{
		printf("stack is full\n");
	}
	else
	{
		top++;
		printf("top===%d\n",top);
		int ele=0;
		printf("enter element  \n");
		scanf("%d",&ele);
		stack[top]=ele;
		printf("element is inserted succesfully\n");
	}
}

void display()
{
	int i=0;
	if(top<0)
		printf("stack is empty\n");
	else
	{
		for(i=0;i<=top;i++)
			printf("stack data elements=%d\n",stack[i]);
	}
}

void pop()
{
	if(top<0)
		printf("stack is empty\n");
	else
	{
		stack[--top];
		printf("element is popped succesfully\n");
	}
}
