# [과제 1] Arbitrary precision integer arithmetic

## 1) 큰 수의 연산시 처리가 필요한 이유

C언어에서는 숫자를 표현할 수 있는 여러 자료형들이 존재합니다.<br>
그 중에서 가장 큰 정수를 표현할 수 있는 long long 타입의 자료형이 있습니다.<br><br>
long long 타입은 8byte의 크기이며<br>-9223372036854775808 부터 9223372036854775807 까지의 수를 표현할 수 있습니다.<br><br>
만약 long long 타입에 저장할 수 있는 크기를 넘어가는 연산이 이루어진다면<br>
결과는 아래와 같이 long long 타입이 저장할 수 있는 숫자 범위의 초기값으로 돌아가 계산이 이루어 집니다.<br><br>
```
#include <stdio.h>

int main(){
    long long a = 9223372036854775807;

    printf("long long a = %lld\n", a);
    printf("(long long a)  + 1 = %lld\n", a + 1);

    return 0;
}
```

<br>위처럼 계산이 된다면, 프로그램에서 사용자가 원하는 결과값을 얻지 못하게 됩니다.<br>
이렇게 자료형이 저장할 수 있는 숫자 범위를 벗어난 경우를 overflow가 발생했다고 말합니다.<br>

## 2) Overflow 발생 없이 큰 수의 연산을 처리하는 방법
<b>1. 덧셈, 뺄셈</b><br>
- 문자열로 2개의 수를 입력<br>
- 문자열 배열을 정수 배열로 변환<br>
- 각 자리수를 계산(덧셈은 10이상 올림 처리, 뺄셈은 0 미만 내림 처리)<br>

