#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "timer.h"
 
/************************************************
 ALIENTEKս��STM32������ʵ��9
 PWM���ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

	
 int main(void)
 {		
 	LED_Init();			     //LED�˿ڳ�ʼ��
 	TIM4_PWM_Init(700-1,72);	 //����Ƶ��PWMƵ��=72000000/900=80Khz
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
 
