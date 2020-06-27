import java.io.*;
import java.util.*;

class arraylist {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        // 1-indexed for easy query
        ArrayList<ArrayList<Integer>> a = new ArrayList<>();
        for (int i = 0; i < n + 1; i ++) {
            a.add(new ArrayList<Integer>());
        }

        // read the n lines
        for (int i = 1; i <= n; i++) {
            int d = sc.nextInt();
            for (int j = 0; j < d; j++) {
                a.get(i).add(sc.nextInt());
            }
        }

        // handle queries
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            try {
                int x = sc.nextInt();
                int y = sc.nextInt();
                System.out.println(a.get(x).get(y-1));
            } catch(Exception e) {
                System.out.println("ERROR!");
            }
        }
    }
}
