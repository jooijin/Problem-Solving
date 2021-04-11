// 별로 효율적이지 못한 것 같다..

#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> q;
    int days = 0;
        
    for(int i=0; i<progresses.size(); i++) {
        q.push(make_pair(progresses[i], speeds[i]));
    }
    
    while(!q.empty()) {
        int days = 0;
        days += (100-q.front().first) / q.front().second;
        if((100-q.front().first) % q.front().second != 0)
            days++;
        int temp = 0;
        while(q.front().first + q.front().second*days >= 100) {
            temp++;
            q.pop();
        }
        answer.push_back(temp);
    }
    
    return answer;
}
