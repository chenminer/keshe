#include <stdio.h>

#include <unistd.h>
#include <pthread.h>

#include <errno.h>



int num = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void print_A()
{
    int i;
    
    for(i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
	
	if(num == 0)
	{
	    printf("A!\n");
	    num = (num + 1)%3;
	}
                 
	pthread_mutex_unlock(&mutex);
    }
}

void print_B()
{
    int i;
    
    
    for(i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        if(num == 1)
	{
	    printf("B!\n");
	    num = (num + 1)%3;
	}

                 
	pthread_mutex_unlock(&mutex);
    }
}

void print_C()
{
    int i;

    
    for(i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex);
        if(num == 2)
	{
	    printf("C!\n");
	    num = (num + 1)%3;
	}
	pthread_mutex_unlock(&mutex);
    }
}

int main()
{

    pthread_t id1;
    pthread_t id2;
    pthread_t id3;

    pthread_create(&id1,NULL,(void *)print_A,NULL);
    pthread_create(&id2,NULL,(void *)print_B,NULL); 
    pthread_create(&id3,NULL,(void *)print_C,NULL);

    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    pthread_join(id3,NULL);

    return 0;
}


