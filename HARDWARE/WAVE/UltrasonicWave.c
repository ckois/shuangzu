#include "UltrasonicWave.h"
#include "usart.h"
#include "timer.h"
#include "delay.h"
#include "stm32f10x.h"
#include "action.h"
#include "tcer.h"
#define	TRIG_PORT      GPIOB		//TRIG       
#define	ECHO_PORT      GPIOA		//ECHO 
#define	TRIG_PIN       GPIO_Pin_6   //TRIG       
#define	ECHO_PIN       GPIO_Pin_15	//ECHO   

float UltrasonicWave_Distance;      //������ľ���    
//extern int z;

/*
 * ��������UltrasonicWave_Configuration
 * ����  ��������ģ��ĳ�ʼ��
 * ����  ����
 * ���  ����	
 */
void UltrasonicWave_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;	
	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;
	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);	//�ر�jtag
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);
    
  GPIO_InitStructure.GPIO_Pin = TRIG_PIN;					 //PB6��TRIG
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		     //��Ϊ�������ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	         
  GPIO_Init(TRIG_PORT, &GPIO_InitStructure);	                 //��ʼ������GPIO 

  GPIO_InitStructure.GPIO_Pin = ECHO_PIN;				     //PA15��ECH0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;		 //��Ϊ����
  GPIO_Init(ECHO_PORT,&GPIO_InitStructure);						 //��ʼ��GPIOA
	
	 //GPIOA.15	  �ж����Լ��жϳ�ʼ������
 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource15);

 	 EXTI_InitStructure.EXTI_Line=EXTI_Line15;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		
			
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;					//�����ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
}


void EXTI15_10_IRQHandler(void)
{

	static double UltrasonicWave_Distance1;
	static int f=0;
	delay_us(10);		                      //��ʱ10us
//		if(z==0)
//	{
     if(EXTI_GetITStatus(EXTI_Line15) != RESET)
	{
			TIM_SetCounter(TIM4,0);
			TIM_Cmd(TIM4, ENABLE);                                             //����ʱ��
		
			while(GPIO_ReadInputDataBit(ECHO_PORT,ECHO_PIN));	                 //�ȴ��͵�ƽ

			TIM_Cmd(TIM4, DISABLE);			                                 //��ʱ��4ʧ��
			UltrasonicWave_Distance=TIM_GetCounter(TIM4)*5*34/200.0;									 //�������&&UltrasonicWave_Distance<150
		
	if(UltrasonicWave_Distance>0)
	{
		printf("distance:%f cm",UltrasonicWave_Distance);
		if(UltrasonicWave_Distance>450&&tcer10==1)
		{
//			go();
//			left1();
			f++;
		}
		if(350<UltrasonicWave_Distance<=450&&tcer10==1)
		{
			left1();
			right();
			f++;
		}
		else if(250<UltrasonicWave_Distance<=350&&tcer10==0)
		{
			houtui();
			houtui();
			right2();
			right2();
			right2();
			houtui();
			left1();
			f++;
		}
		else if(210<UltrasonicWave_Distance<=250&&tcer10==0)
		{
			houtui();
			houtui();
			houtui();
			right2();
			right2();
			right2();
			right2();
			houtui();
			left1();
			f++;
		}
		else if(UltrasonicWave_Distance<210)
		{
			houtui();
			houtui();
			houtui();
			houtui();
	  	right2();
			right2();
			right2();
			houtui();
			left1();
			f++;

		}
		if(f%5==0)
		{
	  	UltrasonicWave_Distance1=UltrasonicWave_Distance;
		}
		if(-10<UltrasonicWave_Distance1-UltrasonicWave_Distance<10)
		{
		go();
		}
	}
	
	
	
	EXTI_ClearITPendingBit(EXTI_Line15);  //���EXTI15��·����λ
}
//}
}

/*
 * ��������UltrasonicWave_StartMeasure
 * ����  ����ʼ��࣬����һ��>10us�����壬Ȼ��������صĸߵ�ƽʱ��
 * ����  ����
 * ���  ����	
 */
void UltrasonicWave_StartMeasure(void)
{
  GPIO_SetBits(TRIG_PORT,TRIG_PIN); 		  //��>10US�ĸߵ�ƽ�TRIG_PORT,TRIG_PIN��������define����
  delay_us(20);		                      //��ʱ20US
  GPIO_ResetBits(TRIG_PORT,TRIG_PIN);
	
}

/******************* (C) 1209 Lab *****END OF FILE************/
