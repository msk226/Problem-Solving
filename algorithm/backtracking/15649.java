
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int m;
    static int[] arr;
    static boolean[] isUsed;
    static StringBuilder sb = new StringBuilder();

    static void func(int k) {
        if (k == m){
            for (int num : arr){
                sb.append(num).append(' ');
            }
            sb.append('\n');
            return;
        }
        for (int i = 0; i < n; i++){
            if (!isUsed[i]){
                arr[k] = i + 1;
                isUsed[i] = true;
                func(k + 1);
                isUsed[i] = false;
            }
        }
    }


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[m];
        isUsed = new boolean[n];

        func(0);
        System.out.println(sb);
    }
}
