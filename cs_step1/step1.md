## Nand Gate

----

#### 학습 목표

디지털 논리회로 기본 부품을 응용해서 만들 수 있는 부가적인 회로에 대해 학습한다.

#### 배경 지식

이 게이트는 릴레이가 동작하지 않을 때 전압이 출력되고 전구에 불이 들어오는 특징이 있다.

아래 그림을 살펴보자. 회로에서 나오는 출력이 연결되어 있어서 OR 게이트처럼 비슷하게 보인다. 이 회로는 두 스위치가 모두 닫혀있을 때만 전구에 불이 꺼집니다. 그 외에 나머지 경우에는 불이 켜진다.

![nand](http://public.codesquad.kr/jk/cs23/step1-nand.png)

이 논리 게이트는 AND 게이트의 동작과 완전히 반대로 동작한다. 그래서 이 논리 게이트의 이름을 NOT AND (줄여서 NAND) 게이트라고 한다.

NAND 는 AND 게이트 동작에 NOT(인버터)를 붙인 것과 동일하다. NAND 게이트의 출력은 다음 표와 같습니다.

| NAND  | false | true  |
| :---- | :---- | :---- |
| false | true  | true  |
| true  | true  | false |

#### 미션

- NAND 게이트 동작을 함수로 구현합니다.
- 함수의 매개변수는 BOOL 타입을 갖는 두 개를 갖고, 결과값은 BOOL 타입으로 리턴합니다.
- paramA 와 paramB 가 모두 true 일 때만 결과가 false 가 되고, 나머지 다른 경우는 모두 true가 됩니다.

> 함수 시그니처 예시

```c
bool nand(bool paramA, bool paramB) {
    bool answer = true;
  	
  	answer = !(paramA && paramB)
    
    return answer;
}
```

말 그대로 NOT AND 게이트이므로 연언에 대해서 역을 취해주면 된다.

| answer | paramA | paramB |
| ------ | ------ | ------ |
| 0      | 1      | 1      |
| 1      | 1      | 0      |
| 1      | 0      | 1      |
| 1      | 0      | 0      |



## Nor Gate

----

#### 배경 지식

이 게이트는 릴레이가 동작하지 않을 때 전압이 출력되고 전구에 불이 들어오는 특징이 있다.

아래 그림을 살펴보자. 첫 번째 릴레이의 출력은 두 번째 릴레이에 전력을 공급하는 형태가 된다. 결국 두 입력 모두가 꺼져 있어서 전구에는 불이 들어오게 된다.

![nor](http://public.codesquad.kr/jk/cs23/step1-nor.png)

이 논리 게이트는 OR 게이트의 동작과 완전히 반대로 동작한다. 그래서 이 논리 게이트의 이름을 NOT OR (줄여서 NOR) 게이트라고 한다.

NOR 는 OR 게이트 동작에 NOT(인버터)를 붙인 것과 동일하다. NOR 게이트의 출력은 다음 표와 같다.

| NOR   | false | true  |
| :---- | :---- | :---- |
| false | true  | false |
| true  | false | false |

#### 미션

- NOR게이트 동작을 구현합니다.
- 함수의 매개변수는 BOOL 타입을 갖는 두 개를 갖고, 결과값은 BOOL 타입으로 리턴합니다.
- paramA 와 paramB 가 모두 false 일 때만 결과가 true 가 되고, 나머지 다른 경우는 모두 false가 됩니다.

> 함수 시그니처 예시

```cpp
bool nor(bool paramA, bool paramB) {
    bool answer = true;
    
  	answer = !(paramA || paramB);
  	
    return answer;
}
```

NOR GATE 는 NOT OR GATE이다. 따라서 OR 연산자에 NOT을 붙여주면 된다.

| answer | paramA | paramB |
| ------ | ------ | ------ |
| 0      | 1      | 1      |
| 0      | 1      | 0      |
| 0      | 0      | 1      |
| 1      | 0      | 0      |



## 이진 덧셈기(Binary Adder)



### 학습 목표

디지털 논리회로 기본 부품을 응용해서 만들 수 있는 부가적인 회로를 연결해서, 이진 덧셈기를 만든다. 우선 1비트를 더하는 half-adder를 만들고, 8비트를 처리하는 adder를 만든다.

### 배경 지식

A,B 두 개 비트를 이진 덧셈기로 더하는 과정을 생각해보자. 다음과 같이 2비트 값으로 표현해볼 수 있다.

| +    | 0    | 1    |
| :--- | :--- | :--- |
| 0    | 00   | 01   |
| 1    | 01   | 10   |

#### 1) 반가산기 half-adder

![nor](http://public.codesquad.kr/jk/cs23/step1-halfadder.png)

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

![nor](http://public.codesquad.kr/jk/cs23/step1-fulladder.png)

위와 같은 복잡한 그림 대신에 사각형과 직선으로, 아래처럼 표현하고 전가산기(full-adder)라고 부른다.

![nor](http://public.codesquad.kr/jk/cs23/step1-fulladder-symbol.png)

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

#### 함수 시그니처 예시

> 자바

```java
class Adder {
    public boolean[] halfadder(boolean bitA, boolean bitB) {
        boolean[] answer = {};
        return answer;
    }
    public boolean[] fulladder(boolean bitA, boolean bitB, boolean carry) {
        boolean[] answer = {};
        return answer;
    }
}
```

> 자바스크립트

```javascript
function halfadder(bitA, bitB) {
    var answer = [];
    return answer;
}

function fulladder(bitA, bitB, carry) {
    var answer = [];
    return answer;
}
```

> 스위프트

```swift
func halfadder(_ bitA:Bool, _ bitB:Bool) -> [Bool] {
    return []
}

func fulladder(_ bitA:Bool, _ bitB:Bool, _ carry:Bool) -> [Bool] {
    return []
}
```

### 미션2

앞에서 만든 이진 덧셈기를 이용해서 BOOL 타입으로 동작하는 8비트 덧셈기를 구현한다.

- 바이트 덧셈(byteadder) : 8비트를 BOOL타입 배열로 2개를 입력 받는다.
- 자리올림(carry) + 전체 합(sum)을 순서대로 배열로 담아서 리턴하는 함수를 구현한다.
- 입력으로 들어오는 byteA, byteB 배열의 길이는 같다고 가정한다.
- 입력으로 들어오는 byteA 비트 순서는 낮은 자리가 배열의 앞쪽에 오도록 표현한다. 배열의 순서대로 보면 이진수가 뒤집혀 있는 것처럼 보인다고 가정한다.

```
이진수 1100 = [ 0, 0, 1, 1 ]` `이진수 0101 = [ 1, 0, 1, 0 ]
```

- 덧셈 예상 결과

```
byteA  = [ 1, 1, 0, 1, 1, 0, 1, 0 ]
byteB  = [ 1, 0, 1, 1, 0, 0, 1, 1 ]
   결과 = [ 0, 0, 0, 1, 0, 1, 0, 0, 1 ]
byteA  = [ 1, 1, 0, 0, 1, 0, 1, 0 ]
byteB  = [ 1, 1, 0, 1, 1, 0, 0, 1 ]
   결과 = [ 0, 1, 1, 1, 0, 1, 1, 1, 0 ]
```

#### 함수 시그니처 예시

> Java

```java
class Adder {
    public boolean[] byteadder(boolean[] byteA, boolean[] byteB) {
        boolean[] answer = {};
        return answer;
    }
}
```

> 자바스크립트

```javascript
function byteadder(byteA, byteB) {
    var answer = [];
    return answer;
}
```

> 스위프트

```swift
func byteadder(_ byteA:[Bool], _ byteB:[Bool]) -> [Bool] {
    return []
}
```

### 정리

- 4비트나 16비트도 같은 함수로 한꺼번에 처리 가능한가?
- byteA와 byteB 배열의 크기가 다르면 어떻게 처리 가능할까?

​	