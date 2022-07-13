#include <stdint.h>
#include <Arduino.h>
#include "parameters.h"

//GLOBAL PARAMETER INITIALIZATION

//DAC RASTER SCAN
uint8_t dimOneChan = 0;
float dimOneStartV = 0; //In volts
float dimOneLenV = 0;
float dimOneStepSizeV = 0;
uint8_t dimTwoChan = 0;
float dimTwoStartV = 0;
float dimTwoLenV = 0;
float dimTwoStepSizeV = 0;
uint8_t dimThreeChan = 0;
float dimThreeStartV = 0;
float dimThreeLenV = 0;
float dimThreeStepSizeV = 0;
uint8_t dimFourChan = 0;
float dimFourStartV = 0;
float dimFourLenV = 0;
float dimFourStepSizeV = 0;
uint16_t settlingTimeUs = 0;
uint16_t dwellTimeUs = 0;
float angleRad = 0;
elapsedMicros usSinceReset;

//PIXEL CYCLE PARAMETERS, CURRENTLY FOR UP TO 3 PULSES
uint8_t p1Line = 0;
uint16_t p1StartUs = 0;
uint16_t p1EndUs = 0;
uint8_t p2Line = 0;
uint16_t p2StartUs = 0;
uint16_t p2EndUs = 0;
uint8_t p3Line = 0;
uint16_t p3StartUs = 0;
uint16_t p3EndUs = 0;
elapsedMicros sincePixelCycleStart;

void readParameter(String & inputString) {
  String out = "Running read parameter function\n";
  Serial.print(out);
  //Function to read paramter sent on form "PARAMETER,pName,pType,pValue\n"
  byte charPos = 10;
  String pName = "";
  while (inputString[charPos] != ',' && inputString[charPos] != '\n' )
  {
    while (inputString[charPos] == ' ') {
      charPos++;
    }//Skip white spaces
    pName += (char)inputString[charPos];
    charPos++;
  }

  //Skip commma
  charPos++;
  String pValue = "";
  while (inputString[charPos] != ',' && inputString[charPos] != '\n' )
  {
    while (inputString[charPos] == ' ') {
      charPos++;
    }//Skip white spaces
    pValue += (char)inputString[charPos];
    charPos++;
  }
  out = "Recieved pName: " + pName + ", pValue: " + pValue + "\n";
  Serial.print(out);
  setParameter(pName, pValue);//Send extracted strings to setParameter function
}

void setParameter(String pName, String pValue)
{
  String runStr = "Running setParameter function\n";
  Serial.print(runStr);
  if (pName == "dimOneChan") {
    dimOneChan = pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)dimOneChan + "\n";
    Serial.print(out);
  }
  if (pName == "dimOneStartV") {
    dimOneStartV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimOneStartV + "\n";
    Serial.print(out);
  }
  if (pName == "dimOneLenV") {
    dimOneLenV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimOneLenV + "\n";
    Serial.print(out);
  }
  if (pName == "dimOneStepSizeV") {
    dimOneStepSizeV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimOneStepSizeV + "\n";
    Serial.print(out);
  }
  if (pName == "dimTwoChan") {
    dimTwoChan = pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)dimTwoChan + "\n";
    Serial.print(out);
  }
  if (pName == "dimTwoStartV") {
    dimTwoStartV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimTwoStartV + "\n";
    Serial.print(out);
  }
  if (pName == "dimTwoLenV") {
    dimTwoLenV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimTwoLenV + "\n";
    Serial.print(out);
  }
  if (pName == "dimTwoStepSizeV") {
    dimTwoStepSizeV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimTwoStepSizeV + "\n";
    Serial.print(out);
  }
  if (pName == "dimThreeChan") {
    dimThreeChan = pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)dimThreeChan + "\n";
    Serial.print(out);
  }
  if (pName == "dimThreeStartV") {
    dimThreeStartV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimThreeStartV + "\n";
    Serial.print(out);
  }
  if (pName == "dimThreeLenV") {
    dimThreeLenV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimThreeLenV + "\n";
    Serial.print(out);
  }
  if (pName == "dimThreeStepSizeV") {
    dimThreeStepSizeV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimThreeStepSizeV + "\n";
    Serial.print(out);
  }
  if (pName == "dimFourChan") {
    dimFourChan = pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)dimThreeChan + "\n";
    Serial.print(out);
  }
  if (pName == "dimFourStartV") {
    dimFourStartV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimThreeStartV + "\n";
    Serial.print(out);
  }
  if (pName == "dimFourLenV") {
    dimFourLenV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimThreeLenV + "\n";
    Serial.print(out);
  }
  if (pName == "dimFourStepSizeV") {
    dimFourStepSizeV = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)dimThreeStepSizeV + "\n";
    Serial.print(out);
  }
  if (pName == "settlingTimeUs") {
    settlingTimeUs = pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)settlingTimeUs + "\n";
    Serial.print(out);
  }
  if (pName == "dwellTimeUs") {
    dwellTimeUs = pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)dwellTimeUs + "\n";
    Serial.print(out);
  }
  if (pName == "angleRad") {
    angleRad = pValue.toFloat();
    String out = "Parameter " + pName + " set to " + (String)angleRad + "\n";
    Serial.print(out);
  }
  if (pName == "p1Line") {
    p1Line = pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p1Line + "\n";
    Serial.print(out);
  }
  if (pName == "p1StartUs") {
    p1StartUs = (uint16_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p1StartUs + "\n";
    Serial.print(out);
  }
  if (pName == "p1EndUs") {
    p1EndUs = (uint16_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p1EndUs + "\n";
    Serial.print(out);
  }
  if (pName == "p2Line") {
    p2Line = (uint8_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p2Line + "\n";
    Serial.print(out);
  }
  if (pName == "p2StartUs") {
    p2StartUs = (uint16_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p2StartUs + "\n";
    Serial.print(out);
  }
  if (pName == "p2EndUs") {
    p2EndUs = (uint16_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p2EndUs + "\n";
    Serial.print(out);
  }
  if (pName == "p3Line") {
    p3Line = (uint8_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p3Line + "\n";
    Serial.print(out);
  }
  if (pName == "p3StartUs") {
    p3StartUs = (uint16_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p3StartUs + "\n";
    Serial.print(out);
  }
  if (pName == "p3EndUs") {
    p3EndUs = (uint16_t)pValue.toInt();
    String out = "Parameter " + pName + " set to " + (String)p3EndUs + "\n";
    Serial.print(out);
  }
}
