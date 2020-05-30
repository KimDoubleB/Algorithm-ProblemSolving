def solution(p, location):
    ind = 0
    while True:
        present = p.pop(0)
        # print(ind, location)
        if len(p) == 0 or present >= max(p):
            ind += 1
            if location == 0:
                break
        else:
            p.append(present)

        location = len(p)-1 if location <= 0 else location-1

    return ind