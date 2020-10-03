#ifndef UTILITIES_H
#define UTILITIES_H
#include <unistd.h>
#include <pthread.h>

#define MAX_BUF 256

pthread_t threads[2]; // 2 Thread per cercare nel file
pthread_mutex_t lock; // Mutex

#endif // UTILITIES_H