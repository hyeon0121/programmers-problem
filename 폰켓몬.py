class Solution {
    public int solution(int[] nums) {        
        int[] checks = new int[200000];
        int n = nums.length / 2;
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            checks[nums[i]-1] = 1; 
        }
        
        for (int j = 0; j < checks.length; j++) {
                if (checks[j] == 1) 
                    sum++;
            }
        
        if (sum >= n) {
            return n;
        } else {
            return sum;
        }
    }
}