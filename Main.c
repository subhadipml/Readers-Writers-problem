#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_mutex_t mutex, wrt;
int s, rcount = 0;

void *writer(void *arg){
        pthread_mutex_lock(&wrt);
        int n = rand() % 10;
        int d = ((int)arg);
        printf("--------------------------------------------------\n");
        printf("W%d Wait for Random time between 0ns and 10ns = %d\n", d, n);
        sleep(n);
        printf("Enter the number of time W%d want to write:\n", d);
        int t;
        scanf("%d", &t);
        printf("Now W%d is writing... i.e. ADDING...\n", d);
        int j;
        for(j=0; j<t; j++){
                printf("Enter the %dth INTEGER value to write:\n", (j+1));
                int u;
                scanf("%d", &u);
                s = s + u;
        }
        printf("UPDATED value of Shared variable = %d \n", s);
        printf("--------------------------------------------------\n");
        pthread_mutex_unlock(&wrt);
}

void *reader(void *arg){
        //Entry Part
        pthread_mutex_lock(&mutex);
        rcount++;
        if(rcount==1){
                pthread_mutex_lock(&wrt);//No writer should come
        }
        pthread_mutex_unlock(&mutex);//so next reader can come
        //Exit Part
        int n = rand() % 10;
        int d = ((int)arg);
        printf("R%d wait for Random time between 0ns and 10ns = %d\n", d, n);
        sleep(n);
        printf("Enter the number of time R%d want to read:\n", d);
        int t;
        scanf("%d", &t);
        printf("Now R%d is reading....\n", d);
        int j;
        for(j=0; j<t; j++){
                printf("R%d read the shared value = %d\n", d, s);
        }
        printf("Number of Readers present = %d\n", rcount);
        pthread_mutex_lock(&mutex);
        rcount--;
        if(rcount==0){//Now writer can come if they want
                pthread_mutex_unlock(&wrt);
        }
        pthread_mutex_unlock(&mutex);
}

void main(){
        printf("Enter the 'INTEGER' Initial value of share variable: \n");
        scanf("%d", &s);
        printf("---------------------------------------------\n");
        int rn, wn, i;
        printf("Enter the no. of Reader:\n");
        scanf("%d", &rn);
        for(i=0; i<rn; i++){
                printf("R%d\n", i);
        }
        printf("---------------------------------------------\n");
        printf("Enter the no. of Writer:\n");
        scanf("%d", &wn);
        for(i=0; i<wn; i++){
                printf("W%d\n", i);
        }
        printf("---------------------------------------------\n");

        pthread_t r[rn], w[wn];
        pthread_mutex_init(&wrt, NULL);
        pthread_mutex_init(&mutex, NULL);

        if(rn<0 || wn<0){
                printf("Sorry: You have Entered NEGATIVE number of READER | WRITER\n");
                printf("Program is Terminating....\n");
                return;
        }else if(rn == 0){
                printf("Sorry: You have not taken any READER\n");
                printf("No READER thread will be creaded\n");
        }else if(wn == 0){
                printf("Sorry: You have not taken any WRITER\n");
                printf("No WRITER thread will be creaded\n");
        }else{
                printf("Thread Creating....\n");
        }
        printf("---------------------------------------------\n");

        if(wn==rn){
                for(i=0; i<wn; i++){
                        pthread_create(&w[i], NULL, &writer, (int *)i);
                        pthread_create(&r[i], NULL, &reader, (int *)i);
                }
                for(i=0; i<wn; i++){
                        pthread_join(w[i], NULL);
                        pthread_join(r[i], NULL);
                }
        }else if(wn>rn){
                for(i=0; i<rn; i++){
                        pthread_create(&w[i], NULL, &writer, (int *)i);
                        pthread_create(&r[i], NULL, &reader, (int *)i);
                }
                for(i=rn; i<wn; i++){
                        pthread_create(&w[i], NULL, &writer, (int *)i);
                }
                for(i=0; i<rn; i++){
                        pthread_join(w[i], NULL);
                        pthread_join(r[i], NULL);
                }
                for(i=rn; i<wn; i++){
                        pthread_join(w[i], NULL);
                }
        }else{
                for(i=0; i<wn; i++){
                        pthread_create(&w[i], NULL, &writer, (int *)i);
                        pthread_create(&r[i], NULL, &reader, (int *)i);
                }
                for(i=wn; i<rn; i++){
                        pthread_create(&r[i], NULL, &reader, (int *)i);
                }
                for(i=0; i<wn; i++){
                        pthread_join(w[i], NULL);
                        pthread_join(r[i], NULL);
                }
                for(i=wn; i<rn; i++){
                        pthread_join(r[i], NULL);
                }
        }
        printf("-------------After joining the thread---------\n");
        printf("Final value of share variable = %d\n", s);
}
