#include <string>
#include <vector>

using namespace std;

int cnt = 0;

int dfs(vector<int> numbers, int target, int curr, int sum) {
    
    if(curr == numbers.size()-1) {
        if(sum == target)
            cnt++;
        
        return 0;
    }
    
    curr++;
    
    dfs(numbers, target, curr, sum+numbers[curr]);
    dfs(numbers, target, curr, sum-numbers[curr]);
    
    return 0;
}

int solution(vector<int> numbers, int target) {
    int curr = 0;
    
    dfs(numbers, target, 0, numbers[0]);
    dfs(numbers, target, 0, -numbers[0]);
    
    return cnt;
}
