#ifndef RFACTOR_H
#define RFACTOR_H

#include <pthread.h>

// Define the structure for rf2_udp_state_t
typedef struct {
    double x, y, z;
    double x_rot, y_rot, z_rot;
    pthread_t udp_thread;
    int run;
    int s;
    char *server;
    int sample;
} rf2_udp_state_t;

// Function prototypes
void *rf2_init(char *server, int sample);
int rf2_readnext(void *sstate, double *Faa, double *Oaa, int *valid);
void rf2_close(void *sstate);

#endif /* RFACTOR_H */
