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

int* bin2hex(bool biArr[], size_t biLen){
  int* answer = (int*) malloc(sizeof(int)*biLen/4);
  int i = 1;
  int j = 1;
  int hexDigit = 0;
  int tmpAns = 0;
  bool outLoop = false;
  
  while(1) {
    for(int k = 0;k < 4; k++) {
      tmpAns = biArr[i-1]*j + tmpAns;
      j = j*2;
      i++;
      if(i > biLen){
        outLoop = true;
        break;
      }
    }
    *(answer + hexDigit) = tmpAns;
    hexDigit++;
    j = 1;
    tmpAns = 0;
    
    if (outLoop == true)
      break;
  }
  
  return answer;
}

bool* hex2bin(int hexArr[], size_t hexLen) {
  bool* answer = (bool*) malloc(sizeof(bool)*9);
  int hexDigit = 0;
  int ansIndex = 0;
  for(int i = 0; i< hexLen; i++) {
    hexDigit = hexArr[i];
    for(int j = 0; j< 4; j++) {
      if(hexDigit == 0 || hexDigit == 1) {
        *(answer + ansIndex) = hexDigit;
        ansIndex++;
        break;
      }
       *(answer + ansIndex) = hexDigit%2;
      hexDigit = hexDigit/2;
      ansIndex++;
    }
  }
  return answer;
}

int main() {
  bool* biAnswer = (bool*) malloc(sizeof(bool)*9);
  int* hexAnswer = (int*) malloc(sizeof(int)*8);
  int inDec = 0;
  int decAnswer = 0;
  size_t arrLen = 0;
  bool test1[] = {0, 1, 0, 1, 0, 1, 1, 1};
  bool test2[] = {1, 0, 0, 1, 1, 0, 1};
  bool test3[] = {1, 1, 1, 1, 1};

  printf("0~256 사이의 숫자를 입력하세요 : ");
  scanf("%d", &inDec);
  biAnswer = dec2bin(inDec);

  printf("converting...\n");
  for(int i = 0; i<9; i++) {
    printf("%d ", *(biAnswer+8-i));
  }
  printf("converted\n");
  
  printf("\nbin2dec Test ::\n");

  arrLen = sizeof(test1)/sizeof(bool);
  printf("test1 bin : ");
  for(int i = 0; i< arrLen; i++)
    printf("%d", test1[arrLen - i - 1]);
  decAnswer = bin2dec(test1, arrLen);
  printf("\nto dec : %d\n", decAnswer);

  arrLen = sizeof(test2)/sizeof(bool);
  printf("test2 bin : ");
  for(int i = 0; i< arrLen; i++)
    printf("%d", test2[arrLen - i - 1]);
  decAnswer = bin2dec(test2, arrLen);
  printf("\nto dec : %d\n", decAnswer);

  arrLen = sizeof(test3)/sizeof(bool);
  printf("test3 bin : ");
  for(int i = 0; i< arrLen; i++)
    printf("%d", test3[arrLen - i - 1]);
  decAnswer = bin2dec(test3, arrLen);
  printf("\nto dec : %d\n", decAnswer);
  

  
  printf("\n\nBINARY TO HEX\n ");
  arrLen = sizeof(test1)/sizeof(bool);
  hexAnswer = bin2hex(test1, arrLen);
  for(int i = 0; i< arrLen; i++)
    printf("%d", test1[arrLen - i - 1]);
  printf("\nbin 2 hex => ");
  for(int i = 0; i< arrLen/4 + 1; i++)
    printf("%X ", hexAnswer[arrLen/4 - i]);
  
  printf("\n\n hex2bin test\n");
  arrLen = sizeof(hexAnswer)/sizeof(int);
  biAnswer = hex2bin(hexAnswer, arrLen);
  for(int i = 0; i< arrLen; i++)
    printf("%X ", hexAnswer[arrLen -i - 1]);
  arrLen = sizeof(biAnswer, arrLen);
  printf("\narrLen = %d\n", arrLen);
  for(int i = 0; i< arrLen; i++) {
    printf("%d", biAnswer[arrLen - i - 1]);
  }
  
  printf("\n\nBINARY TO HEX\n ");
  arrLen = sizeof(test2)/sizeof(bool);
  hexAnswer = bin2hex(test2, arrLen);
  for(int i = 0; i< arrLen; i++)
    printf("%d", test2[arrLen - i - 1]);
  printf("\nbin 2 hex => ");
  for(int i = 0; i< arrLen/4 + 1; i++)
    printf("%X ", hexAnswer[arrLen/4 - i]);
  
  printf("\n\n hex2bin test\n");
  arrLen = sizeof(hexAnswer)/sizeof(int);
  biAnswer = hex2bin(hexAnswer, arrLen);
  for(int i = 0; i< arrLen; i++)
    printf("%X ", hexAnswer[arrLen -i - 1]);
  arrLen = sizeof(biAnswer, arrLen);
  printf("\narrLen = %d\n", arrLen);
  for(int i = 0; i< arrLen; i++) {
    printf("%d", biAnswer[arrLen - i - 1]);
  }
  
  printf("\n\nBINARY TO HEX\n ");
  arrLen = sizeof(test3)/sizeof(bool);
  hexAnswer = bin2hex(test3, arrLen);
  for(int i = 0; i < arrLen; i++)
    printf("%d", test3[arrLen - i - 1]);
  printf("\nbin 2 hex => ");
  for(int i = 0; i < arrLen/4 + 1; i++)
    printf("%X ", hexAnswer[arrLen/4 - i]);
  
  printf("\n\n hex2bin test\n");
  arrLen = sizeof(hexAnswer)/sizeof(int);
  biAnswer = hex2bin(hexAnswer, arrLen);
  for(int i = 0; i< arrLen; i++)
    printf("%X ", hexAnswer[arrLen -i - 1]);
  arrLen = sizeof(biAnswer, arrLen);
  printf("\narrLen = %d\n", arrLen);
  for(int i = 0; i< arrLen; i++) {
    printf("%d", biAnswer[arrLen - i - 1]);
  }
  
  printf("\nfinished\n");
  free(hexAnswer);
  free(biAnswer);

  return 0;
}
