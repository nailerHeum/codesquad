def solution(land, P, Q):
    answer = 0
    allArea = []
    for i in land:
        allArea = allArea + i
    current = 0
    maxFloor = max(allArea)
    oneFloor = len(allArea)
    for i in range(1, maxFloor + 2):
        current += allArea.count(i-1)
        if current*P < (oneFloor-current)*Q:
            answer += current*P
        else:
            answer += (oneFloor-current)*Q
    return answer
