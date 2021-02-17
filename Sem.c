// Cyrus Duncan CST-221
// included librares to create pthreads and semaphore
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> 

// variables
sem_t mutex;
int users = 0;


/*
*Check if users is equal to 10, if so tell the thread to wait, subract by 1, sleep for 4 seconds and post thread
* else if its lest than 10, tell thread mutex to wait, add on to the users and print it out then post.
*/
void* Queue(void* arg)
{
  if(users == 10) {
  sem_wait(&mutex);
   users--;

   printf("%d\n", users);
   sleep(4);
   sem_post(&mutex);
  }
  else {
 sem_wait(&mutex);
  users++;
   printf("%d\n", users);
  sem_post(&mutex);
  }
}
int main() 
{
// Create Semaphore
 sem_init(&mutex, 1, 10);
// Initalize threads t1 and t2
 pthread_t t1, t2;
// create multiple thread variables running the same process, increasing or decreasing users value
 pthread_create(&t1, NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
 sleep(2);
 pthread_create(&t2,NULL,Queue,NULL);
// join t1 and t2  variables nulling them out
 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
// destory the Semaphore
 sem_destroy(&mutex);
// return 0 closing program.
 return 0;
}
