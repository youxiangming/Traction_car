#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
/************************************************
 ALIENTEK战舰STM32开发板实验9
 PWM输出实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

	
 int main(void)
 {		
 	LED_Init();			     //LED端口初始化
 	TIM4_PWM_Init(700-1,72);	 //不分频。PWM频率=72000000/900=80Khz
   	while(1)
	{
		
 		int a,b,c,d;
		a=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8);
		b=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_9);
		c=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_10);
		d=GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);
		if(a==0&&b==0&&c==0&&d==0)
			{
			TIM_SetCompare1(TIM4,700);	//in2
			TIM_SetCompare2(TIM4,300);	//in1
			TIM_SetCompare3(TIM4,700);   //in3
			TIM_SetCompare4(TIM4,300);//in4
		} 
			if(a==1&&b==0&&c==0&&d==0)
			{
			TIM_SetCompare1(TIM4,700);	//in2
			TIM_SetCompare2(TIM4,300);	//in1
			TIM_SetCompare3(TIM4,700);   //in3
			TIM_SetCompare4(TIM4,300);//in4
		} 
			if(a==0&&b==0&&c==1&&d==0){
			TIM_SetCompare1(TIM4,300);	//in2
			TIM_SetCompare2(TIM4,700);	//in1
			TIM_SetCompare3(TIM4,700);   //in3
			TIM_SetCompare4(TIM4,300);//in4
			
			}
			if(a==0&&b==0&&c==0&&d==1){
			TIM_SetCompare1(TIM4,350);	//in2
			TIM_SetCompare2(TIM4,700);	//in1
			TIM_SetCompare3(TIM4,700);   //in3
			TIM_SetCompare4(TIM4,350);//in4
			
			}
			if(a==1&&b==1&&c==1&&d==1){
			TIM_SetCompare1(TIM4,0);	//in2
			TIM_SetCompare2(TIM4,0);	//in1
			TIM_SetCompare3(TIM4,0);   //in3
			TIM_SetCompare4(TIM4,0);//in4
				
			}
			
		
			
		 
 }
}
 
