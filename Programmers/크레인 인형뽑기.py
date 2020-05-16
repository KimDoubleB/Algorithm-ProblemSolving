def solution(board, moves):
    answer = []
    count = 0
    for move in moves:
        move -= 1
        for eb in board:    # each board
            if eb[move] < 1: continue
            if len(answer) > 0 and eb[move] == answer[-1]: 
                answer.pop()
                count += 2
            else: 
                answer.append(eb[move])
            eb[move] = 0
            break
    return count