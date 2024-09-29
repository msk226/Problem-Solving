import java.util.Scanner;

public class Main {
    static int n;

    static long[][] arr = new long[101][10]; // [자릿수][마지막 숫자]

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // 초깃값 저장
        for (int i = 1; i < 10; i++)
            arr[1][i] = 1;

        for (int i = 2; i <= n; i++){
            for (int j = 0; j < 10; j++){
                if (j == 0){
                    arr[i][j] += arr[i - 1][j + 1] % 1_000_000_000;
                }
                else if (j == 9){
                    arr[i][j] += arr[i - 1][j - 1] % 1_000_000_000;
                }else {
                    arr[i][j] += (arr[i - 1][j + 1] + arr[i - 1][j - 1]) % 1_000_000_000;
                }
            }
        }
        long result = 0;
        for (int j = 0; j < 10; j++){
            result += (arr[n][j]);
        }
        System.out.println((result % 1_000_000_000));
    }
}

