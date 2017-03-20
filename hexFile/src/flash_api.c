
#include "flash_api.h"

/*! \brief Function to erase one page in the Application Table Section.
 *
 *  \note The maximum pageAddress must not be exceeded. The maximum number of 
 *        pages can be found in the datasheet. For the ATxmega128A1, the maximum
 *        number of pages in the application table is 16.
 *
 *  \param pageAddress Page address to the page to erase.
 */


void EraseAppTablePage(uint32_t pageAddress)
{
	/* Calculate actual start address of the page.*/
	uint32_t tableAddress = (pageAddress * FLASH_PAGE_SIZE);
	
	/* Perform page erase. */
	SP_EraseApplicationPage(APP_SECTION_START + tableAddress);

	/* Wait for NVM to finish. */
	SP_WaitForSPM();
	NVM.CMD = NVM_CMD_NO_OPERATION_gc;
}



/*! \brief Function to do an atomic erase-write on one page in the Application Table Section.
 *
 *  \note The maximum pageAddress must not be exceeded. The maximum number of 
 *        pages can be found in the datasheet. For the ATxmega128A1, the maximum
 *        number of pages in the application table is 16.
 

 *  \param pageAddress Page address to the page to erase/write.
 */


void EraseWriteAppTablePage(uint32_t pageAddress)
{
	/* Calculate actual start address of the page.*/
	uint32_t tableAddress = (pageAddress * FLASH_PAGE_SIZE);

	/* Perform page erase. */
	SP_EraseWriteApplicationPage(APP_SECTION_START + tableAddress);

	/* Wait for NVM to finish. */
	SP_WaitForSPM();
	NVM.CMD = NVM_CMD_NO_OPERATION_gc;
}


/*! \brief Function to program one page in the Application Table Section.
 *
 *  \note The maximum pageAddress must not be exceeded. The maximum number of 
 *        pages can be found in the datasheet. For the ATxmega128A1, the maximum
 *        number of pages in the application table is 16.
 *
 *  \param pageAddress Page address to the page to write.
 */

void WriteAppTablePage(uint32_t pageAddress)
{
	/* Calculate actual start address of the page.*/
	uint32_t tableAddress = (pageAddress * FLASH_PAGE_SIZE);
	
	/* Perform page write. */
	SP_WriteApplicationPage(APP_SECTION_START + tableAddress);

	/* Wait for NVM to finish. */
	SP_WaitForSPM();
	NVM.CMD = NVM_CMD_NO_OPERATION_gc;
}


/*! \brief Function to load one word into page buffer.
 *
 *  \param tableAddress Address in buffer to write the word.
 *  \param lowByte      The low byte of the word to load.
 *  \param highByte     The high byte of the word to load.
 */
void LoadAppTableWord(uint16_t tableAddress, uint8_t lowByte, uint8_t highByte)
{
	/* Perform word load. */
	SP_LoadFlashWord(tableAddress, ((uint16_t) highByte << 8) | lowByte);

	/* Wait for NVM to finish. */
	SP_WaitForSPM();
	NVM.CMD = NVM_CMD_NO_OPERATION_gc;
}


/*! \brief Function to read a flash page.
 *
 *  \note The maximum pageAddress must not be exceeded. The maximum number of 
 *        pages can be found in the datasheet. For the ATxmega128A1, the maximum
 *        number of pages in the application table is 16.
 *
 *  \param data         Pointer to a data buffer to store the data.
 *  \param pageAddress  Page address to read from. 
 */
void ReadFlashPage(const uint8_t * data, uint8_t pageAddress)
{
	/* Calculate actual start address of the page.*/
	uint32_t tableAddress = (pageAddress * FLASH_PAGE_SIZE);
	
	/* Read the flash page into the buffer. */
	SP_ReadFlashPage(data, APP_SECTION_START + tableAddress);
	NVM.CMD = NVM_CMD_NO_OPERATION_gc;
}

/*! \brief Example to show how to read and write to the flash.
 */

void writeRead(uint8_t* WriteBuffer, uint32_t pageNumber) 
{
	
	
		///* Load the flashbuffer with the test buffer. */
		/* Calculate actual start address of the page.*/
		uint32_t tableAddress = (pageNumber * FLASH_PAGE_SIZE);
		
		SP_LoadFlashPage(WriteBuffer);
		SP_WaitForSPM();
		
		SP_EraseWriteApplicationPage(tableAddress);
		NVM.CMD = NVM_CMD_ERASE_WRITE_APP_PAGE_gc;
		NVM_EXEC();
		NVM.CMD = NVM_CMD_NO_OPERATION_gc;

}




