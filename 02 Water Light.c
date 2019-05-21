#include<reg52.h>
int s[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};	
int Delay(void)
{
	int i, j;
	for (i = 0; i < 50; i++)
		for (j = 0; j < 30; j++);
		return 0;
}
int Flash()
{
	int i = 0;
	for (i = 0; i < 9; i++)
	{
		P2 = s[i];
		Delay();
	}
	return 0;
}
void main(void)
{
	while(1)
	{
		Flash();			
	}
}

