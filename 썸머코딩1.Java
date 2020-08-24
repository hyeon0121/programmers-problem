import java.util.*;

class Solution {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int P = sc.nextInt();
        int answer = 0;
    
        for(int i = P+1; i <= 9876; i++) {
            String s = toString(i);
            
            int flag = true;
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    if (j != k) {
                        if (s.charAt(j) == s.charAt(k)) {
                            flag = false;
                            break;
                        }
                    }
                }

                if (!flag) break;
            }

            if (flag) {
                answer = i;
                break;
            }
        }

        System.out.println(answer);
    }
}