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

​	