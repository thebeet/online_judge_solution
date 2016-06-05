#include <iostream>
#include <algorithm>

using namespace std;

class Logical
{
public:
	Logical(void) :
		type('\0'), left(NULL), right(NULL)
	{
	}
	~Logical(void)
	{
		if (left != NULL)
		{
			delete left;
		}
		if (right != NULL)
		{
			delete right;
		}
	}
	bool Value(const bool *root)
	{
		switch (type)
		{
			case 'K':
			{
				return (left->Value(root) && right->Value(root));
			}
			case 'A':
			{
				return (left->Value(root) || right->Value(root));
			}
			case 'N':
			{
				return (!(left->Value(root)));
			}
			case 'C':
			{
				return (!(left->Value(root)) || right->Value(root));
			}
			case 'E':
			{
				return (left->Value(root) == right->Value(root));
			}
			default:
			{
				return root[type];
			}
		}
	}
	char type;
	Logical *left, *right;
};

istream &operator >> (istream &in, Logical &logical)
{
	in >> logical.type;
	if (in)
	{
		switch (logical.type)
		{
			case 'K':
			case 'A':
			case 'C':
			case 'E':
			{
				logical.left = new Logical;
				in >> *logical.left;
				logical.right = new Logical;
				in >> *logical.right;
				break;
			}
			case 'N':
			{
				logical.left = new Logical;
				in >> *logical.left;
				break;
			}
			default:
			{
			}
		}
	}
	return in;
}

int main()
{
	Logical inp;
	while ((cin >> inp), inp.type != '0')
	{
		bool root[256];
		int i;
		for (i = 0; i < (1 << 5); ++i)
		{
			for (char var = 'p'; var <= 't'; ++var)
			{
				root[(int)var] = (i & (1 << (int)(var - 'p')));
			}
			if (inp.Value(root) == false)
			{
				break;
			}
		}
		cout << ((i < (1 << 5)) ? "not" : "tautology") << endl;
}
	return 0;
}
