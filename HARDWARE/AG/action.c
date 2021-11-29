#include "action.h"
#include "sys.h"
#include "delay.h"
#include "tcer.h"
int c=2,e=2,f=3,g=5;
   	 static int a=1500,b=1500;
		 
		 extern int z;
		 extern int x;
//调整机器人动作幅度只需调整各函数中b，a。。。。的加减速度，速度越快，幅度越大，动作越剧烈
//尽量不要更改a，b阈值和pwm值，不要更改初值
//go，翻跟头，后退动作已经调好，不要更改，只需调整寻迹函数，左拐右拐函数即可
//右拐已经调好


//在action.c文件中增加新函数后不要忘记在action.h文件中进行声明



//直走
void go()
{
	  delay_init();	    	 //延时函数初始化	  

		    while(b>1350)
	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(c);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(c);
		  b-=3;
	     }
		 delay_ms(100);
		  while(a>1200)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(c);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(c);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(c);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(c);
				a-=10;
			}
		    while(b<1650) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(c);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(c);
		        b+=3;
			}
			delay_ms(100);
             while(a<1800)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(c);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(c);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(c);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(c);
			    a+=10;
			}
			

	
}

void go1()
{
	delay_init();	    	 //延时函数初始化	  

		    while(b>1370)
	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(f);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(f);
		  b-=3;
	     }
		 delay_ms(100);
		  while(a>1300)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(f);
				a-=30;
			}
		    while(b<1630) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(f);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(f);
		        b+=3;
			}
			delay_ms(100);
             while(a<1700)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(f);
			    a+=30;
			}
			
}

//后退
void houtui()
{
	delay_init();	    	 //延时函数初始化	  

		    while(b>1380)
	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(f);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(f);
		  b-=3;
	     }
		 delay_ms(100);
		  while(a<1610)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(f);
			    a+=10;
			}
		    while(b<1620) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(f);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(f);
		        b+=3;
			}
			delay_ms(100);
			 while(a>1390)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(f);
				a-=10;
			}
            
			
}






//翻跟头，翻跟头前先立正2，否则翻不了

void overturn()
{
	  delay_init();	    	 //延时函数初始化	  
		 while(a>490&&b<2510)  
		 {
		  TIM_SetCompare1(TIM2,a);
		   delay_ms(g);
	      TIM_SetCompare2(TIM2,b);
		   delay_ms(g);
	      a-=10;
          b+=10;
		 }
		 delay_ms(2000);
		 a=1500;
		 b=1500;
		  while(a>500&&b<2500)  
		 {
		  TIM_SetCompare4(TIM2,a);
		   delay_ms(g);
		  TIM_SetCompare3(TIM2,b);
		   delay_ms(g);
	      a-=10;
          b+=10;
		 }
		 delay_ms(2000);
		 while(a<1510&&b>1490)  
		 {
		  TIM_SetCompare1(TIM2,a);
		   delay_ms(g);
	      TIM_SetCompare2(TIM2,b);
		   delay_ms(g);
	      a+=10;
          b-=10;
		 }
		 a=500;
		 b=2500;
		  delay_ms(2000);
		  while(a<1510&&b>1490)  
		 {
		  TIM_SetCompare4(TIM2,a);
		   delay_ms(g);
		  TIM_SetCompare3(TIM2,b);
		   delay_ms(g);
	      a+=10;
          b-=10;
		 }
		 delay_ms(2000);
		  while(a<2530&&b>490)  
		 {
		  TIM_SetCompare3(TIM2,b);
		   delay_ms(g);
		  TIM_SetCompare4(TIM2,a);
		   delay_ms(g);
	      a+=10;
          b-=10;
		 }
		 a=1500;
		 b=1500;
		  while(a<2510&&b>490)  
		 {
		  TIM_SetCompare1(TIM2,a);
		   delay_ms(g); 
	      TIM_SetCompare2(TIM2,b);
		   delay_ms(g);
	      a+=10;
          b-=10;
		 }
		 delay_ms(2000);
          while(a>1490&&b<1510)  
		 {
		  TIM_SetCompare4(TIM2,a);
		   delay_ms(g);
		  TIM_SetCompare3(TIM2,b);
		   delay_ms(g);
	      a-=10;
          b+=10;
		 } 
		 a=2500;
		 b=500;		 
	    while(a>1490&&b<1510)  
		 {
		  TIM_SetCompare1(TIM2,a);
		   delay_ms(g);
	      TIM_SetCompare2(TIM2,b);
		   delay_ms(g);
	      a-=10;
          b+=10;
		 } 
		 	
       
}



