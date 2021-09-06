#include <stdio.h>
#include <stdlib.h>

struct poly *link(struct poly *);
void display(struct poly *);
struct poly *addlink(struct poly *, struct poly *, struct poly *);

struct poly
{
	int coeff, pow;
	struct poly *ptr;
};

int main()
{
	struct poly *head1, *head2, *head3;
	int num;
	head1 = NULL;
	head2 = NULL;
	head3 = NULL;

	while (1)
	{
		printf("\nEnter\n1->To create first polynomial function\n2->To create second polynomial function\n3->To display first polynomial function\n4->To display second polynomial function\n5->To add both the polynomial functions\n6->To display the new polynomial created after addition\n");
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			head1 = link(head1);
			break;

		case 2:
			head2 = link(head2);
			break;

		case 3:
			display(head1);
			break;

		case 4:
			display(head2);
			break;

		case 5:
			head3 = addlink(head1, head2, head3);
			break;

		case 6:
			display(head3);
			break;

		default:
			printf("\nBoss ! Enter the correct value\n");
		}
	}
}

struct poly *link(struct poly *head1)
{
	struct poly *newnode;
	int value, degree;
	newnode = NULL;
	printf("\nEnter the coefficient of the polynomial\n");
	scanf("%d", &value);
	printf("\nEnter the degree for variable x\n");
	scanf("%d", &degree);

	newnode = (struct poly *)malloc(sizeof(struct poly));

	newnode->pow = degree;
	newnode->coeff = value;

	if (head1 == NULL)
	{
		printf("\nThe first node is created\n");
		newnode->ptr = NULL;
	}
	else
	{
		printf("\nThe next node is being linked\n");
		newnode->ptr = head1;
	}
	return newnode;
}

void display(struct poly *head)
{
	if (head == NULL)
	{
		printf("\nThe polynomial function is not created.\nPlease create a new polynomial function.\n");
	}

	while (head != NULL && head->ptr != NULL)
	{
		printf("The polynomial function has been detected\n");
		printf("%dx^%d+", head->coeff, head->pow);
		head = head->ptr;
	}

	if (head->ptr == NULL)
	{
		printf("\nEntering the last node\n");
		printf("%dx^%d", head->coeff, head->pow);
		head = head->ptr;
	}
}

struct poly *addlink(struct poly *head, struct poly *tail, struct poly *head3)
{
	struct poly *temp1, *temp, *newnode;
	temp = newnode = temp1 = head3 = NULL;

	newnode = (struct poly *)malloc(sizeof(struct poly));

	if (head == NULL || tail == NULL)
	{
		printf("\nYou have no node to get added\n");
	}
	if (head != NULL && tail == NULL)
	{
		printf("\nThe existing first polynomial is the final polynomial\n");
		return head;
	}
	if (head == NULL && tail != NULL)
	{
		printf("\nThe existing second polynomial is the final polynomial\n");
		return tail;
	}

	head3 = newnode;

	if (head3 == NULL)
	{
		printf("\nEnter a node first\n");
	}

	if (head3 != NULL)
	{
		while (head != NULL && tail != NULL)
		{
			if (head->pow > tail->pow)
			{
				temp = tail;
				temp1 = head;
				while ((head->pow) > (temp->pow))
				{
					printf("\nThe element's degree in first poly. is greater than the second\n");

					if (temp->ptr == NULL)
					{
						newnode->coeff = temp->coeff;
						newnode->pow = temp->pow;
						newnode->ptr = NULL;
						head3 = newnode;
						return head3;
						temp1 = temp1->ptr;
					}

					temp = temp->ptr;
				}
				printf("\nYou have come to the end of the tail pointer\n");
			}

			if (tail->pow > head->pow)
			{
				temp = head;
				temp1 = tail;
				while ((tail->pow) > (temp->pow))
				{
					printf("\nThe element's degree in second poly. is greater than the first\n");

					if (temp->ptr == NULL)
					{
						newnode->coeff = temp->coeff;
						newnode->pow = temp->pow;
						newnode->ptr = NULL;
						head3 = newnode;
						return head3;
						temp1 = temp1->ptr;
					}

					temp = temp->ptr;
				}

				printf("\nYou have come to the end of the tail pointer\n");
			}

			if (head->pow == tail->pow)
			{
				temp = head;
				temp1 = tail;

				while ((temp->pow == temp1->pow))
				{
					newnode->coeff = (temp->coeff + tail->coeff);
					newnode->pow = temp->pow;
					head3 = newnode;
					return head3;
					temp = temp->ptr;
					temp1 = temp1->ptr;
				}
			}
		}
	}
}
