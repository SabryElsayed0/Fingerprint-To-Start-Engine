
/******************************************************************************
 *
 * Module: LCD

 *
 * Description: Source file of KEYPAD driver for AVR
 *
 *******************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_int.h"
#include "LCD.h"
GPIO_PinConfig LCD[10] =
{
		{.Port = LCD_PORT,.Pin  = D4 ,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_OUTPUT_SPEED_LOW,.OutputType = GPIO_OUTPUT_PUSH_PULL},
		{.Port = LCD_PORT,.Pin  = D5 ,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_OUTPUT_SPEED_LOW,.OutputType = GPIO_OUTPUT_PUSH_PULL},
		{.Port = LCD_PORT,.Pin  = D6 ,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,.OutputType = GPIO_OUTPUT_PUSH_PULL},
		{.Port = LCD_PORT,.Pin  = D7 ,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,.OutputType = GPIO_OUTPUT_PUSH_PULL},
		{.Port = LCD_PORT,.Pin  = RS ,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,.OutputType = GPIO_OUTPUT_PUSH_PULL},
		{.Port = LCD_PORT,.Pin  = EN ,.Mode = GPIO_MODE_OUTPUT,.OutputSpeed = GPIO_OUTPUT_SPEED_MEDIUM,.OutputType = GPIO_OUTPUT_PUSH_PULL},

};
/*****************************************************************************/
/*checking if we use 8 bit with LCD*/
#if LCD_MODE == _8_BIT

/*this function to transmit command to LCD*/
static void LCD_WriteCommand(u8 command)
{
	// to transmit command we should make pin0=0
	GPIO_voidSetPinValue(LCD_PORT , RS , GPIO_LOW);
	GPIO_voidSetPinValue(LCD_PORT,D7,GET_BIT(command,7));
	GPIO_voidSetPinValue(LCD_PORT,D6,GET_BIT(command,6));
	GPIO_voidSetPinValue(LCD_PORT,D5,GET_BIT(command,5));
	GPIO_voidSetPinValue(LCD_PORT,D4,GET_BIT(command,4));

	GPIO_voidSetPinValue(LCD_PORT,D3,GET_BIT(command,3));
	GPIO_voidSetPinValue(LCD_PORT,D2,GET_BIT(command,2));
	GPIO_voidSetPinValue(LCD_PORT,D1,GET_BIT(command,1));
	GPIO_voidSetPinValue(LCD_PORT,D0,GET_BIT(command,0));
	//trigger rising edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_HIGH);

	//trigger time between rising and falling
	MSTK_vSetBusyWait(1000);

	//trigger falling edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_LOW);
	MSTK_vSetBusyWait(1000);

}
/**************************************************************************/

/*****************************************************************************/
/*to transmit data to LCD */
static void LCD_WriteData(u8 data)
{
	GPIO_voidSetPinValue(LCD_PORT , RS , GPIO_HIGH);
	GPIO_voidSetPinValue(LCD_PORT,D7,GET_BIT(data,7));
	GPIO_voidSetPinValue(LCD_PORT,D6,GET_BIT(data,6));
	GPIO_voidSetPinValue(LCD_PORT,D5,GET_BIT(data,5));
	GPIO_voidSetPinValue(LCD_PORT,D4,GET_BIT(data,4));

	GPIO_voidSetPinValue(LCD_PORT,D3,GET_BIT(data,3));
	GPIO_voidSetPinValue(LCD_PORT,D2,GET_BIT(data,2));
	GPIO_voidSetPinValue(LCD_PORT,D1,GET_BIT(data,1));
	GPIO_voidSetPinValue(LCD_PORT,D0,GET_BIT(data,0));
	//trigger rising edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_HIGH);

	//trigger time between rising and falling
	MSTK_vSetBusyWait(1000);

	//trigger falling edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_LOW);
	MSTK_vSetBusyWait(1000);

}
/************************************************************************/

/**********************************************************************/
/*to initialize LCD */
void LCD_Init(void)
{
	MSTK_vSetBusyWait(50000);
	//2 line 5*7;
	LCD_WriteCommand(0x38);

	//cursor 0x0f, 0x0E ;
	LCD_WriteCommand(0x0c);

	//clear screen;
	LCD_WriteCommand(0x01);
	MSTK_vSetBusyWait(1000);

	//increase ddram address,no shift;
	LCD_WriteCommand(0x06);



}
/*******************************************************************/
///*checking if we use 8 bit with LCD*/
#elif LCD_MODE==_4_BIT

