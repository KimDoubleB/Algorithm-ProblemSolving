tc = int(input())
for _ in range(tc):
    num = int(input())
    grade = []
    for n in range(num):
        grade.append(list(map(int, input().split(' '))))
    grade.sort(key=lambda x: x[0])
    
    meet, cnt = grade[0][1] + 1, 0
    for g in grade:
        if g[1] < meet:
            meet = g[1]
            cnt += 1
    print(cnt)