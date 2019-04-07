#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool* dec2bin(int decimal){
  bool* answer = (bool*) malloc(sizeof(bool)*9);
  int tmp = 0;
  int i =0;
  while(1) {
    tmp = decimal%2;
    decimal = decimal / 2;
    *(answer+i) = tmp;
    if(decimal == 1 || decimal == 0){
      *(answer+i+1) = decimal;
      break;
    }
    i++;
  }
  return answer;
}

int bin2dec(bool biArr[], size_t biLen){
  int answer = 0;
  int i = 1;
  int j = 1;
  while(1){
    answer = biArr[i-1]*j +answer;
    j = j*2;
    if(i == biLen)
      break;
    i++;
  }
  return answer;
}

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
  int aDec = 0;
  int bDec = 0;
  int ansLength = 0;
  int decAnswer = 0;
  bool* biAnswer = (bool*) malloc(sizeof(bool)*64);
  printf("10진수 A를 입력해주세요 : ");
  scanf("%d", &aDec);
  printf("10진수 B를 입력해주세요 : ");
  scanf("%d", &bDec);
  
  bool* a = dec2bin(aDec);
  bool* b = dec2bin(bDec);
  biAnswer = byteadder(a, b, sizeof(a)/sizeof(*a), sizeof(b)/sizeof(*b));
  ansLength = sizeof(biAnswer);
  for(int i = 0; i<ansLength; i++){
    printf("%d ", biAnswer[ansLength-i-1]);
  }
  printf("\n");
  
  decAnswer = bin2dec(biAnswer, ansLength);
  printf("%d + %d = %d\n", aDec, bDec, decAnswer);
  free(biAnswer);
  
}
