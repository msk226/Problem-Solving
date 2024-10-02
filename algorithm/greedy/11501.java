import java.util.Scanner;

public class Main {
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        for (int i = 0; i < n; i++){
            int m;
            m = sc.nextInt();

            int[] arr = new int[m];

            long  sum = 0;
            for (int j = 0; j < m; j++){
                arr[j] = sc.nextInt();
            }
            int max = arr[m - 1];

            for (int j = m - 1; j >= 0; j--){
                if (max < arr[j]){
                    max = arr[j];
                }else{
                    sum += max - arr[j];
                }
            }
            System.out.println(sum);
        }
    }
}


