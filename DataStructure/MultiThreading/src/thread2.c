#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // For multi-threading
#include <time.h>

// complie with -pthread
#define NSEC_PER_SEC 1000000000
static inline void tsnorm(struct timespec *ts)
{
	while (ts->tv_nsec >= NSEC_PER_SEC)
	{
		ts->tv_nsec -= NSEC_PER_SEC;
		ts->tv_sec++;
	}
}

typedef struct
{
	unsigned int mode;
	unsigned int deci;
	unsigned int tick;
	unsigned int data;
	char name[32];
	struct timespec t_request;
	pthread_mutex_t mutex;
} arincBus_t;

void *recv_thread(arincBus_t *arincBus);
void *send_thread(arincBus_t *arincBus);

int n_bus = 6;
int masterSwitch = 1;
int main(int argc, char **argv)
{
	int i;
	int rc;
	int loop = 0;
	arincBus_t arincBus[8];
	struct timespec t_request;
	pthread_t *threads = (pthread_t *)malloc(n_bus * sizeof(pthread_t));
	if (NULL == threads)
	{
		printf("Out of memory!\n");
		return -1;
	}
	for (i = 0; i < n_bus; i++)
	{
		arincBus[i].mode = i % 2;
		arincBus[i].deci = (i + 1) * 4;
		arincBus[i].data = 0;
		arincBus[i].tick = 0;
		sprintf(arincBus[i].name, "Arinc Bus %d", i);
		rc = pthread_mutex_init(&arincBus[i].mutex, NULL);
		if (rc != 0)
		{
			printf("Error occur during initializing mutex.\n");
			return -1;
		}
		printf("%s %d %d %d\n", arincBus[i].name, arincBus[i].mode, arincBus[i].deci, arincBus[i].data);
	}
	// Let us create three threads
	for (i = 0; i < n_bus; i++)
	{
		if (arincBus[i].mode == 0)
		{
			if (0 != pthread_create(&threads[i], NULL /*Add attribute later*/, (void *)send_thread, (void *)&(arincBus[i])))
			{
				printf("Error at creating a send thread.\n");
				return -1;
			}
		}
		else
		{
			if (0 != pthread_create(&threads[i], NULL /*Add attribute later*/, (void *)recv_thread, (void *)&(arincBus[i])))
			{
				printf("Error at creating a recv thread.\n");
				return -1;
			}
		}
	}
	printf("Start while 1\n");
	clock_gettime(CLOCK_MONOTONIC, &t_request);
	while (loop < 101)
	{
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &t_request, NULL);
		/*
		for (i = 0; i < n_bus; i++){
			pthread_mutex_lock(&arincBus[i].mutex);
			arincBus[i].tick++;
			pthread_mutex_unlock(&arincBus[i].mutex);
		}
		sleep(1);
		*/
		t_request.tv_sec++;
		loop++;
		printf("%d\n", loop);
	}

	masterSwitch = 0;
	for (i = 0; i < n_bus; i++)
	{
		// Add return value and Error checking
		pthread_join(threads[i], NULL);
	}

	return 0;
}

/* Introduce multi-threading version of the transmission */
void *recv_thread(arincBus_t *arincBus)
{

	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &(arincBus->t_request));
	while (masterSwitch)
	{
		//	printf("send id:%d, before lock\n",uart->id);
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &(arincBus->t_request), NULL);
		arincBus->t_request.tv_sec += arincBus->deci;
		/*
		if(arincBus->tick == arincBus->deci){
			flag = 1;
			pthread_mutex_lock(&(arincBus->mutex));	// Mutex lock
			arincBus->tick = 0;
			pthread_mutex_unlock(&(arincBus->mutex));	// Mutex unlock
		}else{
			usleep(200000); // 200ms
		}
		*/

		arincBus->data++;
		clock_gettime(CLOCK_MONOTONIC, &t_end);
		printf("Recv: %s: %d,current time: %ld, %ld, request: %ld, %ld\n", arincBus->name, arincBus->data, t_end.tv_sec, t_end.tv_nsec, arincBus->t_request.tv_sec, arincBus->t_request.tv_nsec);
	}
	pthread_exit((void *)0);
}

void *send_thread(arincBus_t *arincBus)
{
	unsigned int flag = 0;
	struct timespec t_end;
	clock_gettime(CLOCK_MONOTONIC, &(arincBus->t_request));
	while (masterSwitch)
	{
		//	printf("send id:%d, before lock\n",uart->id);
		clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &(arincBus->t_request), NULL);
		arincBus->t_request.tv_sec += arincBus->deci;
		/*
		if(arincBus->tick == arincBus->deci){
			flag = 1;
			pthread_mutex_lock(&(arincBus->mutex));	// Mutex lock
			arincBus->tick = 0;
			pthread_mutex_unlock(&(arincBus->mutex));	// Mutex unlock
		}else{
			usleep(200000); // 200ms
		}
		*/

		arincBus->data++;

		clock_gettime(CLOCK_MONOTONIC, &t_end);
		printf("Send: %s: %d,current time: %ld, %ld, request: %ld, %ld\n", arincBus->name, arincBus->data, t_end.tv_sec, t_end.tv_nsec, arincBus->t_request.tv_sec, arincBus->t_request.tv_nsec);
	}
	pthread_exit((void *)0);
}
