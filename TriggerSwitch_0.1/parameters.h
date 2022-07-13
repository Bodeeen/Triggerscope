#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdint.h>
#include <Arduino.h>
//GLOBAL PARAMETER INITIALIZATION

//DAC RASTER SCAN
uint8_t dimOneChan;
float dimOneStartV; //In volts
float dimOneLenV;
float dimOneStepSizeV;
uint8_t dimTwoChan;
float dimTwoStartV;
float dimTwoLenV;
float dimTwoStepSizeV;
uint8_t dimThreeChan;
float dimThreeStartV;
float dimThreeLenV;
float dimThreeStepSizeV;
uint8_t dimFourChan;
float dimFourStartV;
float dimFourLenV;
float dimFourStepSizeV;
uint16_t settlingTimeUs;
uint16_t dwellTimeUs;
float angleRad;
elapsedMicros usSinceReset;

//PIXEL CYCLE PARAMETERS, CURRENTLY FOR UP TO 3 PULSES
uint8_t p1Line;
uint16_t p1StartUs;
uint16_t p1EndUs;
uint8_t p2Line;
uint16_t p2StartUs;
uint16_t p2EndUs;
uint8_t p3Line;
uint16_t p3StartUs;
uint16_t p3EndUs;
elapsedMicros sincePixelCycleStart;


//FUNCTIONS
void readParameter(String&);
void setParameter(String, String);

#endif
