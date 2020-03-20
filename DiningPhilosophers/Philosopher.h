//
// Created by dawid on 09.03.2020.
//

#ifndef DININGPHILOSOPHERS_PHILOSOPHER_H
#define DININGPHILOSOPHERS_PHILOSOPHER_H

#include <iostream>
#include <semaphore.h>
#include <unistd.h>

enum State {eating, thinking};

class Philosopher{
private:
    State _state;

    int _philosopherId;

    sem_t* forks;

    int numberOfMeals;

    int min(int a, int b);

    int max(int a, int b);



public:
    Philosopher(int id, sem_t* forks);

    void takeForks(sem_t& mutex);

    void putForks(sem_t& mutex);

    void think() const;

    void eat() const;

    int philosophersId() const;

};

#endif //DININGPHILOSOPHERS_PHILOSOPHER_H
