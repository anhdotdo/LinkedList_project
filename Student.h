#ifndef _MYLIB_STUDENT_H_
#define _MYLIB_STUDENT_H_

#include<stdint.h>

#define MAX_NAME 40
#define MAX_ID 10

typedef struct{                 // user-defined data type
    uint8_t name[MAX_NAME]; 
    uint8_t id[MAX_ID];
    uint8_t age;
    uint8_t math_point;
}StudentType;

#endif /*_MYLIB_STUDENT_H_*/