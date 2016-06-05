/*
 * PKU3181::Main.java
 *
 *  Created on: Oct 8, 2008 7:12:34 PM
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

	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int k = cin.nextInt();
		BigInteger[] ans = new BigInteger[n + 1];
		ans[0] = BigInteger.ONE;
		for (int i = 1; i <= n; ++i)
		{
			ans[i] = BigInteger.ZERO;
		}
		for (int i = 0; i < k; ++i)
		{
			for (int j = i; j <= n; ++j)
			{
				ans[j] = ans[j].add(ans[j - i]);
			}
		}
		System.out.println(ans[n]);
	}

}
