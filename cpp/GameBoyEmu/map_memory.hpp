#pragma once

//////////////////////////////////////////////////////////////

#define CARTMEM_SIZE		0x200000
#define INTERNALMEM_SIZE	0x10000

#define ROM_SIZE			0x8000
#define RAMBANK_SIZE		0x8000

#define BANK00_BEGIN		0x0000
#define BANK00_END			0x3fff
#define BANKNN_BEGIN		0x4000
#define BANKNN_END			0x7fff
#define VRAM_BEGIN			0x8000
#define VRAM_END			0x9fff
#define EXTERNALRAM_BEGIN	0xA000
#define EXTERNALRAM_END		0xBFFF	
#define WORKRAM00_BEGIN		0xC000	
#define WORKRAM00_END		0xCFFF
#define WORKRAMNN_BEGIN		0xD000	
#define WORKRAMNN_END		0xDFFF
#define ECHO_BEGIN			0XE000
#define ECHO_END			0xFDFF

#define HRAM_BEGIN			0xFF80
#define HRAM_END			0xFFFE

#define INTENABLE_REG		0xFFFF
#define MEMOBANKING_MODE	0x0147

//////////////////////////////////////////////////////////////