a = list(range(0, 10000))
for i in range(10):
    try:
        a.remove(2*i)
    except:
        pass
    for j in range(10):
        try:
            a.remove(11*i + 2*j)
        except: 
            pass
        for k in range(10):
            try:
                a.remove(101*i + 11*j + 2*k)
            except:
                pass
            for l in range(10):
                try:
                    a.remove(1001*i + 101*j + 11*k + 2*l)
                except:
                    pass
for i in a:
    print(i)
