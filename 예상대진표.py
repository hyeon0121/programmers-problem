def solution(n,a,b):
    cnt = 0
        
    while True : 
        cnt += 1
        if a % 2 == 0 :
            if a-1 == b : 
                break
            a //= 2
        else :
            if a+1 == b : 
                break
                 
            a //= 2
            a += 1

        if b % 2 == 0 :
            b //= 2
        else :
            b //= 2
            print(b)
            b += 1
            print(b)
            
    return cnt;