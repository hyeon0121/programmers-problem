def solution(n, words):
    past = []
    ans = [0,0]
    past.append(words[0])
    
    for i in range(1, len(words)) :
        ans1 = i // n + 1
        ans2 = i % n + 1
        if words[i-1][-1] != words[i][0] :
            return [ans2,ans1]
        elif words[i] in past:
            return [ans2,ans1]
        
        past.append(words[i])
        
    return ans