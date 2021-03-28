// 금방 풀긴 했는데 그닥 힙 자료구조의 특징을 활용하지는 못했다..
// 나중에 multiSet으로 다시 풀어볼 계획!

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> q;
        
    for(int i=0; i<operations.size(); i++) {
        if(operations[i].substr(0,1) == "I") {
            q.push_back(stoi(operations[i].substr(2)));
            sort(q.begin(), q.end());
        }
        else if(operations[i].substr(2) == "1") {
            if(!q.empty()) {
                q.pop_back();
            }
        }
        else {
            if(!q.empty()) {
                q.erase(q.begin());
            }
        }
    }
    
    if(q.empty()) {
        answer.assign(2, 0);
        return answer;
    }
    
    answer.assign({q.back(), q.front()});
    
    return answer;
}
