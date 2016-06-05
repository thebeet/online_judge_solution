/*
 * PKU3699::miniSQL.cpp
 *
 *  Created on: Oct 5, 2008 2:17:45 PM
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
#include <sstream>
#include <map>

using namespace std;

const int SQL_INT_TYPE = 0;
const int SQL_STR_TYPE = 1;

class miniSQL_TYPE
{
public:
	miniSQL_TYPE(int a_type = 0, string a_name = "") :
		m_type(a_type), m_name(a_name)
	{
	}
	int m_type;
	string m_name;
	int len;
};

class miniSQL_Value
{
public:
	miniSQL_Value(void) :
		m_type(SQL_INT_TYPE), m_intvalue(0)
	{
	}
	int m_type;
	int m_intvalue;
	string m_strvalue;
	int len;
};

class miniSQL_Column : public vector<miniSQL_TYPE>
{
public:
	miniSQL_Column(void)
	{
	}
};

class miniSQL
{
public:
	miniSQL(void)
	{
	}
	miniSQL &InsertType(const int tp, const string &name)
	{
		m_columns.push_back(miniSQL_TYPE(tp, name));
		m_type_assign[name] = tp;
		m_pos_assign[name] = m_columns.size() - 1;
		return *this;
	}
	miniSQL &Insert(const vector<miniSQL_Value> &row)
	{
		m_database.push_back(row);
		return *this;
	}
	istream &readRow(istream &in, vector<miniSQL_Value> &row) const
	{
		row.clear();
		row.resize(m_columns.size());
		for (unsigned int i = 0; i < row.size(); ++i)
		{
			if (m_columns[i].m_type == SQL_INT_TYPE)
			{
				in >> row[i].m_intvalue;
			}
			else
			{
				in >> row[i].m_strvalue;
			}
		}
		return in;
	}

	miniSQL select_q(const string &q)
	{
		miniSQL result;
		stringstream strm(q);
		string q_select, col_list, q_where, q_con;
		strm >> q_select >> col_list >> q_where >> q_con;
		int prepos(0);
		for (unsigned int i = 0; i <= col_list.size(); ++i)
		{
			if ((i == col_list.size()) || (col_list[i] == ','))
			{
				string tp_name = col_list.substr(prepos, i - prepos);
				result.InsertType(m_type_assign[tp_name], tp_name);
				prepos = i + 1;
			}
		}
		string con_var;
		string con_value;
		miniSQL_Value con_val;
		char con_op;
		for (unsigned int i = 0; i < q_con.size(); ++i)
		{
			if ((q_con[i] == '=') || (q_con[i] == '<') || (q_con[i] == '>'))
			{
				con_op = q_con[i];
				con_var = q_con.substr(0, i);
				con_value = q_con.substr(i + 1, q_con.size() - i + 1);
				break;
			}
		}
		if (m_type_assign[con_var] == SQL_INT_TYPE)
		{
			stringstream mstrm(con_value);
			mstrm >> con_val.m_intvalue;
		}
		else
		{
			con_val.m_type = SQL_STR_TYPE;
			con_val.m_strvalue = con_value.substr(1, con_value.size() - 2);
		}
		for (unsigned int i = 0; i < m_database.size(); ++i)
		{
			if (Comp(con_var, con_op, con_val, m_database[i]))
			{
				vector<miniSQL_Value> newrow;
				for (unsigned int t = 0; t < result.m_columns.size(); ++t)
				{
					newrow.push_back(m_database[i][m_pos_assign[result.m_columns[t].m_name]]);
				}
				result.m_database.push_back(newrow);
			}
		}
		return result;
	}

	bool Comp(const string &var, const char op, const miniSQL_Value &value, const vector<miniSQL_Value> &row)
	{
		if (value.m_type == SQL_INT_TYPE)
		{
			switch (op)
			{
				case '=':
				{
					return value.m_intvalue == row[m_pos_assign[var]].m_intvalue;
				}
				case '<':
				{
					return row[m_pos_assign[var]].m_intvalue < value.m_intvalue;
				}
				case '>':
				{
					return row[m_pos_assign[var]].m_intvalue > value.m_intvalue;
				}
				default:
				{
					cerr << "error" << endl;
					return false;
				}
			}
		}
		else
		{
			return value.m_strvalue == row[m_pos_assign[var]].m_strvalue;
		}
	}

	miniSQL_Column m_columns;
	map<string, int> m_type_assign;
	map<string, int> m_pos_assign;
	vector< vector<miniSQL_Value> > m_database;
};

ostream &operator << (ostream &out, miniSQL &sql)
{
	int sumlen(0);
	for (int i = 0; i < sql.m_columns.size(); ++i)
	{
		sql.m_columns[i].len = sql.m_columns[i].m_name.size();
		//cout << sql.m_columns[i].m_name << " ";
	}
	//cout << endl;
	for (int j = 0; j < sql.m_database.size(); ++j)
	{
		for (int i = 0; i < sql.m_columns.size(); ++i)
		{
			if (sql.m_columns[i].m_type == SQL_INT_TYPE)
			{
				char buf[32];
				snprintf(buf, 32, "%d", sql.m_database[j][i].m_intvalue);
				sql.m_database[j][i].len = strlen(buf);
				//cout << sql.m_database[j][i].m_intvalue << " ";
			}
			else
			{
				sql.m_database[j][i].len = sql.m_database[j][i].m_strvalue.size();
				//cout << sql.m_database[j][i].m_strvalue << " ";
			}
			sql.m_columns[i].len = max(sql.m_columns[i].len, sql.m_database[j][i].len);
		}
		//cout << endl;
	}
	for (int i = 0; i < sql.m_columns.size(); ++i)
	{
		sumlen += sql.m_columns[i].len + 2;
	}
	out << '+' << string(sumlen + sql.m_columns.size() - 1, '-') << '+' << endl;
	for (int i = 0; i < sql.m_columns.size(); ++i)
	{
		out << "|";
		out << string((sql.m_columns[i].len - sql.m_columns[i].m_name.size()) / 2 + 1, ' ');
		out << sql.m_columns[i].m_name;
		out << string((sql.m_columns[i].len - sql.m_columns[i].m_name.size() + 1) / 2 + 1, ' ');
	}
	out << "|" << endl;
	for (int i = 0; i < sql.m_columns.size(); ++i)
	{
		out << "|";
		out << string(sql.m_columns[i].len + 2, '-');
	}
	out << "|" << endl;
	for (int j = 0; j < sql.m_database.size(); ++j)
	{
		for (int i = 0; i < sql.m_columns.size(); ++i)
		{
			out << "|";
			out << string((sql.m_columns[i].len - sql.m_database[j][i].len) / 2 + 1, ' ');
			if (sql.m_columns[i].m_type == SQL_INT_TYPE)
			{
				out << sql.m_database[j][i].m_intvalue;
			}
			else
			{
				out << sql.m_database[j][i].m_strvalue;
			}
			out << string((sql.m_columns[i].len - sql.m_database[j][i].len + 1) / 2 + 1, ' ');
		}
		out << "|" << endl;
	}
	out << '+' << string(sumlen + sql.m_columns.size() - 1, '-') << '+' << endl;
	return out;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	miniSQL sql;
	for (int i = 0; i < n; ++i)
	{
		string name, tp;
		cin >> name >> tp;
		int d_tp = ((tp == "INT") ? SQL_INT_TYPE : SQL_STR_TYPE);
		sql.InsertType(d_tp, name);
	}
	for (int i = 0; i < m; ++i)
	{
		vector<miniSQL_Value> newrow;
		sql.readRow(cin, newrow);
		sql.Insert(newrow);
	}
	string que;
	getline(cin, que);
	for (int i = 0; i < k; ++i)
	{
		getline(cin, que);
		miniSQL result = sql.select_q(que);
		cout << result << endl;
	}
	return 0;
}
