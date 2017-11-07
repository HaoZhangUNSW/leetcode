while True:
    try:
        a, res = input(), []
        for i in range(len(a)):res.append(a[i:])
        for i in sorted(res):
            print(i)
    except:
        break
