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