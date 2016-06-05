import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		for (int i = 0; i < n; ++i)
		{
			String sa = cin.next();
			String sb = cin.next();
			if (sa.charAt(0) == '+')
			{
				sa = sa.substring(1, sa.length());
			}
			if (sa.charAt(0) == '-')
			{
				sb = sb.substring(1, sa.length());
			}
			BigInteger a = new BigInteger(sa);
			BigInteger b = new BigInteger(sb);
			System.out.println(a.add(b));
		}
	}
}