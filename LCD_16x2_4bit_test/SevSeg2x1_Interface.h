#ifndef  _SEVSEG2X1_INTERFACE_H_ //Header guard if not defined
#define  _SEVSEG2X1_INTERFACE_H_
#define On 1
#define Off 0





void SevSeg2x1_VidInit(void);
void SevSeg2x1_VidDisplayRightDigit(u8 LOC_u8Digit);
void SevSeg2x1_VidDisplayLeftDigit(u8 LOC_u8Digit);

void SevSeg2x1_VidCountUp(u8 LOC_u8Start, u8 LOC_u8End);

void SevSeg2x1_VidCountDown(u8 LOC_u8Start, u8 LOC_u8End);

void SevSeg2x1_VidLoading(u16 LOC_u8Speed);














#endif
