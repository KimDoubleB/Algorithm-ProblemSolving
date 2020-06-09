def solution(numbers):
    answer =""
    numbers = [[str(num), str(num) * 4] for num in numbers]
    numbers.sort(key=lambda x: x[1], reverse=True)
    for num in numbers:
        answer += num[0]
    return answer if answer[0] != '0' else '0'