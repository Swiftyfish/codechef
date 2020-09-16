def get_cuts(stick_heights):
    count = 0
    heights = {0}
    for stick in stick_heights:
        heights.add(stick)
    heights = list(heights)
    heights.sort()
    
    count = len(heights) - 1
    return count

t = int(input())
for i in range(t): #for each test case
    n = int(input())
    a = list(map(int, input().split()))
    z = get_cuts(a)
    print(z)