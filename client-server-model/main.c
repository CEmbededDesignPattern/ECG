#include <stdio.h>
#include "src/TestBuilder.h"

int main(int argc, char const *argv[])
{
    
    TestBuilder *p_TestBuilder;
    p_TestBuilder = TestBuilder_Create();

    // collect data
    ECG_Module_acquireValue(TestBuilder_getItsECG_Module(p_TestBuilder));
    ECG_Module_acquireValue(TestBuilder_getItsECG_Module(p_TestBuilder));
    ECG_Module_acquireValue(TestBuilder_getItsECG_Module(p_TestBuilder));
    ECG_Module_acquireValue(TestBuilder_getItsECG_Module(p_TestBuilder));
    ECG_Module_acquireValue(TestBuilder_getItsECG_Module(p_TestBuilder));

    HistogramDisplay_getValue(TestBuilder_getItsHistogramDisplay(p_TestBuilder));
    HistogramDisplay_getValue(TestBuilder_getItsHistogramDisplay(p_TestBuilder));
    HistogramDisplay_getValue(TestBuilder_getItsHistogramDisplay(p_TestBuilder));
    HistogramDisplay_getValue(TestBuilder_getItsHistogramDisplay(p_TestBuilder));
    HistogramDisplay_getValue(TestBuilder_getItsHistogramDisplay(p_TestBuilder));

    printf("Done\n");

    TestBuilder_Destroy(p_TestBuilder);

    return 0;
}
