class Stack {
  constructor(){
    this.data = []
  }
  pop(){
    return this.data.pop()
  }
  push(item){
    this.data.push(item)
  }
  size(){
    return this.data.length
  }
  peek(){
    return this.data[this.data.length-1]
  }
  isEmpty(){
    return this.data.length === 0
  }
}

class StackWithSize{
  constructor(size){
    this.data = []
    this.size = size
  }
  pop(){
    if(this.isEmpty()){
      console.log('Empty stack')
      return false
    }
    return this.data.splice(this.data.length-1, 1)[0]
  }
  push(item){
    if(this.data.length === this.size){
      console.log('stack overflow')
      return false
    }
    this.data[this.data.length] = item
    return true
  }
  getSize(){
    return this.size
  }
  peek(){
    return this.data[this.data.length-1]
  }
  isEmpty(){
    return this.data.length === 0
  }
}

let stack = new Stack()
console.log(stack.isEmpty())
console.log(stack.push('ohoh'))
console.log(stack.size())
console.log(stack.peek())
console.log(stack.pop())

let stackWithSize = new StackWithSize(2)
console.log(stackWithSize.isEmpty())
console.log(stackWithSize.push('ohoh'))
console.log(stackWithSize.getSize())
console.log(stackWithSize.peek())
console.log(stackWithSize.pop())
console.log(stackWithSize.push('ohoh2'))
console.log(stackWithSize.push('ohoh3'))
console.log(stackWithSize.push('ohoh4'))
console.log(stackWithSize.peek())
console.log(stackWithSize.push('ohoh5'))
console.log(stackWithSize.getSize())