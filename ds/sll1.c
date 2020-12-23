#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node * link;
};
struct node *root=NULL;
int len=0;
void create_node();
int find_len();
void display();
void delete();
void insert_at_start();
void insert_inmiddle();
void swap_node();
void reverse();
void removeduplicates();
void sort();
int main()
{
        //printf("%d",sizeof(root));
        int choice=0;

        while(1)
        {
                printf("enter your choice :\n");
                printf("1.append\n2.find length\n3.display data\n4.delete\n5.insert_at_start\n6.insert_inmiddle\n7.swap_node\n8.reverse\n9.removeduplicates\n10.sort list\n0.exit()\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                create_node();
                                break;
                        case 2:
                                len=find_len();
                                printf("len==%d\n",len);
				break;
                        case 3:
                                display();
                                break;
                        case 4:
                                delete();
                                break;
                        case 5:
                                insert_at_start();
                                break;
                        case 6:
                                insert_inmiddle();
                                break;
			case 7:
				swap_node();
				break;
			case 8:
				reverse();
				break;
			case 9:
				removeduplicates();
				break;
			case 10:
				sort();
				break;
			default:
				exit(0);

	}
		}
}

void create_node()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter node data  ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p=NULL;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}

}
int find_len()
{
	struct node *temp=NULL;
	int cnt=0;
	temp=root;
	while(temp!=NULL)
	{
		cnt++;
		temp=temp->link;
	}
	return cnt;
}

void display()
{
	struct node *temp=NULL;
	while(temp!=NULL)
	{
		printf("data -->%d\n",temp->data);
		temp=temp->link;
	}
}

void delete()
{
	struct node *temp=NULL;
	struct node *p=NULL;
	int i=1;
	int loc=0;
	printf("enter location to delete element\n");
	scanf("%d",&loc);
	temp=root;
	if(loc>find_len())
	{
		printf("invalid location\n");
	}
	else if(loc==1)
	{
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		p=root;
		if(i<loc-1)
		{
			p=p->link;
			i++;
		}
		temp=p->link;
		p->link=temp->link;
		temp->link=NULL;
		free(temp);
	}
}

void insert_at_start()
{
	struct node *temp=NULL;
	struct node *p=NULL;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter node data\n  ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		printf("this is first node\n");
	}
	else
	{
		temp->link=root;
		root=temp;
	}
}

void insert_inmiddle()
{
	struct node *temp=NULL;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter node data\n  ");
	scanf("%d",&temp->data);
	int i=1;
	int loc=0;
	printf("enter location to insert\n");
	scanf("%d",&loc);
	if(loc>find_len())
	{
		printf("invalid location\n");
	}
	else
	{
		struct node*p=root;
		while(i<loc)
		{
			p=p->link;
			i++;
		}
		temp->link=p->link;
		p->link=temp;
	}
}

void swap_node()
{	struct node *r=NULL;
	struct node *p=NULL;
	struct node *q=NULL;
	int i=1;
        int loc=0;
        printf("enter location to swap\n");
        scanf("%d",&loc);
        if(loc>find_len())
        {
                printf("invalid location\n");
        }
        else
        {
                struct node*p=root;
                while(i<loc-1)
                {
                        p=p->link;
                        i++;
                }
                q=p->link;
                r=q->link;
		q->link=r->link;
		r->link=q;
		p->link=r;
		
        }

}
