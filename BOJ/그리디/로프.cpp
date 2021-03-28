// 2217

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, ans = 0;
    scanf("%d", &N);
    vector<int> rope;
    
    for(int i=0; i<N; i++) {
        int tmp;
        scanf("%d", &tmp);
        rope.push_back(tmp);
    }
    
    sort(rope.begin(), rope.end());
    
    for(int i=0; i<N; i++) {
        ans = max(ans, rope[i]*(N-i));
    }
    
    printf("%d", ans);
    
    return 0;
}
