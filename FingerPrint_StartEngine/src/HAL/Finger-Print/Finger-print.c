/************************************************************************
 * Author           :Sabry Elsayed
 * File description :Finger Print.c
 * Date             :20/10/2023
 * Target           :STM32F401
 * Version          :v0.1
 ************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/UART/UART_prv.h"
#include "../../MCAL/UART/UART_int.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"
#include "../../MCAL/STK/STK_int.h"
#include "Finger-print.h"


/*********************************Finger Print Packets*******************************************************/
static const u8 ReadFingerFrame[12]    = {0xEF ,0x01 ,0xFF ,0xFF ,0XFF ,0XFF ,0x01 ,0x00 ,0x03 ,0x01 ,0x00 ,0x05};
static const u8 StoreBuffer_1Frame[13] = {0xEF ,0x01 ,0xFF ,0xFF ,0XFF ,0XFF ,0x01 ,0x00 ,0x04 ,0x02 ,0x01 ,0x00 ,0x08};
static const u8 StoreBuffer_2Frame[13] = {0xEF ,0x01 ,0xFF ,0xFF ,0XFF ,0XFF ,0x01 ,0x00 ,0x04 ,0x02 ,0x02 ,0x00 ,0x09};
static const u8 MakeTamplateFrame[12]  = {0xEF ,0x01 ,0xFF ,0xFF ,0XFF ,0XFF ,0x01 ,0x00 ,0x03 ,0x05 ,0x00 ,0x09};
static const u8 StoreFrame [10]        = {0xEF ,0x01 ,0xFF ,0xFF ,0XFF ,0XFF ,0x01 ,0x00 ,0x06 ,0x06  };
static const u8 CheckFrame[17]         = {0xEF ,0x01 ,0xFF ,0xFF ,0XFF ,0XFF ,0x01 ,0x00 ,0x08 ,0x04 ,0x01 ,0x00 ,0x0A ,0x00 ,0x5A ,0x00 ,0x72 };
/*************************************************************************************************************/
 u8 id = 20;
/*************************************************************************
 * @name         FP_RecieveAck
 * @brief        This function receive ACK from finger print to
 *               to indicate command is success or not
 * @parm         None
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
static u8 FP_RecieveAck(void)

{
	u8 Error_Status = NOK;
	u8 ch = 0  , k = 0;
	for (s8 i = 0 ; i < 10 ; i++)
	{
		k=MUSART_u8ReceiveByteSynchNonBlocking(USART2);//0-9 //10
		if(i == 9)
		{
			ch = k;
			k=MUSART_u8ReceiveByteSynchNonBlocking(USART2);//0-9 //10
			k=MUSART_u8ReceiveByteSynchNonBlocking(USART2);//0-9 //10

		}
	}
	if(ch == 0x00 || ch == 0x21)
	{
		Error_Status = OK;
	}
	return Error_Status;
}

/*************************************************************************
 * @name         FP_CheckingRecieveAck
 * @brief        This function is used only with searching ACK
 *                 if finger image is exist in data base or not
 *
 * @parm         PageNO_H- and PageNo_L to store Id , Match_H and Match_L
 *               for matching with template
 * @return       u8 as (OK if searching finger is exist and NOK if not)
 *************************************************************************/

