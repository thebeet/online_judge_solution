#include <stdio.h>
#include <memory.h>

#define e 0.0000001

struct task
{
	double size;
	double speed;
	double maxspeed;
	double resttime;
	double usetime;
	bool fullspeed;
	bool done;
}tasks[110];

long totalbandwidth;
long n;

bool iszero(double a)
{
	return (a < e) ? true : false;
}

long findunfull()
{
	long i, ans;
	ans = 0;
	for (i = 1; i <= n; i++)
	{
		if (iszero(tasks[i].maxspeed - tasks[i].speed) == false)
		{
			ans++;
		}
	}
	return ans;
}

void output()
{
	long i;
	for (i = 1; i <= n; i++)
	{
		printf("NO%ld:%.3lfs\n", i, tasks[i].usetime);
	}
}

double mn(double a, double b)
{
	return (a > b) ? a : b;
}

int main()
{
	long ti, i, mintimep, unfull;
	double time, gotime, freebandwidth, exbandwidth, eachbandwidth;
	bool op;
	ti = 0;
	while (scanf("%ld", &n), n > 0)
	{
		ti++;
		printf("Case %ld:\n", ti);
		scanf("%ld", &totalbandwidth);
		memset(tasks, 0, sizeof(tasks));
		tasks[0].resttime = 1e20;
		time = 0.0;
		for (i = 1; i <= n; i++)
		{
			scanf("%lf%lf%lf", &tasks[i].size, &tasks[i].speed, &tasks[i].maxspeed);
			if ((tasks[i].maxspeed - tasks[i].speed) < e) tasks[i].fullspeed = true;
			tasks[i].resttime = tasks[i].size / tasks[i].speed;
		}
		freebandwidth = 0;
		while (1)
		{
			//find the fast task
			mintimep = 0;
			for (i = 1; i <= n; i++)
			{
				if ((tasks[i].done == false) && (tasks[i].resttime < tasks[mintimep].resttime))
				{
					mintimep = i;
				}
			}
			if (mintimep == 0) break;
			gotime = tasks[mintimep].resttime;
			time += gotime;
			//exec download 
			for (i = 1; i <= n; i++)
			{
				if (tasks[i].done == false)
				{
					tasks[i].size -= (gotime * tasks[i].speed);
					if (iszero(tasks[i].size))
					{
						tasks[i].done = true;
						tasks[i].usetime = time;
						freebandwidth += tasks[i].speed;
					}
				}
			}
			//disturble the free bandwidth
			op = true;
			while ((iszero(freebandwidth) == false) && op)
			{
				op = false;
				unfull = findunfull();
				eachbandwidth = freebandwidth / unfull;
				for (i = 1; i <= n; i++)
				{
					if ((tasks[i].done || tasks[i].fullspeed) == false)
					{
						op = true;
						exbandwidth = mn(tasks[i].fullspeed - tasks[i].speed, eachbandwidth);
						freebandwidth -= exbandwidth;
						tasks[i].speed += exbandwidth;
						if ((tasks[i].maxspeed - tasks[i].speed) < e) tasks[i].fullspeed = true;
					}
				}
			}
			if (op == false)
			{
				for (i = 1; i <= n; i++)
				{
					if (tasks[i].done == false)
					{
						tasks[i].usetime = time + tasks[i].size / tasks[i].speed;
					}
				}
				break;
			}
		}
		output();
	}
	return 0;
}









