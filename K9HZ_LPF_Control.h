#ifndef K9HZ_LPF_CONTROL_h
#define K9HZ_LPF_CONTROL_h

#include <Adafruit_MCP23X17.h> 
#include "AD7991.h"

#define K9HZ_LPF_ADDR 0x25

extern Adafruit_MCP23X17 mcpLPF; // connected to Wire2
extern AD7991 swrADC; // on K9HZ LPF board
extern uint8_t LPF_GPB_state;
extern uint8_t LPF_GPA_state;

// The LPF band control definitions

// Register A pin mapping:
// Bit    Description     Default
// GPA0   TX BPF          0 (BPF in path)
// GPA1   RX BPF          0 (BPF in path)
// GPA2-GPA7   Not used
#define LPF_STARTUP_STATE_A 0x00

// Register B pin mapping:
// Bit    Description     Default
// GPB0   Band BIT0       1
// GPB1   Band BIT1       1
// GPB2   Band BIT2       1
// GPB3   Band BIT3       1
// GPB4   Antenna BIT0    0
// GPB5   Antenna BIT1    0
// GPB6   XVTR_SEL        1 (1 means no XVTR)
// GPB7   100W_PA_SEL     0 (0 means no 100W)
#define LPF_STARTUP_STATE_B 0b01001111

void K9HZLPFControlInit();
void setLPFBand(int currentBand);

#endif // K9HZ_LPF_CONTROL_h