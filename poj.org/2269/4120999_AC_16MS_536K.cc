/*
 * HRBEU_87_A::A.cpp
 *
 *  Created on: Sep 19, 2008 3:14:22 PM
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
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <cctype>
#include <algorithm>
#include <set>

using namespace std;

typedef map<string, int> SymTables;
typedef SymTables::iterator i_SymTable;
typedef vector<string> Strings;
typedef Strings::iterator i_String;


set<char> operator + (const set<char> &s1, const set<char> &s2)
{
	set<char> ret(s1);
	for (set<char>::iterator it = s2.begin(); it != s2.end(); ++it)
	{
		ret.insert(*it);
	}
	return ret;
}

set<char> operator - (const set<char> &s1, const set<char> &s2)
{
	set<char> ret(s1);
	for (set<char>::iterator it = s2.begin(); it != s2.end(); ++it)
	{
		set<char>::iterator findit = s1.find(*it);
		if (findit != s1.end())
		{
			ret.erase(*it);
		}
	}
	return ret;
}

set<char> operator * (const set<char> &s1, const set<char> &s2)
{
	set<char> ret;
	ret.clear();
	for (set<char>::iterator it = s2.begin(); it != s2.end(); ++it)
	{
		set<char>::iterator findit = s1.find(*it);
		if (findit != s1.end())
		{
			ret.insert(*it);
		}
	}
	return ret;
}

ostream &operator <<(ostream &out, const set<char> s1)
{
	out << "{";
	for (set<char>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		out << *it;
	}
	out << "}";
	return out;
}

class Token
{
	friend istream &operator >> (istream &in, Token &token);
	friend ostream &operator << (ostream &out, const Token &token);
public:
	Token(void);
	Token(const string &inp);
	~Token(void);

	typedef int t_TokenType;

	t_TokenType m_type;
	int m_detail;
	string m_content;
	set<char> m_s;

	static const t_TokenType TYPE_NONE = -1;
	static const t_TokenType TYPE_NUM = 256;
	static const t_TokenType TYPE_OPERATOR_DIV = 257;
	static const t_TokenType TYPE_OPERATOR_MOD = 258;
	static const t_TokenType TYPE_ID = 259;
};


static map<string, int> Type_Maps;

Token::Token(void) :
	m_type(TYPE_NONE), m_detail(0)
{
	if (Type_Maps.size() == 0) // never init
	{
		for (int i = 0; i <= 255; ++i)
		{
			Type_Maps[string(1, (char)i)] = i;
		}
	}
	m_content = "";
}

Token::Token(const string &inp) :
	m_type(TYPE_NONE), m_detail(0)
{
	stringstream sstrm(inp);
	sstrm >> *this;
	m_content = "";
}

Token::~Token(void)
{
}

istream &operator >> (istream &in, Token &token)
{
	char c;
	// ignore ws char
	token.m_type = Token::TYPE_NONE;
	while (in.get(c))
	{
		if ((c == ' ') || (c == '\t'))
		{
			continue;
		}
		else if (c == '\n')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if (in)
	{
		if (c == '{')
		{
			token.m_content.clear();
			token.m_content.push_back(c);
			token.m_s.clear();
			while (in.get(c), c != '}')
			{
				token.m_content.push_back(c);
				token.m_s.insert(c);
			}
			token.m_content.push_back(c);
			token.m_type = Token::TYPE_ID;
		}
		else
		{
			token.m_type = Type_Maps[string(1, c)];
			token.m_content = c;
		}
	}
	return in;
}

ostream &operator << (ostream &out, const Token &token)
{
	switch (token.m_type)
	{
		case Token::TYPE_NUM:
		{
			out << token.m_detail;
			return out;
		}
		default:
		{
			return out << token.m_content;
		}
	}
}


istream &GetToken(istream &in);

class Expr
{
	friend istream &operator >> (istream &in, Expr &parser);
	friend ostream &operator << (ostream &out, const Expr &parser);
public:
	Expr(void);
	virtual ~Expr(void);
	set<char> Value(void) const;

private:
	typedef vector<Token> Tokens;
	typedef Tokens::iterator i_Token;
	typedef Tokens::const_iterator i_Const_Token;

	istream &GetExpr(istream &in);
	istream &GetFactor(istream &in);
	istream &GetTerm(istream &in);
	istream &Match(istream &in, const Token::t_TokenType tokentype, const bool readnext = true);

	void Emit(const Token &token);

	Tokens m_tokens;
};

class Parser
{
	friend istream &operator >> (istream &in, Parser &parser);
	friend ostream &operator << (ostream &out, const Parser &parser);
public:
	typedef vector<Expr> Exprs;
	typedef Exprs::iterator i_Expr;
	typedef Exprs::const_iterator i_Const_Expr;
	Parser(void);
	virtual ~Parser(void);
	Exprs m_exprs;
private:

	istream &GetParser(istream &in);
	istream &Match(istream &in, const Token::t_TokenType tokentype, const bool readnext = true);
};

static SymTables SymTable;
static int SymTable_ID(0);
static Strings IDTables;
static Token NextToken;

istream &GetToken(istream &in)
{
	in >> NextToken;
	if (NextToken.m_type == Token::TYPE_ID)
	{
		int &id = SymTable[NextToken.m_content];
		if (id == 0)
		{
			id = ++SymTable_ID;
			IDTables.push_back(NextToken.m_content);
		}
		NextToken.m_content = id;
	}
	return in;
}


Parser::Parser(void)
{
}

Parser::~Parser(void)
{
}

istream &operator >> (istream &in, Parser &parser)
{
	return parser.GetParser(in);
}

ostream &operator << (ostream &out, const Parser &parser)
{
	for (Parser::i_Const_Expr i = parser.m_exprs.begin(); i != parser.m_exprs.end(); ++i)
	{
		if (i != parser.m_exprs.begin()) out << " ";
		out << *i;
	}
	return out;
}

istream &Parser::GetParser(istream &in)
{
	while (GetToken(in))
	{
		Expr expr;
		if (in >> expr)
		{
			m_exprs.push_back(expr);
			Match(in, ';', false);
		}
	}
	return in;
}

istream &Parser::Match(istream &in, const Token::t_TokenType tokentype, const bool readnext)
{
	if (tokentype == NextToken.m_type)
	{
		if (readnext)
		{
			GetToken(in);
		}
		else
		{
			NextToken.m_type = Token::TYPE_NONE;
		}
	}
	else
	{
		//error
		cerr << "error while Match Type " << tokentype << " But " << NextToken.m_content << " Appear" << endl;
	}
	return in;
}

Expr::Expr(void)
{
}

Expr::~Expr(void)
{
}

set<char> Expr::Value(void) const
{
	stack< set<char> > st;
	for (i_Const_Token i = m_tokens.begin(); i != m_tokens.end(); ++i)
	{
		switch (i->m_type)
		{
			case Token::TYPE_NUM:
			{
				//st.push((int)i->m_detail);
				break;
			}
			case Token::TYPE_ID:
			{
				st.push(i->m_s);
				break;
			}
			case '*':
			{
				set<char> num1, num2;
				if (st.size() < 2)
				{
					cerr << "Error Expr" << endl;
				}
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				set<char> ret = num1 * num2;
				st.push(ret);
				break;
			}
			case '+':
			{
				set<char> num1, num2;
				if (st.size() < 2)
				{
					cerr << "Error Expr" << endl;
				}
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				set<char> ret = num1 + num2;
				st.push(ret);
				break;
			}
			case '-':
			{
				set<char> num1, num2;
				if (st.size() < 2)
				{
					cerr << "Error Expr" << endl;
				}
				num2 = st.top();
				st.pop();
				num1 = st.top();
				st.pop();
				set<char> ret = num1 - num2;
				st.push(ret);
				break;
			}
			default:
			{
				cerr << "UnKnow Operator" << endl;
				/*error*/
			}
		}
	}
	return st.top();
}

