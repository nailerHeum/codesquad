### JS STEP 3 배열과 객체 실습

----

**객체(object)**

- javascript로 데이터를 표현하기 위해 Array와 Object를 사용한다.
- object는 key : value 구조를 사용(ES6부터 Map도 추가)
- 서버와 클라이언트간의 데이터 교환에는 JSON 포멧을 사용한다.



객체의 key값에는 따옴표가 필요하지 않은데 굳이 사용하면?

```js
const obj1 = {"a" : "b", "c" : "d"}

console.log(obj1)

for(var key in obj1) {
  console.log(typeof(key))
  console.log(typeof(obj1[key]))
  console.log(key)
  console.log(obj1[key])
}
//result
//string
//string
//a
//b
//string
//string
//c
//d
```

상관없다. key들을 따옴표없이 사용해도 같은 결과



```js
const obj1 = {"a" : "b", c : "d"}

console.log(obj1["a"])
//console.log(obj1[a])   -> error!

console.log(obj1["c"])
//console.log(obj1[c])   -> error!
```

key값에 따옴표가 있어도 없어도 **똑같다**

object에서 value값을 갖고오기 위해서

- `object["key"]` 이렇게 갖고오거나

- `object.key` 이렇게 갖고 오는 것 둘 중 하나를 사용하면 된다.



**for( var key in object)**

- object의 key들을 하나씩 갖고 온다.
- 위처럼 사용가능



**Object.keys(object)**

말그대로 object의 key들을 갖고오는데

갖고 와서 순차배열이 가능한 자연수(0포함)일 경우만 오름차순으로 정렬하여 배열로 반환한다.

실수로 된 키값도 순차배열이 가능할까?

```js
const obj2 = {1.2 : "wewqgwef", 15.2 : "eeieieie", 3.33 : "qwg32233"}

console.log(Object.keys(obj2))
// result
// [ '1.2', '15.2', '3.33' ]
```

예상과 달리 안됨



문자로 된 키값도 순차배열이 가능할까?

```js
const obj1 = {a : "wfwqegew", c : "wqgwef", b : "wf2323"}

console.log(Object.keys(obj1))

// result
// [ 'a', 'c', 'b' ]
```

안되니까 기대하지말자



**Object.values(object)**

말그대로 object의 value들을 갖고옴 마찬가지로 배열로 반환해준다.



**Object.entries(object)**

entry 들을 배열로 반환한다.

```js
console.log(Object.entries(obj1))
// result
// [ [ 'a', 'wfwqegew' ], [ 'c', 'wqgwef' ], [ 'b', 'wf2323' ] ]
```

하나만 꺼내오고 싶으면?

```js
console.log(Object.entries(obj1)[1])

// result
// [ 'c', 'wqgwef' ]
```

하나씩 꺼내오고 싶으면?

```js
for(const [key, value] of Object.entries(obj1)){
  console.log(`key : ${key}, value : ${value}`)
}

// result
// key : a, value : wfwqegew
// key : c, value : wqgwef
// key : b, value : wf2323
```



- Object.keys(obj)가 key들을 배열로 반환해주면 forEach와 함께 사용이 가능하네



**map (배열에서 사용하는 method임)**

- 배열의 모든 요소에 대해 주어진 함수를 호출한 그 결과들을 배열로 반환

```js
const obj1 = [{a : "wfwqegew", c : "wqgwef", b : "wf2323"}, {a : "wewqgwef", 3 : "eeieieie", 1 : "qwg32233"}]

let newData = obj1.map((v) => v.a + '뀨꺄뀨꺄')
console.log(newData)

// result
// [ 'wfwqegew뀨꺄뀨꺄', 'wewqgwef뀨꺄뀨꺄' ]
```



**filter는 함수에서 정의한 조건에 맞는 원소만 추려서 새로운 배열을 반환한다.**

```js
const obj1 = [{a : "wf", c : "wqgwef", b : "wf2323"}, {a : "wewqgwef", 3 : "eeieieie", 1 : "qwg32233"}]

let cleanData =obj1.filter(v => v.a.length > 6)
console.log(cleanData)

// result
// [ { '1': 'qwg32233', '3': 'eeieieie', a: 'wewqgwef' } ]
```



