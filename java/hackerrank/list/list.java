import java.util.*;
import java.util.stream.Collectors;

class list {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        List<Integer> arr = new ArrayList<>();

        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            arr.add(sc.nextInt());
        }

        int Q = sc.nextInt();
        for (int i = 0; i < Q; i++) {
            String s = sc.next();
            if (s.equals("Insert")) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                arr.add(x, y);
            }
            if (s.equals("Delete")) {
                int x = sc.nextInt();
                arr.remove(x);
            }
        }

        String res = arr.stream()
                .map(String::valueOf)
                .collect(Collectors.joining(" "));
        System.out.println(res);
    }
}
