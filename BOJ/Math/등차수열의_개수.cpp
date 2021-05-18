// 미완성.. 
// 13558
/*
문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 
이때, 1 ≤ i < j < k ≤ N 이면서, Aj - Ai = Ak - Aj를 만족하는 (i, j, k) 쌍의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열의 크기 N (3 ≤ N ≤ 100,000)가 주어진다.

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 30,000)

출력
1 ≤ i < j < k ≤ N 이면서, Aj - Ai = Ak - Aj를 만족하는 (i, j, k) 쌍의 개수를 출력한다.
*/

#include <stdio.h>

#define ll long long
#define all(x) ((x).begin()),((x).end())

#define int ll

int presum[60100], sufsum[60100], arr[101010];
int ans[101010], res=0;
int n; 

int main()
{
    scanf("%d", &n); 
    for (int i = 1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
        if (i >= 3) 
            sufsum[arr[i]]++;
    }
    presum[arr[1]]++;
    for (int i = 2; i<n; i++)
    {
        for (int j = 1; j<=2*arr[i]; j++)
            ans[i] += presum[j] * sufsum[2*arr[i]-j];
    
        presum[arr[i]]++;
        sufsum[arr[i+1]]--;
        res += ans[i];
    }
    printf("%d\n", res);
    
    return 0;
}
