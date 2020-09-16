def get_max(n, k, x, y):
    x.sort()
    j = n - 1
    r = [0 for i in range(n)]
    l = r.copy()
    for i in range(n-1, -1, -1):
        while (x[j] - x[i]) > k:
            j -= 1
        r[i] = j - i + 1
        if i + 1 < n:
            r[i] = max(r[i], r[i + 1])

    j = 0
    for i in range(n):
        while (x[i] - x[j]) > k:
            j += 1
        l[i] = i - j + 1
        if i > 0:
            l[i] = max(l[i], l[i - 1])

    ans = 1
    for i in range(n-1):
        ans = max(ans, r[i+1] + l[i])
    return ans
        

    
        

t = int(input())
for i in range(t):
    n, k = list(map(int, input().split()))
    x = list(map(int, input().split()))
    #y = list(map(int, input().split()))
    print(get_max(n, k, x, 0))