#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

sem_t mutex, wrt;
int s = 10, rcount = 0;

void *writer(){
        sem_wait(&wrt);
        int n = rand() % 5;
        printf("Writer Wait for Random time between 0-5 = %d\n", n);
        sleep(n);
        printf("Shared value increament by 10\n");
        s+=10;
        printf("Writer: No. of reader present = %d, When shared value = %d\n", rcount, s);
        sem_post(&wrt);
}

void *reader(){
        //Entry Part
        sem_wait(&mutex);
        rcount++;
        if(rcount==1){
                sem_wait(&wrt);//No writer should come
        }
        sem_post(&mutex);//so next reader can come
        //Exit Part
        int n = rand() % 5;
        printf("Reader wait for Random time between 0-5 = %d\n", n);
        sleep(n);
        printf("Reader: No. of reader present = %d, When shared value = %d\n", rcount, s);
        sem_wait(&mutex);
        rcount--;
        if(rcount==0){//Now writer can come if they want
                sem_post(&wrt);
        }
        sem_post(&mutex);
}

int main(){
        printf("Initial value of share variable = %d\n", s);
        int n;
        printf("Enter the no. of Reader = Writer\n");
        scanf("%d", &n);
        pthread_t r[n], w[n];
        sem_init(&wrt, 0, 1);
        sem_init(&mutex, 0, 1);
        printf("Total no. of READERS=WRITERS=%d\n", n);
        for(int i=0; i<n; i++){
                pthread_create(&w[i], NULL, &writer, NULL);
                pthread_create(&r[i], NULL, &reader, NULL);
        }
        for(int i=0; i<n; i++){
                pthread_join(w[i], NULL);
                pthread_join(r[i], NULL);
        }
        printf("Final value of share variable = %d\n", s);
}
