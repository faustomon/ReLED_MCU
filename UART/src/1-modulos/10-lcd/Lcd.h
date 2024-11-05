
#ifndef SRC_LCD_H_
#define SRC_LCD_H_

#include "systick.h"
#include "gpio.h"
#include "perifericotemporizado.h"

#define 	LCD_D4				0
#define 	LCD_D5				1
#define 	LCD_D6				2
#define 	LCD_D7				3
#define 	LCD_RS				4
#define 	LCD_EN				5
#define		LCD_DATA			0
#define		LCD_CONTROL			1
#define 	LCD_BUFFER_SIZE		340
#define	 	LCD_LINE_SIZE		16
#define 	LCD_LINES			2
#define 	RENGLON0			0
#define 	RENGLON1			1
#define 	LINE_1_ADDRESS		0x00
#define 	LINE_2_ADDRESS		0x40

class Lcd:public PerifericoTemporizado
{
	private:
		uint8_t m_lcdBuffer[LCD_BUFFER_SIZE];
		uint32_t m_lcdInxIn;
		uint32_t m_lcdInxOut;
		uint32_t m_lcdDataCount;
		Gpio**   m_bus;

	public:
		Lcd(Gpio** bus);
		void Set( const char *string , uint8_t line , uint8_t pos );
		void HandlerDelPeriferico(void);
		virtual ~Lcd();

	private:
		int16_t Pop( void );
		int8_t Push( uint8_t data , uint8_t control );
};

#endif /* SRC_LCD_H_ */
