class Solution {
    public String solution(int a, int b) {
        String[] week = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
     
        int day = b-1;   
        int month = 1;

        while(month != a) {
            if (month == 2) day += 29;
            else if (month == 4 || month == 6 || month == 9 || month == 11) day += 30;
            else day += 31;
                
            month++;
        }
        
        int res = day % 7;
        return week[res];
    }
}