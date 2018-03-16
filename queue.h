#ifndef QUEUE_H
#define QUEUE_H

typedef void* QUEUE;

typedef enum status {FAILURE, SUCCESS}Status;
typedef enum boolean { FALSE, TRUE }Boolean;

QUEUE queue_init_default(void);

Status enqueue(QUEUE hQueue, int size);

Status dequeue(QUEUE hQueue);

Boolean queue_is_empty(QUEUE hQueue);

int queue_front(QUEUE hQueue);

void queue_delete(QUEUE* phQueue);

#endif
