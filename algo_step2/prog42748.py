def solution(array, commands):
    answer = []
    for i in commands:
        outArr = array[i[0]-1:i[1]]
        outArr.sort()
        inAns = outArr[i[2]-1]
        answer.append(inAns)
    return answer
