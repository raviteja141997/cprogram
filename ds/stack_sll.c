#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*top=NULL;
void push();
void display();
void pop();
int main()
{
	int choice=0;
	while(1)
	{
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
	struct node*temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data  \n");
	scanf("%d",&temp->data);
	temp->link=top;
	top=temp;
}

void display()
{
	struct node*temp=top;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}

	else
	{
		while(temp!=NULL)
		{
			printf("data %d  \n",temp->data);
			temp=temp->link;

		}
	}
}

void pop()
{
	struct node*temp=top;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		top=temp->link;
		temp->link=NULL;
		free(temp);
	}
}