static u8 FP_CheckingRecieveAck(u8 *PageNO_H , u8 *pageNo_L ,u8 *Match_H ,u8 *Match_L)
{
	u8 Error_Status = NOK;
	u8 ch = 0  , k = 0;
	for(s8 i=0;i<10;i++)
	{
		k=MUSART_u8ReceiveByteSynchNonBlocking(USART2);
		if(i==9)
		{
			ch=k;
			*PageNO_H=MUSART_u8ReceiveByteSynchNonBlocking(USART2);
			*pageNo_L=MUSART_u8ReceiveByteSynchNonBlocking(USART2);
			*Match_H=MUSART_u8ReceiveByteSynchNonBlocking(USART2);
			*Match_L=MUSART_u8ReceiveByteSynchNonBlocking(USART2);
			k=MUSART_u8ReceiveByteSynchNonBlocking(USART2);
			k=MUSART_u8ReceiveByteSynchNonBlocking(USART2);
		}

	}
	if(ch == 0x00 || ch == 0x21)
	{
		Error_Status = OK;
	}
	return Error_Status;
}
/*************************************************************************
 * @name         FP_GetImage
 * @brief        This function is used to get user finer image
 * @parm         None
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/

static u8 FP_GetImage(void)
{
	u8 Error_Status = NOK;

	for(s8 i = 0 ; i < 12 ; i++)
	{
		MUSART_vTransmitByteSynch(USART2,ReadFingerFrame[i]);
	}
	Error_Status = FP_RecieveAck();

	return Error_Status;
}
/*************************************************************************
 * @name         FP_GenerateFile
 * @brief        This function is store user finger image into
 *               buffer1 or buffer2 to process data of image
 * @parm         buffer1 or buffer2 packet
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
static u8 FP_GenerateFile (const u8 * BufferFrame )
{
	u8 Error_Status = NOK;

	for(s8 i =0 ; i < 13 ; i++)
	{
		MUSART_vTransmitByteSynch(USART2 ,BufferFrame[i]);
	}
	Error_Status = FP_RecieveAck();
	return Error_Status;
}
/*************************************************************************
 * @name         FP_ReadFinger
 * @brief        This function is used to take finger image and
 *               store it into buffer1
 * @parm         None
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
u8 FP_ReadFinger(void)
{

	u8 Error_Status = NOK;

	if(FP_GetImage() == OK)
	{
		Error_Status = FP_GenerateFile(StoreBuffer_1Frame);
	}
	return Error_Status;

}
/*************************************************************************
 * @name         FP_ConfirmFinger
 * @brief        This function is used to take finger image and
 *               store it into buffer2 to confirm that
 *               your finger was got successfully
 * @parm         None
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
static u8 FP_ConfirmFinger(void)          //for char_buffer2
{
	u8 Error_Status = NOK;

	if(FP_GetImage() == OK)
	{
		Error_Status = FP_GenerateFile(StoreBuffer_2Frame);
	}
	return Error_Status;

}
/*************************************************************************
 * @name         FP_ConfirmFinger
 * @brief        This function is used to make a template of user finger
 *               to process data
 * @parm         None
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
static u8 FP_MakeTemplate(void)
{

	u8 Error_Status = NOK;

	for(s8 i =0 ; i < 12 ; i++)
	{
		MUSART_vTransmitByteSynch(USART2,MakeTamplateFrame[i]);
	}

	Error_Status = FP_RecieveAck();
	return Error_Status;

}
/*************************************************************************
 * @name         FP_StoreFinger
 * @brief        This function is used to store your finger into
 *               flash of finger print module to register of user finger
 * @parm         None
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
static u8 FP_StoreFinger(u8 charBuf ,u32 ID)
{
	u8 Error_Status = NOK;
	u8 sum=14+ID;

	for (s8 i = 0 ; i < 10 ; i++)
	{
		MUSART_vTransmitByteSynch(USART2,StoreFrame[i]);
	}
	MUSART_vTransmitByteSynch(USART2,charBuf);
	MUSART_vTransmitByteSynch(USART2,(unsigned char )(ID>>8));
	MUSART_vTransmitByteSynch(USART2,(unsigned char )ID);
	MUSART_vTransmitByteSynch(USART2,0);//C
	MUSART_vTransmitByteSynch(USART2,sum);//C
	Error_Status = FP_RecieveAck();

	return Error_Status;

}
/*************************************************************************
 * @name         FP_CheckFinger
 * @brief        This function is used to check if user finger is exist
 *               into finger module flash memory or not
 * @parm         pointer of u16 to store user ID
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
static u8 FP_CheckFinger(u16 * ID)
{
	u8 Error_Status = NOK;
	u8 MatchScore_H=0;
	u8 MatchScore_L=0;
	u8 PageNo_H=0;
	u8 PageNo_L=0;


	for (s8 i = 0 ; i < 17 ; i++)
	{
		MUSART_vTransmitByteSynch(USART2,CheckFrame[i]);
	}
	Error_Status = FP_CheckingRecieveAck(&PageNo_H, &PageNo_L ,&MatchScore_H ,&MatchScore_L);
	*ID = ((u16) PageNo_L) | ((u16)PageNo_H << 8);

	return Error_Status;
}
/*************************************************************************
 * @name         FP_Register
 * @brief        This function is used to register user finger print
 *               into finger module flash memory
 * @parm         None
 * @return       u8 as (OK if command sucess and NOK if command is Fail)
 *************************************************************************/
u8 FP_Register(void)
{
	u8 ReadFingerStatus    = NOK;
	u8 ConfirmFingerStatus = NOK;
	u8 Error_Status        = NOK;
	MSTK_vSetBusyWait(DELAY);
	while(ConfirmFingerStatus != OK)
	{
		MSTK_vSetBusyWait(DELAY);
		ReadFingerStatus=FP_ReadFinger();
		if(ReadFingerStatus == OK)
		{

			MSTK_vSetBusyWait(MODULE_DELAY);
			ConfirmFingerStatus = FP_ConfirmFinger();
			if(ConfirmFingerStatus == OK)
			{
				FP_MakeTemplate();
				MSTK_vSetBusyWait(MODULE_DELAY);
				FP_StoreFinger(1,id);
				id++;
				Error_Status = OK;
			}
			else
			{

				Error_Status = NOK;
			}
		}
	}
	return Error_Status;
}
/*************************************************************************
 * @name         FP_Search
 * @brief        This function is used to search about user finger print
 *               into finger module flash memory to check if exist or not
 * @parm         pointer of u16 to store user ID
 * @return       u8 as (OK if user finger is exist and NOK if not)
 *************************************************************************/
u8 FP_Search (u16 *Id)
{
	u8 ReadFingerStatus = NOK;
	u8 Error_Status    = NOK;
	MSTK_vSetBusyWait(DELAY);
	while(ReadFingerStatus != OK)
	{
		ReadFingerStatus=FP_ReadFinger();
		if(ReadFingerStatus == OK)
		{
			MSTK_vSetBusyWait(MODULE_DELAY);
			FP_MakeTemplate();
			MSTK_vSetBusyWait(MODULE_DELAY);
			if( FP_CheckFinger(Id) == OK)
			{
				Error_Status = OK;

			}
			else
			{
				Error_Status = NOK;
			}
		}
	}
	return Error_Status;
}
/*********************************************************************************************/














