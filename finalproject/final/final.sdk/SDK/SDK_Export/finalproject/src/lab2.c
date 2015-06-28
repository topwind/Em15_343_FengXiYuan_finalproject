#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"
  

//====================================================

int main (void) 
{

	//----------��������-------------//
	XGpio led , push; //2��GPIO  LED �� BUTTON
	int i ,j , psb_check;//psb_checkΪpush�ķ���ֵ
	const int BLINK_TIMES = 2;
	int n = -1;

    xil_printf("-- Start of the Program --\r\n");


	//��ʼ��GPIO �� �����������
	XGpio_Initialize(&led,XPAR_LED_DEVICE_ID);
	XGpio_SetDataDirection(&led,1,0x00000000);//led  0�����

	XGpio_Initialize(&push, XPAR_BUTTON_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xffffffff);//button 1������

    void wait_sec()//æ�Ⱥ���
    {
    	for (i=0; i<50000000; i++);
    	{
    	psb_check = XGpio_DiscreteRead(&push,1);
    	}

    }
	while (1)
	{
        //����button,�õ������ĸ���ť
		psb_check = XGpio_DiscreteRead(&push,1);//��ȡbtn����������
		if( psb_check==1 )
		{
		  xil_printf("= = = R-E-S-E-T = = =\r\n");
		  n = 0;
		  goto L0;
		}

		psb_check = 0;

L0:
        if(n==0)//��һ���̵������ڶ�������
        {
        	XGpio_DiscreteWrite(&led, 1, 0x21);
        	for (j = 0 ; j < 12 ;j++)
        	{
        		wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
        	}
        	n = n +6;
        }
        if(n==6)//��һ���̵���˸���ڶ�������
        {
           for(j=0;j<BLINK_TIMES;j++)
           {
        	wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
            XGpio_DiscreteWrite(&led, 1, 0x21);
        	wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
        	XGpio_DiscreteWrite(&led, 1, 0x20);
        	n++;
           }
        }
        if(n==8)//��һ��Ƶ���˸���ڶ�������
        {
           for(j=0;j<BLINK_TIMES;j++)
           {
            XGpio_DiscreteWrite(&led, 1, 0x22);
            wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
            XGpio_DiscreteWrite(&led, 1, 0x20);
            wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
            n++;
           }
        }
        if(n==10)//��һ���������ڶ����̵���
        {
        	XGpio_DiscreteWrite(&led, 1, 0xc);
        	for (j = 0 ; j < 12 ;j++)
        	{
        		wait_sec();
        		if( psb_check==1 )
        		{
        		  xil_printf("= = = R-E-S-E-T = = =\r\n");
        		  n = 0;
                  goto L0;
        		}
        		if( psb_check==2 )
        		{
        		  xil_printf("= = =  S-T-O-P  = = =\r\n");
        		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
        		  n = -1;
                  goto L0;
        	    }
        	}
        	n = n +6;
        }
        if(n==16)//��һ���������ڶ����̵���˸
        {
           for(j=0;j<BLINK_TIMES;j++)
           {
        	wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
            XGpio_DiscreteWrite(&led, 1, 0xc);
        	wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
        	XGpio_DiscreteWrite(&led, 1, 0x4);
        	n++;
           }
        }
        if(n==18)//��һ���������ڶ���Ƶ���˸
        {
           for(j=0;j<BLINK_TIMES;j++)
           {
         	wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
         	XGpio_DiscreteWrite(&led, 1, 0x14);
          	wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
        	XGpio_DiscreteWrite(&led, 1, 0x4);
        	wait_sec();
    		if( psb_check==1 )
    		{
    		  xil_printf("= = = R-E-S-E-T = = =\r\n");
    		  n = 0;
              goto L0;
    		}
    		if( psb_check==2 )
    		{
    		  xil_printf("= = =  S-T-O-P  = = =\r\n");
    		  XGpio_DiscreteWrite(&led, 1, 0x00000000);
    		  n = -1;
              goto L0;
    	    }
        	n++;
           }
        }
        if(n==20){n=0;}
	  }

}