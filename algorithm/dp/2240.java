import java.util.Scanner;

public class Main {
    static int n;
    static int m;

    static int[][] arr = new int[1001][31]; // [떨어지는 시간][움직인 횟수] = 가질 수 있는 자두 수
    static int[] plums = new int[1001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();

        // input
        for (int i = 1; i <= n; i++){
            plums[i] = sc.nextInt();
        }
        arr[1][0] = plums[1] % 2; // 1번에 떨어지는 경우
        arr[1][1] = plums[1] / 2; // 2번에 떨어지는 경우

        for (int t = 2; t <= n; t++) {
            for (int w = 0; w <= m; w++) {
                
                // 현재 얻을 수 있는 자두 갯수 구하기
                // 짝수번 이동했으면 1번 나무, 홀수번 이동했으면 2번 나무. 
                int j = (w % 2 == 0) ? plums[t] % 2 : plums[t] / 2;
                
                arr[t][w] = arr[t - 1][w] + j;
                
                if (w > 0) {
                    arr[t][w] = Math.max(arr[t][w], arr[t - 1][w - 1] + j);
                }
            }
        }

        // output
        int maxPlums = 0;
        for (int w = 0; w <= m; w++) {
            maxPlums = Math.max(maxPlums, arr[n][w]);
        }

        System.out.println(maxPlums);

    }
}

