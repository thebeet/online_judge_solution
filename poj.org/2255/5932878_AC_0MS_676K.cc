/*
 * Tree_Recovery.cpp
 *
 *  Created on: Sep 29, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

class Node
{
public:
	Node(const char key) :
		m_key(key), m_left(NULL), m_right(NULL)
	{
	}
	~Node()
	{
		if (m_left != NULL) delete m_left;
		if (m_left != NULL) delete m_right;
	}

	char m_key;
	Node *m_left, *m_right;
};

Node *MakeNode(const string &s1, const string &s2)
{
	Node *now = new Node(s1[0]);
	int pos = s2.find(s1[0], 0);
	if (pos > 0)
	{
		now->m_left = MakeNode(s1.substr(1, pos), s2.substr(0, pos));
	}
	if (s1.size() - pos - 1 > 0)
	{
		now->m_right = MakeNode(s1.substr(1 + pos, s1.size() - pos - 1), s2.substr(1 + pos, s2.size() - pos - 1));
	}
	return now;
}

void Output(Node *root)
{
	if (root == NULL) return;
	Output(root->m_left);
	Output(root->m_right);
	cout << root->m_key;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		Node *root = MakeNode(s1, s2);
		Output(root);
		cout << endl;
		delete root;
	}
	return 0;
}
