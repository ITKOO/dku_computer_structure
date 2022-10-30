# Spike(ISS) - 환경세팅

작성한 RISC-V 프로그램을 실행하기 위해서는 명령어 셋 시뮬레이터(ISS)가 필요합니다.<br>
ISS로는 Spike를 사용했으며, 환경은 Ubuntu 20.04.4 LTS / 개인 서버를 
사용해 설치를 진행했습니다.<br>

명령어셋 시뮬레이터 Spike 설치를 위해서는 크게 아래의 과정을 거쳐야합니다.<br>
1. wget을 통한 riscv 다운로드
2. 다운로드 받은 riscv 파일 압축 풀기
3. apt를 통한 명령어셋 시뮬레이터 Spike 다운로드
4. ~/.bashrc 파일에 riscv의 환경변수 설정
5. 설치 확인 테스트 : spike help 명령어 및 c파일 테스트

### 1) wget을 통한 riscv 다운로드

wget은 http 또는 ftp 통신을 사용해 서버에서 파일을 다운로드 받을 때 사용하는 명령어 입니다.<br> 
이 명령어를 통해 riscv를 다운로드 합니다.<br>
<img width="80%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885506-8770f479-a528-4a62-b7a7-3f8e1ac903db.png">


### 2) 다운로드 받은 riscv 파일 압축 풀기

tar 명령어(압축을 하거나, 해제하는 명령어)를 통해 다운로드 받은 riscv파일의 압축을 풀어줍니다.<br>
이때 아래 명령어에서 –xJvf은 확장자 .tar.xz 파일의 압축을 푸는 옵션입니다.<br>
`sudo tar -xJvf /tmp/riscv.tar.xz`<br><br>
<img width="80%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885511-40652424-6435-422b-97f4-233be5e1252e.png">

### 3) apt를 통한 명령어셋 시뮬레이터 Spike 다운로드

apt는 ubuntu에서 패키지를 설치, 업데이트, 제거 등의 관리하기 위한 유틸리티 입니다.<br>
apt를 통해 ISS Spike를 다운로드 합니다.<br>
<img width="80%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885520-6d5503bb-ab48-4bcf-a2f5-e62fe068787a.png">

### 4) ~/.bashrc 파일에 riscv의 환경변수 설정

ubuntu에서 환경변수를 설정하기 위해서는 .bashrc 파일에서 경로를 추가해주어야 합니다<br>
vi 에디터로 해당 파일을 열어, 하단에 riscv 관련 환경 변수를 설정한 후<br>
source 명령어를 통해 변경한 파일의 내용을 적용시킵니다.<br>
(위에서 다운받은 riscv를 tar을 통해 압축 해제했기 때문에 rm 명령어를 통해<br>
tmp 폴더에 있는 riscv 원본 파일을 삭제해줍니다.)
<img width="80%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885529-dc372030-649b-4ef5-b1d6-ab9d4e8cd6c9.png">

### 5) 설치 확인 테스트 : spike help 명령어 및 c파일 테스트

설치되었는지 확인하기 위해서 spike help명령어와 tmp 폴더에 c파일을 만든 후 실행시켜 보겠습니다.
<img width="80%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885624-e0be1849-9713-43f5-bb74-b8ca0522665b.png">

아래는 Spike를 통해 Hello, I am Jiwon Koo를 출력하는 C언어 파일을 실행한 화면입니다.
<img width="80%" alt="image" src="https://user-images.githubusercontent.com/31758135/198885635-e2c4c57d-8c88-45df-a4f4-34588519423a.png">


