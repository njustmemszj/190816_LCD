
#include <project.h>

/* Set the write buffer length to be 16 bites or 2 bytes */
#define RD_BUFFER_SIZE        (2u)


/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main function performs following functions:
*   1. Starts all used components.
*   2. Controls sequencing of ADC inputs.
*   3. Reads ADC converted data, puts this in a read buffer to be read by the
*       I2C Master.
*   4. Displays ADC converted data on Character LCD.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
//#include <reg51.h>
//#include <intrins.h>
//#include <at89x51.h>

//sbit LCD_RS=P1^0;//定义引脚
//sbit LCD_RW=P1^1;
//sbit LCD_E=P1^2;
//#define LCD_Data P2
#define Busy    0x80 //用于检测LCD状态字中的Busy标识
#define DELAY_LCD 10


void WriteDataLCD(unsigned char WDLCD);
void WriteCommandLCD(unsigned char WCLCD,char BuysC);
unsigned char ReadDataLCD(void);
unsigned char ReadStatusLCD(void);
void LCDInit(void);
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char  DData[]);
void Delay5Ms(void);
void Delay400Ms(void);


unsigned char  uctech[] = "ABCDEF";
//unsigned char  net[] = "It is Ok";

int main(void)
{
    char i=0;
 Delay400Ms(); //启动等待，等LCD讲入工作状态
 LCDInit(); //LCM初始化
 Delay5Ms(); //延时片刻(可不要)
    CyDelay(50);
//for (char i = 0;i<16;i++)
//{
//    CyDelay(5);
//    DisplayOneChar(i, 0, 0x31+i);
//    CyDelay(5);
//    
//}
//for (char i = 0;i<16;i++)
//{
//    DisplayOneChar(i, 1, 0x41+i);
//}
////DisplayOneChar(0, 1, 0x30);
//DisplayListChar(5,1,uctech);
 while(1)
{
    
    DisplayOneChar(0, 0, 0x31);
    CyDelay(500);
    LenRun_Write(~LenRun_Read());
//    i++;
//    if (i>=16)
//    {
//        i=0;
//    }

}
return 1;
//DB_Write(WDLCD);
//DB_Read();
//
//PinRS_Write();
//PinRW_Write();
//PinEn_Write();
}

//写数据
void WriteDataLCD(unsigned char WDLCD)
{
 ReadStatusLCD(); //检测忙

 DB_Write(WDLCD);

 PinRS_Write(1);
 PinRW_Write(0);
 PinEn_Write(0); //若晶振速度太高可以在这后加小的延时
 CyDelay(DELAY_LCD);
 PinEn_Write(0); //延时
 PinEn_Write(1);
}

//写指令
void WriteCommandLCD(unsigned char WCLCD,char BuysC) //BuysC为0时忽略忙检测
{
 if (BuysC) ReadStatusLCD(); //根据需要检测忙
 DB_Write(WCLCD);
 PinRS_Write(0);
 PinRW_Write(0); 
 PinEn_Write(0);
 CyDelay(DELAY_LCD);
 PinEn_Write(0);
 PinEn_Write(1); 
}

//读数据
unsigned char ReadDataLCD(void)
{
 PinRS_Write(1); 
 PinRW_Write(1);
 PinEn_Write(0);
 PinEn_Write(0);
 PinEn_Write(1);
 return(DB_Read());
}

//读状态
unsigned char ReadStatusLCD(void)
{
 DB_Write(0xFF); 
 PinRS_Write(0);
 PinRW_Write(1);
 PinEn_Write(0);
 PinEn_Write(0);
 PinEn_Write(1);
 while (DB_Read() & Busy); //检测忙信号
 return(DB_Read());
}

void LCDInit(void) //LCM初始化
{
 DB_Write(0x00);
 WriteCommandLCD(0x38,1); //三次显示模式设置，不检测忙信号
 Delay5Ms(); 
 WriteCommandLCD(0x38,1);
 Delay5Ms(); 
 WriteCommandLCD(0x38,1);
 Delay5Ms(); 

 WriteCommandLCD(0x38,1); //显示模式设置,开始要求每次检测忙信号 
 WriteCommandLCD(0x08,1); //关闭显示
 WriteCommandLCD(0x01,1); //显示清屏
 WriteCommandLCD(0x06,1); // 显示光标移动设置 
 WriteCommandLCD(0x0C,1); // 显示开及光标设置
}

//按指定位置显示一个字符
void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData)
{
 Y &= 0x1;
 X &= 0xF; //限制X不能大于15，Y不能大于1
 if (Y) X |= 0x40; //当要显示第二行时地址码+0x40;
 X |= 0x80; // 算出指令码
 WriteCommandLCD(X, 1); //这里不检测忙信号，发送地址码
 Delay5Ms(); 
 WriteDataLCD(DData);
}

//按指定位置显示一串字符
void DisplayListChar(unsigned char X, unsigned char Y, unsigned char  DData[])
{
 unsigned char ListLength;

  ListLength = 0;
 Y &= 0x1;
 X &= 0xF; //限制X不能大于15，Y不能大于1
 while (DData[ListLength]>=0x20) //若到达字串尾则退出
  {
   if (X <= 0xF) //X坐标应小于0xF
    {
     DisplayOneChar(X, Y, DData[ListLength]); //显示单个字符
     ListLength++;
     X++;
    }
  }
}

//5ms延时
void Delay5Ms(void)
{
 unsigned int TempCyc = 5552;
 while(TempCyc--);
}

//400ms延时
void Delay400Ms(void)
{
 unsigned char TempCycA = 5;
 unsigned int TempCycB;
 while(TempCycA--)
 {
  TempCycB=7269;
  while(TempCycB--);
 };
}