#include <string>
#include <vector>

// 이중 for문은 비효율적인거같다,, 다른 방법 없을까?
// 큐/스택 문제인데 큐와 스택을 사용하지 않은 것도 문제이다.
// 나중에 좀 더 개선해야겠다.
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0; i<prices.size(); i++) {
        int temp = prices[i];
        for(int j=i; j<prices.size(); j++) {
            if(prices[j]<temp) {
                answer.push_back(j-i);
                break;
            }
        }
        if(answer.size() == i) {
            answer.push_back(prices.size()-i-1);
        }
    }
    
    return answer;
}
