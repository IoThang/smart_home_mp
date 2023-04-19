//#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
//#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
//#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
//#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
//#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
//#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
//#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
//#include <xc.h>
//#include <stdio.h>
//#include "lcd.h"
//#define _XTAL_FREQ 4000000
////unsigned char flag = 1;
//unsigned char i = 0;
//unsigned int j = 0;
//void blink()
//{
//    for(i = 0; i < 100; i++)
//    {
//        if(RC0 == 0) return;
//        PORTD = 0;
//        __delay_ms(1);
//    }
//    for(i = 0; i < 100; i++)
//    {
//        if(RC0 == 0) return;
//        PORTD = 0XFF;
//        __delay_ms(1);
//    }
//}
//void blink1()
//{
//        unsigned char temp = 0;
//        while(temp <= 255) //255 = 11111111
//        {
//            for(i = 0; i < 100; i++)
//            {
//                if(RC0 == 0) return;
//                PORTD = temp;
//                __delay_ms(1);
//            }
//            if(temp == 255) break;
//            temp = (temp << 1) + 0x01;
//        }
//}
//void blink2()
//{
//        unsigned char temp = 0b00000001;
//        while(temp <= 128)  //128 = 10000000
//        {
//            for(i = 0; i < 100; i++)
//            {
//                if(RC0 == 0) return;
//                PORTD = temp;
//                __delay_ms(1);
//            }
//            if(temp == 128) break;
//            temp = (temp << 1);
//        }
//        for(i = 0; i < 100; i++)
//        {
//            if(RC0 == 0) return;
//            PORTD = 0;
//            __delay_ms(1);
//        }
//}
//void blink3()
//{
//        unsigned char run, stop, y;
//        stop = 0;
//        for(unsigned char j = 0; j <= 7; j++)
//        {
//            run = 0b00000001;
//            for(unsigned char k = 0; k <= 7 - j; k++)
//            {
//                y = run | stop;
//                for(i = 0; i < 100; i++)
//                {
//                    if(RC0 == 0) return;
//                    PORTD = y;
//                    __delay_ms(1);
//                }
//                run = run << 1;
//            }
//            stop = y;
//        }
//}
//void main(void) {
//    unsigned char flag = 1;
//    TRISC = 1;
//    PORTB = 0;
//    TRISD = 0;
//    PORTD = 0;
//    PORTC = 0;
//    LCD_Initialize();
//    LCDGoto(0, 0);
//    LCDPutStr("LED:OFF        ");
//    LCDGoto(0, 1);
//    LCDPutStr("FAN:OFF");
//    while(1)  
//    {
//        if(RC0 == 0)
//        {
//            __delay_ms(500);
//            for(j = 0; j < 300; j++)
//            {
//                __delay_ms(1);
//                if(RC0 == 0) goto THANG;
//            }
//            if(RC0 == 0)
//            {
//                THANG:
//                PORTD = 0; RC7 = 0; flag = 1;
//                LCDGoto(0, 0);
//                LCDPutStr("LED:OFF       ");
//                LCDGoto(0, 1);
//                LCDPutStr("FAN:OFF");
//                __delay_ms(100);
//                while(RC0 == 1);
//            }
//            else
//            {
//                RC7 = 1;
//                while(RC0 == 0);
//                if((flag == 1) && (RC0 == 1)) //chop tat
//                {
//                    flag = 2;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 1");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(RC0 == 1)
//                        blink();    
//                }
//                else if((flag == 2) && (RC0 == 1)) //sang dan
//                {
//                    flag = 3;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 2");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(RC0 == 1)
//                        blink1();
//                }
//                else if((flag == 3) && (RC0 == 1)) //sang tat dan
//                {
//                    flag = 1;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 3");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(RC0 == 1)
//                        blink2();
//                }
//                else if((flag == 4) && (RC0 == 1))
//                {
//                    flag = 1;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 4");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(RC0 == 1)
//                        blink3();
//                }
//            }
//        }
//    }
//    return;
//}
//#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
//#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
//#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
//#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
//#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
//#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
//#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
//#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
//#include <xc.h>
//#include <stdio.h>
//#include "lcd.h"
//#define _XTAL_FREQ 4000000
////unsigned char flag = 1;
//unsigned char i = 0;
//unsigned int j = 0;
//unsigned int temp1 ;
//void blink()
//{
//    for(i = 0; i < 100; i++)
//    {
//        if(temp1 > 200) return;
//        PORTD = 0;
//        __delay_ms(1);
//    }
//    for(i = 0; i < 100; i++)
//    {
//        if(temp1 > 200) return;
//        PORTD = 0XFF;
//        __delay_ms(1);
//    }
//}
//void blink1()
//{
//        unsigned char temp = 0;
//        while(temp <= 255) //255 = 11111111
//        {
//            for(i = 0; i < 100; i++)
//            {
//                if(temp1 > 200) return;
//                PORTD = temp;
//                __delay_ms(1);
//            }
//            if(temp == 255) break;
//            temp = (temp << 1) + 0x01;
//        }
//}
//void blink2()
//{
//        unsigned char temp = 0b00000001;
//        while(temp <= 128)  //128 = 10000000
//        {
//            for(i = 0; i < 100; i++)
//            {
//                if(temp1 > 200) return;
//                PORTD = temp;
//                __delay_ms(1);
//            }
//            if(temp == 128) break;
//            temp = (temp << 1);
//        }
//        for(i = 0; i < 100; i++)
//        {
//            if(temp1 > 200) return;
//            PORTD = 0;
//            __delay_ms(1);
//        }
//}
//void blink3()
//{
//        unsigned char run, stop, y;
//        stop = 0;
//        for(unsigned char j = 0; j <= 7; j++)
//        {
//            run = 0b00000001;
//            for(unsigned char k = 0; k <= 7 - j; k++)
//            {
//                y = run | stop;
//                for(i = 0; i < 100; i++)
//                {
//                    if(temp1 > 200) return;
//                    PORTD = y;
//                    __delay_ms(1);
//                }
//                run = run << 1;
//            }
//            stop = y;
//        }
//}
//void ADCInit()
//{
//    /*ADCON0bits.ADCS = 0x00; ////Fosc/2 ADC
//    ADCON1bits.ADFM = 1; //Right justified
//    ADCON1bits.VCFG0 = 0;
//    ADCON1bits.VCFG1 = 0;*/
//    ADCON0 = 0b10000000;   // FOSC/64, AN0, GO_nDONE off, ADON off
//    ADCON1 = 0xC0;  // Right justified, Vss, Vdd
//    ADRESL = 0;
//    ADRESH = 0;
//}
//unsigned int get_val()
//{
//    ADCON0bits.ADON = 1; //ADC on (B?t ADC lên)
//    __delay_ms(10);
//    ADCON0bits.GO_nDONE = 1; //GO_nDONE on. Start to read ADC (B?t ch? ?? ??c ADC lên. ADC b?t ??u ??c)
//    __delay_ms(10);
//    while(ADCON0bits.GO_nDONE); //When ADC read completed(finish), GO_nDONE become '0' level and then get out of loop(while)
//    //(Ch? cho ??n khi ADC ??c hoàn t?t. S? ??a GO_nDONE = 0 và thoát kh?i vòng l?p)
//    return ((ADRESH<<8)+ADRESL); 
//    //??c hàm get_val ? d??i cùng ?? hi?u rõ
//} 
//void main(void) {
//    TRISA = 1;
//    unsigned char flag = 1;
//    TRISC = 1;
//    PORTB = 0;
//    TRISD = 0;
//    PORTD = 0;
//    PORTC = 0;
//    ADCInit();
//    LCD_Initialize();
//    LCDGoto(0, 0);
//    LCDPutStr("LED:OFF        ");
//    LCDGoto(0, 1);
//    LCDPutStr("FAN:OFF");
//    while(1)  
//    {
//        temp1 = get_val();
//        while(temp1 < 50)
//            temp1 = get_val();
//        if(temp1 > 50)
//        {
//            __delay_ms(500);
//            for(j = 0; j < 300; j++)
//            {
//                __delay_ms(1);
//                if(temp1 > 200) goto THANG;
//            }
//            if(temp1 > 200)
//            {
//                THANG:
//                PORTD = 0; RC7 = 0; flag = 1;
//                LCDGoto(0, 0);
//                LCDPutStr("LED:OFF       ");
//                LCDGoto(0, 1);
//                LCDPutStr("FAN:OFF");
//                __delay_ms(100);
//                while(temp1 < 50);
//            }
//            else
//            {
//                RC7 = 1;
//                while(temp1 > 50);
//                if((flag == 1) && (temp1 < 50)) //chop tat
//                {
//                    flag = 2;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 1");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(temp1 < 50)
//                        blink();    
//                }
//                else if((flag == 2) && (temp1 < 50)) //sang dan
//                {
//                    flag = 3;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 2");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(temp1 < 50)
//                        blink1();
//                }
//                else if((flag == 3) && (temp1 < 50)) //sang tat dan
//                {
//                    flag = 1;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 3");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(temp1 < 50)
//                        blink2();
//                }
//                else if((flag == 4) && (RC0 == 1))
//                {
//                    flag = 1;
//                    LCDGoto(0, 0);
//                    LCDPutStr("LED:ON-MODE 4");
//                    LCDGoto(0, 1);
//                    LCDPutStr("FAN:ON ");
//                    while(RC0 == 1)
//                        blink3();
//                }
//            }
//        }
////    }
//    return;
//}
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#include <xc.h>
#include <stdio.h>
#include "lcd.h"
#define _XTAL_FREQ 4000000
unsigned char chu[60] = {"                WELCOME TO SMART HOME BY 94                "};
//                        01234567890123456789012345678901234567890123456789012345678
unsigned char chu2[60] = {"                  GVHD:TS.VO XUAN TIEN                "};
//                         012345678901234567890123456789012345678901234567890123
unsigned char buffer[20];
unsigned char i = 0;
unsigned int j = 0;
//#define PK0 PORTDbits.RD0
//#define PK1 PORTDbits.RD1
//#define PK2 PORTDbits.RD2
//#define PK3 PORTDbits.RD3
//#define K1  PORTDbits.RD4
//#define K2  PORTDbits.RD5
//#define B1  PORTDbits.RD6
//#define B2  PORTDbits.RD7

