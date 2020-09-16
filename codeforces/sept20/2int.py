def get_min_moves(a, b):
    diff = abs(b - a)
    if diff == 0:
        return 0
    return -(-diff//10)

t = int(input())
for i in range(t):
    a, b = list(map(int, input().split()))
    print(get_min_moves(a, b))