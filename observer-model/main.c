#include <stdio.h>
#include "src/TestBuilder.h"

int main(int argc, char const *argv[])
{
    
    TestBuilder *p_TestBuilder;
    p_TestBuilder = TestBuilder_Create();

    /* subscribers */
    TMDQueue_subscribe(TestBuilder_getItsTMDQueue(p_TestBuilder), HistogramDisplay_update);

    // collect data
    ECG_Module_acquireValue(TestBuilder_getItsECG_Module(p_TestBuilder));

    printf("Done\n");

    TestBuilder_Destroy(p_TestBuilder);

    return 0;
}
