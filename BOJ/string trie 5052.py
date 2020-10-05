import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, deny = int(input()), False
    phone = [input().strip() for _ in range(n)]
    phone.sort()
    for i in range(0, len(phone)-1):
        cur, nxt = phone[i], phone[i+1]
        if len(cur) >= len(nxt):
            continue
        if nxt.startswith(cur):
            deny = True
            break
    print("NO" if deny else "YES")