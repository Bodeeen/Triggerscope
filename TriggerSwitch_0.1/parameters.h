#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdint.h>
#include <Arduino.h>
//GLOBAL PARAMETER INITIALIZATION

//DAC RASTER SCAN
extern uint8_t dimOneChan;
extern float dimOneStartV; //In volts
extern float dimOneLenV;
extern float dimOneStepSizeV;
extern uint8_t dimTwoChan;
extern float dimTwoStartV;
extern float dimTwoLenV;
extern float dimTwoStepSizeV;
extern uint8_t dimThreeChan;
extern float dimThreeStartV;
extern float dimThreeLenV;
extern float dimThreeStepSizeV;
extern uint8_t dimFourChan;
extern float dimFourStartV;
extern float dimFourLenV;
extern float dimFourStepSizeV;
extern float angleRad;

//PIXEL CYCLE PARAMETERS, CURRENTLY FOR UP TO 3 PULSES
extern uint8_t p1Line;
extern uint16_t p1StartUs;
extern uint16_t p1EndUs;
extern uint8_t p2Line;
extern uint16_t p2StartUs;
extern uint16_t p2EndUs;
extern uint8_t p3Line;
extern uint16_t p3StartUs;
extern uint16_t p3EndUs;


//FUNCTIONS
void readParameter(String&);
void setParameter(String, String);

#endif
