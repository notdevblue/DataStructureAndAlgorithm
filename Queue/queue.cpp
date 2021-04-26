#include <iostream>

#define NEXT(index, QSIZE) ((index + 1) % QSIZE)

typedef struct _queue
{
	int* buf;
	int qsize;
	int front;
	int rear;
	int count;
} Queue;

void initQueue(Queue* queue, int qsize);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);

int main()
{
	int i;
	Queue queue;

	initQueue(&queue, 10);


	int data;
	while (std::cin >> data)
	{
		enqueue(&queue, data);
	}


	for (i = 0 ; i < queue.qsize; ++i)
	{
		std::cout << dequeue(&queue) << std::endl;
	}



	return(0);
}


void initQueue(Queue* queue, int qsize)
{
	queue->buf = new int[qsize];
	queue->qsize = qsize;
	queue->front = queue->rear = 0;
	queue->count = 0;
}

int isFull(Queue* queue)
{
	return queue->count == queue->qsize;
}

int isEmpty(Queue* queue)
{
	return queue->count == 0;
}

void enqueue(Queue* queue, int data)
{
	if (!isFull(queue))
	{
		queue->buf[queue->rear] = data;
		queue->rear = NEXT(queue->rear, queue->qsize);
		queue->count++;
	}
	else
	{
		std::cout << "큐가 꽉 참" << std::endl;
	}
}

int dequeue(Queue* queue)
{
	int re = 0;
	if (!isEmpty(queue))
	{
		re = queue->buf[queue->front];
		queue->front = NEXT(queue->front, queue->qsize);
		queue->count--;
		return re;
	}
	else
	{
		std::cout << "큐가 비었음" << std::endl;
		return re;
	}
}