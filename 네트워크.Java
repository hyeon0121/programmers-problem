import java.util.*;

class Solution {
    public int solution(int n, int[][] computers) {     
        int answer = 0;
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                answer++;
                visited[i] = true;
                q.add(i);
                
                while (!q.isEmpty()) {
                    int idx = q.poll();
                    for (int j = 0; j < n; j++) {
                        if (idx == j) continue;
                        if (computers[idx][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            q.add(j);
                        }
                        
                    }
                }
            }
        }
        return answer;
    }
}