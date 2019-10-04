#if !defined(_ARRYTHMIADETECTOR)
#define _ARRYTHMIADETECTOR

typedef struct ArrythmiaDetector ArrythmiaDetector;
struct ArrythmiaDetector {
    int pvcCount;
    int STSegmentHeight;
    int firstDegreeHeatBlock;
    int Two_one_heartBlock;
};

#endif // _ARRYTHMIADETECTOR
