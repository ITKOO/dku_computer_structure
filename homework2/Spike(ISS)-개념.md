# Spike(ISS) - 개념

### 1) Instruction Set Simulator란?

명령어 집합(IS) 또는 명령어 집합 구조(ISA)는 마이크로프로세서가 인식해서 기능을 이해하고<br>
실행할 수 있는 기계어 명령어를 말합니다. 이런 명령어 집합들을 읽고, 수행하는 시뮬레이션 모델을<br>
명령어 집합 시뮬레이터(ISS)라고 말합니다. GDB 또한 컴파일된 ISS를 가진 하나의 디버거이며,<br>
이런 디버깅 기능들을 ISS에서도 제공합니다. 마이크로 컨트롤러의 동작을 수행하기 위해<br> 
타이머, interrupts, 시리얼 포트, I/O 포트 등과 같은 기능들도 통합되어 있습니다.<br>

### 2) Spike란?

RISC-V ISA 시뮬레이터로, RISC-V 차트에 있는 기능 모델들을 구현합니다.<br>
시뮬레이터의 이름은 미국 대륙 횡단 철도의 완공을 축하하기 위해 사용된 금색 스파이크의<br>
이름을 따서 Spike로 지어졌습니다. Spike는 아래의 RISC-V ISA 기능을 지원합니다.<br>
(더 자세한 내용은 Spike Github 페이지의 README 파일에서 확인이 가능합니다.)<br>

<br>위처럼 계산이 된다면, 프로그램에서 사용자가 원하는 결과값을 얻지 못하게 됩니다.<br>
이렇게 자료형이 저장할 수 있는 숫자 범위를 벗어난 경우를 overflow가 발생했다고 말합니다.<br>

- RV32I and RV64I base ISAs, v2.1
- RV32E and RV64E base ISAs, v1.9
- Zifencei extension, v2.0
- Zicsr extension, v2.0 …

### 3) Spike 버전 및 API

프로젝트는 주로 API가 확장되었거나 렌더링된 시기를 나타내기 위해 버전화됩니다. <br>
Spike는 하위 호환 API가 변경될 때 주요 버전 번호가 증가하고, 새로운 API가 추가될 때<br>
마이너 버전 번호가 증가합니다. (SemVer 버전 스키마를 따릅니다.)<br>
공개된 RISC-V ISA 기반이며, 현재 스파이크 내부의 C++ 인터페이스는<br>
현재 공개 API로 간주되지 않습니다.<br>

 * SemVer : Semantic Versioning의 줄임말, 좀 더 체계적인 버전 관리를 위해 버전 형식에 의미를 부여한 것
