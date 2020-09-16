def test_fun(n, a, l):
    unlocked_idx = [i for i in range(len(a)) if l[i] == 0]
    unlocked_vals = [a[i] for i in unlocked_idx]
    unlocked_vals.sort()
    unlocked_vals.reverse()
    return [a[i] if l[i] == 1 else unlocked_vals.pop(0) for i in range(len(a))]

t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    l = list(map(int, input().split()))
    print(test_fun(n, a, l))