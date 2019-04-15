def solution(d, budget):
    answer = 0
    d.sort()
    for dollar in d:
        if budget - dollar < 0:
            return answer
            break
        budget -= dollar
        answer += 1
    return answer
