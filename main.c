#include <stdio.h>

#define LIMIT 1000

void processing_line(char *buf);

int main(void)
{
	char line[LIMIT];
	gets(line);
	processing_line(line);
	puts(line);
	getchar();
	getchar();
	return 0;
}

void processing_line(char *buf)
{
	char *ps;
	char *ph;
	char *pt;
	char *now;
	int cnt;
	ps = 0;
	cnt = 0;
	now = buf-1;
	do 
	{
		now++;
		if(*now  == ' ' || *now == '.' || *now == ',' || *now == '\n' || *now == '\0')
		{
			if(ps && !(cnt&1))
			{
				ph = ps;
				pt = now;
				while(*ph++ = *pt++);
				now = ps--;
			}
			cnt = 0;
			ps = 0;
		}
		else
		{
			if(!ps)	ps = now;
			if(*now  == 'a' || *now == 'e' || *now == 'y' || *now == 'u' || *now == 'i' || *now == 'o')cnt++;
		}
	}while(*now);
}
