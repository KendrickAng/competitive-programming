import java.math.*;
import java.io.*;
import java.util.*;

public class Goldbach2 {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        HashSet<Integer> primes = new HashSet<>();

        for (int i = 2; i <= 32000; i++) {
            if (new BigInteger(String.valueOf(i)).isProbablePrime(10)) {
                primes.add(i);
            }
        }

        int n = io.getInt();
        for (int i = 0; i < n; i++) {
            int x = io.getInt();
            ArrayList<String> lst = new ArrayList<>();

            for (int j = 2; j <= x/2; j++) {
                boolean a = primes.contains(j);
                boolean b = primes.contains(x-j);
                if (a && b) {
                    lst.add(String.format("%d+%d", j, x-j));
                }
            }

            io.println(String.format("%d has %d representation(s)", x, lst.size()));
            for (String s: lst) {
                io.println(s);
            }
            io.println();
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