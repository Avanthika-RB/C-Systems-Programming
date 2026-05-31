#include <stdlib.h>

int main() {
  
  int* list = (int*) malloc(10);
  for (int i=0; i<10; i++) {
    list[i] = i;
  }
  list = (int*) realloc(list, 20);

  return 0;
}
