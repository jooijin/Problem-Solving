// 다른 사람의 풀이를 참고하였다..
// 규칙/ 최적구조 찾기를 잘 하자

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 예를 들어 N=5라면 5, 55, 555, 5555.. 는 무조건 1, 2, 3, 4개의 N을 사용한 것이 최소가 됨

unordered_set<int> dp[9];

int N;

unordered_set<int> DP(int used_N) {
    if(!dp[used_N].empty()) return dp[used_N];
    unordered_set<int> res;
    int num = 0;
    for(int i=0; i<used_N; i++) num = num*10 + N;
    res.insert(num);
    for(int i=1; i<used_N; i++) {
        auto s1 = DP(i);
        auto s2 = DP(used_N-i);
        for(auto n1 : s1) {
            for(auto n2 : s2) {
                res.insert(n1+n2);
                res.insert(n1*n2);
                res.insert(n1-n2);
                if(n2 != 0)
                    res.insert(n1/n2);
            }
        }
    }
    return dp[used_N] = res;
}

int solution(int _N, int number) {
    N = _N;
    
    for(int i=1; i<=8; i++) {
        DP(i);
        if(dp[i].find(number) != dp[i].end()) {
            return i;
        }
    }
    
    return -1;
}
