#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "GPIO_Private.h"
#include "GPIO_Interface.h"
void GPIO_voidSetPinMode    (   u8 Copy_u8PortId,
		u8 Copy_u8PinId,
		u8 Copy_u8Mode
)
{

	switch(Copy_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->MODER &= ~(0b11 << (Copy_u8PinId * 2));
		GPIOA->MODER = (GPIOA->MODER) | (Copy_u8Mode << (Copy_u8PinId * 2));
		break;
	case GPIO_PORTB:
		GPIOB->MODER &= ~(0b11 << (Copy_u8PinId * 2));
		GPIOB->MODER = (GPIOB->MODER) | (Copy_u8Mode << (Copy_u8PinId * 2));
		break;
	case GPIO_PORTC:
		GPIOC->MODER = GPIOC->MODER  & (~(0b11 << (Copy_u8PinId * 2)));
		GPIOC->MODER = (GPIOC->MODER) | (Copy_u8Mode << (Copy_u8PinId * 2));
		break;
	}
}


void GPIO_voidSetPinOutputType  (   u8 Copy_u8PortId,
		u8 Copy_u8PinId,
		u8 Copy_u8OutputType)
{

	if(Copy_u8OutputType == GPIO_OUTPUT_PUSH_PULL)
	{

		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->OTYPER ,Copy_u8PinId );
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->OTYPER ,Copy_u8PinId );
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->OTYPER ,Copy_u8PinId );
			break;
		}


	}
	else if(Copy_u8OutputType == GPIO_OUTPUT_OPEN_DRAIN)
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->OTYPER ,Copy_u8PinId );
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->OTYPER ,Copy_u8PinId );
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->OTYPER ,Copy_u8PinId );
			break;
		}




	}

}


void GPIO_voidSetPinOutputSpeed (   u8 Copy_u8PortId,
		u8 Copy_u8PinId,
		u8 Copy_u8OutputSpeed)
{
	switch(Copy_u8PortId)
	{
	case GPIO_PORTA :
		GPIOA->OSPEEDR   &=   ~(0b11 << ( Copy_u8PinId * 2 )) ;
		GPIOA->OSPEEDR   |=   (Copy_u8OutputSpeed << ( Copy_u8PinId * 2 )) ;
		break;

	case GPIO_PORTB :
		GPIOB->OSPEEDR   &=   ~(0b11 << ( Copy_u8PinId * 2 )) ;
		GPIOB->OSPEEDR   |=   (Copy_u8OutputSpeed << ( Copy_u8PinId * 2 )) ;
		break;

	case GPIO_PORTC :
		GPIOC->OSPEEDR   &=   ~(0b11 << ( Copy_u8PinId * 2 )) ;
		GPIOC->OSPEEDR   |=   (Copy_u8OutputSpeed << ( Copy_u8PinId * 2 )) ;
		break;

	default:
		break;
	}

}

void GPIO_voidSetPinInputPull   (   u8 Copy_u8PortId,
		u8 Copy_u8PinId,
		u8 Copy_u8Pull)
{


	if(Copy_u8PinId <=15 &&  Copy_u8Pull<=3)
	{

		switch(Copy_u8PortId)
		{
		case GPIO_PORTA :


			GPIOA->PUPDR &= ~((0b11)<<(Copy_u8PinId*2));
			GPIOA->PUPDR |=((Copy_u8Pull)<<(Copy_u8PinId*2));
			break;
		case GPIO_PORTB :


			GPIOB->PUPDR &= ~((0b11)<<(Copy_u8PinId*2));
			GPIOB->PUPDR |=((Copy_u8Pull)<<(Copy_u8PinId*2));
			break;
		case GPIO_PORTC :


			GPIOC->PUPDR &= ~((0b11)<<(Copy_u8PinId*2));
			GPIOC->PUPDR |=((Copy_u8Pull)<<(Copy_u8PinId*2));
			break;
		}
	}
}



u8 GPIO_u8GetPinValue       (   u8 Copy_u8PortId,
		u8 Copy_u8PinId)
{
	u8 L_u8Val=2;
	switch(Copy_u8PortId)
	{
	case GPIO_PORTA :
		L_u8Val=GET_BIT(GPIOA->IDR,Copy_u8PinId);
		break;
	case GPIO_PORTB :
		L_u8Val=GET_BIT(GPIOB->IDR,Copy_u8PinId);
		break;
	case GPIO_PORTC :
		L_u8Val=GET_BIT(GPIOC->IDR,Copy_u8PinId);
		break;
	}
	return L_u8Val;

}

void GPIO_voidSetPinValue   (   u8 Copy_u8PortId,
		u8 Copy_u8PinId,
		u8 Copy_u8Value)
{
	if(Copy_u8Value == GPIO_HIGH)
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			SET_BIT(GPIOA->ODR,Copy_u8PinId);
			break;
		case GPIO_PORTB:
			SET_BIT(GPIOB->ODR,Copy_u8PinId);
			break;
		case GPIO_PORTC:
			SET_BIT(GPIOC->ODR,Copy_u8PinId);
			break;
		}
	}
	else if(Copy_u8Value == GPIO_LOW)
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			CLR_BIT(GPIOA->ODR,Copy_u8PinId);
			break;
		case GPIO_PORTB:
			CLR_BIT(GPIOB->ODR,Copy_u8PinId);
			break;
		case GPIO_PORTC:
			CLR_BIT(GPIOC->ODR,Copy_u8PinId);
			break;
		}
	}
	else
	{

	}

}

