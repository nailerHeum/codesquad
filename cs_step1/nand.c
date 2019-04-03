#include <stdio.h>
#include <stdbool.h>

bool nand(bool paramA, bool paramB) {
    bool answer = true;
  	answer = !(paramA && paramB);
    return answer;
}

int main() {
  printf("true NAND true => %d\n", nand(true, true));
  printf("true NAND false => %d\n", nand(true, false));
  printf("false NAND true => %d\n", nand(false, true));
  printf("false NAND false => %d\n", nand(false, false));

  return 0;
}
