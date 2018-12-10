#pragma once
#include "../types.h"

typedef u64 iova_t;

typedef enum {
    NvLayout_Pitch = 1,
    NvLayout_Tiled = 2,
    NvLayout_BlockLinear = 3,
} NvLayout;

typedef enum {
    NvDisplayScanFormat_Progressive = 0,
    NvDisplayScanFormat_Interlaced = 1,
} NvDisplayScanFormat;

typedef enum {
    NvKind_Pitch = 0x0,
    NvKind_Z16 = 0x1,
    NvKind_Z16_2C = 0x2,
    NvKind_Z16_MS2_2C = 0x3,
    NvKind_Z16_MS4_2C = 0x4,
    NvKind_Z16_MS8_2C = 0x5,
    NvKind_Z16_MS16_2C = 0x6,
    NvKind_Z16_2Z = 0x7,
    NvKind_Z16_MS2_2Z = 0x8,
    NvKind_Z16_MS4_2Z = 0x9,
    NvKind_Z16_MS8_2Z = 0xa,
    NvKind_Z16_MS16_2Z = 0xb,
    NvKind_Z16_4CZ = 0xc,
    NvKind_Z16_MS2_4CZ = 0xd,
    NvKind_Z16_MS4_4CZ = 0xe,
    NvKind_Z16_MS8_4CZ = 0xf,
    NvKind_Z16_MS16_4CZ = 0x10,
    NvKind_S8Z24 = 0x11,
    NvKind_S8Z24_1Z = 0x12,
    NvKind_S8Z24_MS2_1Z = 0x13,
    NvKind_S8Z24_MS4_1Z = 0x14,
    NvKind_S8Z24_MS8_1Z = 0x15,
    NvKind_S8Z24_MS16_1Z = 0x16,
    NvKind_S8Z24_2CZ = 0x17,
    NvKind_S8Z24_MS2_2CZ = 0x18,
    NvKind_S8Z24_MS4_2CZ = 0x19,
    NvKind_S8Z24_MS8_2CZ = 0x1a,
    NvKind_S8Z24_MS16_2CZ = 0x1b,
    NvKind_S8Z24_2CS = 0x1C,
    NvKind_S8Z24_MS2_2CS = 0x1d,
    NvKind_S8Z24_MS4_2CS = 0x1e,
    NvKind_S8Z24_MS8_2CS = 0x1f,
    NvKind_S8Z24_MS16_2CS = 0x20,
    NvKind_S8Z24_4CSZV = 0x21,
    NvKind_S8Z24_MS2_4CSZV = 0x22,
    NvKind_S8Z24_MS4_4CSZV = 0x23,
    NvKind_S8Z24_MS8_4CSZV = 0x24,
    NvKind_S8Z24_MS16_4CSZV = 0x25,
    NvKind_V8Z24_MS4_VC12 = 0x26,
    NvKind_V8Z24_MS4_VC4 = 0x27,
    NvKind_V8Z24_MS8_VC8 = 0x28,
    NvKind_V8Z24_MS8_VC24 = 0x29,
    NvKind_S8 = 0x2a,
    NvKind_S8_2S = 0x2b,
    NvKind_V8Z24_MS4_VC12_1ZV = 0x2e,
    NvKind_V8Z24_MS4_VC4_1ZV = 0x2f,
    NvKind_V8Z24_MS8_VC8_1ZV = 0x30,
    NvKind_V8Z24_MS8_VC24_1ZV = 0x31,
    NvKind_V8Z24_MS4_VC12_2CS = 0x32,
    NvKind_V8Z24_MS4_VC4_2CS = 0x33,
    NvKind_V8Z24_MS8_VC8_2CS = 0x34,
    NvKind_V8Z24_MS8_VC24_2CS = 0x35,
    NvKind_V8Z24_MS4_VC12_2CZV = 0x3a,
    NvKind_V8Z24_MS4_VC4_2CZV = 0x3b,
    NvKind_V8Z24_MS8_VC8_2CZV = 0x3c,
    NvKind_V8Z24_MS8_VC24_2CZV = 0x3d,
    NvKind_V8Z24_MS4_VC12_2ZV = 0x3e,
    NvKind_V8Z24_MS4_VC4_2ZV = 0x3f,
    NvKind_V8Z24_MS8_VC8_2ZV = 0x40,
    NvKind_V8Z24_MS8_VC24_2ZV = 0x41,
    NvKind_V8Z24_MS4_VC12_4CSZV = 0x42,
    NvKind_V8Z24_MS4_VC4_4CSZV = 0x43,
    NvKind_V8Z24_MS8_VC8_4CSZV = 0x44,
    NvKind_V8Z24_MS8_VC24_4CSZV = 0x45,
    NvKind_Z24S8 = 0x46,
    NvKind_Z24S8_1Z = 0x47,
    NvKind_Z24S8_MS2_1Z = 0x48,
    NvKind_Z24S8_MS4_1Z = 0x49,
    NvKind_Z24S8_MS8_1Z = 0x4a,
    NvKind_Z24S8_MS16_1Z = 0x4b,
    NvKind_Z24S8_2CS = 0x4c,
    NvKind_Z24S8_MS2_2CS = 0x4d,
    NvKind_Z24S8_MS4_2CS = 0x4e,
    NvKind_Z24S8_MS8_2CS = 0x4f,
    NvKind_Z24S8_MS16_2CS = 0x50,
    NvKind_Z24S8_2CZ = 0x51,
    NvKind_Z24S8_MS2_2CZ = 0x52,
    NvKind_Z24S8_MS4_2CZ = 0x53,
    NvKind_Z24S8_MS8_2CZ = 0x54,
    NvKind_Z24S8_MS16_2CZ = 0x55,
    NvKind_Z24S8_4CSZV = 0x56,
    NvKind_Z24S8_MS2_4CSZV = 0x57,
    NvKind_Z24S8_MS4_4CSZV = 0x58,
    NvKind_Z24S8_MS8_4CSZV = 0x59,
    NvKind_Z24S8_MS16_4CSZV = 0x5a,
    NvKind_Z24V8_MS4_VC12 = 0x5b,
    NvKind_Z24V8_MS4_VC4 = 0x5C,
    NvKind_Z24V8_MS8_VC8 = 0x5d,
    NvKind_Z24V8_MS8_VC24 = 0x5e,
    NvKind_Z24V8_MS4_VC12_1ZV = 0x63,
    NvKind_Z24V8_MS4_VC4_1ZV = 0x64,
    NvKind_Z24V8_MS8_VC8_1ZV = 0x65,
    NvKind_Z24V8_MS8_VC24_1ZV = 0x66,
    NvKind_Z24V8_MS4_VC12_2CS = 0x67,
    NvKind_Z24V8_MS4_VC4_2CS = 0x68,
    NvKind_Z24V8_MS8_VC8_2CS = 0x69,
    NvKind_Z24V8_MS8_VC24_2CS = 0x6a,
    NvKind_Z24V8_MS4_VC12_2CZV = 0x6f,
    NvKind_Z24V8_MS4_VC4_2CZV = 0x70,
    NvKind_Z24V8_MS8_VC8_2CZV = 0x71,
    NvKind_Z24V8_MS8_VC24_2CZV = 0x72,
    NvKind_Z24V8_MS4_VC12_2ZV = 0x73,
    NvKind_Z24V8_MS4_VC4_2ZV = 0x74,
    NvKind_Z24V8_MS8_VC8_2ZV = 0x75,
    NvKind_Z24V8_MS8_VC24_2ZV = 0x76,
    NvKind_Z24V8_MS4_VC12_4CSZV = 0x77,
    NvKind_Z24V8_MS4_VC4_4CSZV = 0x78,
    NvKind_Z24V8_MS8_VC8_4CSZV = 0x79,
    NvKind_Z24V8_MS8_VC24_4CSZV = 0x7a,
    NvKind_ZF32 = 0x7b,
    NvKind_ZF32_1Z = 0x7C,
    NvKind_ZF32_MS2_1Z = 0x7d,
    NvKind_ZF32_MS4_1Z = 0x7e,
    NvKind_ZF32_MS8_1Z = 0x7f,
    NvKind_ZF32_MS16_1Z = 0x80,
    NvKind_ZF32_2CS = 0x81,
    NvKind_ZF32_MS2_2CS = 0x82,
    NvKind_ZF32_MS4_2CS = 0x83,
    NvKind_ZF32_MS8_2CS = 0x84,
    NvKind_ZF32_MS16_2CS = 0x85,
    NvKind_ZF32_2CZ = 0x86,
    NvKind_ZF32_MS2_2CZ = 0x87,
    NvKind_ZF32_MS4_2CZ = 0x88,
    NvKind_ZF32_MS8_2CZ = 0x89,
    NvKind_ZF32_MS16_2CZ = 0x8a,
    NvKind_X8Z24_X16V8S8_MS4_VC12 = 0x8b,
    NvKind_X8Z24_X16V8S8_MS4_VC4 = 0x8c,
    NvKind_X8Z24_X16V8S8_MS8_VC8 = 0x8d,
    NvKind_X8Z24_X16V8S8_MS8_VC24 = 0x8e,
    NvKind_X8Z24_X16V8S8_MS4_VC12_1CS = 0x8f,
    NvKind_X8Z24_X16V8S8_MS4_VC4_1CS = 0x90,
    NvKind_X8Z24_X16V8S8_MS8_VC8_1CS = 0x91,
    NvKind_X8Z24_X16V8S8_MS8_VC24_1CS = 0x92,
    NvKind_X8Z24_X16V8S8_MS4_VC12_1ZV = 0x97,
    NvKind_X8Z24_X16V8S8_MS4_VC4_1ZV = 0x98,
    NvKind_X8Z24_X16V8S8_MS8_VC8_1ZV = 0x99,
    NvKind_X8Z24_X16V8S8_MS8_VC24_1ZV = 0x9a,
    NvKind_X8Z24_X16V8S8_MS4_VC12_1CZV = 0x9b,
    NvKind_X8Z24_X16V8S8_MS4_VC4_1CZV = 0x9c,
    NvKind_X8Z24_X16V8S8_MS8_VC8_1CZV = 0x9d,
    NvKind_X8Z24_X16V8S8_MS8_VC24_1CZV = 0x9e,
    NvKind_X8Z24_X16V8S8_MS4_VC12_2CS = 0x9f,
    NvKind_X8Z24_X16V8S8_MS4_VC4_2CS = 0xa0,
    NvKind_X8Z24_X16V8S8_MS8_VC8_2CS = 0xa1,
    NvKind_X8Z24_X16V8S8_MS8_VC24_2CS = 0xa2,
    NvKind_X8Z24_X16V8S8_MS4_VC12_2CSZV = 0xa3,
    NvKind_X8Z24_X16V8S8_MS4_VC4_2CSZV = 0xa4,
    NvKind_X8Z24_X16V8S8_MS8_VC8_2CSZV = 0xa5,
    NvKind_X8Z24_X16V8S8_MS8_VC24_2CSZV = 0xa6,
    NvKind_ZF32_X16V8S8_MS4_VC12 = 0xa7,
    NvKind_ZF32_X16V8S8_MS4_VC4 = 0xa8,
    NvKind_ZF32_X16V8S8_MS8_VC8 = 0xa9,
    NvKind_ZF32_X16V8S8_MS8_VC24 = 0xaa,
    NvKind_ZF32_X16V8S8_MS4_VC12_1CS = 0xab,
    NvKind_ZF32_X16V8S8_MS4_VC4_1CS = 0xac,
    NvKind_ZF32_X16V8S8_MS8_VC8_1CS = 0xad,
    NvKind_ZF32_X16V8S8_MS8_VC24_1CS = 0xae,
    NvKind_ZF32_X16V8S8_MS4_VC12_1ZV = 0xb3,
    NvKind_ZF32_X16V8S8_MS4_VC4_1ZV = 0xb4,
    NvKind_ZF32_X16V8S8_MS8_VC8_1ZV = 0xb5,
    NvKind_ZF32_X16V8S8_MS8_VC24_1ZV = 0xb6,
    NvKind_ZF32_X16V8S8_MS4_VC12_1CZV = 0xb7,
    NvKind_ZF32_X16V8S8_MS4_VC4_1CZV = 0xb8,
    NvKind_ZF32_X16V8S8_MS8_VC8_1CZV = 0xb9,
    NvKind_ZF32_X16V8S8_MS8_VC24_1CZV = 0xba,
    NvKind_ZF32_X16V8S8_MS4_VC12_2CS = 0xbb,
    NvKind_ZF32_X16V8S8_MS4_VC4_2CS = 0xbc,
    NvKind_ZF32_X16V8S8_MS8_VC8_2CS = 0xbd,
    NvKind_ZF32_X16V8S8_MS8_VC24_2CS = 0xbe,
    NvKind_ZF32_X16V8S8_MS4_VC12_2CSZV = 0xbf,
    NvKind_ZF32_X16V8S8_MS4_VC4_2CSZV = 0xc0,
    NvKind_ZF32_X16V8S8_MS8_VC8_2CSZV = 0xc1,
    NvKind_ZF32_X16V8S8_MS8_VC24_2CSZV = 0xc2,
    NvKind_ZF32_X24S8 = 0xc3,
    NvKind_ZF32_X24S8_1CS = 0xc4,
    NvKind_ZF32_X24S8_MS2_1CS = 0xc5,
    NvKind_ZF32_X24S8_MS4_1CS = 0xc6,
    NvKind_ZF32_X24S8_MS8_1CS = 0xc7,
    NvKind_ZF32_X24S8_MS16_1CS = 0xc8,
    NvKind_SmskedMessage = 0xca,
    NvKind_SmhostMessage = 0xcb,
    NvKind_C64_MS2_2CRA = 0xcd,
    NvKind_ZF32_X24S8_2CSZV = 0xce,
    NvKind_ZF32_X24S8_MS2_2CSZV = 0xcf,
    NvKind_ZF32_X24S8_MS4_2CSZV = 0xd0,
    NvKind_ZF32_X24S8_MS8_2CSZV = 0xd1,
    NvKind_ZF32_X24S8_MS16_2CSZV = 0xd2,
    NvKind_ZF32_X24S8_2CS = 0xd3,
    NvKind_ZF32_X24S8_MS2_2CS = 0xd4,
    NvKind_ZF32_X24S8_MS4_2CS = 0xd5,
    NvKind_ZF32_X24S8_MS8_2CS = 0xd6,
    NvKind_ZF32_X24S8_MS16_2CS = 0xd7,
    NvKind_C32_2C = 0xd8,
    NvKind_C32_2CBR = 0xd9,
    NvKind_C32_2CBA = 0xda,
    NvKind_C32_2CRA = 0xdb,
    NvKind_C32_2BRA = 0xdc,
    NvKind_C32_MS2_2C = 0xdd,
    NvKind_C32_MS2_2CBR = 0xde,
    NvKind_C32_MS2_2CRA = 0xcc,
    NvKind_C32_MS4_2C = 0xdf,
    NvKind_C32_MS4_2CBR = 0xe0,
    NvKind_C32_MS4_2CBA = 0xe1,
    NvKind_C32_MS4_2CRA = 0xe2,
    NvKind_C32_MS4_2BRA = 0xe3,
    NvKind_C32_MS8_MS16_2C = 0xe4,
    NvKind_C32_MS8_MS16_2CRA = 0xe5,
    NvKind_C64_2C = 0xe6,
    NvKind_C64_2CBR = 0xe7,
    NvKind_C64_2CBA = 0xe8,
    NvKind_C64_2CRA = 0xe9,
    NvKind_C64_2BRA = 0xea,
    NvKind_C64_MS2_2C = 0xeb,
    NvKind_C64_MS2_2CBR = 0xec,
    NvKind_C64_MS4_2C = 0xed,
    NvKind_C64_MS4_2CBR = 0xee,
    NvKind_C64_MS4_2CBA = 0xef,
    NvKind_C64_MS4_2CRA = 0xf0,
    NvKind_C64_MS4_2BRA = 0xf1,
    NvKind_C64_MS8_MS16_2C = 0xf2,
    NvKind_C64_MS8_MS16_2CRA = 0xf3,
    NvKind_C128_2C = 0xf4,
    NvKind_C128_2CR = 0xf5,
    NvKind_C128_MS2_2C = 0xf6,
    NvKind_C128_MS2_2CR = 0xf7,
    NvKind_C128_MS4_2C = 0xf8,
    NvKind_C128_MS4_2CR = 0xf9,
    NvKind_C128_MS8_MS16_2C = 0xfa,
    NvKind_C128_MS8_MS16_2CR = 0xfb,
    NvKind_X8C24 = 0xfc,
    NvKind_PitchNoSwizzle = 0xfd,
    NvKind_Generic_16BX2 = 0xfe,
    NvKind_Invalid = 0xff,
} NvKind;

