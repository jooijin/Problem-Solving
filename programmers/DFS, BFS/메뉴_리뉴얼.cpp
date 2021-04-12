// 2021 카카오 기출문제
// 혼자 풀지 못해서 다른 사람의 풀이를 참고하였다.

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;

void combination(string crs, string cur, int depth) {
    if(depth == cur.size())
        map[cur]++;
    
    else {
        for(int i=0; i<crs.size(); i++)
        combination(crs.substr(i+1), cur+crs[i], depth);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(string &str : orders)
        sort(str.begin(), str.end());
    
    for(int depth : course) {
        for(string str : orders) {
            combination(str, "", depth);
        }
        
        int sup = 0;
        for (auto it : map)
            sup = max(sup, it.second);
        for (auto it : map)
            if (sup >= 2 && it.second == sup)
                answer.push_back(it.first);
        map.clear();
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
