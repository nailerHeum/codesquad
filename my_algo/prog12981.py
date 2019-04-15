def solution(n, words):
    answer = []
    tmp = words[0][0]
    list = []
    breakPoint = -1
    for i in range(len(words)):
        if words[i][0] != tmp[-1]:
            breakPoint = i
            break
        for element in list:
            if element == words[i]:
                breakPoint = i
                break
        if breakPoint != -1:
            break
        tmp = words[i]
        list.append(words[i])
    if breakPoint == -1:
        return [0, 0]
    answer.append(breakPoint % n + 1)
    answer.append(breakPoint // n + 1)
    
    return answer
