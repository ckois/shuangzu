#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "action.h"//���ֻ����˶�������
#include "tcer.h"//�ĸ��Ų�Ѱ���������ϲ��紫�������Ŷ���
#include "UltrasonicWave.h"
#include "stm32f10x_exti.h"
 int z=0;
 int x=0;
 int main(void)
{	  
	 int i=0,j=0,k=0,js=0,w=0,g=0,h=0;//��־λ

	 delay_init();
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  	uart_init(9600);         //���ڳ�ʼ��
	 Tcer_Init();
  UltrasonicWave_Configuration(); 
	 TIM3_PWM_Init(19999,71);	 //����Ƶ��PWMƵ��=72000000/900=80Khz
	 Timer4_Init(5000,7199);   //10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms ,������
	 lizheng1();//�ϵ���������Ȼ����ִ��whileѭ��
	 delay_ms(1000);
   EXTI->IMR&=~(EXTI_Line15);//�����ⲿ�ж�
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
//			if(g==0)//ִֻ��һ�Σ����붯��������ǰ��һ��
//			{
//				go();
//				g++;
//			}
//		if(tcer8==0)
//		{
//		right2();
//		}
		 EXTI->IMR|=EXTI_Line15;//ʹ���ⲿ�ж�
		 UltrasonicWave_StartMeasure();//��������ʼ���
			//ִ�����������ƫ
			if(tcer10==1)//��ֹ����ͷ��ײǽ
			{
//   	 EXTI_InitStruct->EXTI_LineCmd=DISABLE;
		  EXTI->IMR&=~(EXTI_Line15);//�����ⲿ�ж�
			right();//��ƫ����������������ƫ�Ķ�
			delay_ms(1000);
			z++;//�������жϴ���ȫ�ֱ�����z==1������
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
		for(h=0;(tcer9==1&&tcer4==0&&i!=0)&&h<10;h++)//hΪ����������ͷ��ǰ��ʮ�������Ƿ������Ҳ࣬�������ı䷽��
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
		  
	   
