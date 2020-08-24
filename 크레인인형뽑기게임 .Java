import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        
        Stack<Integer> s = new Stack<>();
        
        for (int i = 0; i < moves.length; i++) {
            int idx = moves[i]-1;
            
            int toy = -1;
            for (int j = 0; j < board.length; j++) {
                if (board[j][idx] != 0) {
                    toy = board[j][idx];
                    board[j][idx] = 0;
                    break;
                }
            }
            
            if (toy == -1) continue;
            
            if (!s.isEmpty()) {
                if (s.peek() == toy) {
                    answer += 2;
                    s.pop();
                    continue;
                } 
            }
                
            s.push(toy);

        }
        return answer;
    }
}