
/******************************************************************************
 *
 * Module: LCD

 *
 * Description: header file of LCD driver for stm
 *
 *******************************************************************************/

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_




#define  _4_BIT    1
#define  _8_BIT    2
/**********************pin configuration********/
#define LCD_MODE      _4_BIT

#define RS           GPIO_PIN8
#define EN           GPIO_PIN11
#define D7           GPIO_PIN7
#define D6           GPIO_PIN6
#define D5           GPIO_PIN5
#define D4           GPIO_PIN4
//#define D3           GPIO_PIN3
//#define D2           GPIO_PIN2
//#define D1           GPIO_PIN1
//#define D0           GPIO_PIN0


#define LCD_PORT    GPIO_PORTA


/****************************************************/

/*to initialize LCD */
void LCD_Init();

//To clear any data on LCD
void LCD_Clear(void);

//to Write String on LCD
void LCD_WriteString(u8*str);

//to Write Number on LCD
void LCD_WriteNumber(s32 num);

//to WriteChar on LCD
void LCD_WriteChar(u8 ch);

//to Write Binary on LCD
void LCD_WriteBinary(u8 num);

//To set cursor at specific position
void LCD_GoTo(u8 line,u8 cell);

//to write Hexadecimal on LCD
void LCD_WriteHex(u8 num);



#endif /* HAL_LCD_LCD_H_ */
