import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin = new Scanner(System.in);
		BigInteger bs[] = new BigInteger[1024];
		bs[1] = BigInteger.ZERO;
		bs[2] = BigInteger.ONE;
		bs[3] = BigInteger.ONE;
		BigInteger st = BigInteger.valueOf(2);
		for (int i = 4; i <= 1000; ++i)
		{
			bs[i] = bs[i - 2].add(st);
			st = st.multiply(BigInteger.valueOf(2));
		}
		while (cin.hasNextInt())
		{
			int n = cin.nextInt();
			System.out.println(bs[n]);
		}
	}

}
