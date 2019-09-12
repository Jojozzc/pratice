

import java.util.*;

public class Main {
public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        String[] words = str.split(",");
        Map<String, Integer> countMap = new HashMap<>();
        for (String s : words) {
            char ch = s.charAt(s.length() - 1);
            if (ch == 'd' || ch == 'e')
                countMap.put(s, countMap.getOrDefault(s, 0) + 1);
        }


        System.out.println(countMap);
    }
}
