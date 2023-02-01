#include <pthread.h>
#include <string.h>
#include <stdio.h>

// Create buffer to remove and delete from.
int buffer[10];
// Count to keep the correct point in the buffer.
int count = 0;

int produce() { return count++; }

void consume(int i) { printf("%i", i); }

void put(int i)
{
  buffer[count] = i;
}

int get()
{
  return buffer[count];
}

void *producer()
{
  int i;

  while (count < 10)
  {
    i = produce();
    put(i);
  }
}

void *consumer()
{
  int i;

  while (count >= 0)
  {
    i = get();
    consume(i);
  }
}

int main()
{
  pthread_t produceThread;
  pthread_t consumeThread;

  pthread_create(&produceThread, NULL, producer, NULL);
  pthread_join(produceThread, NULL);

  pthread_create(&consumeThread, NULL, consumer, NULL);
  pthread_join(consumeThread, NULL);

  return 0;
}
