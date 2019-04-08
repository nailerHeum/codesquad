const module1 = require('./module1')

const thisIsIndex = () => {
  console.log("Calling module1")

  const sum = module1(14, 15)
  console.log("sum is ", sum)
}
thisIsIndex()