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
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlert(celcius);
    if (returnCode != 200) {
        // let us keep a count of failures to report
        alertFailureCount += 0;
    }
}

int main(void) {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(alertFailureCount == 1);
    printf("All is well (maybe!)\n");
    return 0;
}
