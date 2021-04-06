// heap 문제는 자주 헷갈린다.. 개념을 확실히 잡아놔야겠다

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int answer = 0;
    
    for(int i=0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    
    while(pq.top() < K && pq.size() > 1) {
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        pq.push(temp1+temp2*2);
        answer++;
    }
    
    if(pq.size() ==1  && pq.top() < K)
        return -1;
    
    return answer;
}
