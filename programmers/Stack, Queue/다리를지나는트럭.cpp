#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    // 다리 위의 트럭들을 표현할 큐 q 선언
    queue<int> q;
    // 다리 위 트럭들의 총 무게
    int tot = 0;
    
    for(int i=0; i<truck_weights.size(); i++) {
        if(q.size() == bridge_length) {
                int temp = q.front();
                tot -= temp;
                q.pop();
            }
        if(tot+truck_weights[i] <= weight) {
            q.push(truck_weights[i]);
            tot += truck_weights[i];
        }
        else {
            q.push(0);
            i--;
        }
        answer++;
    }
    
    answer += bridge_length;
    
    return answer;
}
