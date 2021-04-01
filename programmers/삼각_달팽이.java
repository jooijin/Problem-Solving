// 그냥 노동력을 갈아넣어서 풀었다..
// 이렇게 풀면 비효율적인것 같은데 다른 방법이 있는지 생각해봐야겠다

class Solution {
    public int[] solution(int n) {
        int N = n;
        int[] answer = new int[n*(n+1)/2];
        int[][] tri = new int[n][n];
        int num = 0;
        int cnt = 0;
        
        do {
            for(int i=0; i<n; i++) {
                num++;
                tri[i+2*cnt][0+cnt] = num;
            }
            for(int i=1; i<n; i++) {
                num++;
                tri[n-1+2*cnt][i+cnt] = num;
            }
            for(int i=2; i<n; i++) {
                num++;
                tri[n-i+2*cnt][n-i+cnt] = num;
            }
            n -= 3;
            cnt++;
            
        } while(n>0);
            
        int index = 0;
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<=i; j++){
                answer[index] = tri[i][j];
                index++;
            }
        }
            
        return answer;
    }
}
