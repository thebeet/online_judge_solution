/*
 * PKU2513::Colored_Stricks.cpp
 *
 *  Created on: Sep 28, 2008 2:12:18 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int id[250010];
vector<int> path[250010];
bool gone[250010];


const int Trie_Size = 256;

class Trie_Node
{
public:
	typedef Trie_Node* Trie_Node_ptr;
	Trie_Node(const int n = 0) :
		id(n)
	{
		next = new Trie_Node_ptr[Trie_Size];
		memset(next, 0, sizeof(Trie_Node_ptr) * Trie_Size);
	}
	~Trie_Node(void)
	{
		for (int i = 0; i < Trie_Size; ++i)
		{
			if (next[i] != NULL)
			{
				delete next[i];
			}
		}
		delete [] next;
	}
	int id;
	Trie_Node_ptr *next;
};

class Trie
{
public:
	Trie(void)
	{
		root = new Trie_Node;
	}
	~Trie(void)
	{
		delete root;
	}

	void Clear(void)
	{
		delete root;
		root = new Trie_Node;
	}

	int Find(const char *str) const
	{
		Trie_Node *p = root;
		for (const char *st = str; *st != '\0'; ++st)
		{
			if (p->next[*st] == NULL)
			{
				return -1;
			}
			p = p->next[*st];
		}
		if (p->id > 0)
		{
			return p->id;
		}
		else
		{
			return -1;
		}
	}

	int Insert(const char *str, const int id)
	{
		Trie_Node *p = root;
		for (const char *st = str; *st != '\0'; ++st)
		{
			if (p->next[*st] == NULL)
			{
				p->next[*st] = new Trie_Node;
			}
			p = p->next[*st];
		}
		p->id = id;
		return id;
	}

	int Find_Insert(const char *str, int &index)
	{
		Trie_Node *p = root;
		for (const char *st = str; *st != '\0'; ++st)
		{
			if (p->next[*st] == NULL)
			{
				p->next[*st] = new Trie_Node;
			}
			p = p->next[*st];
		}
		if (p->id == 0)
		{
			p->id = ++index;
		}
		return p->id;
	}

private:
	Trie_Node *root;
};

int dfs(const int p)
{
	if (gone[p]) return 0;
	gone[p] = true;
	int ans(1);
	for (int i = 0; i < path[p].size(); ++i)
	{
		ans += dfs(path[p][i]);
	}
	return ans;
}

int main()
{
	char inp1[16];
	char inp2[16];
	int n(0);
	Trie trie;
	while (scanf("%s%s", inp1, inp2) != EOF)
	{
		int x1 = trie.Find_Insert(inp1, n);
		int x2 = trie.Find_Insert(inp2, n);
		if (n > 250004)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		++id[x1];
		++id[x2];
		path[x1].push_back(x2);
		path[x2].push_back(x1);
		//father[findx(d1)] = findx(d2);
	}
	if (n == 0)
	{
		cout << "Possible" << endl;
		return 0;
	}
	int flag(2);
	for (int i = 1; i <= n; ++i)
	{
		if ((id[i] & 1) == 1)
		{
			if (--flag < 0)
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	}
	if (dfs(1) != n)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	/*
	for (int i = 2; i <= n; ++i)
	{
		if (findx(1) != findx(i))
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	*/
	cout << "Possible" << endl;
	return 0;
}
