#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* halfadder(bool bitA, bool bitB) {
  bool* result = (bool*) malloc(sizeof(bool)*2);
  bool sum = bitA ^ bitB;
  bool carry = bitA & bitB;
  
  *result = sum;
  *(result+1) = carry;

  return result;
}

bool* fulladder(bool bitA, bool bitB, bool carry) {
  bool* result = (bool*) malloc(sizeof(bool)*2);
  bool tmpCarry = 0;
  
  result = halfadder(bitA, bitB);
  tmpCarry = result[1];

  result = halfadder(result[0], carry);
  result[1] = tmpCarry | result[1];

  return result; 
}

bool* byteadder(bool byteA[], bool byteB[], size_t alen, size_t blen) {
  int bigLen = alen>blen ? alen : blen;
  int smaLen = alen>blen ? blen : alen;
  bool* tmp = (bool*) malloc(sizeof(bool)*2);
  bool* result = (bool*) malloc(sizeof(bool)*bigLen);

  result = halfadder(byteA[0], byteB[0]);
  printf("\n test1: %d %d\n", *(result+1), *result);
  for(int i = 1;i < bigLen;i++) {
    printf("byteA: %d, byteB: %d, carry: %d\n", byteA[i], byteB[i], result[i]);
    tmp = fulladder(byteA[i], byteB[i], result[i]);
    result[i] = *tmp;
    result[i+1] = *(tmp+1);
  } 
  free(tmp);
  return result;
}

int main() {
  bool* answer = (bool*) malloc(sizeof(bool)*64);
  int ansLength = 0;
  bool a[] = {0, 1, 1, 1, 1, 1};
  bool b[] = {1, 0, 1, 0, 1, 1, 0, 1};
 
  printf("halfadder operating...\n");
  answer = halfadder(true, false);
  printf("0 + 1 = %d%d\n", answer[1], answer[0]);
  answer = halfadder(true, true);
  printf("1 + 1 = %d%d\n\n", answer[1], answer[0]);
 
  printf("fulladder operating...\n"); 
  answer = fulladder(1, 1, 1);
  printf("1 + 1 + 1 = %d%d\n", answer[1], answer[0]);
  answer = fulladder(1, 0, 1); 
  printf("1 + 0 + 1 = %d%d\n\n", answer[1], answer[0]);
  answer = fulladder(1, 0, 0);
  printf("1 + 0 + 0= %d%d\n", answer[1], answer[0]);
  
  printf("byteadder testing...\n");
  answer = byteadder(a, b, sizeof(a)/sizeof(*a), sizeof(b)/sizeof(*b));
  ansLength = sizeof(answer); 
  for(int i = 0; i<ansLength; i++){
    printf("%d ", answer[ansLength-i-1]);
  }
  printf("\n");
  free(answer);
  return 0;
}
