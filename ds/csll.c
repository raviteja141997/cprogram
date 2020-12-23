#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
struct node * root=NULL;
int len=0;
void append();
int find_len();
void display();
void insert_atstart();
void insert_inmiddle();
int main()
{
	int choice =0;
	while(1)
	{

		printf("enter your choice\n");
		printf("1.append\n2.find_len\n3.display\n4.insert_at_start\n5.insert_inmiddle\n0.exit()\n");

		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				append();
				break;
			case 2:
				len=find_len();
				printf("len ==%d\n",len);
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
	if(root==NULL)
	{
		root=temp;
		temp->link=root;
	}
	else
	{
		struct node *p=root;
		while(p->link!=root)
		{
			p=p->link;
		}
		p->link=temp;
		temp->link=root;

	}
}

int find_len()
{
	struct node*temp=root;
	int cnt=0;
	while(temp->link!=root)
	{
		temp=temp->link;
		cnt++;
	}
//	cnt++;
	return ++cnt;
}

void display()
{
	struct node*temp=root;
	while(temp->link!=root)
	{
	 printf("address %p data %d address link %p\n",temp,temp->data,temp->link);

	temp=temp->link;
//	printf("address %p data %d address link %p\n",temp,temp->data,temp->link);
	//temp=temp->link;
	}
	printf("address %p data %d address link %p\n",temp,temp->data,temp->link);
}

void insert_atstart()
{
	struct node*temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data \n ");
	scanf("%d",&temp->data);
	struct node*p=NULL;
	if(root==NULL)
	{
		root=temp;
		temp->link=root;
	}
	else
	{
		p=root;
		while(p->link!=root)
		{
			p=p->link;
		}
		temp->link=root;
		root=temp;
		p->link=root;
	}
}


void insert_inmiddle()
{
	struct node*temp,*p=root;
        int i=1;
        int loc=0;
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter node data ");
        scanf("%d",&temp->data);
        printf("enter location to insert node==");
        scanf("%d",&loc);
	if(root==NULL)
        {
                root=temp;
                temp->link=root;
        }

       else if(loc>find_len())
        {
                printf("invalid location\n");
        }
        else
        {
                while(i<loc)
                {
                        p=p->link;
                        i++;
                }
                temp->link=p->link;
                p->link=temp;
        }

}
