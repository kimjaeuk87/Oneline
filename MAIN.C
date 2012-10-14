#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include "print.h"

void print_chang();	// 테두리 네모
void print_chang2(); // 안의 이중 네모
void print_chang3(); // 밑 세번째 네모
void print_gak();	// 테두리 「,ㄴ,ㄱ,」배치
void print_jul();	// 가로선 긎기
void print_gak2();	// 이중 네모 데두리 「,ㄴ,ㄱ,」배치 
void print_gak3();  // 밑 세번째 네모 「,ㄴ,ㄱ,」배치
void print_Menu();	// Menu 문자열 출력


static unsigned int x;
static unsigned int y;

int main()
{

	clrscr();
	
	print_chang();	// 테두리 네모
	print_chang2();	// 안의 이중 네모
	print_chang3();	// 밑 세번째 네모

	print_Menu();	// Menu 문자열 출력

	
	VGA_inverse_bar(7, 3, 5);

	getche();
	return 0;
}


void print_jul() // ㅓ ㅏ
{
	print_char (1, 5, PEN_RC, 7);
	print_char (X_MAX-1, 5, PEN_LC, 7);
	for (x = 2; x <= X_MAX-2; x++)
	{
		print_char (x, 5, GARO, 7);
	}
}

void print_gak() // // 「,ㄴ,ㄱ,」
{
	print_char (1, 1, PEN_RT, 7);
	print_char (1, Y_MAX-1, PEN_RD, 7);
	print_char (X_MAX-1, 1, PEN_LT, 7);
	print_char (X_MAX-1, Y_MAX-1, PEN_LD, 7);
}

void print_gak2() // 이중 네모 데두리 「,ㄴ,ㄱ,」배치 
{
	print_char (5, 7, PEN_RRT, 7);
	print_char (5, Y_MAX-8, PEN_RRD, 7);
	print_char (X_MAX-5, 7, PEN_LLT, 7);
	print_char (X_MAX-5, Y_MAX-8, PEN_LLD, 7);
}

void print_gak3() // 밑 세번째 네모 「,ㄴ,ㄱ,」배치
{
	print_char (5, Y_MAX-6, PEN_RT, 7);
	print_char (5, Y_MAX-2, PEN_RD, 7);
	print_char (X_MAX-5, Y_MAX-6, PEN_LT, 7);
	print_char (X_MAX-5, Y_MAX-2, PEN_LD, 7);
}

void print_chang() 	// 테두리 네모
{
	print_gak();

	for (x = 2; x <= X_MAX-2; x++)
	{
		for (y = 2; y <= Y_MAX-2; y++)
		{
			print_char (x, 1, GARO, 7);
			print_char (x, Y_MAX-1, GARO, 7);
			print_char (1, y, SERO, 7);
			print_char (X_MAX-1, y, SERO, 7);
		}
	}
	print_jul();
}

void print_chang2() // 안의 이중 네모
{
	print_gak2();
	for (x = 6; x <= X_MAX-6; x++)
	{
		for (y = 8; y <= Y_MAX-9; y++)
		{
			print_char (x, 7, PEN_GARO, 7);
			print_char (x, Y_MAX-8, PEN_GARO, 7);
			print_char (5, y , PEN_SERO, 7);
			print_char (X_MAX-5, y, 186, 7);
		}
	}
}

void print_chang3() //  밑 세번째 네모
{
	print_gak3();
	for (x = 6; x <= X_MAX-6; x++)
	{
		for (y = Y_MAX-5; y <= Y_MAX-3; y++)
		{
			print_char (x, Y_MAX-6, GARO, 7);
			print_char (x, Y_MAX-2, GARO, 7);
			print_char (5, y, SERO, 7);
			print_char (X_MAX-5, y, SERO, 7);
		}
	}
}

void print_Menu() //Menu 문자열 출력
{
	print_string(8, 3, "New          Load          Save          Save as           Exit", 7);

	print_string(13, 20, "F10 - Menu          Alt + x - Exit          F1 - Help", 7);
}

