#include<stdio.h>
#include<pthread.h>
#define MAX 5
pthread_t tid[2];
unsigned int shared_data = 0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
unsigned int rc;
//prototypes for callback functions

void* PrintEvenNos(void*);
void* PrintOddNos(void*);

void main(void)
{
    pthread_create(&tid[0],0,&PrintEvenNos,0);
    pthread_create(&tid[1],0,&PrintOddNos,0);
    sleep(3);

    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
}

void* PrintEvenNos(void *ptr)
{
     rc = pthread_mutex_lock(&mutex);
     do
     {
         if( shared_data % 2 != 0 )
         {
		 pthread_cond_wait( &cond, &mutex );
         }
         printf("Even:%d\n",shared_data);
         shared_data++;
	 pthread_cond_signal( &cond );
         rc=pthread_mutex_unlock(&mutex);//if number is odd, do not print, release mutex
     } while (shared_data <= MAX );
	return NULL;
}

void* PrintOddNos(void* ptr1)
{
    rc = pthread_mutex_lock(&mutex);
    do
    {
        if( shared_data%2 == 0)
        {
		pthread_cond_wait( &cond, &mutex );
        } 
        printf("odd:%d\n",shared_data);
        shared_data++;
	pthread_cond_signal( &cond );	
        rc = pthread_mutex_unlock(&mutex);//if number is even, do not print, release mutex
    } while (shared_data <= MAX);
    return NULL;
}
