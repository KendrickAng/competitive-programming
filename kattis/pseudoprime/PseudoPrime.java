import java.util.*;
import java.io.*;
import java.math.*;

public class PseudoPrime {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        while (true) {
            int p = io.getInt();
            int a = io.getInt();
            if (p == 0 && a == 0) break;

            BigInteger bip = new BigInteger(String.valueOf(p));
            
            if (bip.isProbablePrime(10)) {
                io.println("no");
                continue;
            }
            
            BigInteger bia = new BigInteger(String.valueOf(a));

            if (bia.modPow(bip, bip).equals(bia)) {
                io.println("yes");
            } else {
                io.println("no");
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