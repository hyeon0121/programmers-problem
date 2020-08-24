import java.util.*;
class Solution {
    public int solution(int[][] jobs) {
        int[] res = new int[jobs.length];
        
        Arrays.sort(jobs, new Comparator<int[]> () {
            public int compare(int[] o1, int[] o2) {
                if (o1[0] > o2[0]) return 1;
                else return -1;
            }
        });
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>(){
            public int compare(int[] o1, int[] o2) {
                if (o1[1] > o2[1]) return 1;
                else return -1;
            }
        }); 
        
        int time = 0;
        int idx = 0;
        int total = 0;
        
        while(true) {
            while (idx < jobs.length) {
                if (time >= jobs[idx][0]) {
                    pq.add(jobs[idx]);
                    idx++;
                } else break;
            }
            
            if (!pq.isEmpty()) {
                int[] disk = pq.poll();
                time += disk[1];
                total += time - disk[0];
            } else {
                time = jobs[idx][0];
            }
            
            if (idx == jobs.length && pq.isEmpty()) break;
        }
        
        return total / jobs.length;
    
    }
}