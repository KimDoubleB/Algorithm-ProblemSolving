num = int(input())
cnt, cnt_three = -1, 0

while num >= 0:
    if num % 5 == 0:
        cnt = int(num/5) + cnt_three
        break
    else:
        num -= 3
        cnt_three += 1
print(cnt)