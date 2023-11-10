/******************************************************/
/*      Author  : Sabry Elsayed                       */
/*      SWC     :   GPIO                              */
/*      Date    :   4/9/2023                          */
/*      version :       1.00                          */
/******************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*      PORTS    */
#define GPIO_PORTA                      0
#define GPIO_PORTB                      1
#define GPIO_PORTC                      2

/*      PINS    */
#define GPIO_PIN0                       0
#define GPIO_PIN1                       1
#define GPIO_PIN2                       2
#define GPIO_PIN3                       3
#define GPIO_PIN4                       4
#define GPIO_PIN5                       5
#define GPIO_PIN6                       6
#define GPIO_PIN7                       7
#define GPIO_PIN8                       8
#define GPIO_PIN9                       9
#define GPIO_PIN10                      10
#define GPIO_PIN11                      11
#define GPIO_PIN12                      12
#define GPIO_PIN13                      13
#define GPIO_PIN14                      14
#define GPIO_PIN15                      15

/* Modes */
#define GPIO_MODE_INPUT                 0b00
#define GPIO_MODE_OUTPUT                0b01
#define GPIO_MODE_ALTERNATIVE           0b10
#define GPIO_MODE_ANALOG                0b11

/* OutType  */
#define GPIO_OUTPUT_PUSH_PULL           0
#define GPIO_OUTPUT_OPEN_DRAIN          1

/*  OutSpeed   */
#define GPIO_OUTPUT_SPEED_LOW                   0b00
#define GPIO_OUTPUT_SPEED_MEDIUM                0b01
#define GPIO_OUTPUT_SPEED_HIGH                  0b10
#define GPIO_OUTPUT_SPEED_VHIGH                 0b11

/* PULL */
#define GPIO_NO_PULL                    0b00
#define GPIO_PULL_UP                    0b01
#define GPIO_PULL_DOWN                  0b10

/* State Value */
#define GPIO_HIGH                   1
#define GPIO_LOW                    0


typedef struct
{
	u8 Port 		;
	u8 Pin  		;
	u8 Mode			;
	u8 OutputType	;
	u8 OutputSpeed	;
	u8 PullState 	;
	u8 alt_func     ;
}GPIO_PinConfig;



void GPIO_voidSetPinMode    (   u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_u8Mode
                                );

void GPIO_voidSetPinOutputType  (   u8 Copy_u8PortId,
                                    u8 Copy_u8PinId,
                                    u8 Copy_u8OutputType);

void GPIO_voidSetPinOutputSpeed (   u8 Copy_u8PortId,
                                    u8 Copy_u8PinId,
                                    u8 Copy_u8OutputSpeed);

void GPIO_voidSetPinInputPull   (   u8 Copy_u8PortId,
                                    u8 Copy_u8PinId,
                                    u8 Copy_u8Pull);

u8 GPIO_u8GetPinValue       (   u8 Copy_u8PortId,
                                u8 Copy_u8PinId);


void GPIO_voidSetPinValue   (   u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_u8Value);


void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_u8Value);

void GPIO_voidSetPinAlternative(u8 Copy_u8PortId,
                                u8 Copy_u8PinId,
                                u8 Copy_AlternativeId);

void GPIO_voidSetPortValue   (   u8 Copy_u8PortId,
		u16 Copy_u8Value);


void GPIO_voidSetPortModeOUTPUT   (   u8 Copy_u8PortId);
void GPIO_voidSetPortOtuputPushPull   (   u8 Copy_u8PortId);
void GPIO_voidSetPortLowSpeed   (   u8 Copy_u8PortId);

void GPIO_voidInit			(GPIO_PinConfig	*	PinConfig);

#endif
