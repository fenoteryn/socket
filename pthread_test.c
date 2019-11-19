#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func_thread(void *); // 스레드가 수행할 함수
// void *: Java의 Object와 비슷한 개념, 모든 타입으로 형변환 가능

int main(){
	int status;
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, func_thread, NULL); // fork()와 같은 역할, 새로운 thread 생성

	printf("thread %x is created\n", thread_id); // thread id 출력
	pthread_join(thread_id, (void **)&status); // main 함수가 종료하는 경우에도 thread 작업을 완전히 마무리하기 위함
	printf("main thread END\n"); // main thread 종료 메시지, main thread = 부모 프로세스와 같음
	return 0;
}
void *func_thread(void *argv){
	int i = 0;
	while(i < 10){
		i++;
		printf("thread %dth executing....\n", i);	
	}
}
