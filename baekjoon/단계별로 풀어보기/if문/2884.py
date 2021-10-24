h, m = map(int, input().split(' '))

if m - 45 < 0:
    if h - 1 < 0:
        print("23", end=' ')
        print(60 + (m - 45), end=' ')
    else:
        print(h - 1, end=' ')
        print(60 + (m - 45), end=' ')
else:
    print(h, end=' ')
    print(m - 45, end=' ')