#include <stdio.h>
#include <memory.h>

long st[1000000][7];
long stn, sted;
long ts[7][7][7][7][7][7][7];
char inp[10];

void insert(long f, long t)
{
	sted++;
	memcpy(st[sted], st[stn], sizeof(st[stn]));
	st[sted][f] = st[stn][t];
	st[sted][t] = st[stn][f];
	if (ts[st[sted][0]][st[sted][1]][st[sted][2]][st[sted][3]][st[sted][4]][st[sted][5]][st[sted][6]] < 1000000)
	{
		sted--;
	}
	else
	{
		ts[st[sted][0]][st[sted][1]][st[sted][2]][st[sted][3]][st[sted][4]][st[sted][5]][st[sted][6]] = ts[st[stn][0]][st[stn][1]][st[stn][2]][st[stn][3]][st[stn][4]][st[stn][5]][st[stn][6]] + 1; 
	}
}

long findzero(long p)
{
	long i;
	for (i = 0; i <= 6; i++)
	{
		if (st[p][i] == 0) return i;
	}
}

int main()
{
	long ti, tn, i, m, t, p0, ans;
	memset(ts, 1, sizeof(ts));
	memset(st, 0, sizeof(st));
	ts[0][1][2][3][4][5][6] = 0;
	stn = 1;
	sted = 1;
	for (i = 0; i <= 6; i++)
	{
		st[1][i] = i;
	}
	while (stn <= sted)
	{
		p0 = findzero(stn);
		switch (p0)
		{
			case 0:
			{
				insert(0, 2);
				insert(0, 4);
				insert(0, 6);
				break;
			}
			case 1:
			{
				insert(1, 2);
				insert(1, 6);
				break;
			}
			case 2:
			{
				insert(0, 2);
				insert(1, 2);
				insert(2, 3);
				break;
			}
			case 3:
			{
				insert(3, 2);
				insert(3, 4);
				break;
			}
			case 4:
			{
				insert(0, 4);
				insert(3, 4);
				insert(4, 5);
				break;
			}
			case 5:
			{
				insert(5, 6);
				insert(5, 4);
				break;
			}
			case 6:
			{
				insert(0, 6);
				insert(1, 6);
				insert(6, 5);
				break;
			}
		}
		stn++;
	}
	scanf("%ld", &tn);
	for (ti = 1; ti <= tn; ti++)
	{
		scanf("%s", inp);
		ans = ts[inp[0]- 48][inp[1]- 48][inp[2]- 48][inp[3]- 48][inp[4]- 48][inp[5]- 48][inp[6]- 48];
		if (ans > 1000000) printf("-1\n");
		else printf("%ld\n", ans); 
	}
	return 0;
}
