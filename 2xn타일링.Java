class Solution {
    public int solution(int n) {
        
        int[] fibo = new int[60001];
        fibo[0] = 1;
        fibo[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            fibo[i] = (fibo[i-1] + fibo[i-2]) % 1000000007;
        }
        
        return fibo[n];
    }
}