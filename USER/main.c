#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "action.h"//各种机器人动作函数
#include "tcer.h"//四个脚步寻迹，两个上侧光电传感器引脚定义
#include "UltrasonicWave.h"
#include "stm32f10x_exti.h"
 int z=0;
 int x=0;
 int main(void)
{	  
	 int i=0,j=0,k=0,js=0,w=0,g=0,h=0;//标志位

	 delay_init();
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  	uart_init(9600);         //串口初始化
	 Tcer_Init();
  UltrasonicWave_Configuration(); 
	 TIM3_PWM_Init(19999,71);	 //不分频。PWM频率=72000000/900=80Khz
	 Timer4_Init(5000,7199);   //10Khz的计数频率，计数到5000为500ms ,超声波
	 lizheng1();//上电先立正，然后再执行while循环
	 delay_ms(1000);
   EXTI->IMR&=~(EXTI_Line15);//屏蔽外部中断
	 while(1)
	 {
		while(i==0)
		{
		go();
		if(j==0)
		{	
			go();
			go();
			j++;
		}
		while(tcer2==0||tcer9==0)
		{
			if(tcer2==1&&tcer9==0)
			{
				   right1();
			}
			else{	
						right2();
					}
			while(tcer10==0)
				{
				houtui();
				houtui();
				right2();
				right2();
				right2();
				}
			go();
		}
		if((tcer2||tcer1==1)&&(tcer4==0))
		{
			
				left1();
			if(tcer9==1)
				{
					left1();
//					left1();
				}
			
		}
		
			while(tcer1==1&&tcer2==1&&tcer3==1&&tcer4==1)
			{
//			if(g==0)//只执行一次，进入动作区域先前进一步
//			{
//				go();
//				g++;
//			}
//		if(tcer8==0)
//		{
//		right2();
//		}
		 EXTI->IMR|=EXTI_Line15;//使能外部中断
		 UltrasonicWave_StartMeasure();//超声波开始检测
			//执行完后依旧左偏
			if(tcer10==1)//防止翻跟头后撞墙
			{
//   	 EXTI_InitStruct->EXTI_LineCmd=DISABLE;
		  EXTI->IMR&=~(EXTI_Line15);//屏蔽外部中断
			right();//右偏矫正，矫正后还是左偏的多
			delay_ms(1000);
			z++;//超声波中断触发全局变量，z==1不触发
			lizheng2();
			lizheng1();
			delay_ms(1000);
			overturn();
			delay_ms(1000);
		  delay_ms(500);
				
			z--;
			if(tcer10==1)
					{	
					go();
					}
			}
			i++;		
			}
			if(tcer1==0&&tcer2==0&&tcer3==0&&tcer4==0&&tcer9==0&&i!=0)
				{
					go();
					left2();
					i++;
				}	
		for(h=0;(tcer9==1&&tcer4==0&&i!=0)&&h<10;h++)//h为步数，翻跟头后前移十步，看是否贴近右侧，贴近即改变方向
		{
			left1();
			if(tcer2==1)
				left();
		}
	
//			if(tcer1==0&&tcer3==0&&tcer4==0)
//				{
//					i++;
//				}
				
		}
		go();

		if(tcer7==0)
		{
			houtui();
			houtui();
			houtui();
			houtui();
			houtui();
			w++;
			jiaozheng();
			left2();
		}
		if(tcer3==1||tcer4==1)
		{
		delay_ms(100);
		if(tcer3==1||tcer4==1)
			{
				while(1)
				{
					w++;
					if(js<20)
					{
					xunji1(js);
					}
					xunji(k);
				if(tcer1==0&&tcer2==0&&tcer3==0&&tcer4==0&&tcer7==1&&k!=0)
					{
						js=0;
						break;
					}
				}
			}
		}
	 }

}
		  
	   
