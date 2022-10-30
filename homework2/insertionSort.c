#include <stdio.h>
#define MAX_SIZE 10
void printArray(char *title, int list[], int listSize);
void insertionSort(int list[], int n);

int main()
{
  printf("** 삽입정렬 프로그램 입니다. **\n\n");
  
  // 1. 정렬시킬 배열 선언 
  int list[MAX_SIZE] = {3, 9, 1, 7, 5, 12, 33, 6, 23, 2};
  printArray("정렬 전 :", list, MAX_SIZE);

  // 2. 삽입정렬 
  insertionSort(list, MAX_SIZE);

  // 3. 결과 출력 
  printArray("정렬 후 :", list, MAX_SIZE);

  return 0;
}

// 출력용 함수 
void printArray(char *title, int list[], int listSize){
  printf("%s ", title);
  for (int i = 0; i < listSize; i++)
  {
    printf("%d ", list[i]);
  }
  printf("\n");
}

// 삽입 정렬 함수 
void insertionSort(int list[], int listSize)
{
  int i, j, temp;

  for (i = 1; i < listSize; i++)
  {
    temp = list[i];

    // temp보다 정렬된 배열에 있는 값이 크면 j+1번째로 이동
    for (j = i - 1; j >= 0 && list[j] > temp; j--)
    {
      // 오른쪽으로 이동 
      list[j + 1] = list[j]; 
    }

    list[j + 1] = temp;
  }
}