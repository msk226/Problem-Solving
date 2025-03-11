package study;

import java.util.*;

public class Main {

    static int N, M;
    static int[] visited = new int[100_003];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        Arrays.fill(visited, Integer.MAX_VALUE);

        Queue<Integer> q = new ArrayDeque<>();

        q.add(N);
        visited[N] = 0;

        while (!q.isEmpty()) {
            Integer cur = q.poll();

            if (cur - 1 >= 0 && visited[cur - 1] == Integer.MAX_VALUE) {
                q.add(cur - 1);
                visited[cur - 1] = Math.min(visited[cur - 1], visited[cur] + 1);
            }
            if (cur + 1 <= 100_000 && visited[cur + 1] == Integer.MAX_VALUE ) {

                q.add(cur + 1);
                visited[cur + 1] = Math.min(visited[cur + 1] ,visited[cur] + 1 );
            }

            if (2 * cur <= 100_000 && 2 * cur >= 0 && visited[2 * cur] == Integer.MAX_VALUE) {
                q.add(2 * cur);
                visited[2 * cur] = Math.min(visited[cur * 2], visited[cur] + 1);
            }
        }
        System.out.println(visited[M]);
    }
}

