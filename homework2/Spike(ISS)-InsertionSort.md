# Spike(ISS)를 통한 Insertion sort 실행

### 1) 삽입정렬 코드 작성

삽입정렬을 수행하는 c언어 코드를 vi 에디터를 통해 작성합니다.<br>
<img width="70%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885869-7af4d85f-ca72-4b28-9eea-53a2af3ae532.png">

Insertion sort, 즉 삽입정렬은 2번째 원소부터 시작하여<br>
그 앞(왼쪽)의 원소들과 비교하면서 삽입할 위치를 지정한 후,<br>
원소를 뒤로 옮기고 지정된 자리에 자료를 삽입 하여 정렬하는 알고리즘입니다.<br>

최선의 경우 O(N), 평균과 최악의 경우 O(n^2) 의 시간복잡도를 갖게 됩니다.<br>
주어진 배열 안에서 교환(swap)을 통해 정렬이 수행되므로 O(n)의 공간복잡도를 가집니다.<br>

삽입정렬은 아래와 같은 단계를 통해 이뤄집니다.<br>

1. 2번째 위치(index)의 값을 temp에 저장합니다.<br>
2. temp와 이전에 있는 원소들과 비교하며 삽입합니다.<br>
3. 1번으로 돌아가 다음 위치(index)의 값을 temp에 저장하고, 위 과정을 반복합니다.<br>

이 단계를 C언어 코드로 나타내면 아래와 같습니다.<br>
<img width="70%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885765-f431d5d4-81e4-4528-9caf-0804f2634a9a.png">

이렇게 작성한 삽입정렬 C언어 코드를 컴퓨터에서 실행하기 위해서는 컴퓨터가 이해할 수 있는<br>
기계어로 번역하는 컴파일 과정이 필요합니다. RISC-V gcc와 Spike ISS를 통해 실행시켜보겠습니다.<br>


### 2) riscv를 통해 binary 목적파일로 컴파일

삽입정렬 c언어 코드를 riscv gcc를 이용해 RISC-V ELF 바이너리 형태로 컴파일합니다.<br>
<img width="70%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885945-ef377928-bf58-489b-8735-f3698c39ba34.png">


### 3) 명령어셋 시뮬레이터 spike를 통해 프록시 커널 위에서 파일 실행

컴파일된 삽입정렬 목적파일을 ISS spike를 통해 실행합니다.<br>
(프록시 커널 위에서 프로그램을 시뮬레이션 할 수 있습니다.)<br>
<img width="70%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885954-4b9eba69-48cd-4db4-8452-36079494d7e2.png">

### 4) Spike의 Debug 모드

-d 옵션을 사용하여 대화형 디버그 모드로 실행할 수 있습니다.<br>
엔터키로 한줄씩 실행할 수 있으며, r 입력시 무기한 실행, q 입력시 컴파일을 중지할 수 있습니다.<br>
<img width="70%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885966-19a7b469-d232-4a59-ad18-29cece0bd0c1.png">


## 참고 문헌

1. RISCV Instruction Set Simulator Spike Github<br>
https://github.com/riscv-software-src/riscv-isa-sim

2. Spike 사용법 관련 블로그<br>
https://myskan.tistory.com/61

3. Spike 설치 튜토리얼 영상<br>
https://www.youtube.com/watch?v=zZUtTplVHwE

4. Ubuntu 20.0.4에서 Spike 설치방법<br>
https://matthieu-moy.fr/spip/?Pre-compiled-RISC-V-GNU-toolchain-and-spike&lang=fr
