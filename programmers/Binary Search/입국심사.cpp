// 이분탐색으로 문제를 풀어본적이 없어서 바로 풀지 못했다ㅠㅠ
// 프로그래머스에서 가장 추천수가 높은 답안을 참고하였다

#include <algorithm>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    // answer 값은 무조건 times[0]과 times[0]*n 사이에 있을것이다
    long long start = times[0];
    // 타입 변환 잊지말자!!
    long long end = (long long)times[0]*n;
    long long mid;
    
    // 이분탐색 적용
    while(start<=end) {
        mid = (start + end) / 2;
        long long cnt = 0;
        for(int i=0; i<times.size(); i++) {
            cnt += mid/times[i];
        }
        
        if(cnt < n) {
            start = mid+1;
        }
        else {
            answer = mid;
            end = mid-1;
        }
    }
    
    return answer;
}
