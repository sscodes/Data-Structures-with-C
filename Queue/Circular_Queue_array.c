#include<stdio.h>
struct cir_queue
{
	int size;
	int front;
	int rear;
	int *CQ;
};
void enqueue(struct cir_queue *q)
{
	if((q->rear+1)%q->size==q->front)
	printf("Queue Overflow!\n");
	else
	{
		int x;
		printf("Enter the element to be enqued : ");
		scanf("%d",&x);
		q->rear=(q->rear+1)%q->size;
		q->CQ[q->rear]=x;
	}
}
void dequeue(struct cir_queue *q)
{
	if(q->rear==q->front)
	printf("Queue Underflow!\n");
	else
	{
		int x;
		q->front=(q->front+1)%q->size;
		x=q->CQ[q->front];
		printf("Element %d is deleted\n", x);
	}
}
void display(struct cir_queue *q)
{
	if(q->front==q->rear)
	printf("Queue Underflow!\n");
	int i=q->front+1;
	while(i!=(q->rear+1)%q->size)
	{
		printf("%d ", q->CQ[i]);
		i=(i+1)%q->size;
	}
	printf("\n");
}
int main()
{
	struct cir_queue cque;
	printf("Enter size of the queue : ");
	scanf("%d", &cque.size);
	cque.front=0;
	cque.rear=0;
	cque.CQ=(int *)malloc(cque.size * sizeof(int));
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
		enqueue(&cque);
		else if(c==2)
		dequeue(&cque);
		else if(c==3)
		display(&cque);
		else if(c==4)
		a=1;
		else
		printf("Invalid Choice\n");
	}	
	return 0;
}
