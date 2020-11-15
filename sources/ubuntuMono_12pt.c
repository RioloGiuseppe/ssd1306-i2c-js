// 
//  Font data for Ubuntu Mono 12pt
// 
#include "stdint.h"
#include "font.h"

// Character bitmaps for Ubuntu Mono 12pt
const uint8_t ubuntuMono_12ptBitmaps[] = 
{
	// @0 'E' (6 pixels wide)
	0x00, //       
	0xFC, // ######
	0x80, // #     
	0x80, // #     
	0x80, // #     
	0xF8, // ##### 
	0x80, // #     
	0x80, // #     
	0x80, // #     
	0x80, // #     
	0xFC, // ######
	0x00, //       
	0x00, //       
	0x00, //       

	// @14 'a' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       
	0x78, //  #### 
	0x04, //      #
	0x04, //      #
	0x7C, //  #####
	0x84, // #    #
	0x84, // #    #
	0x7C, //  #####
	0x00, //       
	0x00, //       
	0x00, //       

	// @28 'e' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       
	0x78, //  #### 
	0x84, // #    #
	0x84, // #    #
	0xFC, // ######
	0x80, // #     
	0x80, // #     
	0x78, //  #### 
	0x00, //       
	0x00, //       
	0x00, //       

	// @42 'g' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       
	0x7C, //  #####
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x7C, //  #####
	0x04, //      #
	0x04, //      #
	0xF8, // ##### 

	// @56 'h' (6 pixels wide)
	0x80, // #     
	0x80, // #     
	0x80, // #     
	0x80, // #     
	0xF8, // ##### 
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x00, //       
	0x00, //       
	0x00, //       

	// @70 'n' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       
	0xF8, // ##### 
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x00, //       
	0x00, //       
	0x00, //       

	// @84 'o' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       
	0x78, //  #### 
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x78, //  #### 
	0x00, //       
	0x00, //       
	0x00, //       

	// @98 'r' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0xF8, // #####
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x00, //      
	0x00, //      
	0x00, //      

	// @112 't' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x20, //   #   
	0x20, //   #   
	0xFC, // ######
	0x20, //   #   
	0x20, //   #   
	0x20, //   #   
	0x20, //   #   
	0x20, //   #   
	0x1C, //    ###
	0x00, //       
	0x00, //       
	0x00, //       

	// @126 'x' (7 pixels wide)
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x82, // #     #
	0x44, //  #   # 
	0x28, //   # #  
	0x10, //    #   
	0x28, //   # #  
	0x44, //  #   # 
	0x82, // #     #
	0x00, //        
	0x00, //        
	0x00, //        
};

// Character descriptors for Ubuntu Mono 12pt
// { [Char width in bits], [Offset into ubuntuMono_12ptCharBitmaps in bytes] }
const FONT_CHAR_INFO ubuntuMono_12ptDescriptors[] = 
{
	{6, 0}, 		// E 
	{0, 0}, 		// F 
	{0, 0}, 		// G 
	{0, 0}, 		// H 
	{0, 0}, 		// I 
	{0, 0}, 		// J 
	{0, 0}, 		// K 
	{0, 0}, 		// L 
	{0, 0}, 		// M 
	{0, 0}, 		// N 
	{0, 0}, 		// O 
	{0, 0}, 		// P 
	{0, 0}, 		// Q 
	{0, 0}, 		// R 
	{0, 0}, 		// S 
	{0, 0}, 		// T 
	{0, 0}, 		// U 
	{0, 0}, 		// V 
	{0, 0}, 		// W 
	{0, 0}, 		// X 
	{0, 0}, 		// Y 
	{0, 0}, 		// Z 
	{0, 0}, 		// [ 
	{0, 0}, 		// \ 
	{0, 0}, 		// ] 
	{0, 0}, 		// ^ 
	{0, 0}, 		// _ 
	{0, 0}, 		// ` 
	{6, 14}, 		// a 
	{0, 0}, 		// b 
	{0, 0}, 		// c 
	{0, 0}, 		// d 
	{6, 28}, 		// e 
	{0, 0}, 		// f 
	{6, 42}, 		// g 
	{6, 56}, 		// h 
	{0, 0}, 		// i 
	{0, 0}, 		// j 
	{0, 0}, 		// k 
	{0, 0}, 		// l 
	{0, 0}, 		// m 
	{6, 70}, 		// n 
	{6, 84}, 		// o 
	{0, 0}, 		// p 
	{0, 0}, 		// q 
	{5, 98}, 		// r 
	{0, 0}, 		// s 
	{6, 112}, 		// t 
	{0, 0}, 		// u 
	{0, 0}, 		// v 
	{0, 0}, 		// w 
	{7, 126}, 		// x 
};

// Font information for Ubuntu Mono 12pt
const FONT_INFO ubuntuMono_12ptFontInfo =
{
	2, //  Character height
	'E', //  Start character
	'x', //  End character
	2, //  Width, in pixels, of space character
	ubuntuMono_12ptDescriptors, //  Character descriptor array
	ubuntuMono_12ptBitmaps, //  Character bitmap array
};

