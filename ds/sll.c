#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
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
void sortlist();
void detectloop();
void removeloop(struct node *);
void search();
void recursive_del();
void reverse_addr();
int main()
{
	//printf("%d",sizeof(root));
	int choice=0;

	while(1)
	{
		printf("enter your choice :\n");
		printf("1.append\n2.find length\n3.display data\n4.delete\n5.insert_at_start\n6.insert_inmiddle\n7.swap_node\n8.reverse\n9.removeduplicates\n10.sort list\n11.create loop\n12.detect loop\n13.search element\n14.recursive_delete\n15.reverse_address\n0.exit()\n");
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
				sortlist();
				break;
			case 11:
				root->link->link->link=root->link;
				break;
			case 12:
				detectloop();
				break;
			case 13:
				search();
				break;
			case 14:
				recursive_del();
				break;
			case 15:
				reverse_addr();
				break;
			default:exit(0);
		}
	}
}
void create_node()
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data  ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
	}

}
// finding length
int find_len()
{
	int count=0;
	struct node*temp=NULL;
	temp=root;

	while(temp!=NULL)
	{
		count++;
		temp=temp->link;
	}
	//printf("length =%d\n",len);
	return count;
}

//displaying data
void display()
{
	struct node*temp=NULL;
int i=0;
	temp=root;
	if(root==NULL)
	{
		printf("no list is created\n");
	}
	else
	{
		while(temp!=NULL)
//		while(i<4)
		{
			printf("address -->%p  ",temp);
			printf("data -->%d  ",temp->data);
			printf("address + link -->%p\n",temp->link);

			temp=temp->link;
//			i++;
		}
	}
}
void delete()
{
	struct node *temp=root;
	int loc=0;
	printf("enter location to delete==");
	scanf("%d",&loc);
	if(loc>find_len())
	{
		printf("no location to delete\n");
	}
	else if(loc==1)
	{
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else
	{
		struct node *p=root,*q;
		int i=1;
		while(i<loc-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
void insert_at_start()
{
	struct node*temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter data ");
	scanf("%d",&temp->data);
	if(root==NULL)
	{
		root=temp;
		printf("no list is created\n");
	}
	else
	{
		temp->link=root;
		root=temp;
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
	if(loc>find_len())
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

void swap_node()
{
	struct node*p,*q,*r;
	int i=1,loc;
	printf("enter location to swap");
	scanf("%d",&loc);
	if(loc>find_len())
	{
		printf("invalid location");
	}
	else
	{
		p=root;
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


void reverse()
{
	struct node*p,*q;
	int temp,i,j,k;
	p=root;
	q=root;
	i=0;
	j=find_len()-1;
	while(i<j)
	{
		k=0;
		while(k<j)
		{
			q=q->link;
			k++;
		}
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		i++;
		j--;
		p=p->link;
		q=root;
	}
}

void removeduplicates() 
{  

	struct node *temp = root, *p = NULL, *q = NULL;  
	if(root == NULL) 
	{  
		return;  
	}  
	else 
	{  
		while(temp != NULL)
		{  
			q = temp;  
			p = temp->link;  
			while(p != NULL) 
			{  
				if(temp->data == p->data) 
				{  

					q->link = p->link;  
				}  
				else 
				{  
					q = p;  
				}  
				p = p->link;  
			}  
			temp = temp->link;  
		}          
	}  
}

void sortlist()
{
	struct node *temp,*p;
	int temp1;
	temp=root;
	while(temp!=NULL)
	{
		p=temp->link;
		while(p!=NULL)
		{
			if(temp->data > p->data)
			{
				temp1=temp->data;
				temp->data=p->data;
				p->data=temp1;
			}
			p=p->link;
		}
		temp=temp->link;
	}

} 

void detectloop()
{
	struct node *slowPtr,*fastPtr;
	slowPtr = root;
	fastPtr = root;

	while(slowPtr!=NULL && fastPtr!=NULL && fastPtr->link!=NULL)
	{
		slowPtr = slowPtr->link;
		fastPtr = fastPtr->link->link;
		if (slowPtr == fastPtr)
		{
			printf("Loop is Detected\n");
//			display();
			removeloop(fastPtr);
			display();
			//           exit(0);
		}
		else
		{
			printf("No loop is detetcted\n");
		}

	}
	//printf("no loop is detected\n");
}

void removeloop(struct node *fast)
{
	struct node *p=root;
	//struct node *r=p;
	while(fast!=p->link)
	{
		p=p->link;
	}
	fast=p->link;
	fast->link=NULL;
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
{
i=1;
printf("enterred element found at address %p \n",temp);
break;
}
temp=temp->link;
}
if(i==0)
{
printf("there is no element\n");
}
}

void recursive_del()
{	struct node*temp=root;
	if(root==NULL)
	printf("list is empty\n");
	else
	{
	temp=temp->link;
	//recursive_del(root->link);
	free(root);
	root=temp;
	recursive_del();
	}
//	root=NULL;	

}

void reverse_addr()
{

	struct node* prev = NULL;
	struct node* current = root;
	struct node* next = NULL;
	while (current != NULL) {
		// Store next
		next = current->link;

		// Reverse current node's pointer
		current->link = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	root = prev;
}
