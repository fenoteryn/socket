#include <stdio.h>

int main(){
	int a = 10;
	int b = 100;
	
	a = a + 10; // 원래 값: a = 20, b = 100

	sleep(10); // fork() 함수 전에 sleep()
	int pid = fork(); // fork() 함수는 현재 구동 중인 프로세스의 복제본을 생성
	// 현재 프로세스 = 부모 프로세스, fork()에 의해 생성된 프로세스 = 자식 프로세스
	// 리턴 값(pid) = 0, if 자식 프로세스
	// 리턴 값 = 자식 프로세스의 pid값 if 부모 프로세스
	// 만약 용량 부족 등의 이유로 fork() 함수 실패 시, -1값을 리턴

	if (pid > 0){ // 부모 프로세스에선 a의 값만 변한다
		printf("부모 프로세스\n");
		a = a + 10;
		printf("[Parent] a = %d, b = %d\n", a, b);
		sleep(20); // 프로그램을 종료하지 말고 20초 대기
	}
	else if (pid == 0) { // 자식 프로세스에선 b의 값만 변한다
		printf("자식 프로세스 \n");
		b = b * 10;
		printf("[Child] a = %d, b = %d\n", a, b);
		sleep(20);
	}
	else { // fork() 실패
		printf("fork() 함수가 실패하였습니다.\n");
	}
	return 0;
}
