//package study;

import java.util.*;

public class Main {

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    static int[][] map;
    static boolean[][] visited;
    static int N, unused = 1;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();

        map = new int[N + 1][N + 1];
        visited = new boolean[N + 1][N + 1];

        for (int i = 0; i < N; i++) {
            String next = sc.next();
            for (int j = 0; j < N; j++) {
                map[i][j] = next.charAt(j) - '0';
            }
        }

        Queue<Pair> q = new ArrayDeque<>();
        List<Integer> l  = new ArrayList<>();
        int tmp = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    tmp++;
                    int cnt = 0;
                    q.add(new Pair(i, j));
                    visited[i][j] = true;
                    while (!q.isEmpty()) {
                        Pair cur = q.poll();
                        cnt++;
                        for (int k = 0; k < 4; k++) {
                            int nx = cur.x + dx[k];
                            int ny = cur.y + dy[k];
                            if (nx >= N || ny >= N || nx < 0 || ny < 0) continue;
                            if (map[nx][ny] == 0 || visited[nx][ny]) continue;
                            visited[nx][ny] = true;
                            q.add(new Pair(nx, ny));
                        }
                    }
                    l.add(cnt);
                }

            }
        }
        System.out.println(tmp);
        l.sort(Comparator.naturalOrder());
        for (int i : l)
            System.out.println(i);

    }

    static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

