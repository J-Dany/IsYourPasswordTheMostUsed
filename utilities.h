#ifndef UTILITIES_H
#define UTILITIES_H
#include <unistd.h>
#include <pthread.h>

#define MAX_BUF               256
#define ERROR_OPENING_FILE      1
#define ERROR_INIT_MUTEX        2
#define ERROR_CREATING_THREAD   3

struct args
{
    FILE **file_passwd;
    char *passwd;
};

pthread_t threads[2]; // 2 Thread per cercare nel file
pthread_mutex_t lock; // Mutex

extern void *search(void *__args);

#endif // UTILITIES_H