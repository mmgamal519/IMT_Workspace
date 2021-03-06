#ifndef  _SEVSEG2X1_REGISTER_H_ //Header guard if not defined
#define  _SEVSEG2X1_REGISTER_H_

#define Zero			0b11000000//0
#define One			0b11111001//1
#define Two			0b10100100//2
#define Three		0b10110000//3
#define Four			0b10011001//4
#define Five			0b10010010//5
#define Six			0b10000010//6
#define Seven		0b11111000//7
#define Eight		0b10000000//8
#define Nine			0b10010000//9

//
//int _7Seg_loading_array_Right[4]={0b11111110, 0b11111101, 0b11111011, 0b11110111};
//int _7Seg_loading_array_Left [4]={0b11110111, 0b11101111, 0b11011111, 0b11111110};
#define R7seg_loadA		0b11111110
#define R7seg_loadB		0b11111101
#define R7seg_loadC		0b11111011
#define R7seg_loadD		0b11110111
#define L7seg_loadA		0b11110111
#define L7seg_loadB		0b11101111
#define L7seg_loadC		0b11011111
#define L7seg_loadD		0b11111110

#define SevSeg_loadA		0b11111110
#define SevSeg_loadB		0b11111101
#define SevSeg_loadC		0b11111011
#define SevSeg_loadD		0b11110111
#define SevSeg_loadE		0b11101111
#define SevSeg_loadF		0b11011111
#define SevSeg_loadG		0b10111111
#define SevSeg_Point		0b01111111


#endif
