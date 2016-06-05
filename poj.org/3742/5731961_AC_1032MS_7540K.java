/*
 * JPKU3742::Main.java
 *
 *  Created on: Aug 23, 2009 2:24:28 PM
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

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class Main
{
	public static BigInteger CC[][] = new BigInteger[202][202];
	public static BigInteger tp[] = new BigInteger[202];
	public static BigInteger coef[] = new BigInteger[202];
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		for (int i = 0; i <= 200; ++i)
		{
			CC[i][0] = BigInteger.ONE;
			for (int j = 1; j < i; ++j)
			{
				CC[i][j] = CC[i - 1][j].add(CC[i - 1][j - 1]);
			}
			CC[i][i] = BigInteger.ONE; 
		}
		int n, t;
		while (cin.hasNextInt())
		{
			n = cin.nextInt();
			t = cin.nextInt();
			tp[0] = BigInteger.ONE;
			tp[1] = BigInteger.valueOf(t);
			for (int i = 2; i <= n; ++i)
			{
				tp[i] = tp[i - 1].multiply(tp[1]);
			}
			
			for (int i = 0; i <= n; ++i)
			{
				coef[i] = cin.nextBigInteger();
			}
			
			for (int i = 0; i <= n; ++i)
			{
				BigInteger c = BigInteger.ZERO;
				for (int j = i; j <= n; ++j)
				{
					c = c.add((coef[j].multiply(CC[j][i])).multiply(tp[j - i]));
				}
				if (i == n)
				{
					System.out.println(c);
				}
				else
				{
					System.out.print(c);
					System.out.print(" ");
				}
			}
		}
	}

}
