const data = {
  "debug": "on",
  "window": {
      "title": "Sample Konfabulator Widget",
      "name": "main_window",
      "width": 500,
      "height": 500
  },
  "image": { 
      "src": "Images/Sun.png",
      "name": "sun1",
      "hOffset": 250,
      "vOffset": 250,
      "alignment": "center"
  },
  "text": {
      "data": "Click Here",
      "size": 36,
      "style": "bold",
      "name": "text1",
      "hOffset": 250,
      "vOffset": 100,
      "alignment": "center",
      "onMouseUp": "sun1.opacity = (sun1.opacity / 100) * 90;"
  }
}

// 1. 배열 만들기 ## 숫자타입으로만 구성된 요소를 뽑아 배열만들기
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


// 2. 배열 결과 출력 ## 특정 타입의 이름으로 배열만들기
const dataArr = [{
	"id": 1,
	"name": "Yong",
	"phone": "010-0000-0000",
	"type": "sk",
	"childnode": [{
		"id": 11,
		"name": "echo",
		"phone": "010-0000-1111",
		"type": "kt",
		"childnode": [{
				"id": 115,
				"name": "hary",
				"phone": "211-1111-0000",
				"type": "sk",
				"childnode": [{
					"id": 1159,
					"name": "pobi",
					"phone": "010-444-000",
					"type": "kt",
					"childnode": [{
							"id": 11592,
							"name": "cherry",
							"phone": "111-222-0000",
							"type": "lg",
							"childnode": []
						},
						{
							"id": 11595,
							"name": "solvin",
							"phone": "010-000-3333",
							"type": "sk",
							"childnode": []
						}
					]
				}]
			},
			{
				"id": 116,
				"name": "kim",
				"phone": "444-111-0200",
				"type": "kt",
				"childnode": [{
					"id": 1168,
					"name": "hani",
					"phone": "010-222-0000",
					"type": "sk",
					"childnode": [{
						"id": 11689,
						"name": "ho",
						"phone": "010-000-0000",
						"type": "kt",
						"childnode": [{
								"id": 116890,
								"name": "wonsuk",
								"phone": "010-000-0000",
								"type": "kt",
								"childnode": []
							},
							{
								"id": 1168901,
								"name": "chulsu",
								"phone": "010-0000-0000",
								"type": "sk",
								"childnode": []
							}
						]
					}]
				}]
			},
			{
				"id": 117,
				"name": "hong",
				"phone": "010-0000-0000",
				"type": "lg",
				"childnode": []
			}
		]
	}]
}]



// 3. reduce 구현하기!!!

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



const getSkUsers = (userData) => {
  let skUsers = []
  // userData.forEach(v => {
  //   if(v.childnode.length !==0){
  //     skUsers = skUsers.concat(getSkUsers(v.childnode))
  //   }
  //   if(v.type === "sk"){
  //     skUsers.push(v.name)
  //   }
	// })
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

let skUsers = getSkUsers(dataArr)
console.log(skUsers)

mapArr = [1, 2, 3, 4, 5, 6]

const myMap = (myArr, callback) => {
	let resultArr = []

	for(element of myArr){
		resultArr.push(callback(element))		
	}
	
	return resultArr
}

var result = myMap(mapArr, element => element*3)
console.log(result)