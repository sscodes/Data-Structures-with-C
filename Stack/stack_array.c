#include<stdio.h>
struct stack
{
	int size;
	int top;
	int *s;
};
void push(struct stack *st)
{
	int x;
	printf("Enter the element to be pushed : ");
	scanf("%d",&x);
	if(st->top==st->size-1)
	printf("Stack Overflow");
	else
	{
		st->top++;
		st->s[st->top]=x;
	}
}
void pop(struct stack *st)
{
	int x;
	if(st->top==-1)
	{
		printf("Stack Underflow");
	}
	else
	{
		x=st->s[st->top];
		st->top--;
		printf("Element %d is deleted", x);
	}
}
void display(struct stack *st)
{
	int i=st->top;
	while(i!=-1)
	{
		printf("%d\n", st->s[i]);
		i--;
	}
}
int main()
{
	struct stack st;
	printf("Enter size of the stack : ");
	scanf("%d", &st.size);
	st.s=(int *)malloc(st.size * sizeof(int));
	st.top=-1;
	int c;
	int a=0;
	while(a==0)
	{
		printf("Enter your choice : \n");
		printf("1. PUSH. \n");
		printf("2. POP. \n");
		printf("3. DISPLAY. \n");
		printf("4. QUIT.\n");
		scanf("%d", &c);
		if(c==1)
		push(&st);
		else if(c==2)
		pop(&st);
		else if(c==3)
		display(&st);
		else if(c==4)
		a=1;
		else
		printf("Invalid Choice\n");
	}	
	return 0;
}
