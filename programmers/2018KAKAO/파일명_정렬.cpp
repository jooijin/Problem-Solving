// TC 6,7,8,9 
// 공백, -문자 처리가 잘못된거같다
// head로 먼저 정렬해놓고 그 다음에 number로 정렬하는 방식을 사용해야겠다

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(string a, string b) {
    string ahead, bhead;
    int atail, btail;
    int i=0, j=0;
    int cnt = 0;
    
    for(i=0; i<a.size(); i++) {
        if('0' <= a[i] && a[i] <= '9') {
            ahead = a.substr(0, i);
            transform(ahead.begin(), ahead.end(), ahead.begin(), ::toupper);
            break;
        }
    }
    
    for(j=0; j<b.size(); j++) {
        if('0' <= b[j] && b[j] <= '9') {
            bhead = b.substr(0, j);
            transform(bhead.begin(), bhead.end(), bhead.begin(), ::toupper);
            break;
        }
    }
    
    for(int n=0 ; n<min(ahead.size(), bhead.size()); n++) {
        if(ahead[n] > bhead[n])
            return false;
        else if(ahead[n] < bhead[n])
            return true;
        else
            continue;
    } 
    
    for(;i<a.size(); i++) {
        if(a[i] < '0' || a[i] > '9' || cnt == 5 || (i == a.size()-1 && '0' <= a[i] && a[i] <= '9')) {
            if(i == a.size()-1)
                atail = stoi(a.substr(i-cnt, cnt+1));
            else
                atail = stoi(a.substr(i-cnt, cnt));
            break;
        }
        cnt++;
    }
    
    cnt = 0;
    
    for(;j<b.size(); j++) {
        if(b[j] < '0' || b[j] > '9' || cnt == 5 || (j == b.size()-1 && '0' <= b[j] && b[j] <= '9')) {
            if(j == b.size()-1)
                btail = stoi(b.substr(j-cnt, cnt+1));
            else
                btail = stoi(b.substr(j-cnt, cnt));
            break;
        }
        cnt++;
    }
    
    if(atail < btail)
        return true;
    
    return false;
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), cmp);
    
    return files;
}
