#include<stdio.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *first;
void insert(struct node *p)
{
	int x, pos, i;
	printf("Enter the element to be inserted : ");
	scanf("%d",&x);
	printf("Enter the position : ");
	scanf("%d", &pos);
	struct node *t=(struct node*)malloc(sizeof(struct node));
	if(pos==1)
	{
		t->prev=NULL;
		t->data=x;
		t->next=first;
		first->prev=t;
		first=t;
	}
	else
	{
		t->data=x;
		for(i=1;i<pos-1;i++)
		p=p->next;
		t->next=p->next;
		t->prev=p;
		if(p->next)
		p->next->prev=t;
		p->next=t;
	}
}
void del(struct node *p)
{
	int x, pos, i;
	printf("Enter the position : ");
	scanf("%d", &pos);
	if(pos==1)
	{
		first=p->next;
		x=p->data;
		if(p->next)
		first->prev=NULL;
		printf("%d is deleted.\n", x);
	}
	else
	{
		for(i=0;i<pos-1;i++)
		p=p->next;
		p->prev->next=p->next;
		if(p->next)
		p->next->prev=p->prev;
		x=p->data;
		printf("%d is deleted.\n", x);
	}
}
void display(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ", p->data);
		p=p->next;
	}	
	printf("\n");
}
int main()
{
	int x=0, a=0, c;
	printf("Enter the element of first node : ");
	scanf("%d", &x);
	first = (struct node*)malloc(sizeof(struct node));
	first->prev=NULL;
	first->data=x;
	first->next=NULL;
	while(a==0)
	{
		printf("Enter your choice : \n");
		printf("1. Insert. \n");
		printf("2. Delete. \n");
		printf("3. Display. \n");
		printf("4. Quit.\n");
		scanf("%d", &c);
		if(c==1)
		insert(first);
		else if(c==2)
		del(first);
		else if(c==3)
		display(first);
		else if(c==4)
		a=1;
		else
		printf("Invalid Choice\n");
	}
	return 0;
}
