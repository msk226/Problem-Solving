import java.util.Scanner;

public class Main {
    static int n;
    static int m;
    static int x;
    static int y;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int loop = sc.nextInt();

        for (int i = 0; i < loop; i++){
            m = sc.nextInt(); n = sc.nextInt();
            x = sc.nextInt(); y = sc.nextInt();

            System.out.println(solve(m, n, x, y));
        }
    }

    private static int gcd(int a, int b){
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    private static int lcb(int a, int b){
        return a / gcd(a, b) * b;
    }

    private static int solve(int m, int n, int x, int y){
        if (m == x) x = 0;
        if (n == y) y = 0;
        int lcb = lcb(m, n);

        for (int i = x; i <= lcb; i += m){
            if (i == 0) continue;
            if (i % n == y) return i;
        }
        return -1;
    }

}


