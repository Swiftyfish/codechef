def operation_count(matrix, n):
    checks = []
    for i in range(2, n+1):
        #Check if successive row elements are adjacent A(i, j) + 1 = A(i+1, j)
        target_row = matrix[i-1]
        checks.append(target_row[0] == target_row[1] - 1)
    count = 0
    while checks:
        test = checks.pop()
        count_bin = (count % 2) == 1
        count += not (test ^ count_bin)
    return count
        
test = int(input())
for i in range(test):
    n = int(input())
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    print(operation_count, a, n)

