#include<reg52.h>
#include<string.h>

int keypad();
void lcdinit();
void lcddata(int);
void lcdcommand(int);
void lcdstr(unsigned char *);
void msdelay(int);
char inputp[8]="\0";

void main()
{

	code char pswd[5]="\0";
	lcdinit();
	if(strcmp(pswd,"\0")==0)
		{
			lcddata("set the password");
			keypad();
			strcpy(pswd,inputp);
		}
	else
		{
		   	lcddata("enter the password");
			keypad();
			if(strcmp(pswd,inputp)==0)
			P3^1=1;
			else
			p3^1=0;
		}
}
int keypad()
{
char x;
int i=0;
 while(1)
	{
	while(1)
		{
			{P0=0x01;P0&=0x01;}
			{
			if((P1&=0x01)==0x01){while((P1&=0x01)!==0x01);x='a'break;}
			if((P1&=0x02)==0x02){while((P1&=0x02)!==0x02);x='a'break;}
			if((P1&=0x04)==0x04){while((P1&=0x04)!==0x04);x='a'break;}
			if((P1&=0x08)==0x08){while((P1&=0x08)!==0x08);x='a'break;}
			}
			{P0=0x02;P0&=0x02;}
			{
			if((P1&=0x01)==0x01){while((P1&=0x01)!==0x01);x='a'break;}
			if((P1&=0x02)==0x02){while((P1&=0x02)!==0x02);x='a'break;}
			if((P1&=0x04)==0x04){while((P1&=0x04)!==0x04);x='a'break;}
			if((P1&=0x08)==0x08){while((P1&=0x08)!==0x08);x='a'break;}
			}
			{P0=0x04;P0&=0x04;}
			{
			if((P1&=0x01)==0x01){while((P1&=0x01)!==0x01);x='a'break;}
			if((P1&=0x02)==0x02){while((P1&=0x02)!==0x02);x='a'break;}
			if((P1&=0x04)==0x04){while((P1&=0x04)!==0x04);x='a'break;}
			if((P1&=0x08)==0x08){while((P1&=0x08)!==0x08);x='a'break;}
			}
			{P0=0x08;P0&=0x08;}
			{
			if((P1&=0x01)==0x01){while((P1&=0x01)!==0x01);x='a'break;}
			if((P1&=0x02)==0x02){while((P1&=0x02)!==0x02);x='a'break;}
			if((P1&=0x04)==0x04){while((P1&=0x04)!==0x04);x='a'break;}
			if((P1&=0x08)==0x08){while((P1&=0x08)!==0x08);x='a'break;}
			}
		}
 	inputp[i++]=x;
}
}

void lcdinit()
{
P2=0x00;
msdelay(20);
P2=0x30;
msdelay(10);
P2=0x30;
msdelay(1);
P2=0x30;
msdelay(1);
P2=0x20;
msdelay(1);


lcdcmd(0x28);
lcdcmd(0x01);
lcdcmd(0x06);
lcdcmd(0x0C);
lcdcmd(0x80);
}
void lcddata(int a)
{
P2|=(1<<0);
P2&=~(1<<1);
P2=a;
P2|=(1<<2);
msdelay(2)
P2&=~(1<<2);
msdelay(2);
}

void lcdcommand(int a)
{
P2&=~(1<<0);
P2&=~(1<<1);
P2=a;
P2|=(1<<2);
msdelay(2);
P2&=~(1<<2);
msdelay(2);
}

void lcdstr(unsigned char *s)
{
while(*s)
lcddata(*s++)
}

void msdelay(int n)
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<1257;j++);
}