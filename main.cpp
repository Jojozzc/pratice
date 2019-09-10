import java.util.Scanner;

public class Main {
public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String arrStr = in.nextLine();
        arrStr = arrStr.substring(1, arrStr.length() - 1);
        String[] numsStr = arrStr.split(",");
        if (numsStr.length == 0) {
            System.out.println(0);
            return;
        }
        int[] nums = new int[numsStr.length];
        int res = nums[0];
        int curSum = 0;
        for (int i = 0; i < nums.length; i++) {
            numsStr[i] = numsStr[i].trim();
            nums[i] = Integer.parseInt(numsStr[i]);
        }
        for (int i = 0; i < nums.length; i++) {
            if (curSum > 0) {
                curSum += nums[i];
            } else {
                curSum = nums[i];
            }
            res = Math.max(res, curSum);
        }
        System.out.println(res);

    }
}
