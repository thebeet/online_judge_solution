/*
 * Is_It_A_Tree.cpp
 *
 *  Created on: Sep 2, 2009
 *      Author: thebeet
 */

/*
 * Is_It_A_Tree.cpp
 *
 *  Created on: Sep 2, 2009
 *      Author: thebeet
 */

/*
 * unionset.cpp
 *
 *  Created on: Sep 2, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class UnionSet
{
public:
	UnionSet(const int n) :
		m_size(n)
	{
		m_father = new int[n];
		Clear();
	}
	~UnionSet()
	{
		delete [] m_father;
	}

	int FindRoot(const int p)
	{
		if (m_father[p] != p)
		{
			m_father[p] = FindRoot(m_father[p]);
		}
		return m_father[p];
	}

	void Clear()
	{
		for (int i = 0; i < m_size; ++i)
		{
			m_father[i] = i;
		}
	}

	void Merge(const int p1, const int p2)
	{
		int f1 = FindRoot(p1);
		int f2 = FindRoot(p2);
		m_father[f1] = f2;
	}

private:
	int m_size;
	int *m_father;
};

int main()
{
	UnionSet us(10000);
	vector<int> app;
	int a, b;
	int ti(0);
	while ((cin >> a >> b), a != -1)
	{
		cout << "Case " << ++ti << " ";
		bool flag(true);
		us.Clear();
		app.clear();
		while (a > 0)
		{
			int f1 = us.FindRoot(a);
			int f2 = us.FindRoot(b);
			app.push_back(a);
			app.push_back(b);
			if (f1 == f2)
			{
				flag = false;
			}
			else
			{
				us.Merge(f1, f2);
			}
			cin >> a >> b;
		}
		for (int i = 1; i < app.size(); ++i)
		{
			if (us.FindRoot(app[i]) != us.FindRoot(app[0]))
			{
				flag = false;
				break;
			}
		}
		cout << ((flag) ? "is a tree." : "is not a tree.") << endl;
	}
	return 0;
}
