#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 1000010

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

int ans[20000];
segmeng_tree seg_t(16);

int main()
{
	int i, n, x, y, ret;
	memset(ans, 0, sizeof(ans));
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d%d", &x, &y);
		ret = seg_t.readvalue(x);
		++ans[seg_t.readvalue(x)];
		seg_t.insert(x, 32000, 1);
	}
	for (i = 0; i < n; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
