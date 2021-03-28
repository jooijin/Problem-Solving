#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 전화번호가 int가 아닌 string이기 때문에 정렬로 풀 수 있다
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1;i++) {
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))
            return false;
    }
    
    return answer;
}
