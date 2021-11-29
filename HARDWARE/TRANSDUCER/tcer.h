#ifndef __tcer_h
#define __tcer_h
#include "sys.h"
/*
当没加右边中间的传感器时的传感器排序
*/
#define tcer1 PAin(10)//zuo3
#define tcer2 PBin(4)//zuo4
#define tcer9 PBin(5)//you zhong
#define tcer3 PBin(8)//zuo2
#define tcer4 PAin(13)//zuo1


#define tcer5 PAin(9)//youshang

#define tcer7 PBin(7)//youahangqianmian

#define tcer10 PAin(12)//zuoshangqianmian
void Tcer_Init(void);
#endif




//更改。h文件引脚时，不要忘记。c文件中初始化引脚的更改




