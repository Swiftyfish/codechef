def min_product(a, b, x, y, n):        
    pair = [a, b]
    pair_lims = [x, y]
    pair_check = [pair[i] > pair_lims[i] for i in range(2)]

    if n > (a - x) + (b - y):
        return x*y

    while n > 0 and any(pair_check):
        #want to decrease the smaller of a and b at each step
        #need to deal with cases where a and b are same
        
        res = [max(pair_lims[i], pair[i] - min(pair[i], n)) for i in range(2)]
        which = res[1] == min(res)

        index = 1* (not (which ^ pair_check[1*which]))

        max_change = min(pair[index] - pair_lims[index], n)
        pair[index] -= max_change
        n -= max_change
        pair_check = [pair[i] > pair_lims[i] for i in range(2)]

    return pair[0]*pair[1]
            
t = int(input())
for i in range(t):
    a, b, x, y, n = list(map(int, input().split()))
    print(min_product(a, b, x, y, n))