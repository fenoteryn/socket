#include <stdio.h>
#include <pthread.h>

int ncount = 0; // 전역변수이므로 data 영역에 저장됨 --> 모든 스레드가 공유함
// e.g. 1번 스레드가 값을 변경하면 변경된 값을 2번 스레드가 볼 수 있음

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_sum2(void *data){ // ncount 값을 증가해 주는 함수
	int i;
	int n = *((int *)data);

	for(i = 0; i < n; i++){
		pthread_mutex_lock(&mutex);
		ncount++;
		pthread_mutex_unlock(&mutex);
		printf("[%x] sum = %d\n", pthread_self(), ncount); // pthread_self() = 자신의 thread_id 값을 리턴
	}
}
int main(){
	pthread_t pthread_id[3];
	int status[3];

	int a = 5;
	int b = 10;
	int c = 20;

	status[0] = pthread_create(&pthread_id[0], NULL, do_sum2, (void *)&a);
	status[1] = pthread_create(&pthread_id[1], NULL, do_sum2, (void *)&b);
	status[2] = pthread_create(&pthread_id[2], NULL, do_sum2, (void *)&c);

	pthread_join(pthread_id[0], (void **)&status[0]);
	pthread_join(pthread_id[1], (void **)&status[1]);
	pthread_join(pthread_id[2], (void **)&status[2]);

	printf("Main thread END\n");
	pthread_mutex_destroy(&mutex);
	return 0;
}
