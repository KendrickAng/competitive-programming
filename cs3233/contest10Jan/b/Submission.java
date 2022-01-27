import java.util.*;
import java.io.*;
import java.time.*;
import java.time.temporal.*;

public class Submission {
    public static void main(String[] args) {
        Kattio io = new Kattio(System.in);

        LocalDate base = LocalDate.of(2009, 12, 19);
        while (true) {
            int day = io.getInt();
            int month = io.getInt();
            int year = io.getInt();
            if (day == 0 && month == 0 && year == 0) break;

            LocalDate d1 = LocalDate.of(year, month, day);
            // io.println("hi");
            long daysBetween = base.until(d1, ChronoUnit.DAYS);
            
            if (daysBetween < 0) {
                io.println(-1);
            } else {
                io.println(daysBetween);
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