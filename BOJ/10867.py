import sys
input = sys.stdin.readline

input()
vals = list(set(map(int, input().split())))
vals.sort()
for val in vals:
  print(val, end=" ")