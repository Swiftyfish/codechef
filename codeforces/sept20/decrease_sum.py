def get_min(n, s):
    str_n = str(n)
    d = len(str_n)
    count = 0
    sum_digits = sum([int(i) for i in str_n])
    if sum_digits <= s:
        return 0

    for i in range(d):
        count += int(str_n[i])
        if count > s or (count == s and sum_digits > s):
            return 10**(d-i) - int(str_n[i:])

t = int(input())
for i in range(t):
    n, s = list(map(int, input().split()))
    print(get_min(n, s))