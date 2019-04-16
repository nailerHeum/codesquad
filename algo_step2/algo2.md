## STEP 2 재귀와 DP(Dynamic Programming)

### 재귀함수

----

**재귀함수를 사용한 피보나치**

```js
let firstMonth = 1
let secondMonth = 1
let current = 1

const fibonacci = (firstMonth, secondMonth, targetPeriod) => {
  if (current === 1){
    console.log('재귀함수를 사용하였다!')
    console.log('1 개월 째 토끼의 수 : 1')
  }
  current++
  console.log(`${current} 개월 째 토끼의 수 : ${secondMonth}`)
  if(current === targetPeriod){
    return secondMonth
  }
  let tmp = secondMonth
  secondMonth = firstMonth + secondMonth
  firstMonth = tmp
  fibonacci(firstMonth, secondMonth, targetPeriod)
}
```



**재귀함수를 사용하지 않은 피보나치**

```js
let firstm = 1
let secondm = 1
let c = 1

const fibonacciWithoutRecursive = (firstm, secondm, targetp) => {
  if (c === 1){
    console.log('재귀함수를 사용안했다!')
    console.log('1 개월 째 토끼의 수 : 1')
  }
  while(c < targetp){
    c++
    console.log(`${c} 개월 째 토끼의 수 : ${secondm}`)
    let tmp = secondm
    secondm = firstm + secondm
    firstm = tmp
  }
  return secondm
}
```

재귀함수를 읽을 때 좀더 직관적으로 이해할 수 있다.



**하노이**

```js
var count = 0
function hanoi (base, temp, target, num) {
  count++
  if(num === 1) {
    console.log(`${num}번 원반을 ${base}에서 ${target}으로 옮깁니다.`)
    return
  }
  hanoi(base, target, temp, num-1)
  console.log(`${num}번 원반을 ${base}에서 ${target}으로 옮깁니다.`)
  hanoi(temp, base, target, num-1)
  return
}

hanoi('A', 'B', 'C', 10)

console.log(`${count} moves!`)
```



**Dynamic Programming**

----

DP가 아니라 메모제이션 기법을 사용하는거라 생각하자



