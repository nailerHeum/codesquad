starStack = int(input())
a = ''
for i in range(starStack):
    a += ' '*(starStack-i-1) + '*'*(i+1)
    a += '\n'
print(a)
