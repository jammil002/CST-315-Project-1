#include <pthread.h>
#include <string.h>

void producer() {
  int i;

  while(1){
    i = produce();
    put(i);
  }
}

void consumer() {
  int i;

  while(1){
    i = get();
    consume(i);
  }
}

int theProduct;

int produce(){ return theProduct++; }

void consume(int i){ printf("%i", i); }

int main() {
  
  return 0;
}



