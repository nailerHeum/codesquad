sugar = input()
sugar = int(sugar)
def sugarCalcul(sugar):
    loopNum = sugar//5
    if sugar == 5*loopNum:
        return loopNum
    for i in range(0,loopNum+1):
        if((sugar-5*(loopNum-i))%3==0):
            return loopNum-i+(sugar-5*(loopNum-i))//3
    return -1
print(sugarCalcul(sugar))
