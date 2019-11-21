#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h> // For multi-threading

// complie with -pthread

typedef struct
{
	unsigned int mode;
	unsigned int deci;
	unsigned int tick;
	unsigned int data;
	char name[32];
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
	while (loop < 101)
	{
		for (i = 0; i < n_bus; i++)
		{
			pthread_mutex_lock(&arincBus[i].mutex);
			arincBus[i].tick++;
			pthread_mutex_unlock(&arincBus[i].mutex);
		}
		sleep(1);
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
	unsigned int flag = 0;
	while (masterSwitch)
	{
		//	printf("send id:%d, before lock\n",uart->id);

		if (arincBus->tick == arincBus->deci)
		{
			flag = 1;
			pthread_mutex_lock(&(arincBus->mutex)); // Mutex lock
			arincBus->tick = 0;
			pthread_mutex_unlock(&(arincBus->mutex)); // Mutex unlock
		}
		else
		{
			usleep(200000); // 200ms
		}

		if (1 == flag)
		{
			arincBus->data++;
			printf("Recv: %s: %d\n", arincBus->name, arincBus->data);
			flag = 0;
		}
	}
	pthread_exit((void *)0);
}

void *send_thread(arincBus_t *arincBus)
{
	unsigned int flag = 0;
	while (masterSwitch)
	{
		//	printf("send id:%d, before lock\n",uart->id);

		if (arincBus->tick == arincBus->deci)
		{
			flag = 1;
			pthread_mutex_lock(&(arincBus->mutex)); // Mutex lock
			arincBus->tick = 0;
			pthread_mutex_unlock(&(arincBus->mutex)); // Mutex unlock
		}
		else
		{
			usleep(200000); // 200ms
		}

		if (1 == flag)
		{
			arincBus->data++;
			printf("Send: %s: %d\n", arincBus->name, arincBus->data);
			flag = 0;
		}
	}
	pthread_exit((void *)0);
}
