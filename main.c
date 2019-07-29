#include<reg52.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit gA = P2^2;		//define 38 decoder			
sbit gB = P2^3;			
sbit gC = P2^4;					
uchar ct[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};		//define hex number array
uint dt[][8] = {{1,0,1,0,1,0,1,0},{1,1,0,0,1,1,0,0},{1,1,1,1,0,0,0,0}};		 //define digital tube number
uint i, j;	// for Delay()
uchar m = 0,n = 0,num;
void Delay(uint y);
void Out(uint a,uint b);
void give(uint x);
void main()
{
	TMOD = 0x01;
	TH0 = (65536-45872)/256;
	TL0 = (65536-45872)%256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	while(1)
	{	 
		if(num == 22)
		{
			num = 0;
			n++;
			if(n > 9)
			{	
				n = 0;
				m++;
				if (m > 5)
					m = 0;
			}
		}
		Out(1,n);
		Out(0,m);
		
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
		for(j = 120; j > 0; j--);
}
void T0_Time() interrupt 1
{
	TMOD = 0x01;
	TH0 = (65536-45872)/256;
	TL0 = (65536-45872)%256;
	num++;
		
}