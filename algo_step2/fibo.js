
let firstMonth = 1
let secondMonth = 1
let current = 1

let firstm = 1
let secondm = 1
let c = 1

const fibonacci = (firstMonth, secondMonth, targetPeriod) => {
  if (current ===1){
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

const fibonacciWithoutRecursive = (firstm, secondm, targetp) => {
  if (c ===1){
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

fibonacci(1, 1, 100)
fibonacciWithoutRecursive(1, 1, 100)