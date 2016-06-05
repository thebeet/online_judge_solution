#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 100010

const int defaulth = 16;

class segmeng_tree
{

	public:
		segmeng_tree(){ height = defaulth; tree = new int[1 << height]; }
		~segmeng_tree(){ delete [] tree; }
		segmeng_tree(int th){ height = th; tree = new int[1 << height];}
		void insert(const int left, const int right, const int q);
		void color(const int left, const int right, const int q);
		int readvalue(const int p) const;
		int readcolor(const int p) const;
		int *tree;
	private:
		void insert_tree(const int p, const int real_left, const int real_right, const int left, const int right, const int q, const bool iscolor);
		int height;
};

void segmeng_tree::insert_tree(const int p, const int real_left, const int real_right, const int left, const int right, const int q, const bool iscolor)
{
	if ((real_left == left) && (real_right == right))
	{
		if (iscolor)
		{
			tree[p] += q;
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

void segmeng_tree::color(const int left, const int right, const int q)
{
	insert_tree(1, 0, (1 << height) - 1, left, right, q, true);
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

int segmeng_tree::readcolor(const int p) const
{
	int tree_p = 1;
	int tree_h = height - 1;
	while ((tree[tree_p] == 0) && (tree_h > 0))
	{
		tree_p <<= 1;
		if (((tree_h << 1) & p) > 0)
		{
			++tree_p;
		}
		--tree_h;
	}
	return tree[tree_p];		
}


// make pre-star graph
struct path
{
	int f, t;
}paths[100010];
int s[MAXN];
int p[MAXN];
int st[MAXN];
int ed[MAXN];
bool gone[MAXN];
int tcount;
bool apple[MAXN];

segmeng_tree seg_tree(18);

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

void dfs(int node)
{
	++tcount;
	gone[node] = true;
	st[node] = tcount;
	for (int i = p[node]; i < p[node + 1]; ++i)
	{
		if (gone[paths[i].t] != true)
		{
			dfs(paths[i].t);
		}
	}
	ed[node] = tcount;
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
	dfs(1);
	
	scanf("%d", &m);
	for (i = (1 << 17) + 1; i <= (1 << 17) + m; ++i)
	{ 
		seg_tree.tree[i] = i - (1 << 17);
	}
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
