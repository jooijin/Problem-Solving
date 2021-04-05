#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt = 0;
bool visit[10000000];

int makeNum(vector<int> used, string numbers, string n) {
    int num = stoi(n);
    bool flag = true;
    
    if(visit[num])
        return 0;
    
    for(int i=2; i<=sqrt(num); i++) {
        if(num%i == 0)
            flag = false;
    }
    if(flag == true && !visit[num] && num != 1) {
        cnt++;
        visit[num] = true;
    }
    
    if(n.size() == numbers.size())
        return 0;
    
    for(int i=0; i<numbers.size(); i++) {
        if(find(used.begin(), used.end(), i) == used.end()) {
            vector<int> nowUsed = used;
            nowUsed.push_back(i);
            string nowN = n;
            nowN += numbers[i];
            makeNum(nowUsed, numbers, nowN);
        }
    }
    
    return 0;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end(), greater<>());
    
    for(int i=0; i<numbers.size(); i++) {
        vector<int> used;
        string temp = "";
        used.push_back(i);
        temp += numbers[i];
        if(numbers[i] != '0')
            makeNum(used, numbers, temp);
    }
    
    answer = cnt;
    
    return answer;
}
