#include <stdio.h>
#include <ctype.h>

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
	char tmp;
	int cnt;
	ps = 0;
	cnt = 0;
	now = buf-1;
	do 
	{
		now++;
		if(*now  == ' ' || *now == '.' || *now == ',' || *now == '\n' || *now == '\0')
		{
			if(ps && (cnt+1)%2)
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
			tmp = tolower(*now);
			if(tmp  == 'a' || tmp == 'e' || tmp == 'y' || tmp == 'u' || tmp == 'i' || tmp == 'o')cnt++;
		}
	}while(*now);
}
