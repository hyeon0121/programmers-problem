def solution(d, budget):
    ans = 0
    d.sort()
    for i in range(0, len(d)) :
        budget -= d[i]
        if budget < 0:
            break
            
        ans += 1

    return ans