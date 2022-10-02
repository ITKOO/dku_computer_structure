/**
 * @file multiple.c
 * @author Jiwon Koo
 * @brief 큰수의 곱셈연산을 수행하는 프로그램
 * @version 0.1
 * @date 2022-10-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>
#define ARRAY_SIZE 15001
int main()
{
   printf("** 곱셈 연산을 수행하는 프로그램입니다. **\n\n");

   // 1. 최대 ARRAY_SIZE 15000 자리의 배열 선언 후 2개의 수 입력 받아 배열에 값 넣기
   /// (마지막 \0 를 위해 15000 + 1)
   char numStrA[ARRAY_SIZE];
   char numStrB[ARRAY_SIZE];

   printf("수 입력 : ");
   scanf("%s", numStrA);

   printf("수 입력 : ");
   scanf("%s", numStrB);

   // 2. 입력 받은 두 수의 길이 저장
   int numStrALength = strlen(numStrA);
   int numStrBLength = strlen(numStrB);

   // 3. 결과 값 저장할 배열 추가 및 초기화
   int i, j, k;
   int multipleLength = numStrALength + numStrBLength; 

   char result[multipleLength + 2];
   memset(result, 0x00, multipleLength + 2);

   // 4. 곱셈 연산
   for (i = 0; i < numStrALength; i++)
      for (j = 0; j < numStrBLength; j++) 
      {
         // 올림 값 처리를 위해 뒷자리부터 연산 
         k = multipleLength - i - j;                                                                  
         result[k] += (numStrA[numStrALength - i - 1] - '0') * (numStrB[numStrBLength - j - 1] - '0');
         // 값이 9보다 클때 올림 값 처리 
         if (result[k] > 9)
         {
            result[k - 1] += (result[k] / 10);
            result[k] %= 10;
         } 
      }

   // 5. 결과 값 출력 
   for (i = 0; i <= multipleLength; i++)
      result[i] += '0';
   for (i = 0; result[i] == '0';)
      i++;
   printf("%s\n", &result[i]);

   return 0;
}
