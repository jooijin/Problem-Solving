// Look up table 만드는방식..

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int LUT[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};

int solution(string name) {
    int answer = 0;
    int toggle = name.size()-1;
    int size = name.size();
    
    for(int i=0; i<name.size(); i++) {
        answer += LUT[name[i]-'A'];
    }
    
    for(int i=0; i<name.size()-1; i++) {
        if(name[i] == 'A'){ 
            int next_i = i+1; 
            while(name[next_i] == 'A') {
                next_i++;
            }
            toggle = min(toggle, (i-1)*2+size-next_i);
        }
    }
    
    answer += toggle;
    
    return answer;
}
