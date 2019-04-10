## 2019.04.08~09 JS STEP 2

----



**main.js**

```js
const util = require("./util");

function runProgram(arr) {
    const result = util.sum(arr);
    return `result is ${result}`;
}

const result = runProgram([undefined, 1,2,3,4,5,-1,"3"]);
console.log(result); //result is 14
```



**util.js**

```js
(function callModuleChecker(){
  result = new Date();
  console.log("WELCOME UTIL MODULE : " + result);
})();

module.exports.sum = (arr) => {
  result = result && 0;

  for (let i = 0; i < arr.length; i++) {
      if (arr[i] === undefined) continue;
      if (typeof arr[i] === "string") continue;
      result += arr[i]
  }

  return result;
}
```



**error**

```bash
1. Typeerror: sum is not a function
```
 `const sum = require('util')` 때문에 일어났다. 

sum을 module 객체로 갖고 왔기 때문이다. 따라서 

`const util = require('util')` 로 표현하고,

sum function을 util.sum으로 표현하였다.

```bash
2. Assignment to constant variable
```

for문 내에서 const i =0으로 선언했기 때문에 let i 로 바꿔준다.



이후 error는 발생하지 않았지만 의도에 맞는 결과를 위해 util.js 코드를 바꿔줬다.

- watch를 통해 arr[i]의 type과 value를 체크해봤다.
- typeof가 string type으로 정보를 준다는 것을 알게 되었다.



추가 미션



checkNumber function 만들기

```js
function checkNumber(value) {
  return (typeof value === "number") ? true : false;
}

module.exports.sum = (arr) => {
  result = result && 0;

  for (let i = 0; i < arr.length; i++) {
      if(!checkNumber(arr[i])) continue;
      result += arr[i]
  }

  return result;
}

```

value의 type이 "number"일 경우 true, 아닐경우 false를 반환한다.



이렇게 subroutine을 만들경우

1. 코드의 가독성이 늘어난다. checkNumber라는 함수명을 통해 코드에 대한 이해가 빨라짐
2. 이후 재사용성이 올라간다. 테스트가 용이하다 등등





### 변수

----

- var
  - function scope이기 때문에 만약 for 문 안에서 var를 사용해 변수를 만든경우 for 문 밖에서도 호출이 가능하다.
- let
  - 블록 유효 범위를 갖는 지역 변수(var와 가장 다른 점!)
- const
  - 블록 유효 범위를 가지는데 한 번만 할당할 수 있는 변수(상수)
  - 초기화가 필수



### 연산자

----
#### 산술 연산자에 대해

- 산술 이항 연산자
  - ` + , - , * , / , %` 
  - 실수의 나머지 값 계산 가능
  - `+` 연산자는 피연산자 중 하나가 문자열이면 나머지 피연산자를 문자열로 만들고 둘을 연결한다.
  - false와 null이면 0으로 평가한다. undefined면 NaN으로 평가한다.



- 산술 다항 연산자
  - `++ , -- , + , - `



- 산술 대입 연산자
  - `+= , -= , *= , /= , %= ` 
  - ex) `a += b` 는 a = a + b라는 뜻이다. 나머지도 동일한 원리이다.



- 이외의 수학적 연산이 필요할 때 Math 객체에서 필요한 property를 가져오도록한다.



#### 논리 연산자에 대해

- **관계 연산자**

  - `== , != , === , !==  , < , > , <= , >= `

- `==`와 `===` 에 대하여

  "=="(동일연산자)

  - 좌우 피연산자의 타입이 달라도 같은 타입이 되도록 변환한 다음에 판별한다.

  - 그 예로 아래와 같은 것들이 true 인 연산이 된다.

    `null == undefined`

    `1 == "1"`

    `"0xff" == 255`

    `[2] == 2`

  "==="(일치연산자)

  - 타입이 같고 값이 같아야 true를 돌려준다.

- **논리 연산자**

  - `&& , || , !`



### Data type

----

**동적 타입 언어** : 변수에 저장된 data type을 동적으로 바꿀 수 있는 언어



- **원시 타입(Primitive Type)**
  - **number, string, boolean, undefined, null, Symbol**
- **객체 타입(Object Type)**
  - 변수 여러 개가 모여서 만들어진 복합 data type
  - reference type이기 때문에 object type의 값을 변수에 대압하면 그 object에 대한 참조가 할당된다.  **Array, function, 정규표현식**



#### switch 문

----

