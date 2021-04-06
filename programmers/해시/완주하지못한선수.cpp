// 정렬을 사용하면 아주 간단한게 풀리는 문제인데.. 처음에는 싹다 비교해서 아닌 것을 찾으려 했었다.
// 어쨌든 해쉬 문제이니 추후 해쉬로 푸는 방법을 찾으면 업데이트해야겠다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    answer = participant.back();
    
    for(int i=0; i<completion.size(); i++) {
        if (participant[i]!=completion[i])
            return participant[i];
    }
    
    return answer;
}
