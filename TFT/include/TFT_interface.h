/*****************************************/
/* Author  :  Ahmed ALAA                 */
/* Date    : 21/9/2020                   */
/* Version :  V01            			 */
/*****************************************/


#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInitialize(void);
void HTFT_voidDisplayImage(const u16* Copy_Image);
void HTFT_voidFillColor(u16 Copy_u16color);
void HTFT_voidDrawRect(u8 x1,u8 x2,u8 y1,u8 y2, u16 Copy_u16color);
void HTFT_voidDrawLine(u8 x1,u8 x2,u8 y1,u8 y2, u16 Copy_u16color);
void HTFT_voidDrawchar(u8 x1,u8 y1, u16 Copy_u16color);


#endif
