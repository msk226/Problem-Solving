import java.util.Scanner;

public class Main {
    static String str;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        str = sc.nextLine();

        String[] split = str.split("-");

        int total = Integer.MAX_VALUE;
        for (int i = 0; i < split.length; i++){
            int currentNum = 0;

            String[] add = split[i].split("\\+");
            for (int j = 0; j < add.length; j++){
                currentNum += Integer.parseInt(add[j]);
            }
            if (i == 0)
                total = currentNum;
            else
                total -= currentNum;
        }
        System.out.println(total);
    }

}