**every**

모든 요소들이 해당조건에 대해서 참일경우에만 참을 리턴해준다. 유용함



**some**

- 형식논리학에서 배웠던걸 생각한다면 every가 연언이라면 some은 선언을 사용한다고 보면된다. 
- 단 한개라도 조건을 만족하면 참을 리턴해준다. 마찬가지로 유용하게 사용이 가능할듯



### Misson!



**배열만들기**

```js
const getNumberElements = (v) => {
  let numberElements = []
  for(const [key, value] of Object.entries(v)){
    if(typeof(value) === 'object'){
      numberElements = numberElements.concat(getNumberElements(value))
    }
    if(typeof(value) === 'number'){
      numberElements.push(key)
    }
  }
  return numberElements
}
console.log(getNumberElements(data))

// result
// [ 'width',
//  'height',
//  'hOffset',
//  'vOffset',
//  'size',
//  'hOffset',
//  'vOffset' ]
```

recursive하게 만들어보았다. 

그래서 depth가 깊어지더라도 안쪽까지 들어가서 탐색을 가능하도록 했다.



**배열결과 출력**

```js
const getSkUsers = (userData) => {
  let skUsers = []
  userData.forEach(v => {
    if(v.childnode.length !==0){
      skUsers = skUsers.concat(getSkUsers(v.childnode))
    }
    if(v.type === "sk"){
      skUsers.push(v.name)
    }
  })
  return skUsers
}

let skUsers = getSkUsers(dataArr)
console.log(skUsers)
```

userData는 Array이므로 forEach를 사용하여 각 user들에 접근,

user가 childnode에 user를 갖고 있는 경우 getSkUsers를 호출하여 내부로 들어가도록 하였다.

type이 "sk"인 경우 name을 배열에 담도록 하였다.



**reduce 만들기**

----

reduce를 만드려면 우선 정확한 이해가 필요하다.

```js
arr.reduce(callback[, initialValue])
```

기존 reduce는 callback이 첫번째 인자, initialValue가 필요하다면 initialValue를 받지만 

여기서는 첫번째인자를 array, 두번째 인자를 callback 세번째 인자를 initialValue로 받기로 한다.

callback은 아래와 같이 4가지 인수를 받는데, 

- `accumulator`

  누산기accmulator는 콜백의 반환값을 누적합니다. 콜백의 이전 반환값 또는, 콜백의 첫 번째 호출이면서 `initialValue`를 제공한 경우에는 `initialValue`의 값입니다.

- `currentValue`

  처리할 현재 요소.

- `currentIndex` Optional

  처리할 현재 요소의 인덱스. `initialValue`를 제공한 경우 0, 아니면 1부터 시작합니다.



```js
const myReduce = (arr, callback, initialValue) => {
  if(initialValue !== undefined){
    arr.unshift(initialValue)
  }
  for(let i = 0;i<arr.length-1;i++){
    arr[i+1] = callback(arr[i], arr[i+1])
  }
  return arr[arr.length-1]
}

// const result = myReduce(arr, (next,prev) => {}, []);

console.log(myReduce([1,2,3,4], (accumulator, currentValue) => accumulator + currentValue))
console.log(myReduce([1,2,3,4], (accumulator, currentValue) => accumulator + currentValue, 5))
console.log(myReduce([[0, 1], [2, 3], [4, 5]], ( accumulator, currentValue ) => accumulator.concat(currentValue)))
//  10
//  15
//  [ 0, 1, 2, 3, 4, 5 ]  
```

만약 initialValue가 있다면, arr 앞쪽에 unshift method를 사용해서 붙여주고, 

없다면 그대로 진행한다. arr에서 prev와 next 인자를 사용해서 callback을 실행해야 하므로 for문을 사용하고, prev는 accumulator로써 작용해야 하기 때문에 다음 loop에서 prev로 쓰일 arr[i+1]에 callback의 결과값을 넣는다.







**참고 문서**

[reduce에 대하여](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/Reduce)