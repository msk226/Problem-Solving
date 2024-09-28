//import java.util.Scanner;
//
//public class Main {
//    static int n;
//    static int m;
//    static int count = 0;
//    static int homeCount = 0;
//    static int min = 10000;
//    static int[][] town = new int[51][51];
//    static int[][] tmpTown = new int[51][51];
//    static Pair[] chickens = new Pair[14];
//    static Pair[] homes = new Pair[101];
//    static boolean[] isChecked = new boolean[14];
//
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//
//        n = sc.nextInt();
//        m = sc.nextInt();
//
//        for (int i = 0; i < n; i++){
//            for (int j = 0; j < n; j++){
//                town[i][j] = sc.nextInt();
//                if (town[i][j] == 2){
//                    chickens[count] = new Pair(i, j);
//                    count++;
//                }else if (town[i][j] == 1){
//                    homes[homeCount] = new Pair(i, j);
//                    homeCount++;
//                    town[i][j] = 1000;
//                }
//            }
//        }
//        copy();
//        selectChicken(0);
//        System.out.println(min);
//    }
//
//    // 없어질 치킨 집 고르기
//    static void selectChicken(int idx){
//        if(idx == count - m){
//            min = Math.min(getMinDistance(), min);
//            copy();
//            return;
//        }
//        for (int i = 0; i < count; i++){
//            if (isChecked[i]) continue;
//            if (count - i < (count - m) - idx) {
//                break; // 남은 치킨집이 더 적으면 가지치기
//            }
//
//            isChecked[i] = true;
//            tmpTown[chickens[i].x][chickens[i].y] = 0;
//
//            selectChicken(idx + 1);
//
//            isChecked[i] = false;
//            tmpTown[chickens[i].x][chickens[i].y] = 2;
//        }
//    }
//
//
//    // tempTown -> 집을 치킨집으로부터의 거리로 바꿈.
//    static int getMinDistance(){
//        for (int i = 0; i < count; i++){
//            for (int j = 0; j < homeCount; j++){
//                if (!isChecked[i]){
//                    tmpTown[homes[j].x][homes[j].y] = Math.min(tmpTown[homes[j].x][homes[j].y],
//                        Math.abs((chickens[i].x) - (homes[j].x))+ Math.abs(chickens[i].y - homes[j].y));
//                }
//            }
//        }
//        int result = 0;
//        for (int i = 0; i < homeCount; i++){
//            result += tmpTown[homes[i].x][homes[i].y];
//        }
//        return result;
//    }
//
//    static void copy(){
//        for (int i = 0; i < n; i++){
//            for (int j = 0; j < n; j++)
//                tmpTown[i][j] = town[i][j];
//        }
//    }
//
//    static class Pair{
//        final int x;
//        final int y;
//        public Pair(int x, int y){
//            this.x = x;
//            this.y = y;
//        }
//    }
//}

import java.util.Scanner;

public class Main {
    static int n;
    static int m;
    static int count = 0;
    static int homeCount = 0;
    static int min = Integer.MAX_VALUE;
    static Pair[] chickens = new Pair[14];
    static Pair[] homes = new Pair[101];
    static boolean[] isChecked = new boolean[14];
    static int[][] distances; // 각 집과 치킨집 간의 거리를 저장

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        m = sc.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int value = sc.nextInt();
                if (value == 2) {
                    chickens[count] = new Pair(i, j);
                    count++;
                } else if (value == 1) {
                    homes[homeCount] = new Pair(i, j);
                    homeCount++;
                }
            }
        }

        // 각 집과 치킨집 사이의 거리를 미리 계산
        distances = new int[homeCount][count];
        for (int i = 0; i < homeCount; i++) {
            for (int j = 0; j < count; j++) {
                distances[i][j] = Math.abs(homes[i].x - chickens[j].x)
                    + Math.abs(homes[i].y - chickens[j].y);
            }
        }

        selectChicken(0, 0);
        System.out.println(min);
    }

    // 치킨집을 고르는 함수
    static void selectChicken(int idx, int selected) {
        // m개의 치킨집이 선택되었을 때 최소 거리 계산
        if (selected == m) {
            min = Math.min(getMinDistance(), min);
            return;
        }

        // 더 이상 선택할 치킨집이 없을 때 종료
        if (idx >= count) return;

        // 현재 치킨집을 선택하는 경우
        isChecked[idx] = true;
        selectChicken(idx + 1, selected + 1);

        // 현재 치킨집을 선택하지 않는 경우
        isChecked[idx] = false;
        selectChicken(idx + 1, selected);
    }

    // 집을 선택된 치킨집들로부터의 최소 거리 합 구하기
    static int getMinDistance() {
        int result = 0;
        for (int i = 0; i < homeCount; i++) {
            int minDist = Integer.MAX_VALUE;
            for (int j = 0; j < count; j++) {
                if (isChecked[j]) {
                    minDist = Math.min(minDist, distances[i][j]);
                }
            }
            result += minDist;
        }
        return result;
    }

    static class Pair {
        final int x;
        final int y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

