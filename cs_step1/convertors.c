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

int main() {
  bool* biAnswer = (bool*) malloc(sizeof(bool)*9);
  int inDec = 0;
  int decAnswer = 0;
  size_t biLen = 0; 
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

  biLen = sizeof(test1)/sizeof(bool);
  printf("test1 bin : ");
  for(int i = 0; i< biLen; i++)
    printf("%d", test1[biLen - i - 1]);  
  decAnswer = bin2dec(test1, biLen);
  printf("\nto dec : %d\n", decAnswer);

  biLen = sizeof(test2)/sizeof(bool);
  printf("test2 bin : ");
  for(int i = 0; i< biLen; i++)
    printf("%d", test2[biLen - i - 1]);  
  decAnswer = bin2dec(test2, biLen);
  printf("\nto dec : %d\n", decAnswer);

  biLen = sizeof(test3)/sizeof(bool);
  printf("test3 bin : ");
  for(int i = 0; i< biLen; i++)
    printf("%d", test3[biLen - i - 1]);  
  decAnswer = bin2dec(test3, biLen);
  printf("\nto dec : %d\n", decAnswer);



 
  free(biAnswer);

  return 0;
}
