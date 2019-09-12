

import java.util.*;

public class Main {
public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        count(str);



    }
private static void count(String ss){

        String[] words = ss.split(",");
        Map<String, Integer> countMap = new HashMap<>();
        for (String str : words) {
            if (str.isEmpty()) {
                continue;
            }
            char ch = str.charAt(str.length() - 1);
            if (ch == 'd' || ch == 'e')
                countMap.put(str, countMap.getOrDefault(str, 0) + 1);
        }
        System.out.println(countMap);
    }
}
