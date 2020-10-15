T = 10

for test_case in range(1, T + 1):
    building_length = int(input())
    buildings = list(map(int, input().split()))
    count_good_view = 0
    for i in range(2, building_length-2):
        cur_height = buildings[i]
        max_around_height = max(buildings[i-2], buildings[i-1], buildings[i+1], buildings[i+2])
        diff_height = cur_height - max_around_height
        if diff_height <= 0:
            continue
        count_good_view += diff_height
    print(f'#{test_case} {count_good_view}')