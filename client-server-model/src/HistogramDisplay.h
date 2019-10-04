#if !defined(_HISTOGRAMDISPLAY_H)
#define _HISTOGRAMDISPLAY_H
#include <stdio.h>
#include "ECGPkg.h"

/* class HistogramDisplay */
typedef struct HistogramDisplay HistogramDisplay;
struct HistogramDisplay {
    int index;
    struct TMDQueue *itsTMDQueue;
};

/* Constructors and Destructors */
void HistogramDisplay_Init(HistogramDisplay *const me);
void HistogramDisplay_Cleanup(HistogramDisplay *const me);

/* Operations */
void HistogramDisplay_getValue(HistogramDisplay *const me);
void HistogramDisplay_updateHistogram(HistogramDisplay *const me);

struct TMDQueue *HistogramDisplay_getItsTMDQueue(const HistogramDisplay *const me);
void HistogramDisplay_setItsTMDQueue(HistogramDisplay *const me, struct TMDQueue *p_TMDQueue);

HistogramDisplay *HistogramDisplay_Create(void);
void HistogramDisplay_Destort(HistogramDisplay *const me);

#endif // _HISTOGRAMDISPLAY_H
