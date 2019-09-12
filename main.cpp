

import java.util.*;

public class Main {
public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        statisticSubStr(str);



    }
private static void statisticSubStr(String s){
        if (s == null || s.isEmpty()) {
            return;
        }
        int left = 0;
        int[] count = new int[26];
        PriorityQueue<int[]> heap = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o2[1] - o1[1];
            }
        });
        while (left < s.length()) {
            int right = left;
            while (right < s.length() && (s.charAt(right) == s.charAt(left))) {
                right++;
            }
            if (right - left > 1) {
                count[s.charAt(left) - 'a'] += (right - left);
            }
            left = right;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                heap.add(new int[]{i, count[i]});
            }
        }
        while (!heap.isEmpty()) {
            int[] pair = heap.poll();
            StringBuilder str = new StringBuilder();
            str.append((char)(pair[0] + 'a')).append(":").append(pair[1]);
            System.out.println(str.toString());
        }

    }
}
