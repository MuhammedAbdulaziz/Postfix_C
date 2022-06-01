#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 1000


typedef struct stack {
	int tos;
	int* items = (int*)malloc(STACKSIZE * sizeof(int));;
}Stack;

void Create(Stack*);
void Push(Stack*, int);
int Pop(Stack*);
int IsEmpty(Stack*);
int IsFull(Stack*);
int SumOfStack(Stack*, int);

int main() {
	Stack ss;
	ss.tos = 0;
	Stack* s;
	s = &ss;
	Create(s);
	int size, choice = 1;
	int sum;
	int val;
	printf("Enter Size = ");
	scanf_s("%d", &size);

	do
	{

		for (int i = 0; i < size; i++) {
			printf("Enter Element[%d] = ", i + 1);
			scanf_s("%d", &val);
			Push(s, val);
		}

		sum = SumOfStack(s, size);
		printf("Sum = %d \n", sum);
		printf("Enter 0 To End : ");
		scanf_s("%d", &choice);
	} while (choice != 0);
	return 0;
}

void Create(Stack* ps) {
	ps->tos = 0;
}

void Push(Stack* ps, int val)
{
	ps->items[ps->tos] = val;
	(ps->tos)++;
}

int Pop(Stack* ps) {
	(ps->tos)--;
	printf("X::::%d\n", ps->items[ps->tos]);
	return  ps->items[(ps->tos)];
}

int IsEmpty(Stack* ps) {
	return ps->tos == 0;
}

int SumOfStack(Stack* ps, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + Pop(ps);
	}
	return sum;
}