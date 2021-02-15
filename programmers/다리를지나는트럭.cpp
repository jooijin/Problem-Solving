#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    int size = truck_weights.size();
    int tot=truck_weights[0];
    queue<int> q;
    q.push(truck_weights[0]);
    int temp;
     
    for (int i=1; i<size; i++)
    {
        if(q.size()<bridge_length)
        {
            if(tot+truck_weights[i]<=weight)
            {
                tot += truck_weights[i];
                q.push(truck_weights[i]);
                answer++;
            }
            else
            {
                q.push(0);
                i--;
                answer++;
            }
        }
        
        else
        {
            tot -= q.front();
            q.pop();
            if (tot+truck_weights[i]<=weight)
            {
                tot += truck_weights[i];
                q.push(truck_weights[i]);
                answer++;
            }
            else
            {
                q.push(0);
                i--;
                answer++;
            }
        }
    }
    
    answer += bridge_length;
    
    return answer;
}