#include <stdio.h>
#include <stdbool.h>

bool nor(bool paramA, bool paramB) {
  bool answer = true;

  answer = !(paramA || paramB);

  return answer;
}

int main() {
  bool a = true;
  bool b = true;
  bool norOut = true;

  norOut = nor(a,b);

  printf("%d \n", norOut);

  return 0;
}
