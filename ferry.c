#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void new_line(FILE* fp);

int main(int argc, char* argv[])
{
  int cases;
  int ferry_length;
  int cars;
  int car_length;
  int capacity;
  int trips;
  char side[10];
  QUEUE hRight_Queue = NULL;
  QUEUE hLeft_Queue = NULL;
  printf("hello\n");
  hRight_Queue = queue_init_default();
  hLeft_Queue = queue_init_default();
  FILE *fp;
  fp = fopen("input.txt", "r");
  fscanf(fp, "%d", &cases);
  new_line(fp);
  for(int i = 0; i < cases; i++)
  {
    printf("hello\n");
    capacity = 0;
    trips = 0;
    fscanf(fp, "%d %d", &ferry_length, &cars);
    new_line(fp);
    for (int i = 0; i < cars; i++)
    {
      printf("%d\n %d\n", queue_front(hRight_Queue), queue_front(hLeft_Queue));
      fscanf(fp, "%d %s", &car_length, side);
      capacity = capacity + car_length;
      new_line(fp);
      if (side[0] == 'l')
      {
        while (queue_is_empty(hRight_Queue) != TRUE)
        {
          dequeue(hRight_Queue);
        }
        if (queue_is_empty(hLeft_Queue) == TRUE)
        {
           capacity = 0;
           trips++;
        }
        if (capacity <= ferry_length) enqueue(hLeft_Queue, car_length);
      }
      if (side[0] == 'r')
      {
        while(queue_is_empty(hLeft_Queue) != TRUE)
        {
          dequeue(hLeft_Queue);
        }
        if (queue_is_empty(hRight_Queue) == TRUE)
        {
          capacity = 0;
          trips++;
        }
        if (capacity <= ferry_length) enqueue(hRight_Queue, car_length);
      }
    }
    printf("%d\n", (trips -1 ));
  }
}

void new_line(FILE* fp)
{
  char c = fgetc(fp);
  while (c != '\n')
  {
    c = fgetc(fp);
  }
}
