### 2019.04.01 Step 1-1



###LISP

------

리스프 혹은 리습은 프로그래밍 언어의 계열로서, 오랜 역사와 독특하게 괄호를 사용하는 문법으로 유명하다. 1958년에 초안이 작성된 이 언어는 현재 널리 사용되는 포트란에 이어 두 번째로 오래된 고급 프로그래밍 언어이다. 

1960년 매사추세츠 공대의 매카시(J. McCarthy) 등에 의해 고안된 리스트 처리용 프로그래밍 언어. 복잡한 수식 단위를 간략하게 표현한 언어로서 과학 기술 계산과 인공 지능용 언어임.

래퍼런스가 많이 없기 때문에 과제로 나온듯 하다.



**LISP Practice**

----

```lisp
(defun hello () 
 (concatenate 'string "hello " (read-line))
)
(format t (hello))
```

`hello()` 라는 function 생성하여

`read-line` 으로 입력받고, concatenate method를 사용하여 "hello " 와 입력 받은 string을 합치는 기능을 만든다.

`(format t (hello))`로 hello를 호출하여 그 합쳐진 문장을 출력한다.





**JS forEach Practice**

----

```js
const arr = ['cat', 'dog', 'fish']

arr.forEach(element => {
  console.log(element)
})

// 위의 forEach문을 for문으로 바꾸면

for(let i = 0;i < arr.length; i++) {
  console.log(arr[i])
}

```

forEach는 배열 method로 배열 내의 요소들을 사용할 때 사용할 수 있는 함수이다.

```js
arr.forEach(callback[, thisArg]);
```

callback은 아래 3가지 인수를 받습니다.

- `currentValue` : 처리할 현재 요소
- `index`  : 처리할 현재 요소의 index
- `array` : 호출한 배열



### 수업 자료 정리

------

[Pair programming이란](https://gmlwjd9405.github.io/2018/07/02/agile-pair-programming.html)

[lisp homebrew로 깔기](<https://sanjib.org/2014/01/26/installing-common-lisp-clisp-on-mac-os-x/>)

