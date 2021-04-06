// 꽤나 잘 푼거같아서 뿌듯하다
// 인덱스를 잘 설정하는것이 항상 참 중요한거같다..

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h = citations.size();
    sort(citations.begin(), citations.end(), greater<>());
    
    for(int i=0; i<citations.size(); i++) {
        if(citations[h-1] >= h){
            answer = h;
            break;
        }
        h--;
    }
    
    return answer;
}
