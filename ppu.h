#ifndef PPU_H
#define PPU_H

//#include <assert.h>
//#include "M6502/M6502.h"
//#include "global.h"
//#include "rom.h"



#define PPU_CLOCK_DIVIDER (MASTER_CLOCK_DIVIDER/3)

#define PPU_CTRL         0x2000 
#define PPU_MASK         0x2001 
#define PPU_STATUS      0x2002
#define PPU_OAMADDR     0x2003
#define PPU_OAMDATA     0x2004
#define PPU_SCROLL    0x2005   /* double write */
#define PPU_ADDR        0x2006   /* double write */
#define PPU_DATA        0x2007   /* RW */
#define PPU_OAMDMA      0x4014

#define PPUWRITE_HORIZ	1   /* VRAM write mode - horizontal or vertical */
#define PPUWRITE_VERT	32

typedef int dualmode;
extern int trace_ppu_writes;





struct ppu_struct
{
    unsigned vram:15;
    unsigned spriteram:1;
    unsigned sprite_address;

    
    unsigned tvram:15;
    unsigned w:1;
    unsigned x:3;
    unsigned nameTable:8;
    unsigned attribueTable:8;
    unsigned patternTableLow:8;
    unsigned patternTableHigh:8;
    unsigned patternTableLow:8;
    unsigned patternTableHigh:8;
    unsigned attribute:8
  
    unsigned y:3;


    dualmode ppu_addr_mode;
    int ppu_writemode; /* horizontal or vertical write pattern */

    unsigned read_latch;

    unsigned control1,control2;

    int vblank_flag;
    int hit_flag;
    int spritecount_flag; /* more than 8 sprites on current scanline ? */
};

int palette[63] = {0x7C7C7C, 0x0000FC, 0x0000BC, 0x4428BC, 0x940084, 0xA80020, 0xA81000,
				0x881400, 0x503000, 0x007800, 0x006800, 0x005800, 0x004058, 0x000000,
				0x000000, 0x000000, 0xBCBCBC, 0x0078F8, 0x0058F8, 0x6844FC, 0xD800CC,
				0xE40058, 0xF83800, 0xE45C10, 0xAC7C00, 0x00B800, 0x00A800, 0x00A844,
				0x008888, 0x000000, 0x000000, 0x000000, 0xF8F8F8, 0x3CBCFC, 0x6888FC,
				0x9878F8, 0xF878F8, 0xF85898, 0xF87858, 0xFCA044, 0xF8B800, 0xB8F818,
				0x58D854, 0x58F898, 0x00E8D8, 0x787878, 0x000000, 0x000000, 0xFCFCFC,
				0xA4E4FC, 0xB8B8F8, 0xD8B8F8, 0xF8B8F8, 0xF8A4C0, 0xF0D0B0, 0xFCE0A8,
				0xF8D878, 0xD8F878, 0xB8F8B8, 0xB8F8D8, 0x00FCFC, 0xF8D8F8, 0x000000,
0x000000}



#endif
