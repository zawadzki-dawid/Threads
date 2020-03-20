//
// Created by dawid on 09.03.2020.
//

#include <random>
#include <functional>
#include "Philosopher.h"

using namespace std;

default_random_engine generator;

uniform_int_distribution<int> distribution(1,5);

auto randomize = std::bind(distribution, generator);

Philosopher::Philosopher(int id, sem_t* forks) {
    _state = thinking;

    _philosopherId = id;

    this->forks = forks;

    numberOfMeals = 0;

}

int Philosopher::min(int a, int b) {
    if(a < b)
        return a;
    return b;
}

int Philosopher::max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

void Philosopher::takeForks(sem_t& mutex) {
    sem_wait(&forks[min(_philosopherId, (_philosopherId + 1) % 5)]);

    sem_wait(&forks[max(_philosopherId, (_philosopherId + 1) % 5)]);

    _state = eating;

    sem_wait(&mutex);

    cout<<"Filozf nr. "<<_philosopherId<<" zaczyna jesc."<<endl;

    sem_post(&mutex);

    numberOfMeals++;

}

void Philosopher::putForks(sem_t& mutex) {
    sem_post(&forks[_philosopherId]);

    sem_post(&forks[(_philosopherId + 1) % 5]);

    _state = thinking;

    sem_wait(&mutex);

    cout<<"Filozf nr. "<<_philosopherId<<" mysli."<<endl;

    sem_post(&mutex);

}

int Philosopher::philosophersId() const {
    return _philosopherId;

}

void Philosopher::think() const {
    sleep(randomize());

}

void Philosopher::eat() const {
    sleep(randomize());

}