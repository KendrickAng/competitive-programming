import java.math.*;
import java.util.*;
import java.io.*;

public class Primes2 {
    private static int gcd(int a, int b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        int t = io.getInt();
        for (int i = 0; i < t; i++) {
            String s = io.getWord();
            int numerator = 0;
            int denominator = 0;

            // binary
            try {
                BigInteger bi = new BigInteger(s, 2);
                denominator++;
                if (bi.isProbablePrime(10)) numerator++;
            } catch(NumberFormatException e) {
                // do nothing
            }

            // octal
            try {
                BigInteger bi = new BigInteger(s, 8);
                denominator++;
                if (bi.isProbablePrime(10)) numerator++;
            } catch(NumberFormatException e) {
                // do nothing
            }

            // decimal
            try {
                BigInteger bi = new BigInteger(s, 10);
                denominator++;
                if (bi.isProbablePrime(10)) numerator++;
            } catch(NumberFormatException e) {
                // do nothing
            }

            // hex
            try {
                BigInteger bi = new BigInteger(s, 16);
                denominator++;
                if (bi.isProbablePrime(10)) numerator++;
            } catch(NumberFormatException e) {
                // do nothing
            }

            if (numerator == 0) {
                io.println("0/1");
            } else {
                int divisor = Primes2.gcd(numerator, denominator);
                io.println(String.format("%d/%d", numerator/divisor, denominator/divisor));
            }
        }

        io.close();
    }
}

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
	super(new BufferedOutputStream(System.out));
	r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
	super(new BufferedOutputStream(o));
	r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
	return peekToken() != null;
    }

    public int getInt() {
	return Integer.parseInt(nextToken());
    }

    public double getDouble() { 
	return Double.parseDouble(nextToken());
    }

    public long getLong() {
	return Long.parseLong(nextToken());
    }

    public String getWord() {
	return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
	if (token == null) 
	    try {
		while (st == null || !st.hasMoreTokens()) {
		    line = r.readLine();
		    if (line == null) return null;
		    st = new StringTokenizer(line);
		}
		token = st.nextToken();
	    } catch (IOException e) { }
	return token;
    }

    private String nextToken() {
	String ans = peekToken();
	token = null;
	return ans;
    }
}