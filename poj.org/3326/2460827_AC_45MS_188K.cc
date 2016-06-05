#include <stdio.h>
#include <algorithm>

using namespace std;

struct record
{
	int time;
	int pcid;
	int sid;
	int islogin;
}records[1010];

int pcusage[1010];
bool timeusage[1300];

int main()
{
	int n, m;
	int r, q;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		memset(records, 0, sizeof(records));
		scanf("%d", &r);
		for (int i = 1; i <= r; ++i)
		{
			scanf("%d%d%d%d", &records[i].time, &records[i].pcid, &records[i].sid, &records[i].islogin);
		}
		
		int ts, te, sid, ans;
		scanf("%d", &q);
		for (int i = 1; i <= q; ++i)
		{
			memset(pcusage, 0, sizeof(pcusage));
			memset(timeusage, false, sizeof(timeusage));
			
			scanf("%d%d%d", &ts, &te, &sid);
			for (int j = 1; j <= r; ++j)
			{
				if (records[j].sid == sid)
				{
					if (records[j].islogin == 1)
					{
						pcusage[records[j].pcid] = records[j].time;
					}
					else
					{
						for (int t = pcusage[records[j].pcid]; t < records[j].time; ++t) 
						{
							timeusage[t] = true;
						}
					}
				}
			}
			
			ans = 0;
			for (int t = ts; t < te; ++t)
			{
				if (timeusage[t])
				{
					++ans;
				}
			}
			
			printf("%d\n", ans);
		} 
	}
	return 0;	
}
