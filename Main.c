#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

pthread_mutex_t mutex, writeblock;
int data = 0, rcount = 0;

void *reader(void *arg){
        int num = (int)arg;
        pthread_mutex_lock(&mutex);
        rcount++;
        if(rcount==1){
                pthread_mutex_lock(&writeblock);
        }
        pthread_mutex_unlock(&mutex);
        printf("Data read by the Reader%d is %d\n", num, data);
        sleep(1);
        pthread_mutex_lock(&mutex);
        rcount--;
        if(rcount==0){
                pthread_mutex_unlock(&writeblock);
        }
        pthread_mutex_unlock(&mutex);
}

void *writer(void *arg){
        int num = (int)arg;
        pthread_mutex_lock(&writeblock);
        data++;
        printf("Data written by the Writer%d is %d\n", num, data);
        sleep(1);
        pthread_mutex_unlock(&writeblock);
}

int main(){
        pthread_t rtid[5], wtid[5];
        pthread_mutex_init(&mutex, NULL);
        pthread_mutex_init(&writeblock, NULL);
        for(int i=0; i<n; i++){
                pthread_create(&wtid[i], NULL, &writer, (void*)i);
                pthread_create(&rtid[i], NULL, &reader, (void*)i);
        }
        for(int i=0; i<n; i++){
                pthread_join(wtid[i], NULL);
                pthread_join(rtid[i], NULL);
        }
        return 0;
}
