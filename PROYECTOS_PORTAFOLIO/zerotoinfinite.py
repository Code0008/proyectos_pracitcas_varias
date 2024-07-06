def going(n):  
    s = 20000.0
    for i in range(2, n + 1):
        s = s/i + 1
    return int(s * 1e6) / 1e6

print(going(5))