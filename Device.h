#ifndef _MYLIB_DEVICE_H_
#define _MYLIB_DEVICE_H_

#include<stdint.h>

#define MAX_NAME 40

typedef struct{                 // user-defined data type
    uint8_t name[MAX_NAME];
    uint32_t power;
    uint32_t unit_price;
}DeviceType;

#endif /*_MYLIB_DEVICE_H_*/
