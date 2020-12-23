#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node*left;
	int data;
	struct node*right;
};
struct node*root=NULL;
int len=0;
void append();
int find_len();
void display();
void insert_atstart();
int main()
{
	int choice=0;
	while(1)
	{
		printf("enter your choice \n");
		printf("1.append\n2.find_len\n3.display\n4.insert_atstart\n0.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				append();
				break;
			case 2:
				len=find_len();
				printf("len==%d\n",len);
				break;
			case 3:
				display();
				break;
			case 4:
				insert_atstart();
				break;
			default:
				exit(0);
		}
	}
}

void append()
{
	struct node*temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data  ");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
		root->right=temp;
		root->left=temp;		
	}
	else
	{
		struct node *p=NULL;
		p=root;
		while(p->right!=root)
		{	
			p=p->right;
		}
		p->right=temp;
		temp->right=root;
		temp->left=p;
		root->left=temp;
	}
}

int find_len()
{
	struct node*temp=root;
	int cnt=0;
	while(temp->right!=root)
	{
		cnt++;
		temp=temp->right;
	}
	return ++cnt;
}

void display()
{
	struct node*temp=root;
	while(temp->right!=root)
	{
		printf("data--%d  address--%p  left->link--%p  right->link--%p\n",temp->data,temp,temp->left,temp->right);
		temp=temp->right;

	}
	printf("data--%d  address--%p  left->link--%p  right->link--%p\n",temp->data,temp,temp->left,temp->right);
}

void insert_atstart()
{
struct node*temp=NULL;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter node data  \n");
scanf("%d",&temp->data);
if(root==NULL)
{
root=temp;
root->right=temp;
root->left=temp;
}
else
{
struct node*p=root;
while(p->right!=root)
{
p=p->right;
}
temp->right=root;
p->right=temp;
temp->left=p;
root->left=temp;
root=temp;

}



}
