#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[1] < b[1])
        return true;
    else if(a[1] == b[1])
        if(a[0] < b[0])
            return true;
    
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int now;
    
    sort(routes.begin(), routes.end(), compare);
    
    now = routes[0][1];
    
    for(int i=1; i<routes.size(); i++) {
        if(routes[i][0] > now) {
            now = routes[i][1];
            answer++;
        }
    }
    
    return answer;
}
