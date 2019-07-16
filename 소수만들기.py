def findPrime(s):
    for i in range(2, s) :
        if s % i == 0:
            return False
    return True

def solution(nums):
    answer = -1
    
    sum = 0;
    check = False;
    cnt = 0;
    for i in range(0, len(nums)):
        for j in range(i+1, len(nums)):
            for k in range(j+1, len(nums)):
                sum = nums[i] + nums[j] + nums[k]
               
                if findPrime(sum) == True :
                    cnt = cnt + 1
                    
                sum = 0
                
    return cnt