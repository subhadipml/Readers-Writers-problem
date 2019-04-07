#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t mutex, wrt;
int s = 10, rcount = 0;

void *writer(){
        pthread_mutex_lock(&wrt);
        int n = rand() % 5;
        printf("Writer Wait for Random time between 0-5 = %d\n", n);
        sleep(n);
        printf("Shared value increament by 10\n");
        s+=10;
        printf("Writer: No. of reader present = %d, When shared value = %d\n", rcount, s);
        pthread_mutex_unlock(&wrt);
}

void *reader(){
        //Entry Part
        pthread_mutex_lock(&mutex);
        rcount++;
        if(rcount==1){
                pthread_mutex_lock(&wrt);//No writer should come
        }
        pthread_mutex_unlock(&mutex);//so next reader can come
        //Exit Part
        int n = rand() % 5;
        printf("Reader wait for Random time between 0-5 = %d\n", n);
        sleep(n);
        printf("Reader: No. of reader present = %d, When shared value = %d\n", rcount, s);
        pthread_mutex_lock(&mutex);
        rcount--;
        if(rcount==0){//Now writer can come if they want
                pthread_mutex_unlock(&wrt);
        }
        pthread_mutex_unlock(&mutex);
}

int main(){
        printf("Initial value of share variable = %d\n", s);
        int n, i;
        printf("Enter the no. of Reader = Writer\n");
        scanf("%d", &n);
        pthread_t r[n], w[n];
        pthread_mutex_init(&wrt, NULL);
        pthread_mutex_init(&mutex, NULL);
        printf("Total no. of READERS=WRITERS=%d\n", n);
        for(i=0; i<n; i++){
                pthread_create(&w[i], NULL, &writer, NULL);
                pthread_create(&r[i], NULL, &reader, NULL);
        }
        for(i=0; i<n; i++){
                pthread_join(w[i], NULL);
                pthread_join(r[i], NULL);
        }
        printf("Final value of share variable = %d\n", s);
}