```js
switch(expression) {
  case (exp1) : 
  	statements1
  case (exp2) : 
  	statements2
  case (exp3) : 
  	statements3
  default: 
  	statements4
}
```

`break`를 주지 않으면 switch 문 내부가 계속 실행되고, case에 속한 expression일 경우라도 default의 statements를 수행할 수 있으니 의도하지 않은 이상 break를 준다.



`if / else if / else ,  for , while , do / while ` 등

#### forEach 반복문

----

- Array, Map, Set에서 사용가능한 method(Map이랑 Set은 ES6 한정)

```js
cookieJar.forEach(function(cookie) {
  eat(cookie)
})
```

foreach 구문의 인자로 callback 함수를 등록할 수 있다.

배열의 각 요소들이 반복될 때 callback 함수가 호출됨





#### for ...in 문

----
- 모든 객체에서 사용 가능
- 객체의 key를 접근하고 value에 접근하는 방법은 제공하지 않는다.
```js
var obj = {
  a: 1,
  b: 2,
  c: 3
}
for(x in obj) {
  console.log(x, obj[x]) // a 1, b 2, c 3
}
```

value에는 직접 접근하는 방법만 있음



#### for …of 문

----

- collection 전용 반복 구문이다. collection 객체가 **[Symbol.iterator]** 속성을 갖고 있어야만 가능

  ```js
  var iterable = [10, 20, 30]
  
  for (let value of iterable) {
    console.log(value)
  }
  ```



### 문자열 methods

----

- `.length` : 문자열 길이

- `.indexOf() , lastIndexOf()` 

  : 첫번째로 등장하는 특정 text 의 index 리턴

  : 마지막으로 등장하는 특정 test의 index 리턴

  ```js
  var originalStr = "나는 집에 가고 싶다 왜냠 집이 좋아"
  var firstHome = originalStr.indexOf("집")
  // firstHome = 4
  var lastHome = originalStr.lastIndexOf("집")
  // lastHome = 16
  ```

- `.split()` : string을 인자로 쪼개서 Array에 담아서 반환해준다.

  ```js
  "가나다라가나다라가나다라".split("나")
  //["가", "다라가", "다라가", "다라"]
  ```

- `.replace(":", "a")` : 첫번째 인자를 탐색하고 두번째 인자로 바꾼다.

- `.trim()` : 문자열의 앞뒤 공백을 없애준다.

- `.charCodeAt()` : 

  ```js
  (() => {
  	console.log("쀏".charCodeAt())
  })()
  // 49167
  ```

  a의 charcodeAt을 하면 97, b를 넣어보면 98이 나온다.

  주어진 인덱스에 대한 UTF-16 코드를 나타내는 0부터 65535 사이의 정수를 반환한다.



### expression & statements

-----

- 자바스크립트는 expression과 statement를 구분한다.

- **expression**은 value를 만들어내고 value가 예상되는 곳에 쓰일 수 있다.

  아래 3줄은 모두 expression을 포함한다.

  ```js
  myvar
  3 + x
  myfunc("a", "b")
  ```

- **statement**는 action을 수행한다. loop문들과 if문이 statement들에 속한다.



### 함수 - 함수의 선언

----

함수는 여러개의 instance를 받아서 결과를 출력한다. javascript에서는 parameter 갯수와 instance 갯수가 일치하지 않아도 오류가 나지 않는다. 

parameter가 1개일 때 instance가 한개도 들어오지 않으면, parameter는 undefined라는 값을 갖게 된다.



일반적인 함수 선언

```js
function funcFunc() {
  console.log('funcfunc')
  return 'func'
}
```



### arrow function

----

`const getName = (name) => "kim" + name`

일반적인 함수 선언보다 간단하고 직관적이다. 

- javascript는 함수의 instance로 function을 넣을 수 있고, return으로 함수를 넣을 수 있어서 코드를 간결하게 해준다.



### 유용한 native 함수

----

Date나 Math와 같은 native객체를 사용한 함수들을 이용해 볼 수 있다.

**표준 내장 객체**에는 다양한 것들이 제공된다.

- 값 속성, 함수 속성, 기초 객체, 숫자 및 날짜, 텍스트 처리, 컬렉션(index), 컬렉션(key), 구조화된 데이터, 제어 추상화 객체, 리플렉션, 국제화 등

[표준내장객체](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects) 에서 상세하게 확인할 수 있다.





### 함수 호출과 stack

----

함수 호출은 **Call Stack**에 순서대로 쌓이게 된다.

