## CS Step 1

### Nand Gate

이 논리 게이트는 AND 게이트의 동작과 완전히 반대로 동작한다. 그래서 이 논리 게이트의 이름을 NOT AND (줄여서 NAND) 게이트라고 한다.



**nand**

```c
bool nand(bool paramA, bool paramB) {
    bool answer = true;
  	
  	answer = !(paramA && paramB)
    
    return answer;
}
```

말 그대로 NOT AND 게이트이므로 연언에 대해서 역을 취해주면 된다.

**NAND의 진리표**

| answer | paramA | paramB |
| ------ | ------ | ------ |
| 0      | 1      | 1      |
| 1      | 1      | 0      |
| 1      | 0      | 1      |
| 1      | 0      | 0      |



## Nor Gate

----



**nor**

```cpp
bool nor(bool paramA, bool paramB) {
    bool answer = true;
    
  	answer = !(paramA || paramB);
  	
    return answer;
}
```

NOR GATE 는 NOT OR GATE이다. 따라서 OR 연산자에 NOT을 붙여주면 된다.

**NOR의 진리표**

| answer | paramA | paramB |
| ------ | ------ | ------ |
| 0      | 1      | 1      |
| 0      | 1      | 0      |
| 0      | 0      | 1      |
| 1      | 0      | 0      |





### 이진 덧셈기(Binary Adder)



**배경 지식**

A,B 두 개 비트를 이진 덧셈기로 더하는 과정을 생각해보자. 다음과 같이 2비트 값으로 표현해볼 수 있다.

| +    | 0    | 1    |
| :--- | :--- | :--- |
| 0    | 00   | 01   |
| 1    | 01   | 10   |

#### 1) 반가산기 half-adder

이처럼 한 비트의 두 이진수를 더하면 두 비트가 되며, 각각 합(sum)과 자리올림(carry) 비트라고 한다. 두 개의 표로 구분해본다.

| 합   | 0    | 1    |
| :--- | :--- | :--- |
| 0    | 0    | 1    |
| 1    | 1    | 0    |

| 자리올림 | 0    | 1    |
| :------- | :--- | :--- |
| 0        | 0    | 0    |
| 1        | 0    | 1    |

#### 2) 전가산기 full-adder

위에서 살펴본 반가산기는 이진수 덧셈에서 가장 아래 자릿수만 계산할 수 있다. 두번째 자리부터는 자리올림이 발생하면 그것을 함께 더할 수 있어야 한다.

세 개의 이진수를 더하기 위해서는 두 개의 반가산기와 OR 게이트를 아래 그림처럼 연결하면 된다.

위와 같은 복잡한 그림 대신에 사각형과 직선으로, 아래처럼 표현하고 전가산기(full-adder)라고 부른다.



### 미션1

덧셈은 숫자 연산에서 가장 기본이 되는 동작입니다.

- BOOL 타입으로 동작하는 이진 덧셈기를 논리 게이트 동작만으로 구현해봅니다.
- 합(sum) : 합을 구하는 내부 함수를 구현합니다.
- 자리올림(carry) : 자리올림 비트를 구하는 내부 함수를 구현합니다.
- 반쪽덧셈(halfadder) : 입력을 두 개 받아서, 합(sum)과 자리올림(carry)를 배열로 리턴하는 함수를 구현합니다.
- 반쪽덧셈 예상 결과

```
byteA  = 1
byteB  = 1
결과 = [1, 0]
byteA  = 1
byteB  = 0
결과 = [0, 1]
```

- 전체덧셈(fulladder) : 입력을 두 개와 자리올림 비트를 입력으로 받아서, 합(sum)과 자리올림(carry)를 배열로 리턴하는 함수를 구현합니다.
- 전체덧셈 예상 결과

```
byteA  = 1
byteB  = 1
carry  = 1
결과 = [1, 1]
byteA  = 1
byteB  = 0
carry  = 1
결과 = [1, 0]
```



**C언어의 논리 연산자**

| Operators | Meaning of operators         |
| --------- | ---------------------------- |
| `&`       | Bitwise AND // CARRY 에 사용 |
| `|`       | Bitwise OR                   |
| `^`       | Bitwise XOR // SUM 에 사용   |
| `~`       | Bitwise complement           |
| `<<`      | Shift left                   |
| `>>`      | Shift right                  |

**halfadder**

```c
bool* halfadder(bool bitA, bool bitB) {
  bool* result = (bool*) malloc(sizeof(bool)*2);
  bool sum = bitA ^ bitB;
  bool carry = bitA & bitB;
  
  *result = sum;
  *(result+1) = carry;

  return result;
}
```



**fulladder**

```c
bool* fulladder(bool bitA, bool bitB, bool carry) {
  bool* result = (bool*) malloc(sizeof(bool)*2);
  bool tmpCarry = 0;
  
  result = halfadder(bitA, bitB);
  tmpCarry = result[1];

  result = halfadder(result[0], carry);
  result[1] = tmpCarry | result[1];

  return result; 
}
```



### 미션2



**byteadder** 

```c
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
```



**정리**

- 4비트나 16비트도 같은 함수로 한꺼번에 처리 가능한가?
  - 예 가능합니다.
- byteA와 byteB 배열의 크기가 다르면 어떻게 처리 가능할까?
  - 다르게 처리했습니다.





### 진법변환기

### 미션1

**dec2bin**

```c
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
```



### 미션2



**bin2dec**

```c
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
```



### 정리

- 앞서 만들었던 이진 덧셈기에 입력과 출력에 연결해서 10진수 덧셈이 동작하는지 여부를 확인한다.

**decAdder.c/main**

```c
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
```



- 같은 방식으로 2진수를 16진법으로 변환하는 함수를 만들어본다.

**`int* bin2hex(bool biArr[], size_t biLen)`**

```c
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
```



- 같은 방식으로 16진수를 2진법으로 변환하는 함수를 만들어본다.

**`int* hex2bin(int hexArr[], size_t hexLen)`**

```c
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
```

