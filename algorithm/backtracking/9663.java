import java.util.Scanner;

public class Main {

    static int n;
    static int count = 0;
    static int[][] arr = new int[15][15];
    static boolean[] isUsed1 = new boolean[40]; // 세로
    static boolean[] isUsed2 = new boolean[40]; // 우측 대각선 -> x + y == index
    static boolean[] isUsed3 = new boolean[40]; // 좌측 대각선 -> x - y == 0

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        func(0);
        System.out.println(count);
        sc.close();
    }


    // x,y에 퀸을 놓는다
    static void func(int k){
        if (k == n){
            count++;
            return;
        }
        for (int i = 0; i < n; i++){
            if (!isUsed1[i] && !isUsed2[i + k] && !isUsed3[i - k + n - 1]){
                isUsed1[i] = true;
                isUsed2[i + k] = true;
                isUsed3[i - k + n - 1] = true;

                func(k + 1);

                isUsed1[i] = false;
                isUsed2[i + k] = false;
                isUsed3[i - k + n - 1] = false;

            }
        }
    }
}
