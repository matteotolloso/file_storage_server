#ifndef _FILESYSTEM_H
#define _FILESYSTEM_H
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <myutil.h>

#define OPEN_F 1
#define READ_F 2
#define READ_N_F 3
#define WRITE_F 4
#define APPEND_T_F 5
#define LOCK_F 6
#define UNLOCK_F 7
#define CLOSE_F 8
#define REMOVE_F 9

typedef struct _file{
    char* path;
    int size;
    void * cont; //contenuto del file 

    struct File_t * prev;
    struct File_t * next;

    pthread_mutex_t f_mutex; //accesso in mutua esclusione alle variabili condivise
    pthread_mutex_t f_order; //utilizzata per regolare l'accesso fair
    pthread_cond_t f_go;    //sospensione sia dei lettori che degli scrittori
    int f_activeReaders;
    int f_activeWriters;
    int f_queueSize;
}File_t;

typedef struct _fs{
    int numberOfFile;
    int maxSize;
    int maxNumFile;
    pthread_mutex_t fs_lock;
    pthread_cond_t fs_cond; // qualsiasi operazione che modifica 

    File_t * firstFile;
    File_t * lastFile;

}Filesystem_t;


int fs_request_manager(int clientFd, int requestType);





#endif /* _FILESYSTEM_H */