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

//DAC pLS-RESOLFT SCAN
extern uint8_t onLaserTTLChan;
extern uint8_t offLaserTTLChan;
extern uint8_t roLaserTTLChan;
extern uint8_t galvoXDACChan;
extern uint8_t stageXDACChan;

extern uint16_t onPulseTimeUs;
extern uint16_t delayAfterOnUs;
extern uint16_t offPulseTimeUs;
extern uint16_t delayAfterOffUs;
extern uint16_t delayAfterDACStepUs;
extern uint16_t roPulseTimeUs;
extern float roRestingV;
extern float roStartV;
extern float roStepSizeV;
extern uint16_t roSteps;
extern float cycleStartV;
extern float cycleStepSizeV;
extern uint16_t cycleSteps;

//PIXEL CYCLE PARAMETERS, CURRENTLY FOR UP TO 3 PULSES
extern uint16_t sequenceTimeUs;
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
