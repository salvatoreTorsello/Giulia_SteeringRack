/* This file is generated by BUSMASTER */
/* VERSION [1.2] */
/* BUSMASTER VERSION [3.2.2] */
/* PROTOCOL [CAN] */

/* Start BUSMASTER include header */
#include <Windows.h>
#include <CANIncludes.h>
/* End BUSMASTER include header */


/* Start BUSMASTER global variable */
#define WHEEL_SPEED_VALUE 50        // Wheel speed value in kmh
#define WHEEL_SENSOR_FAIL_STATUS 0  // 0 = No Fail present, 1 = Fail present
#define WHEEL_SENSOR_SPIN 1         // 0 = Standstill, 1 = Forward, 2 = Backwards
#define WHEEL_PULSE_VALUE 0         // Pulse value for wheel speed sensors

int Wheel_Speed_msg_counter = 0;
int Wheel_Info_msg_counter = 0;
unsigned char Wheel_Speed_msg_CRC = 0;
unsigned char Wheel_Info_msg_CRC = 0;
uint8_t crcTable[256] = {0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53, 0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB,
                            0xCD, 0xD0, 0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E, 0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76,
                            0x87, 0x9A, 0xBD, 0xA0, 0xF3, 0xEE, 0xC9, 0xD4, 0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C,
                            0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19, 0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1,
                            0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40, 0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8,
                            0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D, 0x36, 0x2B, 0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65,
                            0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7, 0x7C, 0x61, 0x46, 0x5B, 0x08, 0x15, 0x32, 0x2F,
                            0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A, 0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2,
                            0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75, 0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D,
                            0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8, 0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50,
                            0xA1, 0xBC, 0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2, 0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A,
                            0x6C, 0x71, 0x56, 0x4B, 0x18, 0x05, 0x22, 0x3F, 0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7,
                            0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66, 0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E,
                            0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB, 0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43,
                            0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1, 0x5A, 0x47, 0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09,
                            0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C, 0x97, 0x8A, 0xAD, 0xB0, 0xE3, 0xFE, 0xD9, 0xC4};
/* End BUSMASTER global variable */


/* Start BUSMASTER Function Prototype  */
GCC_EXTERN void GCC_EXPORT OnTimer_Send_WHEEL_SPEED_10( );
GCC_EXTERN void GCC_EXPORT OnTimer_Send_WHEEL_INFO_10( );

unsigned char Utils_CalcCRC(uint8_t * buf, uint8_t len);
/* End BUSMASTER Function Prototype  */


/* Start BUSMASTER Function Wrapper Prototype  */


/* End BUSMASTER Function Wrapper Prototype  */


/* Start BUSMASTER generated function - OnTimer_Send_WHEEL_SPEED_10 */
void OnTimer_Send_WHEEL_SPEED_10( )
{
/* TODO */		//Test message with Wheel Speed data to EPS system
    WHEEL_SPEED Wheel_Speed_msg;
    Wheel_Speed_msg.LHFWheelSpeed = WHEEL_SPEED_VALUE;
    Wheel_Speed_msg.LHRWheelSpeed = WHEEL_SPEED_VALUE;
    Wheel_Speed_msg.RHFWheelSpeed = WHEEL_SPEED_VALUE;
    Wheel_Speed_msg.RHRWheelSpeed = WHEEL_SPEED_VALUE;
    Wheel_Speed_msg.MessageCounter_WS = Wheel_Speed_msg_counter;
    Wheel_Speed_msg_CRC = Utils_CalcCRC(Wheel_Speed_msg.data,7);
    Wheel_Speed_msg.CRC_WS = Wheel_Speed_msg_CRC;
    Wheel_Speed_msg.cluster = 2;

    SendMsg(Wheel_Speed_msg);
    if (Wheel_Speed_msg_counter == 15) 
    {
        Wheel_Speed_msg_counter = 0;  
    }else{
        Wheel_Speed_msg_counter++;
    }        
}/* End BUSMASTER generated function - OnTimer_Send_WHEEL_SPEED_10 */


/* Start BUSMASTER generated function - OnTimer_Send_WHEEL_INFO_10 */
void OnTimer_Send_WHEEL_INFO_10( )
{
/* TODO */
    WHEEL_INFO Wheel_Info_msg;
    Wheel_Info_msg.LHF_WheelSensorFailSts = WHEEL_SENSOR_FAIL_STATUS;
    Wheel_Info_msg.LHR_WheelSensorFailSts = WHEEL_SENSOR_FAIL_STATUS;
    Wheel_Info_msg.RHF_WheelSensorFailSts = WHEEL_SENSOR_FAIL_STATUS;
    Wheel_Info_msg.RHR_WheelSensorFailSts = WHEEL_SENSOR_FAIL_STATUS;
    Wheel_Info_msg.LHF_Spin = WHEEL_SENSOR_SPIN;
    Wheel_Info_msg.LHR_Spin = WHEEL_SENSOR_SPIN;
    Wheel_Info_msg.RHF_Spin = WHEEL_SENSOR_SPIN;
    Wheel_Info_msg.RHR_Spin = WHEEL_SENSOR_SPIN;
    Wheel_Info_msg.LHF_FastPulseCounter = WHEEL_PULSE_VALUE;
    Wheel_Info_msg.LHR_FastPulseCounter = WHEEL_PULSE_VALUE;
    Wheel_Info_msg.RHF_FastPulseCounter = WHEEL_PULSE_VALUE;
    Wheel_Info_msg.RHR_FastPulseCounter = WHEEL_PULSE_VALUE;
    Wheel_Info_msg.MessageCounter_WI = Wheel_Info_msg_counter;
    Wheel_Info_msg_CRC = Utils_CalcCRC(Wheel_Info_msg.data,7);
    Wheel_Info_msg.CRC_WI = Wheel_Info_msg_CRC;
    Wheel_Info_msg.cluster = 2;

    SendMsg(Wheel_Info_msg);
    if (Wheel_Info_msg_counter == 15) 
    {
        Wheel_Info_msg_counter = 0;  
    }else{
        Wheel_Info_msg_counter++;
    }
}/* End BUSMASTER generated function - OnTimer_Send_WHEEL_INFO_10 */


/* Start BUSMASTER generated function - Utils_CalcCRC */
unsigned char Utils_CalcCRC(uint8_t * buf, uint8_t len)
{
/* TODO */
    const uint8_t * ptr = buf;
            uint8_t _crc = 0xFF;

            while(len--) _crc = crcTable[_crc ^ *ptr++];

            return ~_crc;
}/* End BUSMASTER generated function - Utils_CalcCRC */
