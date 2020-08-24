import java.util.*;
class Solution {
    public int[] solution(String[] genres, int[] plays) {        
        Map<String, Integer> map = new HashMap<>();
        
        for (int i = 0; i < genres.length; i++) {
            if (map.containsKey(genres[i])) {
                final int play = plays[i];
                map.computeIfPresent(genres[i], (g,p)-> p+play);
            } else {
                map.put(genres[i], plays[i]);
            }
        }
        

	    List<String> mapList = new ArrayList<>(map.keySet());
        
        Collections.sort(mapList, (o1, o2) -> (map.get(o2).compareTo(map.get(o1))));
        
        List<Integer> list = new ArrayList<>();
        for (String genre : mapList) {
            int fi = -1;
            int si = -1;
            int fv = 0;
            int sv = 0;
            for (int i = 0; i < genres.length; i++) {
                if (genres[i].equals(genre)) {
                    if (fv < plays[i]) {
                        si = fi;
                        sv = fv;
                        fi = i;
                        fv = plays[i];
                    } else if (sv < plays[i]) {
                        si = i;
                        sv = plays[i];
                    }   
                }
            }
            list.add(fi);
            if (si != -1) list.add(si);
        }

	    int[] answer = new int[list.size()];
        
        for (int i = 0; i < list.size(); i++){
            answer[i] = list.get(i); 
        }
        return answer;
    }
    
}