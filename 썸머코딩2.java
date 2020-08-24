import java.util.*;
import java.lang.*;
class Solution {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] arr = new int[n+1];
        arr[1] = 1;

        int num = 3;
        int b = 1;
        int cur = 2;
        int idx = 1;
        int limit = 1;

        while(cur <= n) {
            if (idx == limit) {
                num = (int) Math.pow(3,b);
                arr[cur] = num;
                limit = cur;
                idx = 1;
                b++;

            } else {
                arr[cur] = arr[idx] + num;
                idx++;
            }

            cur++;
        }

        System.out.println(arr[n]);
    }
}