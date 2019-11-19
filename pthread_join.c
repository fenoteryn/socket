#include <stdio.h>
#include <pthread.h>

void *do_sum(void *); // 스레드가 수행할 함수
// 인자로 받은 수까지의 합을 출력해 주는 함수

int main(){
	pthread_t pthread_id[3]; // 자식 스레드 3개
	int status[3]; // status도 자식 스레드 수만큼
	
	int a = 4; // 첫 번째 thread의 인자
	int b = 5; // 두 번째 thread의 인자
	int c = 6; // 세 번째 thread의 인자

	status[0] = pthread_create(pthread_id[0], NULL, do_sum, (void *)&a);
	status[1] = pthread_create(pthread_id[1], NULL, do_sum, (void *)&b);
	status[2] = pthread_create(pthread_id[2], NULL, do_sum, (void *)&c);
	
	pthread_join(&pthread_id[0], (void **)&status[0]);
	pthread_join(&pthread_id[1], (void **)&status[1]);
	pthread_join(&pthread_id[2], (void **)&status[2]);

	printf("Main thread END\n");
	return 0;
}
void *do_sum(void *arg){
	int max = *((int *)arg); // 형변환, 주소값을 int값으로 변환
	int i, sum = 0;
	for(i = 0; i <= max; i++){
		sum += i;
		printf("[%d] - ADD %d\n", max, i);
	}
	printf("1부터 %d까지의 합은 %d입니다.\n", max, sum);
}
