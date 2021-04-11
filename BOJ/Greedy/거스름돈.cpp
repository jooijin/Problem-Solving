// 5585

#include <stdio.h>

using namespace std;

int main() {
    int M;
    int ans = 0;
    int chan[6] = {500, 100, 50, 10, 5, 1};
    
    scanf("%d", &M);
    
    M = 1000-M;
    
    for(auto a: chan) {
        ans += M/a;
        M %= a;
    }
    
    printf("%d", ans);
    
    return 0;
}
