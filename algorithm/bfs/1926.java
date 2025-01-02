import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

     static int[] dx = {-1, 1, 0 ,0};
     static int[] dy = {0, 0, -1, 1};
     static int[][] board = new int[501][501];
     static boolean[][] isVisited = new boolean[501][501];


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = sc.nextInt();
            }
        }

        Queue<Pair> queue = new LinkedList<>();
        int mx = 0;
        int count = 0;
        int result = 0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 1 && !isVisited[i][j]){

                    queue.add(new Pair(i, j));
                    isVisited[i][j] = true;
                    count++; result++;

                    while (!queue.isEmpty()){
                        Pair pair = queue.peek();
                        queue.poll();

                        for (int k = 0; k < 4; k++){
                            int nx = pair.x + dx[k];
                            int ny = pair.y + dy[k];

                            if (nx >= n || ny >= m || nx < 0 || ny < 0) continue;
                            if (board[nx][ny] == 0 || isVisited[nx][ny]) continue;
                            queue.add(new Pair(nx, ny));
                            count++;
                            isVisited[nx][ny] = true;
                        }
                    }
                }
                if (mx < count) {
                    mx = count;
                }
                count = 0;
            }
        }
        System.out.println(result);
        System.out.println(mx);
    }
    static class Pair{
        int x;
        int y;

        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
