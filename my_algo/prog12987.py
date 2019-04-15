def solution(A, B):
    answer = 0
    bOverFlow = False
    A.sort()
    B.sort()
    j = 0
    for i in range(len(A)):
        while A[i] >= B[j]:
            j += 1
            if j == len(B):
                bOverFlow = True
                break
        if bOverFlow == True:
            break
        answer+=1
        j+=1
        if j == len(B):
            break
    return answer