typedef enum {
    NvColorFormat_Unspecified = 0x0000000000UL,
    NvColorFormat_NonColor8 = 0x0009200408UL,
    NvColorFormat_X4C4 = 0x0009200A10UL,
    NvColorFormat_NonColor32 = 0x0100490508UL,
    NvColorFormat_A8L8 = 0x0100490E10UL,
    NvColorFormat_Float_A16L16 = 0x0100495D20UL,
    NvColorFormat_A1B5G5R5 = 0x0100531410UL,
    NvColorFormat_A4B4G4R4 = 0x0100531510UL,
    NvColorFormat_A5B5G5R1 = 0x0100531810UL,
    NvColorFormat_A2B10G10R10 = 0x0100532020UL,
    NvColorFormat_A8B8G8R8 = 0x0100532120UL,
    NvColorFormat_A16B16G16R16 = 0x0100532740UL,
    NvColorFormat_Float_A16B16G16R16 = 0x0100536740UL,
    NvColorFormat_A1R5G5B5 = 0x0100D11410UL,
    NvColorFormat_A4R4G4B4 = 0x0100D11510UL,
    NvColorFormat_A5R1G5B5 = 0x0100D11610UL,
    NvColorFormat_A2R10G10B10 = 0x0100D12020UL,
    NvColorFormat_A8R8G8B8 = 0x0100D12120UL,
    NvColorFormat_A1 = 0x0101240101UL,
    NvColorFormat_A2 = 0x0101240202UL,
    NvColorFormat_A4 = 0x0101240304UL,
    NvColorFormat_A8 = 0x0101240408UL,
    NvColorFormat_A16 = 0x0101240A10UL,
    NvColorFormat_A32 = 0x0101241C20UL,
    NvColorFormat_Float_A16 = 0x0101244A10UL,
    NvColorFormat_L4A4 = 0x0102000508UL,
    NvColorFormat_L8A8 = 0x0102000E10UL,
    NvColorFormat_B4G4R4A4 = 0x01060A1510UL,
    NvColorFormat_B5G5R1A5 = 0x01060A1710UL,
    NvColorFormat_B5G5R5A1 = 0x01060A1810UL,
    NvColorFormat_B8G8R8A8 = 0x01060A2120UL,
    NvColorFormat_B10G10R10A2 = 0x01060A2320UL,
    NvColorFormat_R1G5B5A5 = 0x0106881410UL,
    NvColorFormat_R4G4B4A4 = 0x0106881510UL,
    NvColorFormat_R5G5B5A1 = 0x0106881810UL,
    NvColorFormat_R8G8B8A8 = 0x0106882120UL,
    NvColorFormat_R10G10B10A2 = 0x0106882320UL,
    NvColorFormat_L1 = 0x010A000101UL,
    NvColorFormat_L2 = 0x010A000202UL,
    NvColorFormat_L4 = 0x010A000304UL,
    NvColorFormat_L8 = 0x010A000408UL,
    NvColorFormat_L16 = 0x010A000A10UL,
    NvColorFormat_L32 = 0x010A001C20UL,
    NvColorFormat_Float_L16 = 0x010A004A10UL,
    NvColorFormat_B5G6R5 = 0x010A0A1210UL,
    NvColorFormat_B6G5R5 = 0x010A0A1310UL,
    NvColorFormat_B5G5R5X1 = 0x010A0A1810UL,
    NvColorFormat_B8_G8_R8 = 0x010A0A1918UL,
    NvColorFormat_B8G8R8X8 = 0x010A0A2120UL,
    NvColorFormat_Float_B10G11R11 = 0x010A0A5E20UL,
    NvColorFormat_X1B5G5R5 = 0x010A531410UL,
    NvColorFormat_X8B8G8R8 = 0x010A532120UL,
    NvColorFormat_X16B16G16R16 = 0x010A532740UL,
    NvColorFormat_Float_X16B16G16R16 = 0x010A536740UL,
    NvColorFormat_R3G3B2 = 0x010A880608UL,
    NvColorFormat_R5G5B6 = 0x010A881110UL,
    NvColorFormat_R5G6B5 = 0x010A881210UL,
    NvColorFormat_R5G5B5X1 = 0x010A881810UL,
    NvColorFormat_R8_G8_B8 = 0x010A881918UL,
    NvColorFormat_R8G8B8X8 = 0x010A882120UL,
    NvColorFormat_X1R5G5B5 = 0x010AD11410UL,
    NvColorFormat_X8R8G8B8 = 0x010AD12120UL,
    NvColorFormat_RG8 = 0x010B080E10UL,
    NvColorFormat_R16G16 = 0x010B081D20UL,
    NvColorFormat_Float_R16G16 = 0x010B085D20UL,
    NvColorFormat_R8 = 0x010B200408UL,
    NvColorFormat_R16 = 0x010B200A10UL,
    NvColorFormat_Float_R16 = 0x010B204A10UL,
    NvColorFormat_A2B10G10R10_sRGB = 0x0200532020UL,
    NvColorFormat_A8B8G8R8_sRGB = 0x0200532120UL,
    NvColorFormat_A16B16G16R16_sRGB = 0x0200532740UL,
    NvColorFormat_A2R10G10B10_sRGB = 0x0200D12020UL,
    NvColorFormat_B10G10R10A2_sRGB = 0x02060A2320UL,
    NvColorFormat_R10G10B10A2_sRGB = 0x0206882320UL,
    NvColorFormat_X8B8G8R8_sRGB = 0x020A532120UL,
    NvColorFormat_X16B16G16R16_sRGB = 0x020A532740UL,
    NvColorFormat_A2B10G10R10_709 = 0x0300532020UL,
    NvColorFormat_A8B8G8R8_709 = 0x0300532120UL,
    NvColorFormat_A16B16G16R16_709 = 0x0300532740UL,
    NvColorFormat_A2R10G10B10_709 = 0x0300D12020UL,
    NvColorFormat_B10G10R10A2_709 = 0x03060A2320UL,
    NvColorFormat_R10G10B10A2_709 = 0x0306882320UL,
    NvColorFormat_X8B8G8R8_709 = 0x030A532120UL,
    NvColorFormat_X16B16G16R16_709 = 0x030A532740UL,
    NvColorFormat_A2B10G10R10_709_Linear = 0x0400532020UL,
    NvColorFormat_A8B8G8R8_709_Linear = 0x0400532120UL,
    NvColorFormat_A16B16G16R16_709_Linear = 0x0400532740UL,
    NvColorFormat_A2R10G10B10_709_Linear = 0x0400D12020UL,
    NvColorFormat_B10G10R10A2_709_Linear = 0x04060A2320UL,
    NvColorFormat_R10G10B10A2_709_Linear = 0x0406882320UL,
    NvColorFormat_X8B8G8R8_709_Linear = 0x040A532120UL,
    NvColorFormat_X16B16G16R16_709_Linear = 0x040A532740UL,
    NvColorFormat_Float_A16B16G16R16_scRGB_Linear = 0x0500536740UL,
    NvColorFormat_A2B10G10R10_2020 = 0x0600532020UL,
    NvColorFormat_A8B8G8R8_2020 = 0x0600532120UL,
    NvColorFormat_A16B16G16R16_2020 = 0x0600532740UL,
    NvColorFormat_A2R10G10B10_2020 = 0x0600D12020UL,
    NvColorFormat_B10G10R10A2_2020 = 0x06060A2320UL,
    NvColorFormat_R10G10B10A2_2020 = 0x0606882320UL,
    NvColorFormat_X8B8G8R8_2020 = 0x060A532120UL,
    NvColorFormat_X16B16G16R16_2020 = 0x060A532740UL,
    NvColorFormat_A2B10G10R10_2020_Linear = 0x0700532020UL,
    NvColorFormat_A8B8G8R8_2020_Linear = 0x0700532120UL,
    NvColorFormat_A16B16G16R16_2020_Linear = 0x0700532740UL,
    NvColorFormat_Float_A16B16G16R16_2020_Linear = 0x0700536740UL,
    NvColorFormat_A2R10G10B10_2020_Linear = 0x0700D12020UL,
    NvColorFormat_B10G10R10A2_2020_Linear = 0x07060A2320UL,
    NvColorFormat_R10G10B10A2_2020_Linear = 0x0706882320UL,
    NvColorFormat_X8B8G8R8_2020_Linear = 0x070A532120UL,
    NvColorFormat_X16B16G16R16_2020_Linear = 0x070A532740UL,
    NvColorFormat_Float_A16B16G16R16_2020_PQ = 0x0800536740UL,
    NvColorFormat_A4I4 = 0x0901210508UL,
    NvColorFormat_A8I8 = 0x0901210E10UL,
    NvColorFormat_I4A4 = 0x0903200508UL,
    NvColorFormat_I8A8 = 0x0903200E10UL,
    NvColorFormat_I1 = 0x0909200101UL,
    NvColorFormat_I2 = 0x0909200202UL,
    NvColorFormat_I4 = 0x0909200304UL,
    NvColorFormat_I8 = 0x0909200408UL,
    NvColorFormat_A8Y8U8V8 = 0x0A00D12120UL,
    NvColorFormat_A16Y16U16V16 = 0x0A00D12740UL,
    NvColorFormat_Y8U8V8A8 = 0x0A06882120UL,
    NvColorFormat_V8_U8 = 0x0A080C0710UL,
    NvColorFormat_V8U8 = 0x0A080C0E10UL,
    NvColorFormat_V10U10 = 0x0A08142220UL,
    NvColorFormat_V12U12 = 0x0A08142420UL,
    NvColorFormat_V8 = 0x0A08240408UL,
    NvColorFormat_V10 = 0x0A08240F10UL,
    NvColorFormat_V12 = 0x0A08241010UL,
    NvColorFormat_U8_V8 = 0x0A08440710UL,
    NvColorFormat_U8V8 = 0x0A08440E10UL,
    NvColorFormat_U10V10 = 0x0A08842220UL,
    NvColorFormat_U12V12 = 0x0A08842420UL,
    NvColorFormat_U8 = 0x0A09040408UL,
    NvColorFormat_U10 = 0x0A09040F10UL,
    NvColorFormat_U12 = 0x0A09041010UL,
    NvColorFormat_Y8 = 0x0A09200408UL,
    NvColorFormat_Y10 = 0x0A09200F10UL,
    NvColorFormat_Y12 = 0x0A09201010UL,
    NvColorFormat_YVYU = 0x0A0A500810UL,
    NvColorFormat_VYUY = 0x0A0A500910UL,
    NvColorFormat_YUYV = 0x0A0A880810UL,
    NvColorFormat_UYVY = 0x0A0A880910UL,
    NvColorFormat_Y8_U8_V8 = 0x0A0A881918UL,
    NvColorFormat_V8_U8_RR = 0x0B080C0710UL,
    NvColorFormat_V8U8_RR = 0x0B080C0E10UL,
    NvColorFormat_V8_RR = 0x0B08240408UL,
    NvColorFormat_U8_V8_RR = 0x0B08440710UL,
    NvColorFormat_U8V8_RR = 0x0B08440E10UL,
    NvColorFormat_U8_RR = 0x0B09040408UL,
    NvColorFormat_Y8_RR = 0x0B09200408UL,
    NvColorFormat_V8_U8_ER = 0x0C080C0710UL,
    NvColorFormat_V8U8_ER = 0x0C080C0E10UL,
    NvColorFormat_V8_ER = 0x0C08240408UL,
    NvColorFormat_U8_V8_ER = 0x0C08440710UL,
    NvColorFormat_U8V8_ER = 0x0C08440E10UL,
    NvColorFormat_U8_ER = 0x0C09040408UL,
    NvColorFormat_Y8_ER = 0x0C09200408UL,
    NvColorFormat_V8_U8_709 = 0x0D080C0710UL,
    NvColorFormat_V8U8_709 = 0x0D080C0E10UL,
    NvColorFormat_V10U10_709 = 0x0D08142220UL,
    NvColorFormat_V12U12_709 = 0x0D08142420UL,
    NvColorFormat_V8_709 = 0x0D08240408UL,
    NvColorFormat_V10_709 = 0x0D08240F10UL,
    NvColorFormat_V12_709 = 0x0D08241010UL,
    NvColorFormat_U8_V8_709 = 0x0D08440710UL,
    NvColorFormat_U8V8_709 = 0x0D08440E10UL,
    NvColorFormat_U10V10_709 = 0x0D08842220UL,
    NvColorFormat_U12V12_709 = 0x0D08842420UL,
    NvColorFormat_U8_709 = 0x0D09040408UL,
    NvColorFormat_U10_709 = 0x0D09040F10UL,
    NvColorFormat_U12_709 = 0x0D09041010UL,
    NvColorFormat_Y8_709 = 0x0D09200408UL,
    NvColorFormat_Y10_709 = 0x0D09200F10UL,
    NvColorFormat_Y12_709 = 0x0D09201010UL,
    NvColorFormat_V8_U8_709_ER = 0x0E080C0710UL,
    NvColorFormat_V8U8_709_ER = 0x0E080C0E10UL,
    NvColorFormat_V10U10_709_ER = 0x0E08142220UL,
    NvColorFormat_V12U12_709_ER = 0x0E08142420UL,
    NvColorFormat_V8_709_ER = 0x0E08240408UL,
    NvColorFormat_V10_709_ER = 0x0E08240F10UL,
    NvColorFormat_V12_709_ER = 0x0E08241010UL,
    NvColorFormat_U8_V8_709_ER = 0x0E08440710UL,
    NvColorFormat_U8V8_709_ER = 0x0E08440E10UL,
    NvColorFormat_U10V10_709_ER = 0x0E08842220UL,
    NvColorFormat_U12V12_709_ER = 0x0E08842420UL,
    NvColorFormat_U8_709_ER = 0x0E09040408UL,
    NvColorFormat_U10_709_ER = 0x0E09040F10UL,
    NvColorFormat_U12_709_ER = 0x0E09041010UL,
    NvColorFormat_Y8_709_ER = 0x0E09200408UL,
    NvColorFormat_Y10_709_ER = 0x0E09200F10UL,
    NvColorFormat_Y12_709_ER = 0x0E09201010UL,
    NvColorFormat_V10U10_2020 = 0x0F08142220UL,
    NvColorFormat_V12U12_2020 = 0x0F08142420UL,
    NvColorFormat_V10_2020 = 0x0F08240F10UL,
    NvColorFormat_V12_2020 = 0x0F08241010UL,
    NvColorFormat_U10V10_2020 = 0x0F08842220UL,
    NvColorFormat_U12V12_2020 = 0x0F08842420UL,
    NvColorFormat_U10_2020 = 0x0F09040F10UL,
    NvColorFormat_U12_2020 = 0x0F09041010UL,
    NvColorFormat_Y10_2020 = 0x0F09200F10UL,
    NvColorFormat_Y12_2020 = 0x0F09201010UL,
    NvColorFormat_Bayer8RGGB = 0x1009200408UL,
    NvColorFormat_Bayer16RGGB = 0x1009200A10UL,
    NvColorFormat_BayerS16RGGB = 0x1009208A10UL,
    NvColorFormat_X2Bayer14RGGB = 0x1009210B10UL,
    NvColorFormat_X4Bayer12RGGB = 0x1009210C10UL,
    NvColorFormat_X6Bayer10RGGB = 0x1009210D10UL,
    NvColorFormat_Bayer8BGGR = 0x1109200408UL,
    NvColorFormat_Bayer16BGGR = 0x1109200A10UL,
    NvColorFormat_BayerS16BGGR = 0x1109208A10UL,
    NvColorFormat_X2Bayer14BGGR = 0x1109210B10UL,
    NvColorFormat_X4Bayer12BGGR = 0x1109210C10UL,
    NvColorFormat_X6Bayer10BGGR = 0x1109210D10UL,
    NvColorFormat_Bayer8GRBG = 0x1209200408UL,
    NvColorFormat_Bayer16GRBG = 0x1209200A10UL,
    NvColorFormat_BayerS16GRBG = 0x1209208A10UL,
    NvColorFormat_X2Bayer14GRBG = 0x1209210B10UL,
    NvColorFormat_X4Bayer12GRBG = 0x1209210C10UL,
    NvColorFormat_X6Bayer10GRBG = 0x1209210D10UL,
    NvColorFormat_Bayer8GBRG = 0x1309200408UL,
    NvColorFormat_Bayer16GBRG = 0x1309200A10UL,
    NvColorFormat_BayerS16GBRG = 0x1309208A10UL,
    NvColorFormat_X2Bayer14GBRG = 0x1309210B10UL,
    NvColorFormat_X4Bayer12GBRG = 0x1309210C10UL,
    NvColorFormat_X6Bayer10GBRG = 0x1309210D10UL,
    NvColorFormat_XYZ = 0x140A886640UL,
} NvColorFormat;
