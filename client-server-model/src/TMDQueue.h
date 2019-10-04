#if !defined(_TMDQUEUE_H)
#define _TMDQUEUE_H

/* ## auto_generated */
#include <stdio.h>
#include "ECGPkg.h"
#include "TimeMarkedData.h"

/**
 * This queue is meant to operate as a "leaky" queue. In this queue, data are never removed perse,
 * but are instead overwritten when the buffer pointer wraps around. This allows for many clients
 * to read the same data from the queue.
  */
typedef struct TMDQueue TMDQueue;
struct TMDQueue {
    int head;
    int size;
    struct TimeMarkedData buffer[QUEUE_SIZE];
};

/* Constructors and Destructors */
void TMDQueue_Init(TMDQueue *const me);
void TMDQueue_Cleanup(TMDQueue *const me);

/* Operations */
int TMDQueue_getNextIndex(const TMDQueue *const me, int index);

void TMDQueue_insert(TMDQueue *const me, const struct TimeMarkedData tmd);

boolean TMDQueue_isEmpty(const TMDQueue *const me);

struct TimeMarkedData TMDQueue_remove(TMDQueue *const me, int index);

int TMDQueue_getBuffer(const TMDQueue *const me);

TMDQueue *TMDQueue_Create(void);
void TMDQueue_Destroy(TMDQueue *const me);


#endif // _TMDQUEUE_H
