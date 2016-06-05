#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct person
{
	double x, y, vx, vy;
	double v2;
	double finishtime;
}persons[16];

int perm[16];

double gv, gv2;

double getperson(double &x0, double &y0, int pid, double &nowtime)
{
	double dx(persons[pid].x + persons[pid].vx * nowtime - x0);
	double dy(persons[pid].y + persons[pid].vy * nowtime - y0);
	double a(gv2 - persons[pid].v2);
	double b(-2.0 * (persons[pid].vx * dx + persons[pid].vy * dy));
	double c(-dx * dx - dy * dy);
	double ans = (-b + sqrt(b * b - 4.0 * a * c)) / (2.0 * a);
	nowtime += ans;
	x0 = persons[pid].x + persons[pid].vx * nowtime;
	y0 = persons[pid].y + persons[pid].vy * nowtime;
	persons[pid].finishtime = nowtime + sqrt(((x0 * x0) + (y0 * y0)) / persons[pid].v2); 
	return ans;
}

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		int i, j, fact;
		scanf("%lf", &gv);
		gv2 = gv * gv;
		fact = 1;
		for (i = 0; i < n; ++i)
		{
			fact *= (i + 1);
			perm[i] = i;
			double a, v;
			scanf("%lf%lf%lf%lf", &persons[i].x, &persons[i].y, &v, &a);
			persons[i].vx = v * cos(a);
			persons[i].vy = v * sin(a);
			persons[i].v2 = v * v;
		}
		
		double ans(1e100);
		for (j = 0; j <= fact; ++j)
		{
			double x(0.0);
			double y(0.0);
			double tans(0.0);
			double nowtime(0.0);
			for (i = 0; i < n; ++i)
			{
				getperson(x, y, perm[i], nowtime);
				tans = max(tans, persons[perm[i]].finishtime);
			}
			ans = min(ans, tans);
			next_permutation(perm, perm + n);
		}
		printf("%d\n", (int)(ans + 0.5));
	}
	return 0;
}
