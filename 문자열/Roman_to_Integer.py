# 못풀어서 다른 사람들 코드를 참고해서 했다ㅠㅠ
# 오늘부터 리트코드 문제들을 좀 풀어보기로 했다
# 코딩 테스트 문제에서 스트링이 나오면 C++로 하는게 너무 불리해서 파이썬이랑 자바 문자열을 좀 공부해 볼 계획이다
# 사실 파이썬을 안한지 정말 너무 오래되어서 많이 헷갈린다... 그래도 열심히 하자

class Solution:
    def romanToInt(self, s: str) -> int:
        # 우선 딕셔너리에 로만 문자에 해당하는 숫자 저장해놓기
        rom2int = {"M":1000, "D": 500, "C": 100,"L":50, "X":10, "V": 5, "I":1}
        
        answer = 0
        
        for i in range(len(s)-1) :
            # 현재 로마 문자에 해당하는 정수
            curr = rom2int[s[i]]
            # 다음 로마 문자에 해당하는 정수
            nextRom = rom2int[s[i+1]]
            # 만약 현재 로마 문자에 해당하는 정수>=다음 로마 문자에 해당하는 정수이면
            # 현재 로마 문자에 해당하는 정수 값을 더해준다
            if (curr>=nextRom) :
                answer += curr
            # 그렇지 않은 경우에는 뺴준다!
            # 왜냐하면 그런 경우는 IX=4 처럼 표기하는 경우이기 때문
            else :
                answer -= curr
        
        answer += rom2int[s[len(s)-1]]

        return (answer)
