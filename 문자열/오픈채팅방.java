//런타임 에러..이유를 모르겠다

import java.util.HashMap;

class Solution {
    public String[] solution(String[] record) {
        String[] answer;
        HashMap<String, String> map = new HashMap<String, String>();
        int cnt = 0;
        
        for(int i=0; i<record.length; i++) {
            String[] arr = record[i].split(" ");
            if(arr[0].equals("Enter")) { 
                map.put(arr[1], arr[2]);
                cnt++;
            }
            else if(arr[0].equals("Change"))
                map.put(arr[1], arr[2]);
            else
                cnt++;
        }
        
        answer = new String[cnt];
        
        for(int i=0; i<record.length; i++) {
            String[] arr = record[i].split(" ");
            if(arr[0].equals("Enter"))
                answer[i] = map.get(arr[1]) + "님이 들어왔습니다.";
            else if(arr[0].equals("Leave"))
                answer[i] = map.get(arr[1]) + "님이 나갔습니다.";
        }
        
        return answer;
    }
}
