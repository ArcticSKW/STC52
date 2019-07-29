#include<reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
#define xA 10	//define hex number from A-F
#define xB 11
#define xC 12
#define xD 13
#define xE 14
#define xF 15
sbit gA = P2^2;		//define 38 decoder			
sbit gB = P2^3;			
sbit gC = P2^4;					
uchar ct[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};		//define hex number array
uint dt[][8] = {{1,0,1,0,1,0,1,0},{1,1,0,0,1,1,0,0},{1,1,1,1,0,0,0,0}};		 //define digital tube number
uint i, j;	// for Delay()
void Delay(uint y);
void Out(uint a,uint b);
void give(uint x);
void main()
{
	 while(1)
	 {
		Out(0,xA);
		Out(1,xB);
		Out(3,xD);
		Out(4,xE);				   
		Out(2,xC);
		Out(5,xF);
	 }
}

void Out(uint a,uint b)		 //a = numb of digital tube,b = number you want
{
	give(a);
	P0 = ct[b];
	Delay(3);
}
void give(uint x)	//x from 0-7
{
	gA = dt[0][x];
	gB = dt[1][x];
	gC = dt[2][x];
}

void Delay(uint y)
{
	for(i = y; i > 0; i--)
		for(j = 110; j > 0; j--);
}
