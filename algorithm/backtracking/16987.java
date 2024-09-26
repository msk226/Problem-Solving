import java.util.Scanner;

public class Main {

    static int n;
    static int max = 0;
    static int[] s = new int[10];
    static int[] w = new int[10];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++){
            s[i] = sc.nextInt();
            w[i] = sc.nextInt();
        }
        func(0);
        System.out.println(max);
        sc.close();
    }

    // k = 현재 몇번째 계란을 들고 있는지
    static void func(int k){
        if (k == n){
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] <= 0) tmp++;
            }
            max = Math.max(max, tmp);
            return;
        }
        // 들고 있는 계란이 깨짐 or 더 이상 남은 계란이 없음
        if (s[k] <= 0 || check(k)) {
            func(k + 1);
            return;
        }
        
        // 내가 들고 있는 계란은 살아 있음.
        for (int i = 0; i < n; i++){
            // 들고 있는 계란 혹은 이미 깨진 계란의 턴이면 패스.
            if (i == k || s[i] <= 0) continue;

            s[i] -= w[k];
            s[k] -= w[i];

            func(k + 1);

            s[i] += w[k];
            s[k] += w[i];
        }
    }

    static boolean check(int k){
        for (int i = 0; i < n; i++){
            if (i != k && s[i] > 0) return false;
        }
        return true;
    }


}
