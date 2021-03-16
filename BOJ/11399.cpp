// ATM

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, ans = 0;
    vector<int> P;
    
    cin>>N;
    
    for(int i=0; i<N; i++) {
        int temp;
        cin>>temp;
        P.push_back(temp);    
    }
    
    sort(P.begin(), P.end());
    
    for(int i=0; i<N; i++) {
        ans += P[i]*(N-i); 
    }
    
    cout<<ans;
    
    return 0;
    
}
