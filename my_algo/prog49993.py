def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        comparing = []
        checker = True
        for s in skill:
            if skill_tree.find(s) != -1:
                comparing.append(skill_tree.find(s))
            else:
                comparing.append(27)
        tmp = -1
        for c in comparing:
            if c < tmp:
                checker = False
            tmp = c
        if checker == True:
            answer += 1
    return answer