![call-stack](js2-1/call-stack.png)

[자바스크립트의 동작원리](https://joshua1988.github.io/web-development/translation/javascript/how-js-works-inside-engine/#%ED%98%B8%EC%B6%9C-%EC%8A%A4%ED%83%9Dcall-stack)

- call stack에 쌓이고, 실행이 완료되면 stack에서 사라진다. 

- call stack의 벽돌 하나하나를 **Stack Frame**이라고 한다.

- call stack의 허용치를  넘겨버리면 에러가 발생한다.



### Recursive에 대해서

----

- 재귀로 구현하는 경우 종료조건이 필요하다. 

**재귀 vs 일반**

- 대게 일반함수가 재귀함수보다 성능이 좋으나 성능비교를 통해 최적의 상황을 얻어낸다.
- 모든 재귀 알고리즘은 일반 알고리즘으로 바꿀 수 있다.
- 재귀 알고리즘은 코드를 더 간결하게 만들어 줄 수 있다. 

오늘 짜봤던 재귀함수

```js
let sum = 0
const recurCircle = async (a, b) =>  {
    if(a > b){
      return
    }
    sum = sum + await that.getCircle(a)
    await recurCircle(a+1, b)
}
```

getCircle을 통해 얻은 값을 더하는 재귀함수이다. 

sum이 전역변수로 정의되어있어서 위와 같은 코드를 썼지만 전역변수 없이 짜게 된다면

```js
const recurCircle = async (a, b, sum) =>  {
    if(a > b){
      return sum
    }
    sum = sum + await that.getCircle(a)
    await recurCircle(a+1, b, sum)
  }
```

이렇게 sum을 parameter로 설정하여 정상 작동하게 할 수 있다.

이러한 경우 recurCircle()을 처음으로 호출할 때 sum에 0을 넣으면 된다.



### scope

----

**var** 

- var를 앞에 붙이지 않으면 전역변수가 된다.
- var를 전역공간에 써도 전역변수가 된다.
- var는 함수단위의 scope를 갖는다-> 다시말해서 for문이나 if else 내부에서 선언하게 되면 블록 바깥에서도 접근이 가능하다.

**let & const**

- Block 단위의 scope를 만들 수 있다.

- var 보다는 let과 const 사용을 생활화 하자
- const는 재선언, 재할당이 안된다.
- let은 재선언은 불가능하지만 재할당은 가능하다.

**const 주의할 점**

const를 사용해도 배열과 객체의 값을 변경하는 것이 가능하다!

- const를 먼저 사용하고, 재할당해야 하는 경우가 발생하면 let을 사용한다.



### scope chain이란?

- 변수를 찾기 위해서, 안쪽 scope에서 전역 scope까지 단계적으로 올라가면서 찾는 것



### hoisting

----

- 말 그대로 끌어올려진다는 의미를 가진다.



**hoisting은 선언만 끌어올리고, 초기화는 끌어올리지 않는다**

```js
var x = 1; // x 초기화
console.log(x + " " + y); // '1 undefined'
var y = 2;

```

이처럼 y를 선언만 한 것과 같이 undefined가 나온다





변수 및 함수 선언은 컴파일 단계에서 메모리에 저장되지만, 코드에서 입력한 위치에 그대로 있다.

물리적으로 작성한 코드의 상단으로 변수, 함수 선언이 옮겨지지 않는다는 뜻

```js
catName("Chloe");

function catName(name) {
  console.log("My cat's name is " + name);
}
```

이렇게 함수를 호출할 수 있고

```js
num = 6;
num + 7;
var num; 
```

이렇게 변수를 가져다 쓸 수 있다.

var의 경우는 hoisting이 되지만, const와 let의 hoisting에 대한 설명은 mdn에 없었다.



**let과 const**는 **TDZ(Temporal Dead Zone)** 에 의해 제약을 받는다.

- A period between entering scope and being declared where 'let' and 'const' cannot be accessed

```js
{  //entering scope
  
  console.log(x); //       TEMPORAL
									//			DEAD ZONE
  
  const x = 'hey';		// being declared
}
```

var 와 달리 ReferenceError가 발생한다. var였다면 undefined가 출력됐을 것



- let과 const 선언은 실행중인 실행 context의 어휘적 환경(Lexical Environment)으로 범위가 지정된 변수를 정의한다. 
- 변수는 그들의 어휘적 환경에 포함될 때 생성되지만, 어휘적 바인딩이 실행되기 전까지는 액세스할 수 없다.



**새로운 범위(ENTERING SCOPE)에 진입할 때 지정된 범위에 속한 모든 `let/const`바인딩이 지정된 범위 내부의 코드가 실행되기 전에 실행된다. (즉, `let/const ` "선언" 이 호이스팅된다.)**

대신 access는 안되니까(Temporal Dead Zone) => Error 발생

- 엑세스 할수 없으면 호이스팅을 못하는거나 마찬가지 아닌가?



#### IIFE(Immediately Invoked Function Expressions : "Iffy"로 발음)

----
즉시 호출 함수 표현식!

```js
(() => {
	console.log("쀏".charCodeAt())
})()
```

익명의 함수를 감싸서 함수 선언을 함수 표현식으로 표현될 수 있다.

```js
(showName = function (name) {
  console.log(name || "No Name")
  }
) (); // No Name
showName("Rich"); // Rich
showName(); // No Name
```

익명일 필요는 없음

IIFE의 목적 및 장점

- *젼역 영역(Global Scope)를 오염 시키지 않기 위해서*
- 조건문과 함께 사용하기
- 클로저에서 값의 중복 현상 해결





### 참고문서

----

[자바스크립트 반복문 정리 ](https://jsdev.kr/t/for-in-vs-for-of/2938)

[모던자바스크립트입문(책)](http://www.yes24.com/Product/goods/59410698)

[MDN](https://developer.mozilla.org/en-US/docs/Web/JavaScript)

[캡틴판교](https://joshua1988.github.io/web-development/translation/javascript/how-js-works-inside-engine/#%ED%98%B8%EC%B6%9C-%EC%8A%A4%ED%83%9Dcall-stack)

[let과 const의 hoisting에 대하여](https://medium.com/korbit-engineering/let%EA%B3%BC-const%EB%8A%94-%ED%98%B8%EC%9D%B4%EC%8A%A4%ED%8C%85-%EB%90%A0%EA%B9%8C-72fcf2fac365)

[Binary Search](https://ko.wikipedia.org/wiki/%EC%9D%B4%EC%A7%84_%EA%B2%80%EC%83%89_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)



### step 2-2 추가 미션

- printExecutionSequence 에서 함수의 결과까지 순서대로 출력하도록 하기 위해서

  ```js
  const saveFunctionCallName = (funcName, result) => {
    polygonCalls.push(funcName, result)
  }
  ```

  위 코드처럼 result parameter를 만들고, 도형의 넓이를 구하는 각 함수에서 result에 instance를 넘겨주도록 했다.

- 위의 hoisting에 대해 정리하였다.

- binary search란 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘이다.

  중요한 점은 sorting이 완료된 list가 필요하단 것. 중간의 값을 선택하여, 크고작음을 비교하는 방식으로 이뤄진다. 검색이 반복될 때마다 목표값을 찾을 확률은 두 배가 되어 속도가 빠르다.





## step 2-2 PR 진행과정에서 발생한 수정사항

1. props 대신 arguments 사용 >>arguments를 쓰지말라는 권고사항 => props 재사용

2. var 다신 쓰지말고 const랑 let을 쓴다.  ok

3. 반환값을 쓰는 게 없다면 그냥 return만 ok

4. saveFunctionCallName('cylinder')처럼 함수를 만들어보는게 어떰?  ok

   - push만 해주면 되는데도 사용하는 이유는 이후 결과값또한 push해줄 필요가 있을 때

     function 하나만 수정해줘도 되기 때문에

5. **template literal로 문자열 연산하기**  ok

6. **forEach말고 reduce 사용해보기**  ok



7. circle 를 재귀적으로 호출한 후에는, 전체 누적된 합을 구하는 게 문제에요. (각각의 결과를 출력하는 게 아니고)
   요것도 좀 수정해보세요. **문제를 똑바로 읽자**

**PR 완료**

- 추가미션도 해보실?

  - var, const,let 의 hoisting에 대해서 자세히 알아보자.

    - hoisting은 js를 이해하는데 중요하다. 면접 단골 질문.

    printExecutionSequence 함수를 수정하자.

  ​		수행순서 뿐 아니라, **함수의 결과까지 순서대로 같이 출력**하는 기능을 만들어보자.

  binary search 알고리즘을 공부하고, 이를 재귀함수로 구현해보자.

- 재귀호출시 전역변수 없이 구현하는 것을 생각해보세요. => 

  circle들의 합을 parameter로 넘기는 방법이 존재 한다.



