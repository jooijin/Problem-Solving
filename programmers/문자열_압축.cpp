// 미완성..시간초과

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int len = s.size();
    int cnt = 0;
    int temp;
    
    for(int i=1; i<s.size()/2; i++){
        temp = len;
        for(int j=0; j+2*i<s.size(); j+i) {
            cnt = 1;
            if(s.substr(j,i) == s.substr(j+i,i)){
                for(int k=j+i; k+2*i<s.size() && s.substr(k,i) == s.substr(k+i,i); k+i) {
                    cnt++;
                    j+i;
                }
            }
            temp = temp-i*cnt+i+cnt/10+1; // 압축한 다음 앞에 붙는 숫자가 두자리일수도 있으니,,
        }
        answer = min(answer, temp);
    }
    
    return answer;
}