/*this function to transmit command to LCD*/
static void LCD_WriteCommand(u8 command)
{
	// to transmit command we should make pin0=0
	GPIO_voidSetPinValue(LCD_PORT , RS , GPIO_LOW);

	GPIO_voidSetPinValue(LCD_PORT,D7,GET_BIT(command,7));
	GPIO_voidSetPinValue(LCD_PORT,D6,GET_BIT(command,6));
	GPIO_voidSetPinValue(LCD_PORT,D5,GET_BIT(command,5));
	GPIO_voidSetPinValue(LCD_PORT,D4,GET_BIT(command,4));
	//trigger rising edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_HIGH);

	//trigger time between rising and falling

	MSTK_vSetBusyWait(1000);
	//trigger falling edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_LOW);
	MSTK_vSetBusyWait(1000);

	GPIO_voidSetPinValue(LCD_PORT,D7,GET_BIT(command,3));
	GPIO_voidSetPinValue(LCD_PORT,D6,GET_BIT(command,2));
	GPIO_voidSetPinValue(LCD_PORT,D5,GET_BIT(command,1));
	GPIO_voidSetPinValue(LCD_PORT,D4,GET_BIT(command,0));
	//trigger rising edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_HIGH);

	//trigger time between rising and falling
	MSTK_vSetBusyWait(1000);

	//trigger falling edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_LOW);
	MSTK_vSetBusyWait(1000);
}
/********************************************************************************/

/*******************************************************************************/
/*to transmit data to LCD */
static void LCD_WriteData(u8 data)
{
	// to transmit data we should make pin0=0
	GPIO_voidSetPinValue(LCD_PORT,RS,GPIO_HIGH);
	GPIO_voidSetPinValue(LCD_PORT,D7,GET_BIT(data,7));
	GPIO_voidSetPinValue(LCD_PORT,D6,GET_BIT(data,6));
	GPIO_voidSetPinValue(LCD_PORT,D5,GET_BIT(data,5));
	GPIO_voidSetPinValue(LCD_PORT,D4,GET_BIT(data,4));
	//trigger rising edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_HIGH);

	//trigger time between rising and falling
	MSTK_vSetBusyWait(1000);

	//trigger falling edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_LOW );

	MSTK_vSetBusyWait(1000);
	GPIO_voidSetPinValue(LCD_PORT,D7,GET_BIT(data,3));
	GPIO_voidSetPinValue(LCD_PORT,D6,GET_BIT(data,2));
	GPIO_voidSetPinValue(LCD_PORT,D5,GET_BIT(data,1));
	GPIO_voidSetPinValue(LCD_PORT,D4,GET_BIT(data,0));

	//trigger rising edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_HIGH);

	//trigger time between rising and falling
	MSTK_vSetBusyWait(1000);

	//trigger falling edge
	GPIO_voidSetPinValue(LCD_PORT,EN,GPIO_LOW);
	MSTK_vSetBusyWait(1000);

}
/*******************************************************************/

/******************************************************************/
/*to initialize LCD */
void LCD_Init(void)
{
	for(u8 i = 0 ; i < 6 ; i++)
	{
		GPIO_voidInit(&LCD[i]);
	}
	MSTK_vSetBusyWait(50000);
	LCD_WriteCommand(0x02);
	//2 line 5*7;
	LCD_WriteCommand(0x28);

	//cursor 0x0f, 0x0E ;
	LCD_WriteCommand(0x0c);

	//clear screen;
	LCD_WriteCommand(0x01);
	MSTK_vSetBusyWait(1000);

	//increase ddram address,no shift;
	LCD_WriteCommand(0x06);


	/*******************************************************************/
}
#endif
/*****************************************************************************/

//to WriteChar on LCD
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

//to Write String on LCD
void LCD_WriteString(u8*str)
{
	u8 i;

	//loop to transmit character by character of string
	for(i=0;str[i];i++)
	{
		LCD_WriteData(str[i]);

	}
}

//to Write Number on LCD
void LCD_WriteNumber(s32 num)//2503
{
	u8 str[20];
	u8 rem,i=0;
	if(num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if(num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}

	//to convert each digit in  number  to character and store it in array of character
	while(num>0)
	{
		rem = num % 10;
		str[i] = rem + '0';
		num= num / 10;
		i++;
	}

	//loop to transmit each character in array to LCD
	for(s8 j = i - 1 ; j >= 0 ; j--)
	{
		LCD_WriteChar(str[j]);
	}

}

//to Write Binary on LCD
void LCD_WriteBinary(u8 num)//
{
	s8 i,flag = 0;

	//Loop to check if each bit in the number is equal to 1 or 0
	for(i = 7 ; i >= 0 ; i--)
	{
		if(num >> i & 1)
		{
			LCD_WriteChar('1');
			flag = 1;
		}
		else{
			if(flag == 1)
			{
				LCD_WriteChar('0');
			}

		}
	}
}

//To set cursor at specific position
void LCD_GoTo(u8 line,u8 cell)
{
	if(line==0)
	{
		LCD_WriteCommand(0x80|cell);
	}
	else if(line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);

	}
}

//To clear any data on LCD
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}

//to write Hexadecimal on LCD
void LCD_WriteHex(u8 num)// 0xfe
{
	//u8 HexArray[]={'0','1','2','3'}

	//store High nibble of num
	u8 Hnibble = num >> 4;//0f

	//store LOW nibble of num
	u8 Lnibble = num & 0x0f;//0e

	if(Hnibble <= 9)
	{
		LCD_WriteChar(Hnibble+'0');
	}
	else
	{
		LCD_WriteChar(Hnibble-10+'A');

	}
	if(Lnibble <= 9)
	{
		LCD_WriteChar(Lnibble+'0');
	}
	else {
		LCD_WriteChar(Lnibble-10+'A');

	}

	//LCD_WriteChar(HexArray[Lnibble]);
}