void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortId,
		u8 Copy_u8PinId,
		u8 Copy_u8Value)
{
	if(Copy_u8Value == GPIO_HIGH)
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			GPIOA->BSRR = (1 << (Copy_u8PinId));
			break;
		case GPIO_PORTB:
			GPIOB->BSRR = (1 << (Copy_u8PinId));
			break;
		case GPIO_PORTC:
			GPIOC->BSRR = (1 << (Copy_u8PinId));
			break;
		}
	}
	else if(Copy_u8Value == GPIO_LOW)
	{
		switch(Copy_u8PortId)
		{
		case GPIO_PORTA:
			GPIOA->BSRR = (1 << (Copy_u8PinId + 16 ));
			break;
		case GPIO_PORTB:
			GPIOB->BSRR = (1 << (Copy_u8PinId + 16 ));
			break;
		case GPIO_PORTC:
			GPIOC->BSRR = (1 << (Copy_u8PinId + 16 ));
			break;
		}
	}
	else
	{

	}
}
void GPIO_voidSetPortValue   (   u8 Copy_u8PortId,
		u16 Copy_u8Value)
{

	switch(Copy_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->ODR = Copy_u8Value;
		break;
	case GPIO_PORTB:
		GPIOB->ODR = Copy_u8Value;
		break;
	case GPIO_PORTC:
		GPIOC->ODR = Copy_u8Value;
		break;
	}

}
void GPIO_voidSetPortModeOUTPUT   (   u8 Copy_u8PortId)
{

	switch(Copy_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->MODER = 0x55555555;
		break;
	case GPIO_PORTB:
		GPIOB->MODER = 0x55555555;
		break;
	case GPIO_PORTC:
		GPIOC->MODER = 0x55555555;
		break;
	}

}

void GPIO_voidSetPortOtuputPushPull   (   u8 Copy_u8PortId)
{

	switch(Copy_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->OTYPER = 0x00000000;
		break;
	case GPIO_PORTB:
		GPIOB->OTYPER = 0x00000000;
		break;
	case GPIO_PORTC:
		GPIOC->OTYPER = 0x00000000;
		break;
	}

}
void GPIO_voidSetPortLowSpeed   (   u8 Copy_u8PortId)
{

	switch(Copy_u8PortId)
	{
	case GPIO_PORTA:
		GPIOA->OSPEEDR = 0x00000000;
		break;
	case GPIO_PORTB:
		GPIOB->OSPEEDR = 0x00000000;
		break;
	case GPIO_PORTC:
		GPIOC->OSPEEDR = 0x00000000;
		break;
	}

}

void MGPIO_vSetAlternativeFunction(u8 A_u8PortId,
		u8 A_u8PinNo,
		u8 A_u8Altfun )
{
	if(A_u8PinNo <8)
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA :
			GPIOA->AFRL  &= ~((0b1111)<<(A_u8PinNo*4));
			GPIOA->AFRL  |= ((A_u8Altfun)<<(A_u8PinNo*4));
			break;
		case GPIO_PORTB :
			GPIOB->AFRL  &= ~((0b1111)<<(A_u8PinNo*4));
			GPIOB->AFRL  |= ((A_u8Altfun)<<(A_u8PinNo*4));
			break;
		}
	}
	else if (A_u8PinNo < 16)
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA :
			GPIOA->AFRH  &= ~((0b1111)<<((A_u8PinNo-8)*4));
			GPIOA->AFRH  |= ((A_u8Altfun)<<((A_u8PinNo-8)*4));
			break;
		case GPIO_PORTB :
			GPIOA->AFRH  &= ~((0b1111)<<((A_u8PinNo-8)*4));
			GPIOA->AFRH  |= ((A_u8Altfun)<<((A_u8PinNo-8)*4));
			break;
		}
	}
}

void GPIO_voidInit			(GPIO_PinConfig	*	PinConfig);
void GPIO_voidInit			(GPIO_PinConfig	*	PinConfig)
{
	GPIO_voidSetPinMode(PinConfig->Port , PinConfig->Pin , PinConfig->Mode);
	GPIO_voidSetPinOutputType(PinConfig->Port , PinConfig->Pin , PinConfig->OutputType);
	GPIO_voidSetPinOutputSpeed(PinConfig->Port , PinConfig->Pin , PinConfig->OutputSpeed);
	GPIO_voidSetPinInputPull(PinConfig->Port , PinConfig->Pin , PinConfig->PullState);
	MGPIO_vSetAlternativeFunction(PinConfig->Port ,PinConfig->Pin , PinConfig->alt_func );
}


