// 내 힘으로 풀지 못해서 프로그래머스의 가장 추천수가 높은 답안을 참고하였다.

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

// 재생수 순으로 내림차순 정렬
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first) {
        return true;
    }
    // 재생수가 같을 시 고유번호가 작은 것을 우선으로 하도록
    else if(a.first == b.first) {
        if(a.second < b.second) {
            return true;
        }
    }
    return false; // 처음에 이 부분에서 오류를 냈다.. 이 부분을 else절로 만드는 바보같은 실수를 해서.. 그러지 말자.. 리턴값 전부 조건문으로 하는거 ㄴㄴ
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 장르별 총 재생 횟수
    unordered_map<string, int> sumPlays; 
    // 장르별 <재생 횟수, 고유번호> 페어로 쭉 저장
    unordered_map<string, vector<pair<int, int>>> genMap; 
    
    for(int i=0; i<genres.size(); i++) {
        sumPlays[genres[i]] += plays[i];
        genMap[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    // 장르별 총 재생횟수를 정렬하기 위해 사용하는 벡터
    vector<pair<int, string>> forOrder;
    // 장르별 총 재생횟수가 오름차순으로 정렬됨
    for(auto a: sumPlays) {
        forOrder.push_back(make_pair(a.second, a.first));
    }
    
    sort(forOrder.begin(), forOrder.end());

    while(forOrder.size() > 0) {
        // 장르별로 담긴 노래들을 뽑아내기 위해 사용할 임시 pair
        // 장르별 총 재생 횟수가 오름차순을 정렬되어 있으니
        // 총 재생수가 높은 순으로 장르를 가져오려면 뒤에서부터 조회해야됨 (.back()) 
        pair<int, string> temp = forOrder.back();
        forOrder.pop_back();
        // 장르별 <재생수, 고유번호> 들어있는 벡터 가져옴
        // genMap <string, vector<pair<int, int>>>
        vector<pair<int, int>> a = genMap[temp.second];
        sort(a.begin(), a.end(), compare);
        // 장르별로 2곡씩 수록하도록
        int index = 2;
        // 해당 장르의 곡이 2곡이 안될경우
        if(a.size() < 2)
            index = a.size();
        for(int i=0; i<index; i++)
            answer.push_back(a[i].second);
    }
    
    return answer;
}
