#ifndef __VB_VIP_H
#define __VB_VIP_H

enum
{
 VIP_GSREG_IPENDING = 0,	// Current pending interrupt(bits)
 VIP_GSREG_IENABLE,

 VIP_GSREG_DPCTRL,

 VIP_GSREG_BRTA,
 VIP_GSREG_BRTB,
 VIP_GSREG_BRTC,
 VIP_GSREG_REST,
 VIP_GSREG_FRMCYC,
 VIP_GSREG_XPCTRL,

 VIP_GSREG_SPT0,
 VIP_GSREG_SPT1,
 VIP_GSREG_SPT2,
 VIP_GSREG_SPT3,

 VIP_GSREG_GPLT0,
 VIP_GSREG_GPLT1,
 VIP_GSREG_GPLT2,
 VIP_GSREG_GPLT3,

 VIP_GSREG_JPLT0,
 VIP_GSREG_JPLT1,
 VIP_GSREG_JPLT2,
 VIP_GSREG_JPLT3,

 VIP_GSREG_BKCOL
};

bool VIP_Init(void) MDFN_COLD;
void VIP_Power(void) MDFN_COLD;

void VIP_SetInstantDisplayHack(bool);
void VIP_SetAllowDrawSkip(bool);
void VIP_Set3DMode(uint32 mode, bool reverse, uint32 prescale, uint32 sbs_separation);
void VIP_SetParallaxDisable(bool disabled);
void VIP_SetDefaultColor(uint32 default_color);
void VIP_SetAnaglyphColors(uint32 lcolor, uint32 rcolor);	// R << 16, G << 8, B << 0

v810_timestamp_t MDFN_FASTCALL VIP_Update(const v810_timestamp_t timestamp);
void VIP_ResetTS(void);

void VIP_StartFrame(EmulateSpecStruct *espec);

uint8 VIP_Read8(v810_timestamp_t &timestamp, uint32 A);
uint16 VIP_Read16(v810_timestamp_t &timestamp, uint32 A);

void VIP_Write8(v810_timestamp_t &timestamp, uint32 A, uint8 V);
void VIP_Write16(v810_timestamp_t &timestamp, uint32 A, uint16 V);

int VIP_StateAction(StateMem *sm, int load, int data_only);

uint32 VIP_GetRegister(const unsigned int id, char *special, const uint32 special_len);
void VIP_SetRegister(const unsigned int id, const uint32 value);

extern uint8 BRTA, BRTB, BRTC, REST;
extern uint8 Repeat;
extern uint16 CHR_RAM[0x8000 / sizeof(uint16)];
extern uint16 DRAM[0x20000 / sizeof(uint16)];
extern uint16 FRMCYC;

extern uint16 DPCTRL;
extern bool DisplayActive;

//#define XPCTRL_XP_RST	0x0001
//#define XPCTRL_XP_EN	0x0002
extern uint16 XPCTRL;
extern uint16 SBCMP;	// Derived from XPCTRL

extern uint16 SPT[4];	// SPT0~SPT3, 5f848~5f84e
extern uint16 GPLT[4];
extern uint8 GPLT_Cache[4][4];
extern float VBLEDOnScale;
extern uint32 VB3DMode;
extern uint32 VB3DReverse;
extern uint32 VBPrescale;
extern uint32 VBSBS_Separation;
extern uint32 HLILUT[256];
extern uint32 ColorLUT[2][256];
extern int32 BrightnessCache[4];
extern uint32 BrightCLUT[2][4];

extern double ColorLUTNoGC[2][256][3];
extern uint32 AnaSlowColorLUT[256][256];

// A few settings:
extern bool InstantDisplayHack;
extern bool AllowDrawSkip;

extern bool VidSettingsDirty;
extern bool ParallaxDisabled;
extern uint32 Anaglyph_Colors[2];
extern uint32 Default_Color;

extern uint16 BKCOL;

extern int32 last_ts;

extern int32 Column;
extern int32 ColumnCounter;

extern int32 DisplayRegion;
extern bool DisplayFB;

extern int32 GameFrameCounter;

extern int32 DrawingCounter;
extern bool DrawingActive;
extern bool DrawingFB;
extern uint32 DrawingBlock;
extern int32 SB_Latch;
extern int32 SBOUT_InactiveTime;

extern bool g_debug_show_world[32];
extern bool g_bg_tiles_modified[0x20000 / sizeof(uint16)];

#endif
