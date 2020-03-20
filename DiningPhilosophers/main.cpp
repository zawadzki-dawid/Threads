#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include "Philosopher.h"

#define N 5

using namespace std;

pthread_t threads[N];

sem_t console, forks[N];

void* start(void* arg) {
    Philosopher *philosopher = (Philosopher *) arg;

    while(1) {
        philosopher->think();

        philosopher->takeForks(console);

        philosopher->eat();

        philosopher->putForks(console);

    }

}

int main() {
    sem_init(&console, 0, 1);

    Philosopher* philosophers[N];

    for(int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);

    }

    for(int i = 0; i < N ; i++) {
        philosophers[i] = new Philosopher(i, forks);

        pthread_create(&threads[i], NULL, start, philosophers[i]);

        cout<<"Filozof nr. "<<philosophers[i]->philosophersId()<<" mysli."<<endl;

    }

    for(int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);

    }

    return 0;

}