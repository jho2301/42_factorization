# factorization test

## 테스트 과정
1. 합성수  4, 6 ~ 20, 100 등등: 정상 출력
2. 소수 3, 5, 11, 13: 정상 출력
3. unsigned int 범위 내에서 가장 큰 소수 4294967291: 실행 시간이 10초를 넘김
   1. 피연산자에서 약수를 제거한 값이 소수인지 검사하는 과정을 추가해 시간을 단축함: 즉시 출력
4. 범위를 벗어나는 수 (2 미만 4294967295 초과): 에러메세지 출력 Please enter a valid range. (2 ~ 4294967295)
5. 음수: 에러메세지 출력 Please enter a valid range. (2 ~ 4294967295)
6. 숫자 외 문자가 입력된 경우: 에러메세지 출력 Please enter only numbers
7. 인자가 입력되지 않은 경우: 에러메세지 출력 Please enter a argument
8. 인자가 두 개 이상 입력된 경우: 에러메세지 출력 Too many arguments. Please enter just 1 argument
