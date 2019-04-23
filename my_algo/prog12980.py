def solution(n):
    ans = 0
    if n == 1 or n == 2:
        return 1
    if n%2==0:
        return solution(n/2)
    return solution((n-1)/2) + 1