//void blink()
//{
//    for(i = 0; i < 100; i++)
//    {
//        if(RC0 == 1) return;
//        PORTD = 0;
//        __delay_ms(1);
//    }
//    for(i = 0; i < 100; i++)
//    {
//        if(RC0 == 1) return;
//        PORTD = 0XFF;
//        __delay_ms(1);
//    }
//}
//void blink1()
//{
//        unsigned char temp = 0;
//        while(temp <= 255) //255 = 11111111
//        {
//            for(i = 0; i < 100; i++)
//            {
//                if(RC0 == 1) return;
//                PORTD = temp;
//                __delay_ms(1);
//            }
//            if(temp == 255) break;
//            temp = (temp << 1) + 0x01;
//        }
//}
//void blink2()
//{
//        unsigned char temp = 0b00000001;
//        while(temp <= 128)  //128 = 10000000
//        {
//            for(i = 0; i < 100; i++)
//            {
//                if(RC0 == 1) return;
//                PORTD = temp;
//                __delay_ms(1);
//            }
//            if(temp == 128) break;
//            temp = (temp << 1);
//        }
//        for(i = 0; i < 100; i++)
//        {
//            if(RC0 == 1) return;
//            PORTD = 0;
//            __delay_ms(1);
//        }
//}
//void blink3()
//{
//        unsigned char run, stop, y;
//        stop = 0;
//        for(unsigned char j = 0; j <= 7; j++)
//        {
//            run = 0b00000001;
//            for(unsigned char k = 0; k <= 7 - j; k++)
//            {
//                y = run | stop;
//                for(i = 0; i < 100; i++)
//                {
//                    if(RC0 == 1) return;
//                    PORTD = y;
//                    __delay_ms(1);
//                }
//                run = run << 1;
//            }
//            stop = y;
//        }
//}
unsigned char flag = 0;
void clap1(void)
{
    PORTD = 0b00111111;
}
void clap2(void)
{
    PORTD = 0b11001111;
}
void clap3(void)
{
    PORTD = 0b11000000;
}
void clap4(void)
{
    PORTD = 0b11111111;
}
void ngoaiduong1()
{
    PORTA = 0xFF;
}
void ngoaiduong2()
{
    for(i = 0; i < 100; i++)
    {
        if(RC0 == 1) return;
        PORTA = 0;
        __delay_ms(1);
    }
    for(i = 0; i < 100; i++)
    {
        if(RC0 == 1) return;
        PORTA = 0XFF;
        __delay_ms(1);
    }
}
void buzzer(unsigned char time)
{
    for(i = 0; i < time; i++)
    {
        RC2 = 1;
        __delay_ms(1);
    }
    RC2 = 0;

}
//void shiftLeft(void)
//{
//    while(1)
//    {
//        for(i = 0; i < 43; i++)  //43 = 59(tong cac ky tu) - 16(16 o trong lcd)
//        {
//            for(j = 0; j < 16; j++)
//            {
//                if(RC0 == 1)
//                {
//                    flag = 1;
//                    return;
//                }
//                LCDGoto(j, 0);
//                LCDPutChar(chu[i + j]);
//                if(i < 39)
//                {
//                    LCDGoto(j, 1);
//                    LCDPutChar(chu2[i + j]); 
//                }
//            }
//        }
//    }
//}
void main(void) {
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC7 = 0;
    RC2 = 0;
    RC7 = 0;
    TRISA = 0;
    PORTA = 0;
    TRISB = 0;
//    PORTB = 0;
    TRISD = 0;
    PORTD = 0;
    LCD_Initialize();
    LCDGoto(0, 0);
    LCDPutStr("SMART HOME BY 94");
    LCDGoto(0, 1);
    LCDPutStr("GV:VO XUAN TIEN");
    while(1)  
    {
        if(RC0 == 1)
        {
            __delay_ms(100);
            for(j = 0; j < 400; j++)
            {
                __delay_ms(1);
                if(RC0 == 1) goto THANG;
            }
            if(RC0 == 1)
            {
                THANG:
                PORTD = 0; PORTA = 0; RC7 = 0; flag = 1;
                buzzer(100);
                LCDGoto(0, 0);
                LCDPutStr("L1:OFF L2:OFF   ");
                LCDGoto(0, 1);
                LCDPutStr("L3:OFF FAN:OFF  ");
                __delay_ms(100);
                while(RC0 == 0);
            }
            else
            {
                while(RC0 == 1);
                if((flag == 1) && (RC0 == 0)) //chop tat
                {
                    buzzer(100);
                    flag = 2; RC7 = 0;
                    LCDGoto(0, 0);
                    LCDPutStr("L1:ON  L2:ON    ");
                    LCDGoto(0, 1);
                    LCDPutStr("L3:OFF FAN:OFF  ");
                    while(RC0 == 0)
                    {
                        clap1(); 
                        ngoaiduong1();
                    }
                           
                }
                else if((flag == 2) && (RC0 == 0)) //sang dan
                {
                    buzzer(100);
                    flag = 3; RC7 = 1;
                    LCDGoto(0, 0);
                    LCDPutStr("L1:ON  L2:OFF   ");
                    LCDGoto(0, 1);
                    LCDPutStr("L3:ON  FAN:ON   ");
                    while(RC0 == 0)
                    {
                        clap2();
                        ngoaiduong2();
                    }
                        
                }
                else if((flag == 3) && (RC0 == 0)) //sang tat dan
                {
                    buzzer(100);
                    flag = 4; RC7 = 1;
                    LCDGoto(0, 0);
                    LCDPutStr("L1:OFF L2:OFF   ");
                    LCDGoto(0, 1);
                    LCDPutStr("L3:ON  FAN:ON   ");
                    while(RC0 == 0)
                    {
                        clap3();
                        ngoaiduong1();
                    }
                        
                }
                else if((flag == 4) && (RC0 == 0))
                {
                    buzzer(100);
                    flag = 1; RC7 = 1;
                    LCDGoto(0, 0);
                    LCDPutStr("L1:ON  L2:ON    ");
                    LCDGoto(0, 1);
                    LCDPutStr("L3:ON  FAN:ON   ");
                    while(RC0 == 0)
                    {
                        clap4();
                        ngoaiduong2();
                    }
                    //CO SUA LAI LCD_DELAY    
                }
            }
        }
    }
    return;
}


//void clap1(void)
//{
//    PORTD = 0b00111111;
//}
//void clap2(void)
//{
//    PORTD = 0b11001111;
//}
//void clap3(void)
//{
//    PORTD = 0b11000000;
//}
//void clap4(void)
//{
//    PORTD = 0b11111111;
//}