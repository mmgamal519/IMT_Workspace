/*
 * SevSEG2X1_Config.h
 *
 *  Created on: Jun 1, 2020
 *      Author: MGIsmail
 */

#ifndef  _SEVSEG2X1_CONFIG_H_
#define _SEVSEG2X1_CONFIG_H_

// As is to show port as number from 0 to 3
#define PORT_A 		0
#define PORT_B 		1
#define PORT_C 		2
#define PORT_D 		3
// for common Anode  set Enable=>1 and Disable =>0, for Comm Cathod set Enable=>0 and Disable =>1
#define Enable		1
#define Disable	0
// Port Config for 7segment 2x1 two using same port of data
#define _7seg2x1_DataPort			PORT_C
#define _7seg2x1_CTRLPort 		PORT_B
#define _7seg2x1_CTRLRP 			PIN0				// CTRL pin for Right 7Segment
#define _7seg2x1_CTRLLP 			PIN1				// CTRL pin for Left 7Segment
#define _7seg2x1_Refresh			10				//to adjust refresh rate of 7 segments



#endif /* SevSEG2X1_CONFIG_H_ */