istream &Expr::GetExpr(istream &in)
{
	if (NextToken.m_type == Token::TYPE_NONE)
	{
		GetToken(in);
	}
	GetTerm(in);
	for ( ; ; )
	{
		switch (NextToken.m_type)
		{
			case '+':
			case '-':
			{
				Token op(NextToken);
				Match(in, NextToken.m_type);
				GetTerm(in);
				Emit(op);
				continue;
			}
			default:
			{
				return in;
			}
		}
	}
}

istream &Expr::GetTerm(istream &in)
{
	GetFactor(in);
	for ( ; ; )
	{
		switch (NextToken.m_type)
		{
			case '*':
			case '/':
			case Token::TYPE_OPERATOR_DIV:
			case Token::TYPE_OPERATOR_MOD:
			{
				Token op(NextToken);
				Match(in, NextToken.m_type);
				GetFactor(in);
				Emit(op);
				continue;
			}
			default:
			{
				return in;
			}
		}
	}
}

istream &Expr::GetFactor(istream &in)
{
	switch (NextToken.m_type)
	{
		case '(':
		{
			Match(in, '(');
			GetExpr(in);
			Match(in, ')');
			break;
		}
		case Token::TYPE_NUM:
		case Token::TYPE_ID:
		{
			Emit(NextToken);
			Match(in, NextToken.m_type);
			break;
		}
		default:
		{
			cerr << "Miss Factor." << endl;
		}
	}
	return in;
}

istream &Expr::Match(istream &in, const Token::t_TokenType tokentype, const bool readnext)
{
	if (tokentype == NextToken.m_type)
	{
		if (readnext)
		{
			GetToken(in);
		}
		else
		{
			NextToken.m_type = Token::TYPE_NONE;
		}
	}
	else
	{
		//error
	}
	return in;
}

void Expr::Emit(const Token &token)
{
	m_tokens.push_back(token);
}

istream &operator >> (istream &in, Expr &expr)
{
	return expr.GetExpr(in);
}

ostream &operator << (ostream &out, const Expr &expr)
{
	for (Expr::i_Const_Token i = expr.m_tokens.begin(); i != expr.m_tokens.end(); ++i)
	{
		if (i != expr.m_tokens.begin()) out << " ";
		out << *i;
	}
	return out;
}

int main()
{
	string inp;
	while (cin >> inp)
	{
		stringstream strm(inp);
		Expr expr;
		strm >> expr;
		//cout << expr << endl;
		cout << expr.Value() << endl;
	}
	return 0;
}
