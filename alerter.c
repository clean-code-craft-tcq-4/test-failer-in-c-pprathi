#include <stdio.h>
#include <assert.h>
#include "alerter.h"

int alertFailureCount = 0;

int networkAlert(float celcius) {
int returnCode = 200;
#ifdef USE_STUB_ENABLE
	returnCode = networkAlertStub(celcius);
#else
	if(celcius > THRESHOLD_TEMP){
		returnCode = 500;
	}
#endif
	return returnCode;
}

int networkAlertStub(float celcius) {
	int returnCode = 200;
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    if(celcius > THRESHOLD_TEMP){
    		returnCode = 500;
    	}
    else{
    	returnCode = 200;
    }
    return returnCode;
}

int alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // let us keep a count of failures to report
        alertFailureCount += 1;
    }
    return alertFailureCount;
}

int main(void) {
    assert(alertFailureCount + 1 == alertInCelcius(400.5));
    assert(alertFailureCount == alertInCelcius(303.6));
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