void right()//极小幅度右拐
{

      delay_init();
		    while(b>1400)
	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		  b-=1;
	     }
		 delay_ms(100);
		  while(a>1200)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
				a-=8;
			}
		    while(b<1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b+=1;
			}
			delay_ms(100);
             while(a<1500)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a+=8;
		 }
		 
	
}
void right1()//小幅度右拐，右长拐
{

      delay_init();
		    while(b>1400)
	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		  b-=1;
	     }
		 delay_ms(50);
		  while(a>1340)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
				a-=10;
			}
		    while(b<1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b+=1;
			}
			delay_ms(50);
             while(a<1500)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a+=10;
		 }
		 
	
}



void right2()//大幅度右拐
{

      delay_init();
		    while(b>1400)
	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		  b-=1;                              //增大数值可增大拐角
	     }
		 delay_ms(50);
		  while(a>1340)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
				a-=13;												//增大数值可增大拐角
			}
		    while(b<1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b+=1;										//增大数值可增大拐角
			}
			delay_ms(50);
             while(a<1500)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a+=13;													//增大数值可增大拐角
		 }
		 
	
}

void right3()//yuan right1
{

      delay_init();
		    while(b>1400)
	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		  b-=1;
	     }
		 delay_ms(50);
		  while(a>1340)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
				a-=10;
			}
		    while(b<1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b+=1;
			}
			delay_ms(50);
             while(a<1500)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a+=10;
		 }
		 
	
}
void left()//极小幅度左拐
{
	 delay_init();
	 
		    while(b<1600) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b+=1;
			}
			delay_ms(100);
             while(a<1800)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a+=5;
			}
			 while(b>1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b-=1;
			}
			delay_ms(100);
             while(a>1500)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a-=5;
			}delay_ms(50);
		 
	
}
void left1()//左长拐
{
	 delay_init();
	 
		    while(b<1600) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b+=1;
			}
			delay_ms(50);
             while(a<1660)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a+=10;
			}
			 while(b>1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b-=1;
			}
			delay_ms(50);
             while(a>1500)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a-=10;
			}
		 
	
}

void left2()//左矫正
{
	 delay_init();
	 
		    while(b<1600) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b+=1;
			}
			delay_ms(50);
             while(a<1660)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a+=10;
			}
			 while(b>1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(e);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(e);
		        b-=1;
			}
			delay_ms(50);
             while(a>1500)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(e);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(e);
			    a-=10;
			}
		 
	
}




void lizheng1()
{
	 delay_init();	
	 TIM_SetCompare1(TIM2,1500);
	 TIM_SetCompare2(TIM2,1500);
	 TIM_SetCompare3(TIM2,1500);
	 TIM_SetCompare4(TIM2,1500);
	 TIM_SetCompare1(TIM3,1500);
	 TIM_SetCompare2(TIM3,1500);
	 delay_ms(1000);
}
void lizheng2()
{
	delay_init();
	 while(a>1500) 
			{
				TIM_SetCompare2(TIM2,a);
				delay_ms(3);
			    TIM_SetCompare4(TIM2,a);
				delay_ms(3);
			    TIM_SetCompare1(TIM2,a);
				delay_ms(3);
			    TIM_SetCompare3(TIM2,a);
				delay_ms(3);
			    a-=5;
			}
			 while(b>1500) 
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(3);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(3);
		        b-=2;
			}
	
}

void guogan()
{
	delay_init();	    	 //延时函数初始化	  
//		    while(b>1370)
		    while(b>1370)

	     {
		  TIM_SetCompare1(TIM3,b);
				delay_ms(f);
	      TIM_SetCompare2(TIM3,b);
				delay_ms(f);
		  b-=3;
	     }
		 delay_ms(100);
//		  while(a>1300)
				while(a>1300)

			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(f);
				a-=50;
			}
//		    while(b<1630) 
			    while(b<1630)
			{
				TIM_SetCompare1(TIM3,b);
				delay_ms(f);
	            TIM_SetCompare2(TIM3,b);
				delay_ms(f);
		        b+=3;
			}
			delay_ms(100);
