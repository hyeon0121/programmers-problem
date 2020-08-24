import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        int sum = 0;
        for (int work : works) {
            sum += work;
            pq.add(work);
        }
        
        if (sum <= n) return 0;
                
        while(n > 0) {
            int top = pq.poll();
            
            if (top - n >= pq.peek()) {
                pq.add(top-n);
                break;
            } 
            
            n--;
            pq.add(top-1);
        }
        
        while(!pq.isEmpty()) {
            int top = pq.poll();
            answer += top * top;
        }
        
        return answer;
    }
}