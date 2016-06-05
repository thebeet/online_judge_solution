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
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			System.out.println(a.add(b));
		}
	}
}