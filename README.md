# 시스템 프로그래밍 시그널 실습

## 1. 프로젝트 설명
- 1_sigint.c : SIGINT(Ctrl+C)를 3번 받으면 종료하는 프로그램
- 2_alarm.c : SIGALRM을 이용한 ...
- 3_signal_block.c : 시그널 블록(마스크) ...
- (도전 과제) 4_sigchld.c : SIGCHLD로 자식 3개를 자동 수거

## 2. 실행 화면
![1_sigint 실행](images/1_sigint.png)
![2_alarm 실행](images/2_alarm.png)

## 3. AI 사용 내용
- 사용한 AI: Claude
- 도움받은 부분: WSL 환경 설정, 컴파일 방법, 시그널 핸들러 구조에 대한 힌트
- 코드는 직접 작성하고, 막힌 부분은 힌트를 받아 해결함

## 4. 본인의 보강 내용
- `volatile sig_atomic_t`를 쓰는 이유를 공부하고 적용함
- 핸들러에서는 횟수만 세고 종료 판단은 main에서 하도록 구조를 바꿈
- (추가로 직접 시도한 내용)
