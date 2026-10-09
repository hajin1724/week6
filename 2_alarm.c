/*
 * 2_alarm.c — 정해진 시간 뒤에 시그널을 받는다
 *
 * [핵심 개념]
 *   alarm(n) 은 n 초 뒤에 커널이 SIGALRM 을 보내도록 예약한다.
 *   시간 제한(타임아웃)을 구현하는 가장 간단한 방법이다.
 *   출처: man 2 alarm, man 2 sigaction
 *
 * [컴파일·실행]
 *   gcc -Wall -Wextra -o 2_alarm 2_alarm.c
 *   ./2_alarm      # 3초 안에 뭔가 입력하지 않으면 시간이 끝난다
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static volatile sig_atomic_t timeout = 0;
volatile sig_atomic_t count = 0;
int interval, total;

static void on_alarm(int sig)
{
    (void)sig;
    timeout = 1;
    count++;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("사용법: ./alarm <간격초> <반복횟수>\n");
        return 1;
    }

    struct sigaction sa;
    sa.sa_handler = on_alarm;   /* SIGALRM 이 오면 이 함수를 부르게 등록한다 */
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;   
    sigaction(SIGALRM, &sa, NULL);
    interval = atoi(argv[1]);
    total = atoi(argv[2]);
    
    if (interval <= 0 || total <= 0) {
        printf("간격과 횟수는 1 이상의 정수여야 합니다\n");
        return 1;
    }
    while (count < total)
    {
        timeout = 0;
        alarm(interval);
        while (!timeout) {
            pause();
        }
        printf("%d 번째 알람\n", count);
        fflush(stdout);   /* 프롬프트를 즉시 보이게 한다(버퍼에 남지 않도록) */

    }
    
    printf("\n알람 종료\n");
   

    return 0;
}
