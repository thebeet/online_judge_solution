#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 100010

const int defaulth = 16;

class segmeng_tree
{

	public:
		segmeng_tree(){ height = defaulth; tree = new int[1 << height]; memset(tree, 0, (1 << height)* sizeof(int));}
		~segmeng_tree(){ delete [] tree; }
		segmeng_tree(int th){ height = th; tree = new int[1 << height]; memset(tree, 0, (1 << height)* sizeof(int));}
		void insert(const int left, const int right, const int q);
		int readvalue(const int p) const;
		int *tree;
	private:
		void insert_tree(const int p, const int real_left, const int real_right, const int left, const int right, const int q, const bool iscolor);
		int height;
};

void segmeng_tree::insert_tree(const int p, const int real_left, const int real_right, const int left, const int right, const int q, const bool iscolor)
{
	if ((real_left == left) && (real_right == right))
	{
		if (iscolor == true)
		{
			tree[p] = q;
		}
		else
		{
			tree[p] += q;
		}			
		return;
	}
	int real_mid = (real_left + real_right) >> 1;
	if (left <= real_mid)
	{
		if (right > real_mid)
		{
			insert_tree((p << 1), real_left, real_mid, left, real_mid, q, iscolor);
			insert_tree((p << 1) + 1, real_mid + 1, real_right, real_mid + 1, right, q, iscolor);
		}
		else
		{
			insert_tree((p << 1), real_left, real_mid, left, right, q, iscolor);
		}
	}
	else
	{
		insert_tree((p << 1) + 1, real_mid + 1, real_right, left, right, q, iscolor);
	}
}

void segmeng_tree::insert(const int left, const int right, const int q)
{
	insert_tree(1, 0, (1 << (height - 1)) - 1, left, right, q, false);
}

int segmeng_tree::readvalue(const int p) const
{
	int tree_p = p + (1 << (height - 1));
	int sum = 0;
	while (tree_p >= 1)
	{
		sum += tree[tree_p];
		tree_p >>= 1;
	}
	return sum;
}

// make pre-star graph
struct path
{
	int f, t;
}paths[200010];
int s[MAXN];
int p[MAXN];
int st[MAXN];
int ed[MAXN];
bool gone[MAXN];
int tcount;
bool apple[MAXN];
int stk[MAXN];

segmeng_tree seg_tree(18);

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

void dfs()
{
	int node;
	stk[0] = 1;
	stk[1] = 1;
	gone[1] = true;
	tcount = 0;
	while (stk[0] > 0)
	{
		node = stk[stk[0]];
		if (node > 0)
		{
			stk[stk[0]] = -node;
			st[node] = ++tcount;
			for (int i = p[node]; i < p[node + 1]; ++i)
			{
				if (gone[paths[i].t] != true)
				{
					gone[paths[i].t] = true;
					stk[++stk[0]] = paths[i].t;
				}
			}
		}
		else
		{
			ed[-node] = tcount;
			--stk[0];
		}
	}
}

int main()
{
	int i, n, m, l;
	char inp[10];
	setbuf(stdout, NULL);
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	tcount = 0;
	memset(gone, false, sizeof(gone));
	memset(apple, true, sizeof(apple));
	scanf("%d", &n);
	if (n > 100000)
	{
		for(;;);
	}
	m = n - 1;
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d", &paths[i].f, &paths[i].t);
		paths[i + m].f = paths[i].t;
		paths[i + m].t = paths[i].f;
		++s[paths[i].f];
		++s[paths[i].t];
	}
	sort(paths + 1, paths + 1 + m + m, cmp);
	p[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		p[i + 1] = p[i] + s[i];
	}
	dfs();
	
	for (i = (1 << 17) + 1; i <= (1 << 17) + n; ++i)
	{ 
		seg_tree.tree[i] = i - (1 << 17);
	}
	scanf("%d", &m);
	for (i = 1; i <= m; ++i)
	{
		scanf("%s%d", inp, &l);
		if (inp[0] == 'C')
		{
			 if (apple[l])
			 {
			 	apple[l] = false;
			 	seg_tree.insert(st[l], m, -1);
			 }
			 else
			 {
			 	apple[l] = true;
			 	seg_tree.insert(st[l], m, 1);
			 }
		}
		else
		{
			printf("%d\n", seg_tree.readvalue(ed[l]) - seg_tree.readvalue(st[l] - 1));
		}
	}
	return 0;
}
