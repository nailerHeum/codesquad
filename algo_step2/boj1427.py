a = list(map(int, list(input())))
a.sort(reverse=True)
print(''.join(str(i) for i in a))
