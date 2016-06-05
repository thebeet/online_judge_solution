#include <stdio.h>

struct t_time
{
	int hh, mm, ss;
};

int main()
{
	t_time now_time;
	int new_time = 0;
	int old_time = 0;
	int nowspeed = 0;
	int nowdistance = 0;
	while (scanf("%d:%d:%d", &now_time.hh, &now_time.mm, &now_time.ss) != EOF)
	{
		char inp;
		new_time = now_time.ss + (now_time.mm + now_time.hh * 60) * 60;
		nowdistance += (new_time - old_time) * nowspeed;
		scanf("%c", &inp);
		if (inp == ' ')
		{
			scanf("%d", &nowspeed);
		}
		else
		{
			printf("%02d:%02d:%02d %.2lf km\n", now_time.hh, now_time.mm, now_time.ss, nowdistance / 3600.0);
		}
		old_time = new_time;
	}
	return 0;
}
