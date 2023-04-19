#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

void TestQueue()
{
	//Queue q1;
	//Queue q2;
	//QueueInit(&q1);
	//QueueInit(&q2);


	//QueueDestroy(&q1);
	//QueueDestroy(&q2);

	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueEmpty(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueEmpty(&q));
	//printf("%d\n", QueueFront(&q));
	//printf("%d\n", QueueBack(&q));

	QueueDestroy(&q);
}


int main()
{
	TestQueue();
	return 0;
}