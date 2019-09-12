


import java.util.*;

public class Main {
public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.next();
        count(str);



    }
private static void count(String s){
        String[] words = s.split(",");
        Map<String, Integer> countMap = new HashMap<>();
        for (String str : words) {
            char ch = str.charAt(str.length() - 1);
            if (ch == 'd' || ch == 'e')
                countMap.put(str, countMap.getOrDefault(str, 0) + 1);
        }
        System.out.println(countMap);
    }
}
