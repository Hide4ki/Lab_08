#include <stdio.h>

#define LIMIT 1000
#define gets(s) fgets((s),sizeof(s),stdin)

void processing_line(char *buf);

int main(void)
{
	char line[LIMIT];
	gets(line);
	processing_line(line);
	puts(line);
	getchar();
	return 0;
}

void processing_line(char *buf)
{
	char *ps;     //pointer start word 
	char *pt;	  //pointer tmp
	char *now;	  //pointer to current character
	int cnt;      //counter
	int flag;   
	flag = 0;
	ps = 0;
	cnt = 0;
	now = buf-1;
	do 
	{
		now++; //next character
		if((*now < 'A' || *now > 'Z') && (*now < 'a' || *now > 'z') && (*now < '0' || *now > '9'))//check end of word
		{
			if(ps && !(cnt&1) && !flag)//there is a word start and even number vowels
			{
				pt = ps;//remember start is deleteing word
				while(*ps++ = *now++);//deleting word
				now = pt-1;//return pointer on correct character
			}
			flag = 0;
			cnt = 0;//zeroing the counter
			ps = 0;//zeroing the pointer start 
		}
		else
		{
			ps = ((!ps)?now:ps);//if there is no start, let's remeber start
			if(*now>='0'&&*now<='9') flag = 1;
			cnt += *now  == 'a' | *now == 'e' | *now == 'u' | *now == 'i' | *now == 'o';//if character is vowels, then +1 to counter
		}
	}while(*now);
}
