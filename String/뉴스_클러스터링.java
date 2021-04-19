// 자바의 자료 구조들을 잘 활용해야겠다
// 스트링 관련 함수들을 좀 더 공부해놔야 시간 안에 풀 수 있을 것 같다.

import java.util.ArrayList;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        double inter = 0;
        double sum;
        
        String match = "[^a-zA-Z]";
        
        ArrayList s1 = new ArrayList();
        ArrayList s2 = new ArrayList();

        for(int i=0; i<str1.length()-1; i++) {
            String temp = str1.substring(i, i+2);
            temp = temp.replaceAll(match, "");
            if(temp.length() != 2)
                continue;
            else {
                s1.add(temp.toUpperCase());
            }
        }
        for(int i=0; i<str2.length()-1; i++) {
            String temp = str2.substring(i, i+2);
            temp = temp.replaceAll(match, "");
            if(temp.length() != 2)
                continue;
            else{
                s2.add(temp.toUpperCase());
            }
        }
        
        sum = s1.size()+s2.size();
        
        for(int i=0; i<s1.size();) {
            if(s2.contains(s1.get(i))) {
                inter++;
                s2.remove(s1.get(i));
                s1.remove(i);
            }
            else
                i++;
        }
        
        if(sum == 0)
            return 65536;
        
        answer = (int)Math.floor((inter/(sum-inter))*65536);
        
        return answer;
    }
}
