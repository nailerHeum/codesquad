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



**내가 만든 reduce로 2번 풀어보기**

```js
const getSkUsers = (userData) => {
  let skUsers = []
	skUsers = myReduce(userData, (users, user) => {
		if(user.childnode.length !==0){
			users = users.concat(getSkUsers(user.childnode))
		}
		if(user.type==="sk"){
			users.push(user.name)
		}
		return users
	}, [])
  return skUsers
}
```



**myMap 구현하기**

```js
const myMap = (myArr, callback) => {
	let resultArr = []

	for(element of myArr){
		resultArr.push(callback(element))		
	}
	
	return resultArr
}

var result = myMap(mapArr, element => element*3)
console.log(result)
```



설계할 때 낙서로 만족하지말고 남이 이해할 수 있도록 표현하는 노력을 하자







### 추가 내용



**JSON(JavaScript Object Notation)**

json이란?

- a lightweigth data-interchange format

아래 두가지의 구조가 있다.

- **A collection of name/value pairs.** 
  - 다양한 언어들에서 JSON은  *object*, record, struct, dictionary, hash table, keyed list, associative array 등으로 인식된다.
- **An ordered list of values.** 
  - 대부분의 언어에서 *array*, vector, list, sequence로 인식된다.

json.org에서 직관적으로 json의 사용방식을 파악할 수 있는 그림들을 제공한다.

![img](js3/object.gif)

![img](js3/array.gif)

![img](js3/value.gif)

string에 대해서 양 옆에 쌍따옴표가 존재해야한다.

![img](js3/string.gif)

**JSON.stringify()**

이 method를 통해 javascript의 값이나 객체를 JSON 문자열로 반환할 수 있다.

key에 쌍따옴표가 붙어있어도, 떼어져있어도 똑같이 반환되는 것이다.



### Set & Map

**Map**

값들을 mapping하기 위한 data structure

저장한 순서대로 각 요소들을 반복적으로 접근할 수 있도록 한다.



**object와 map의 차이**

- Object의 키는 String이며, Map의 키는 모든 값을 가질 수 있다.

- Object는 크기를 수동으로 추적해야하지만, Map은 크기를 쉽게 알 수 있다.

- Map은 삽입된 순서대로 반복한다.

  

  **둘중에 뭘 쓸까??**

- 실행시까지 키를 알 수 없고, 모든 key가 동일한 datatype이고, 모든 value들이 동일한 datatype일 경우 object 대신 map을 사용해라

- 각 개별 요소에 대해 적용해야 하는 Logic이 있다? => object 사용



**Set**

집합이다! 저장된 요소들을 반복처리할수있다.(iterable)

중복된 값을 허용하지 않기 때문에 set 안에 있는 값은 set에서 unique하다. 

배열과 set은 서로 호환이 용이하다. set안에 배열을 넣으면 중복된 요소들이 삭제되면서 set으로 들어온다.



**배열과 set의 비교**

- set은 요소의 값으로 해당요소를 삭제할 수 있다.
- set은 값의 유일성을 보장하기 때문에 요소의 중복성을 확인하지 않아도 된다.



### HOF(Higher-Order Function)

고차함수란?

- 하나 이상의 함수를 인자로 받는다
- 함수를 결과로 반환한다.

이 둘 중 하나만 만족해도 고차함수!



**Abstracting Patterns of Control** : 제어 패턴 추상화

계산의 세부사항을 인자로 넘기는 함수안에 캡슐화해서 추상적으로 제공할 수 있다

쉽게 말해서 다양한 변경이 예상되는 로직을 특정 함수안에 넣으려면

```js
function repeat(n, fn) { 
  for (let i = 0; i < n; i++) { 
    fn(i); 
  } 
} 

const list = []; 
repeat(10000, (i) => {list.push(i)});

```

이런 식으로 함수를 인자로 넣어주면 원하는 방식대로 반복문을 수행할 수 있는 코드로 변하고, 다른 함수를 인자로 넣어주면 다른 기능도 수행할수 있게 되는 것이다.

비슷하게 특정 함수를 return해줄 수 있다.

필요에 따라서 적절한 함수를 return해줄 수 있다.





**참고 문서**

[reduce에 대하여](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/Reduce)

[json에 대하여](http://json.org/)

[map 관련 출처](https://developer.mozilla.org/ko/docs/Web/JavaScript/Guide/Keyed_collections)

[고차함수 관련 출처](https://dev-momo.tistory.com/entry/HigherOrder-Function-%EC%9D%B4%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80)