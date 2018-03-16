# Program_2
//linked list queues
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node;

typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

typedef struct queue{
  Node* front;
  Node* rear;
}Queue;


QUEUE queue_init_default(void)
{
  Queue* pQueue = (Queue*)malloc(sizeof(Queue));
  if(pQueue != NULL)
  {
    pQueue->front = NULL;
    pQueue->rear = NULL;
  }
  return pQueue;
}

Status enqueue(QUEUE hQueue, int size)
{
  Queue* pQueue = (Queue*)hQueue;
  Node* temp = (Node*)malloc(sizeof(Node));
  if (temp == NULL) return FAILURE;
  temp->next = NULL;
  temp->data = size;
  if (pQueue->front == NULL && pQueue->rear == NULL)
  {
    pQueue->front = temp;
    pQueue->rear = temp;
    return SUCCESS;
  }
  pQueue->rear->next = temp;
  pQueue->rear = temp;
  return SUCCESS;
}

Status dequeue(QUEUE hQueue)
{
  Queue* pQueue = (Queue*)hQueue;
  Node* temp = pQueue->front;
  if (pQueue->front == NULL)
  {
    printf("queue is empty\n");
    return FAILURE;
  }
  if (pQueue->front == pQueue->rear)
  {
    pQueue->front = NULL;
    pQueue->rear = NULL;
  }
  else
  {
    pQueue->front = pQueue->front->next;
  }
  free(temp);
  return SUCCESS;
}

Boolean queue_is_empty(QUEUE hQueue)
{
  Queue* pQueue = (Queue*)hQueue;
  if (pQueue->front == NULL)
  {
    return TRUE;
  }
  return FALSE;
}

int queue_front(QUEUE hQueue)
{
  Queue* pQueue = (Queue*)hQueue;
  if (queue_is_empty(pQueue) == TRUE) return 0;
  return (pQueue->front->data);
}

void queue_delete(QUEUE* phQueue)
{
  Queue* pQueue = (Queue*)*phQueue;
  Node* temp;
  while (pQueue->front != NULL)
  {
    temp = pQueue->front;
    pQueue->front = pQueue->front->next;
    free(temp);
  }
  free(pQueue);
  *phQueue = NULL;
}
