#include "tcer.h"
void Tcer_Init()
{
	GPIO_InitTypeDef GPIO_InitStructureA;
	GPIO_InitTypeDef GPIO_InitStructureB;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE); 
	GPIO_InitStructureA.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructureA.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_1|GPIO_Pin_15|GPIO_Pin_12;
	GPIO_InitStructureA.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructureA);
//	GPIO_SetBits(GPIOA,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); 
	GPIO_InitStructureB.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructureB.GPIO_Pin=GPIO_Pin_8|GPIO_Pin_7|GPIO_Pin_6|GPIO_Pin_5|GPIO_Pin_4;
	GPIO_InitStructureB.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructureB);
}
