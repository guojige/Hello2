#include "queue.h"

queue_t *queue_init()
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}


void enqueue(queue_t *queue, int value)
{

	if(queue==NULL)
		return ;

	node_t *newnode = (node_t *)malloc(sizeof(node_t));
	newnode->data = value;
	newnode->next = NULL;


	//  queue->rear != NULL
	if(queue->front==NULL && queue->rear==NULL)
	{
		queue->front = newnode;
		queue->rear = newnode;
	}
	else
	{
		queue->rear->next = newnode;
		queue->rear = newnode;
	}

}



int dequeue(queue_t *queue)
{
	if(queue==NULL)
		return -666;
	if(queue->front==NULL && queue->rear==NULL)
		return -666;
	node_t *tmp;
	tmp = queue->front;
	queue->front = queue->front->next;
	if(queue->front == NULL)
		queue->rear = NULL;
	int v = tmp->data;
	free(tmp);
	return v;
}












