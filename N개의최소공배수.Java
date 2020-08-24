import java.util.*;

class Solution {
    public int solution(int[] arr) {
        Arrays.sort(arr);
        
        int mul = 2;
        int answer = 1;
        while (mul <= arr[arr.length-1]) {
            boolean flag = false;          
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] % mul == 0) {
                    flag = true;
                    arr[i] /= mul;
                }
            }
            
            if (flag) {
                answer *= mul;
                mul = 2;
                Arrays.sort(arr);
            } else {
                mul++;
            }
        }
        
        for (int i = 0; i < arr.length; i++) {
            answer *= arr[i];
        }
        
        return answer;
    }
}