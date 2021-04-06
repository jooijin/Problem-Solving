#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // 경우의 수 문제 => (종류별 개수+1)을 쭉 곱한 후 -1(아무것도 안 입은 경우)을 하면 된다
    
    unordered_map<string, int> myMap;
    
    for(int i=0; i<clothes.size(); i++) {
        myMap[clothes[i][1]]++;
    }
    
    for(auto a : myMap) {
        answer *= (a.second+1);
    }
    answer--;
    
    return answer;
}
