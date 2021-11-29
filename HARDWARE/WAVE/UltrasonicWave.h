#ifndef __UltrasonicWave_H
#define	__UltrasonicWave_H

void UltrasonicWave_Configuration(void);               //对超声波模块初始化
void UltrasonicWave_StartMeasure(void);                //开始测距，发送一个>10us的脉冲，然后测量返回的高电平时间

#endif /* __UltrasonicWave_H */

#define tcer8 PBin(6)//超声波 ，PB6接TRIG
#define tcer6 PAin(15)//超声波，PA15接ECH0



