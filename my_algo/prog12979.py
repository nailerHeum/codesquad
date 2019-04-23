def solution(n, stations, w):
    answer = 0
    interval = 2*w + 1
    stations.append(n+w+1)
    stations.insert(0, -w)
    for prev in range(len(stations)-1):
        distance = stations[prev+1] - stations[prev]-1-2*w
        if distance > 0:
            answer += int(distance/interval)
            if distance%interval != 0:
                answer +=1

    return answer
