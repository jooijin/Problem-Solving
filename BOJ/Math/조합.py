# 2407

'''
문제
nCm을 출력한다.

입력
n과 m이 주어진다. (5 ≤ n ≤ 100, 5 ≤ m ≤ 100, m ≤ n)

출력
nCm을 출력한다.
'''

tmp = input().split()
n = int(tmp[0])
m = int(tmp[1])
DP = [[0 for i in range(101)] for j in range(101)]
DP[1][0] = 1
DP[1][1] = 1
for i in range(2, n + 1):
    DP[i][0] = 1
    DP[i][i] = 1
    for j in range(1, m + 1):
        DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j]

print(DP[n][m])
