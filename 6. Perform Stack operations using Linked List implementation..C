#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top = NULL;

struct node *createNode(int data)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = NULL;
}

void push(int data)
{
	struct node *ptr = createNode(data);
	if (!top)
	{
		top = ptr;
		return;
	}
	ptr->next = top;
	top = ptr;
}

void pop()
{
	struct node *ptr;
	if (!top)
	{
		printf("Stack underflow\n");
		return;
	}
	ptr = top;
	ptr = ptr->next;
	free(top);
	top = ptr;
}

void display()
{
	struct node *ptr = top;
	if (!ptr)
	{
		printf("Stack is Empty\n");
		return;
	}
	while (ptr)
	{
		printf("%-3d", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
	return;
}

int main()
{
	int data, ch;
	while (1)
	{
		printf("1. Push\n2. Pop\n3. Display\n");
		printf("4. Exit\nEnter ur choice:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter ur data:");
			scanf("%d", &data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Pleease enter right option\n");
			break;
		}
	}
	return 0;
}
