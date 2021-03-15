// 이게 맞나..? 너무 복잡하다 쉬운 문제인 것 같은데ㅜㅜ

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    
    string A, B, temp;
    vector<int> ans;
    int Atok[10001], Btok[10001];
    int sum;
    
    cin>>A>>B;
    
    if(B.size() > A.size()) {
        temp = B;
        B = A;
        A = temp;
    }
        
    for(int i=0; i<A.size(); i++) {
        Atok[i+1] = A[i]-'0';
    }
    
    for(int i=0; i<B.size(); i++) {
        Btok[i+1+(A.size()-B.size())] = B[i]-'0';
    }
    
    for(int i=A.size(); i>0; i--) {
        sum = Atok[i] + Btok[i];
        if (sum<10) {
            ans.push_back(sum);
        }
        else {
            ans.push_back(sum-10);
            Atok[i-1]++;
        }
    }
    
    if(Atok[0] == 1) {
        cout<<1;
    }
    
    for(int i=ans.size()-1; i>=0; i--) {
        cout<<ans[i];
    }
    
    return 0;
    
}
