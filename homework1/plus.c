#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 15001

int main(void)
{
    printf("** 덧셈 연산을 수행하는 프로그램입니다. **\n\n");

    // 1. 최대 ARRAY_SIZE 15000 자리의 배열 선언 후 2개의 수 입력 받아 배열에 값 넣기
    /// (마지막 \0 를 위해 15000 + 1)
    char numStrA[ARRAY_SIZE];
    char numStrB[ARRAY_SIZE];

    printf("수 입력 : ");
    scanf("%s", numStrA);

    printf("수 입력 : ");
    scanf("%s", numStrB);

    // 2. 입력 받은 두 수의 길이 비교한 후, 변수에 저장(max, min)
    int numStrALength = strlen(numStrA);
    int numStrBLength = strlen(numStrB);

    int minLength = numStrALength < numStrBLength ? numStrALength : numStrBLength;
    int maxLength = numStrALength >= numStrBLength ? numStrALength : numStrBLength;

    // 3. 문자열로 받은 2개의 수를 정수 배열로 전환(아스키 코드 48 ‘0’ 처리)
    int numA[ARRAY_SIZE];
    int numB[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        numA[i] = numStrA[i] - '0';
        numB[i] = numStrB[i] - '0';
    }

    // 4. 덧셈 결과를 저장할 배열 생성(2번에서 저장한 max 크기로)
    int sum[maxLength];
    for (int i = 0; i < maxLength; i++)
    {
        sum[i] = 0;
    }

    // 5. 덧셈 연산 진행 및 저장   * 한자리씩 더하기 연산 진행
    for (int i = 0; i < minLength; i++)
    {
        int numAValue = numA[numStrALength - 1 - i];
        int numBValue = numB[numStrBLength - 1 - i];

        // 5-1. 더한 수가 10이상일 경우 carry = 1 저장 후, 다음 자리 수 연산 때 carry 값 반영
        // 5-2. 더한 수가 10미만일 경우, 그대로 반영
        int digit = (sum[i] + numAValue + numBValue) % 10;
        int carry = sum[i] + numAValue + numBValue >= 10 ? 1 : 0;

        sum[i] = digit;
        // 5-3. 자리 위치가 마지막일 때는 연산 결과 그대로 반영
        if (minLength == maxLength && i == minLength - 1)
        {
            sum[i] += carry * 10;
        }
        else
        {
            sum[i + 1] += sum[i + 1] + carry;
        }
    }

    // 6. 입력 받은 두수의 길이가 다를 경우, 남은 자리 수 만큼 덧셈 계산
    for (int i = minLength; i < maxLength; i++)
    {
        sum[i] += numStrALength < numStrBLength ? numB[maxLength - 1 - i] : numA[maxLength - 1 - i];

        if (sum[i] >= 10 && i != maxLength - 1)
        {
            sum[i] = sum[i] % 10;
            sum[i + 1] += 1;
        }
    }

    // 7. 덧셈 결과를 역순으로 출력
    printf("결과 값 : ");
    for (int i = 0; i < maxLength; i++)
    {
        printf("%d", sum[maxLength - 1 - i]);
    }

    printf("\n");
}