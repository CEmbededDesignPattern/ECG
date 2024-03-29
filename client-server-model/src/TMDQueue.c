#include "TMDQueue.h"
#include <stdlib.h>

static void initRelatios(TMDQueue *const me)
{
    // int iter = 0;
    // while (iter < QUEUE_SIZE)
    // {
    //     TimeMarkedData_Init(&((me->buffer)[iter]));
    //     TimeMarkedData_setItsTMDQueue(&((me->buffer)[iter]), me);
    //     iter++;
    // }
    
}

static void cleanUpRelations(TMDQueue *const me)
{
    // int iter = 0;
    // while (iter < QUEUE_SIZE)
    // {
    //     TimeMarkedData_Cleanup(&((me->buffer)[iter]));
    //     iter++;
    // }
}

/* Constructors and Destructors */
void TMDQueue_Init(TMDQueue *const me)
{
    me->head = 0;
    me->size = 0;
    initRelatios(me);
}
void TMDQueue_Cleanup(TMDQueue *const me)
{
    cleanUpRelations(me);
}

/* Operations */
int TMDQueue_getNextIndex(const TMDQueue *const me, int index)
{
    /* this operation computes the next index from the first using modulo arithmetic */
    return (index + 1) % QUEUE_SIZE;
}

void TMDQueue_insert(TMDQueue *const me, const struct TimeMarkedData tmd)
{
    /**
     * note that because we never 'remove' data from this leaky queue, size only increases  
     * to the queue size and then stops increasing. Insertion always takes place at the head.
     * */
    printf("Inserting at:%d Data#:%d", me->head, tmd.timeInterval);
    me->buffer[me->head] = tmd;
    me->head = TMDQueue_getNextIndex(me, me->head);
    if (me->size < QUEUE_SIZE)
        ++me->size;
    printf(" Storing data value:%d\n", tmd.dataValue);
}

boolean TMDQueue_isEmpty(const TMDQueue *const me)
{
    return (boolean)(me->size == 0);
}

struct TimeMarkedData TMDQueue_remove(TMDQueue *const me, int index)
{
    TimeMarkedData tmd;
    tmd.timeInterval = -1; /* sentinel values */
    tmd.dataValue = -9999;

    if (!TMDQueue_isEmpty(me) && 
        (index >= 0) && (index < QUEUE_SIZE) && 
        (index < me->size))
    {
        tmd = me->buffer[index];
    }

    return tmd;
}

int TMDQueue_getBuffer(const TMDQueue *const me)
{
    int iter = 0;
    return iter;
}

TMDQueue *TMDQueue_Create(void)
{
    TMDQueue *me = (TMDQueue *)malloc(sizeof(TMDQueue));
    if (me != NULL)
    {
        TMDQueue_Init(me);
    }
    
    return me;
}
void TMDQueue_Destroy(TMDQueue *const me)
{
    if (me != NULL)
    {
        TMDQueue_Cleanup(me);
        free(me);
    }
}

