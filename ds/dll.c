#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *root=NULL;
int len=0;
void append();
int find_len();
void display();
void insert_atstart();
void insert_inmiddle();
void delete();
void search();
int main()
{
	int choice=0;
	while(1)
	{
		printf("enter number to perform operation\n");
		printf("1.append\n2.find length\n3.display\n4.insert_at_start\n5.insert in middle\n6.delete node\n7.search element\n0.exit(0)\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				append();
				break;
			case 2:
				len=find_len();
				printf("length==%d\n",len);
				break;
			case 3:
				display();
				break;
			case 4:
				insert_atstart();
				break;
			case 5:
				insert_inmiddle();
				break;
			case 6:
				delete();
				break;
			case 7:	
				search();
				break;
			default:
				exit(0);
		}
	}
}

void append()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data  ");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root ==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p=NULL;
		p=root;
		while(p->right!=NULL)
		{
			p=p->right;
		}
		p->right=temp;
		temp->left=p;

	}
}

int find_len()
{	
	struct node*temp=NULL;
	int cnt=0;
	temp=root;
	while(temp!=NULL)
	{
		cnt++;
		temp=temp->right;
	}
	return cnt;
}

void display()
{
	struct node*temp=NULL;
	temp=root;
	while(temp!=NULL)
	{
		printf("data %d  ",temp->data);
		printf("address %p address left %p  address right %p\n ",temp,temp->left,temp->right);
		temp=temp->right;
	}
}

void insert_atstart()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data  ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		printf("this is first node\n");
	}
	else
	{
		temp->right=root;
		root->left=temp;
		root=temp;
	}
}

void insert_inmiddle()
{
	struct node*p,*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data  ");
	scanf("%d",&temp->data);
	int i=1;
	int loc=0;
	printf("enter location to insert  ");
	scanf("%d",&loc);
	if(loc>find_len())
	{
		printf("invalid location\n");
	}
	else
	{
		p=root;
		while(i<loc)
		{
			p=p->right;
			i++;
		}
		//q=p->right;
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
	}
}

void delete()
{
	struct node*temp=root;
	struct node*p=NULL;
	int i=1;
	int loc=0;
	printf("enter location to delete\n");
	scanf("%d",&loc);
	if(loc>find_len())
	{
		printf("no list is created\n");
	}
	else if(loc==1)
	{
		root=temp->right;
		root->left=NULL;
		free(temp);	
	}
	else if(loc==find_len())
	{
		p=root;
		while(i<loc-1)
		{
			p=p->right;
			i++;
		}
		p->right=NULL;
		
	}
	else
	{	p=root;
		while(i<loc-1)
		{
			p=p->right;
			i++;	
		}
		temp=p->right;
		p->right=temp->right;
		temp->right->left=p;
		free(temp);
	}

}

void search()
{
	struct node*temp=root;
	int ele=0;
	int i=0;
	printf("enter element to search\n");
	scanf("%d",&ele);
	while(temp!=NULL)
	{
		if(temp->data==ele)
		{	i++;
			printf("element found at following location %p\n",temp);
		}
	temp=temp->right;
	}
	if(i==0)
	{
		printf("no element found\n");
	}
}
