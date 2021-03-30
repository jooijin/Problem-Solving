// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> bin;
    int answer = 0;

    while(N != 0) {
        bin.push_back(N%2);
        N /= 2;
    }

    for(int i=0; i<bin.size(); i++) {
        int cnt = 0;
        if(bin[i] == 1){
            for(int j = i+1; j<bin.size() && bin[j] == 0; j++) {
                cnt++;
                if(j == bin.size()-1 && bin[j] == 0)
                    cnt = 0;
            }
            if(answer<cnt)
                answer = cnt;
        }
    }

    return answer;
}
