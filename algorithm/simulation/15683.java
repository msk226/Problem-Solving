import java.util.Scanner;

public class Main {

    static int n;
    static int m;
    static int min = 10000; // 최소 사각지대
    static int count = 0; // 총 CCTV의 갯수
    static int[][] board = new int[10][10];
    static int[][] tempBoard = new int[10][10];
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Pair[] pairs = new Pair[10]; // CCTV 위치의 배열

    static boolean checkIndex(int x, int y){
        return x >= n || y >= m || x < 0 || y < 0;
    }

    static void watch(int x, int y, int dir){
        dir %= 4;
        while (true){
            x += dx[dir];
            y += dy[dir];
            if (checkIndex(x, y) || tempBoard[x][y] == 6) return;
            if (tempBoard[x][y] != 0) continue;
            tempBoard[x][y] = 7;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); m = sc.nextInt();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                board[i][j] = sc.nextInt(); // 1,1(2) -> 4,3(2) -> 5,5(5)에 CCTV가 있음.
                if (board[i][j] >= 1 && board[i][j] <= 5) {
                    pairs[count] = new Pair(i, j);
                    count++;
                }
            }
        }
        for (int i = 0; i < (int) Math.pow(4, count); i++){
            for (int j = 0; j < n; j++){
                if (m >= 0)
                    System.arraycopy(board[j], 0, tempBoard[j], 0, m);
            }
            int idx = i;

            for (int t = 0; t < count; t++){
                int dir = idx % 4;
                idx /= 4;
                int curX = pairs[t].key;
                int curY = pairs[t].value;
                if (board[curX][curY] == 1){
                    watch(curX, curY, dir);
                }
                else if (board[curX][curY] == 2) {
                    watch(curX, curY, dir);
                    watch(curX, curY, dir + 2);
                }
                else if (board[curX][curY] == 3){
                    watch(curX, curY, dir);
                    watch(curX, curY, dir + 1);
                }
                else if (board[curX][curY] == 4){
                    watch(curX, curY, dir);
                    watch(curX, curY, dir + 1);
                    watch(curX, curY, dir + 2);
                }
                else{
                    watch(curX, curY, dir);
                    watch(curX, curY, dir + 1);
                    watch(curX, curY, dir + 2);
                    watch(curX, curY, dir + 3);
                }
            }
            min = getMin();
        }
        System.out.println(min);
        sc.close();
    }

    private static int getMin() {
        int tmp = 0;
        for (int a = 0; a < n; a++){
            for (int b = 0; b < m; b++){
                if (tempBoard[a][b] == 0) tmp++;
            }
        }
        return Math.min(tmp, min);
    }

    public static class Pair {
        private final Integer key;
        private final Integer value;

        public Pair(Integer key, Integer value) {
            this.key = key;
            this.value = value;
        }
    }

}
