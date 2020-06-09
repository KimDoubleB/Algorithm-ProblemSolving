def solution(tri):
    for i in range(1, len(tri)):
        for j in range(len(tri[i])):
            if j == 0:
                tri[i][j] += tri[i-1][0]
            elif j == i:
                tri[i][j] += tri[i-1][i-1]
            else:
                tri[i][j] += max(tri[i-1][j-1], tri[i-1][j])
    return max(tri[-1])