//
// Created by seraphond on 25/11/16.
//
/*
sem_t sem1,sem2,sem3;

sem_init(&sem1,1,0);
sem_init(&sem2,1,0);

p1(){
    a1();
    sem_post(&sem1);
    sem_post(&sem1);
    sem_wait(&sem1);
    sem_wait(&sem3);
    b1();
}

p2(){
    a2();
    sem_post(&sem2);
    sem_post(&sem2);
    sem_wait(&sem1);
    sem_wait(&sem3);
    b2();
}

p3(){
    a3();
    sem_post(&sem3);
    sem_post(&sem3);
    sem_wait(&sem1);
    sem_wait(&sem2);
    b3();
}
*/
//Q1.2)
void exo2(int N) {
    sem_t sem[N];
    int k;

    for (k = 0; k < N; k++) {
        sem_init(&sem[k], 1, 0);
    }
}
p(int i,int N){
    a[i]();
    for(k=0;k<N-1;k++){
        sem_post(&sem[i]);
    }

    for(k=0;k<N;k++){
        if(k!=i){
            sem_wait(&sem[k]);
        }

    }
    b[i];
}


//q1.3)

p3(int me){
    int cpt=0;
    sem_t mutex,sem;
    sem_init(&mutex,1,1);
    sem_init(&sem,1,0);
    a[me];
    sem_wait(&mutex);
    if(cpt==N){
        for(int i;i<N;i++){
            sem_post(&sem);

        }
        sem_post(&mutex);
        cpt=0;
    }else{
        cpt++;
        sem_post(&);
        sem_wait(&sem);
    }
    b[me];
}