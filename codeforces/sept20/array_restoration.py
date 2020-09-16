def get_array(n, x, y):
    if n > 2:
        diff = y - x
        n_spacings = n - 1
        if diff % n_spacings == 0:
            diff_elems = diff//n_spacings
            return [x] + [x + diff_elems*(i+1) for i in range(n - 2)] + [y]
        else:
            #y is not at the end of the list
            for i in range(2, diff):
                if diff % i == 0 and diff//i < n - 1:
                    diff = i
                    break
            # now have new divisor, link x and y then decrease from x
            inner_list = [x + diff*i for i in range(n)]
            shift = min(inner_list) // diff - 1*(x % diff == 0)
            if shift:
                return [i - diff*shift for i in inner_list]

            return inner_list
    else:
        return [x, y]


t = int(input())
for i in range(t):
    n, x, y = list(map(int, input().split()))
    print(' '.join(map(str, get_array(n, x, y))))