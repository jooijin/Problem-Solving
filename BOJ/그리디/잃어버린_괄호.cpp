// 1541

#include <stdio.h>

using namespace std;

int main() {
	// 중간에 마이너스가 한번이라도 나왔다면 그 마이너스 이후는 모두 뺄 수 있다.
    // ex) 10+55-50+40-50 -> 10+55-(50+40)-50
	int ans;
	int num;
	char op;
    bool flag= false; // 마이너스가 나올 경우 true로
	
	scanf("%d", &ans);
    
    while(~scanf("\n%c%d",&op,&num)) {
        if(flag) {
            ans -= num;
        }
        else if(op == '+') {
            ans += num;
        }
        else {
            ans -= num;
            flag = true;
        }
    }
	
	printf("%d", ans);
	
	return 0;	
    
}
