def solution(nums):
    answer = 0
    
    sumOfNums = sum(nums)
    comArr = list(range(2, sumOfNums+1))
    for i in comArr:       # 범위 내 소수들 추적
        if i==0:
            continue
        j = i*2
        while j < sumOfNums+1:
            try:
                comArr.remove(j)
            except:
                pass
            j += i
            
    answerArr = []
    for a in range(len(nums)-2):
        firstIdx = a
        for b in range(len(nums)-a-2):
            secondIdx = firstIdx + b + 1
            for c in range(len(nums)-secondIdx-1):
                thirdIdx = secondIdx + c + 1
                if (nums[firstIdx] + nums[secondIdx] + nums[thirdIdx]) in comArr:
                    answerArr.append(nums[firstIdx] + nums[secondIdx] + nums[thirdIdx])
                    answer+=1
    
    return answer
