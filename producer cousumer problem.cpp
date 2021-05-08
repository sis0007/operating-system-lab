// producer consumer problem.

#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define max 20

sem_t full,empty,mutex;
pthread_t p1,c1,p2,c2,c3;
pthread_attr_t pa1,ca1,pa2,ca2,ca3;
int in=0,out=0,buffer[max],data;

//void producer();
//void consumer();
void *producer()
{
   
   printf("\nPRODUCER THREAD ENTERED THE PRODUCER FUNCTION\n");
   //sleep(10);
   
   if(in==max)
   {
     printf("THE BUFFER IS FULL");
    }
    else
    {
       sem_wait(&empty);
       sem_wait(&mutex);
       printf("ENTER THE DATA TO BE PRODUCED: ");
       scanf("%d",&data);
       buffer[in]=data;
       in++;
       sem_post(&full);
       sem_post(&mutex);
       
     }
     printf("\nPRODUCER THREAD LEAVING THE PRODUCER FUNCTION\n");
}   


void *consumer() 
{
    
   printf("\nCONSUMER THREAD ENTERED THE CONSUMER FUNCTION\n");
   sleep(10);
   
   if(out==in)
   {
     printf("THERE IS NO DATA TO BE CONSUMED");
    }
   else
   {
       sem_wait(&full);
       sem_wait(&mutex);
       data=buffer[out];
       buffer[out]=0;
       printf("CONSUMED DATA IS:%d\n",data);
       out++;
       sem_post(&empty);
       sem_post(&mutex);
    } 
    printf("\nCONSUMER THREAD LEAVING THE CONSUMER FUNCTION\n");  
    
}


int main()
{
  sem_init(&full,0,0);
  sem_init(&empty,0,max);
  sem_init(&mutex,0,1);
  pthread_attr_init(&pa1);
  pthread_attr_init(&pa2);
  pthread_attr_init(&ca1);
  pthread_attr_init(&ca2);
  pthread_attr_init(&ca3);
  pthread_create(&c1,&ca1,consumer,NULL);
  printf("\nCONSUMER THREAD CREATED\n");
  sleep(5);
  pthread_create(&c2,&ca2,consumer,NULL);
  printf("\nCONSUMER THREAD CREATED\n");
  
  pthread_create(&p1,&pa1,producer,NULL);
  printf("\nPRODUCER THREAD CREATED\n");
  sleep(5);
  pthread_create(&p2,&pa2,producer,NULL);
  printf("\nPRODUCER THREAD CREATED\n");
  sleep(5);
  sleep(5);
  pthread_create(&c3,&ca3,consumer,NULL);
  printf("\nCONSUMER THREAD CREATED\n");
  sleep(5);

  pthread_join(p1,NULL);
  pthread_join(c1,NULL);
  pthread_join(c2,NULL);
  pthread_join(c3,NULL);
  pthread_join(p2,NULL);
  return 0;
}
