#pragma once

#include <iostream>
#include <cstdint>

#include "map_memory.hpp"

//////////////////////////////////////////////////////////////

typedef std::uint8_t BYTE;
typedef std::int8_t SIGNED_BYTE;
typedef std::uint16_t WORD;
typedef std::int16_t SIGNED_WORD;

//////////////////////////////////////////////////////////////

// Flags usados. Cada numero corresponde ao bit que
// representa o flag no registro F.
#define FLAG_Z  7
#define FLAG_N  6
#define FLAG_H  5
#define FLAG_C  4

//////////////////////////////////////////////////////////////

#define SCREEN_W    160
#define SCREEN_H    144

//////////////////////////////////////////////////////////////

// Representa o codigo RGB usado no display
struct Color
{
    BYTE r;
    BYTE g;
    BYTE b;
};

//////////////////////////////////////////////////////////////

// O registro funciona como uma variavel de 16 bits ou
// como duas variaveis de 8 bits
union Register
{

    WORD reg;
    struct
    {
        BYTE low;
        BYTE high;
    };
};

//////////////////////////////////////////////////////////////

class GameBoyCPU
{

private:

    BYTE m_CartridgeMemory[CARTMEM_SIZE];

    BYTE m_Rom[INTERNALMEM_SIZE];
    BYTE m_RAMBanks[RAMBANK_SIZE];

    Register m_RegisterAF;
    Register m_RegisterBC;
    Register m_RegisterDE;
    Register m_RegisterHL;

    Register m_StackPointer;
    WORD m_ProgramCounter;

    Color m_ScreenData[SCREEN_W][SCREEN_H];

    bool m_MBC1;
    bool m_MBC2;

    BYTE m_CurrentROMBank;
    BYTE m_CurrentRAMBank;

private:

    void writeMemory ( WORD address, BYTE data );
    BYTE readMemory ( WORD address );

public:

    GameBoyCPU();
    virtual ~GameBoyCPU();

};

//////////////////////////////////////////////////////////////
