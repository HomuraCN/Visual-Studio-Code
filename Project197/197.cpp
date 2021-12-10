#include <stdio.h>
#include <stdlib.h>

struct link* CreateAppendNode(struct link* head);
void DisplayNode(struct link* head);
void DeletMemory(struct link* head);

struct link
{
	long num;
	char name[20];
	char sex;
	float score[3];
	struct link* next;
};

int main()
{
	int i = 0;
	char ch;
	struct link* head = NULL;

	printf("Do you want to create and append a new node(Y / N) ?");
	scanf(" %c", &ch);

	while (ch == 'Y')
	{
		head = CreateAppendNode(head);
		DisplayNode(head);
		printf("Do you want to create and append a new node(Y / N) ?");
		scanf(" %c", &ch);
		i++;
	}

	printf("%d new node(s) have been created and appended !\n", i);

	DeletMemory(head);

	return 0;
}

struct link* CreateAppendNode(struct link *head)
{
	struct link* p = NULL, * prev = head;
	p = (struct link*)malloc(sizeof(struct link));

	if (p == NULL)
	{
		printf("No enough memory to allocate !\n");
		exit(0);
	}

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		while (prev->next != NULL)
		{
			prev = prev->next;
		}
		prev->next = p;
	}

	printf("Please input node data:");
	scanf("%ld%s %c", &p->num, p->name, &p->sex);
	for (int i = 0; i < 3; i++)
	{
		scanf("%f", &p->score[i]);
	}

	p->next = NULL;

	return head;
}

void DisplayNode(struct link *head)
{
	struct link* p = head;
	int j = 1;

	while (p != NULL)
	{
		printf("%5d%12ld%10s%2c", j, p->num, p->name, p->sex);
		for (int i = 0; i < 3; i++)
		{
			printf("%6.2f ", p->score[i]);
		}
		printf("\n");

		p = p->next;
		j++;
	}
}

void DeletMemory(struct link *head)
{
	struct link* p = head, * prev = NULL;
	
	while (p != NULL)
	{
		prev = p;
		p = p->next;
		free(prev);
	}
}