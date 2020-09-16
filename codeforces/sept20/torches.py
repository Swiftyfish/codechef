import math
def min_trades(x,y,k):
    stick_req = k + y*k - 1
    return -(-stick_req//(x - 1)) + k

t = int(input())
for i in range(t):
    x, y, k = list(map(int, input().split()))
    print(min_trades(x,y,k))