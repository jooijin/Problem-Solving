#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;
    
    int sum = (brown-4)/2;
    
    for(int i=1; i<sum; i++) {
        if(i*(sum-i) == yellow) {
            y = i;
            break;
        }
    }
    
    x = sum-y;
    
    answer.assign({x+2, y+2});
    
    return answer;
}
