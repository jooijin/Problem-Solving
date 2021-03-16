// 설탕배달

#include <iostream>

using namespace std;

int main() {
    int N;
    int ans;
    
    cin>>N;
    
    ans = N/5;
    int rem = N%5;
    
    while(ans>=0) {
        if(rem%3 == 0) {
            cout<<ans+rem/3;
            return 0;
        }
        else {
            rem+=5;
            ans--;
        }
    }
    
    cout<<-1;
    
    return 0;
}
