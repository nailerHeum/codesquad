#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* halfadder(bool bitA, bool bitB) {
  bool* result = (bool*) malloc(sizeof(bool)*2);
  bool sum = bitA ^ bitB;
  bool carry = bitA & bitB;
  
  *result = carry;
  *(result+1) = sum;

  return result;
}

bool* fulladder(bool bitA, bool bitB, bool carry) {
  bool* result = (bool*) malloc(sizeof(bool)*2);
  bool tmpCarry = 0;
  
  result = halfadder(bitA, bitB);
  tmpCarry = result[0];

  result = halfadder(result[1], carry);
  result[0] = tmpCarry | result[0];

  return result; 
}

int main() {
  bool* answer = (bool*) malloc(sizeof(bool)*2);
  printf("halfadder operating...\n");
  answer = halfadder(true, false);
  printf("0 + 1 = %d%d\n", answer[0], answer[1]);
  answer = halfadder(true, true);
  printf("1 + 1 = %d%d\n\n", answer[0], answer[1]);
 
  printf("fulladder operating...\n"); 
  answer = fulladder(1, 1, 1);
  printf("1 + 1 + 1 = %d%d\n", answer[0], answer[1]);
  answer = fulladder(1, 0, 1); 
  printf("1 + 0 + 1 = %d%d\n", answer[0], answer[1]);

  free(answer);
  return 0;
}
