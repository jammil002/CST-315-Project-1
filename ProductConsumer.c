#include <pthread.h>
#include <string.h>

void producer()
{
  int i;

  while (1)
  {
    i = produce();
    put(i);
  }
}

void consumer()
{
  int i;

  while (1)
  {
    i = get();
    consume(i);
  }
}

int main()
{
  pthread_t produce;
  pthread_t consume;
  pthread_create(&produce, NULL, producer, NULL);
  pthread_create(&consume, NULL, consumer, NULL);

  pthread_join(produce, NULL);
  pthread_join(consume, NULL);

  return 0;
}
