#include <stdio.h>
#include <stdbool.h>

bool nor(bool paramA, bool paramB) {
  bool answer = true;

  answer = !(paramA || paramB);

  return answer;
}

int main() {
  printf("true NOR true => %d\n", nor(true, true));
  printf("true NOR false => %d\n", nor(true, false));
  printf("false NOR true => %d\n", nor(false, true));
  printf("false NOR false => %d\n", nor(false, false));
  return 0;
}
