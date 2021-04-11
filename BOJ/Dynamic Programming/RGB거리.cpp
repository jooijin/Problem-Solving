// 1149
// 못풀어서 다른 사람들의 풀이를 보고 이해했다
// 아이디어는 비슷하게 떠올렸는데.. 너무 어렵게 생각하지 말자


#include <stdio.h>
#include <algorithm>

using namespace std;

int house[1001][3];

int main() {
    int N;
    int cost[3];
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;
    scanf("%d",&N);
    for(int i = 1; i <= N; ++i)
    {
        scanf("%d %d %d",&cost[0],&cost[1],&cost[2]);
        house[i][0] = min(house[i-1][1],house[i-1][2]) + cost[0];
        house[i][1] = min(house[i-1][0],house[i-1][2]) + cost[1];
        house[i][2] = min(house[i-1][1],house[i-1][0]) + cost[2];
    }
    printf("%d", min(house[N][2],min(house[N][0],house[N][1])));
}
