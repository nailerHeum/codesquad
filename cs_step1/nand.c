#include <stdio.h>
#include <stdbool.h>

bool nand(bool paramA, bool paramB) {
    bool answer = true;
  	answer = !(paramA && paramB);
    return answer;
}

int main() {
  bool a = true;
  bool b = true;
  bool nandOut = true;
  nandOut = nand(a, b);
  printf("%d", nandOut);

  return 0;
}
