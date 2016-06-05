#include <stdio.h>
#include <memory.h>

long team[110];
long tteam[110][110];

void dfs(long p)
{
	long i,t;
	for (i=1;i<=tteam[p][0];i++)
	{
		t=tteam[p][i];
		if (team[t]==0)
		{
			team[t]=-team[p];
			dfs(t);
		}
	}
	return;
}

int main()
{
	long i,n,m,s;
	memset(team,0,sizeof(team));
	memset(tteam,0,sizeof(tteam));
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m);
		while (m>0)
		{
			tteam[i][0]++;
			tteam[i][tteam[i][0]]=m;
			scanf("%d",&m);
		}
	}
	for (i=1;i<=n;i++)
	{
		if (team[i]==0)
		{
			team[i]=1;
			dfs(i);
		}
	}
	s=0;
	for (i=1;i<=n;i++)
		if (team[i]==1) s++;
	printf("%d\n",s);
	for (i=1;i<=n;i++)
		if (team[i]==1) printf("%d ",i);
	return 0;
}
	
			
/*
var
 i,n,m,s:longint;
 team:array [0..100] of byte;
begin
 read(n);
 fillchar(team,sizeof(team),0);
 s:=0;
 for i:=1 to n do
  begin
   if team[i]=0 then team[i]:=1;
   if team[i]=1 then inc(s);
   read(m);
   while (m<>0) do
    begin
     if team[m]=0 then team[m]:=-team[i];
     read(m);
    end;
  end;
 writeln(s);
 for i:=1 to n do
  if team[i]=1 then write(i,' ');
end.
*/
	