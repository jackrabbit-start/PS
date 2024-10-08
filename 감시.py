import copy

n, m = map(int, input().split())
arr = []

cctv = 0
for _ in range(n):
    tmp = list(map(int, input().split()))
    arr.append(tmp)
    for a in tmp:
        if 1 <= a <= 5:
            cctv += 1


# 상하좌우
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

cctv_arr = []
for i in range(n):
    for j in range(m):
        if 1 <= arr[i][j] <= 5:
            cctv_arr.append((i, j, arr[i][j]))


answer = n * m

d = [
    [],
    [[0], [1], [2], [3]],
    [[0, 1], [2, 3]],
    [[0, 3], [1, 3], [2, 0], [2, 1]],
    [[0, 1, 2], [0, 1, 3], [1, 2, 3], [0, 2, 3]],
    [[0, 1, 2, 3]],
]


def is_range(x, y):
    if x < 0 or y < 0 or x >= n or y >= m:
        return False
    return True


def check(x, y, dir, cnt_arr):
    for cd in dir:
        nx = x
        ny = y
        while True:
            nx += dx[cd]
            ny += dy[cd]

            if not is_range(nx, ny):
                break
            if cnt_arr[nx][ny] == 6:
                break
            if cnt_arr[nx][ny] == 0:
                cnt_arr[nx][ny] = "#"


def count_result(arr):
    global answer
    ans = 0
    for a in arr:
        ans += a.count(0)
    answer = min(answer, ans)


checked = []


def dfs(cnt, arr):
    ori_arr = copy.deepcopy(arr)

    if cnt == cctv:
        count_result(arr)
        return

    x, y, kind = cctv_arr[cnt]

    for dir in d[kind]:
        check(x, y, dir, ori_arr)
        dfs(cnt + 1, ori_arr)
        ori_arr = copy.deepcopy(arr)


dfs(0, arr)
print(answer)
