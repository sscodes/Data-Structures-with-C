#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head;
void insert(struct node *p)
{
	int x, pos, i;
	printf("Enter the element to be inserted : ");
	scanf("%d", &x);
	printf("Enter the position : ");
	scanf("%d", &pos);
	struct node *t=(struct node*)malloc(sizeof(struct node));
	if(pos==1)
	{
		t->data=x;
		t->next=head;
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=t;
		head=t;
	}
	else
	{
		t->data=x;
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		t->next=p->next;
		p->next=t;
	}
}
void del(struct node *p)
{
	int x, pos, i;
	printf("Enter the position : ");
	scanf("%d",&pos);
	if(pos==1)
	{
		while(p->next!=head)
		{
			p=p->next;
		}
		p->next=head->next;
		x=head->data;
		head=p->next;
		printf("%d is deleted.\n", x);
	}
	else
	{
		struct node *q=NULL;
		for(i=0;i<pos-1;i++)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;
		x=p->data;
		printf("%d is deleted.\n", x);
	}
}
void display(struct node *p)
{
	do
	{
		printf("%d ",p->data);
		p=p->next;
	}
	while(p!=head);
	printf("\n");
}
int main()
{
	int x,a=0,c;
	printf("Enter the element of the first node : ");
	scanf("%d",&x);
	head=(struct node*)malloc(sizeof(struct node));
	head->data=x;
	head->next=head;
	while(a==0)
	{
		printf("Enter your choice : \n");
		printf("1. Insert. \n");
		printf("2. Delete. \n");
		printf("3. Display. \n");
		printf("4. Quit.\n");
		scanf("%d", &c);
		if(c==1)
		insert(head);
		else if(c==2)
		del(head);
		else if(c==3)
		display(head);
		else if(c==4)
		a=1;
		else
		printf("Invalid Choice\n");
	}	
}
