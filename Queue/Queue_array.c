#include<stdio.h>
struct queue
{
	int size;
	int front;
	int rear;
	int *Q;
};
void enqueue(struct queue *q)
{
	if(q->rear==q->size-1)
	printf("Queue Overflow!\n");
	else
	{
		int x;
		printf("Enter the element to be enqued : ");
		scanf("%d",&x);
		q->rear++;
		q->Q[q->rear]=x;
	}
}
void dequeue(struct queue *q)
{
	if(q->rear==q->front)
	printf("Queue Underflow!\n");
	else
	{
		int x;
		q->front++;
		x=q->Q[q->front];
		printf("Element %d is deleted\n", x);
	}
}
void display(struct queue *q)
{
	if(q->front==q->rear)
	printf("Queue Underflow!\n");
	int i=q->front+1;
	while(i!=q->rear+1)
	{
		printf("%d ", q->Q[i]);
		i++;
	}
	printf("\n");
}
int main()
{
	struct queue que;
	printf("Enter size of the queue : ");
	scanf("%d", &que.size);
	que.front=-1;
	que.rear=-1;
	que.Q=(int *)malloc(que.size * sizeof(int));
	int c;
	int a=0;
	while(a==0)
	{
		printf("Enter your choice : \n");
		printf("1. Enqueue. \n");
		printf("2. Dequeue. \n");
		printf("3. Display. \n");
		printf("4. Quit.\n");
		scanf("%d", &c);
		if(c==1)
		enqueue(&que);
		else if(c==2)
		dequeue(&que);
		else if(c==3)
		display(&que);
		else if(c==4)
		a=1;
		else
		printf("Invalid Choice\n");
	}	
	return 0;
}