//       while(a<1700)
			while(a<1700)
			{
			 TIM_SetCompare2(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare4(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare1(TIM2,a);
				delay_ms(f);
			 TIM_SetCompare3(TIM2,a);
				delay_ms(f);
			    a+=50;
			}
			
}
void jiaozheng()
{
left2();
delay_ms(10);
left2();
delay_ms(10);
left2();
delay_ms(10);
}
void jiaozheng1()
{
	houtui();
	delay_ms(10);
	houtui();
	delay_ms(10);
	houtui();
	delay_ms(10);
	left2();
	delay_ms(10);
	left2();
	delay_ms(10);
	left2();
	delay_ms(10);
}


void xunji(int k)//引脚定义在tcer.h文件内
{         

//	            if(tcer3==0&&tcer4==1&&tcer6==1)
					
//					if(tcer3==1&&tcer4==0&&tcer5==0)
//				 {		 
//					 go();
//				 }
//				 if(tcer3==0&&tcer4==0&&tcer5==0)
//				 {  
//					go();
////					while(tcer3==0&&tcer4==0&&tcer5=0)
////					{
////					  left1();
////					} 			
//				 }
//				 else if(tcer3==1&&tcer4==1&&tcer6==1&&i<1)
if((tcer1==1||tcer2==1||tcer3==1||tcer4==1)&&tcer5==1)
			 {	
					 if(((tcer4==1&&tcer3==0)||(tcer1==1&&tcer2==0))&&tcer5==1)
					{			
					  right1();	
						{
							z--;
						 if(z<0)
							z=0;
					  }
					}
					 if(((tcer3==1)||(tcer1!=1&&tcer2!=1))&&tcer5==1)
					{				
					  right2();	
						{
							z--;
						 if(z<0)
							z=0;
					  }
					}
					if((((tcer4==1)&&(tcer3==1))||(tcer1==1||tcer2==1))&&tcer5==1)
					{	

					  right2();		
						delay_ms(10);
						{
							z--;
						 if(z<0)
							z=0;
					  }
					}
				 	if((((tcer4==0)&&(tcer3==0))||(tcer1!=1&&tcer2!=1))&&tcer5==1)
					{				
					
					  right1();		
						delay_ms(10);
						{
							z--;
						 if(z<0)
							z=0;
					  }
					}
					if(tcer1==1&&tcer2==1&&tcer3==1&&tcer4==1)
					{
//						guogan();
						go();
						k++;
						go();
						delay_ms(100);
						right2();
						right2();
						right2();
						right2();
						right2();
						right2();
						delay_ms(100);
						lizheng2();
						delay_ms(100);
						houtui();
						delay_ms(100);
						{
							z--;
						 if(z<0)
							z=0;
					  }
					}
				 if(tcer5==0)
				 {
				 left1();
				 }
               				 
				}
else if(tcer5==1)
	{	
		go();
		right();
		z++;
  }
else{
				go();
		}

	
	if(tcer7==0)
	{
	 jiaozheng1();	
	{	
			z--;
		 if(z<0)
			z=0;
  }
	}
	if(tcer1==0&&tcer2==0&&tcer3==0&&tcer4==0&&tcer5==1&&tcer7==1&&tcer9==0&&tcer10==1)
	{
	  z++;
	}
	if(z>5)//adjust 7(0 1 2 3 4 5 6) times
	{
	 xunji2();
	}
}


void xunji1(int js)
{    
static int i=0,a=0,b=0;	
	js++;
	if((tcer1==1||tcer2==1||tcer3==1||tcer4==1)&&tcer5==1)
			 {	a++;
   				 if(tcer4==1&&tcer3==1&&tcer5==1)
					{	
						if(a==1)
						{ 
							right2();
						}
						else 
						{
						 right();
						}
					}
					else if(((tcer4==1)&&(tcer3==0))&&tcer5==1)
					{	

					  right();
						i++;
						if(i>2)
							{
							go();
							}
						delay_ms(10);
					
					}
				
				 	else if((((tcer4==0)&&(tcer3==0))||(tcer1==0&&tcer2==0))&&tcer5==1)
					{		
						left2();
					  go();		
					}
					else 
					{
						right();
						go();
					}
					        				 
				}
	if(tcer1==0&&tcer2==0&&tcer3==0&&tcer4==0&&a!=0)//校正，防止撞柱子
	{	 while(tcer7==0||tcer10==0)
					{
						if(a!=0)
						{ 
							do{
									houtui();
									b=a;
								  a++;
						    }
							while(b==a);
						}
					 jiaozheng();	
					}
	}					
}


void xunji2()
{
  while(z>5)
	{
	  go();
		if(tcer1==1||(tcer2==1&&tcer9==1))
		{
		  x++;
		}
		while(x>0)
		{
		if(tcer1==1||tcer9==1)
		{
		left2();
		left2();
		left2();
		left2();
		}
		if(tcer1==1&&tcer2==1&&tcer3==1&&tcer4==1)
		{
			go();
		  left();
		}
		  go();
		while(tcer10==0)
		{
			right2();
			right2();
			go();
		}
		
		}
	}
}
