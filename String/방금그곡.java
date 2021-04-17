// 조금 비효율적인것 같다..

class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        int playtime = 0;
        
        for(int j=0; j<m.length(); j++) {
                if(m.charAt(j) == '#') {
                    String sh = m.substring(j-1, j+1);
                    String ch = m.substring(j-1, j).toLowerCase();
                    m = m.replace(sh, ch);
            }
        }
            
        m = m.replaceAll("#", "");
        
        for(int i=0; i<musicinfos.length; i++) {
            String[] temp = musicinfos[i].split(",");
            
            for(int j=0; j<temp[3].length(); j++) {
                if(temp[3].charAt(j) == '#') {
                    String sh = temp[3].substring(j-1, j+1);
                    String ch = temp[3].substring(j-1, j).toLowerCase();
                    temp[3] = temp[3].replace(sh, ch);
                }
            }
            
            temp[3] = temp[3].replaceAll("#", "");
            
            String[] h1 = temp[0].split(":");
            String[] h2 = temp[1].split(":");
            
            int len = (Integer.parseInt(h2[0])-Integer.parseInt(h1[0]))*60 + Integer.parseInt(h2[1])-Integer.parseInt(h1[1]);
            
            if(len <= temp[3].length()) {
                temp[3] = temp[3].substring(0, len);
            }
            else {
                while(len > temp[3].length()) {
                    temp[3] += temp[3];
                }
                temp[3] = temp[3].substring(0, len);
            }
    
            if(temp[3].contains(m) && len > playtime) {
                answer = temp[2];
                playtime = len;
            }
        }
        
        if(answer == "")
            return "(None)";
        
        return answer;
    }
}
