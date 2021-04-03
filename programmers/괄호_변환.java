// 시간 개선 필요

class Solution {
    public String solution(String p) {
        String answer = "";
        String u = "", v = "";
        int cntL = 0, cntR = 0;
        
        if(p == "")
            return "";
        
        for(int i=0; i<p.length(); i++) {
            if(p.charAt(i) == '(') cntL++;
            else cntR++;
            
            if(cntL == cntR){
                u = p.substring(0, i+1);
                if(i+1 == p.length())
                    v = "";
                else
                    v = p.substring(i+1);
                break;
            }
        }
        
        if(u.startsWith("(") && u.endsWith(")")) {
            answer = u + solution(v);
        }
        
        else {
            String Nu = "";
            u = u.substring(1,u.length()-1);
            for(int j=0; j<u.length(); j++) {
                if(u.charAt(j) == '(')
                    Nu += ")";
                else
                    Nu += "(";
            }
            answer = "("+solution(v)+")"+Nu;
        }
        
        return answer;
    }
}
