import java.util.*;

public class Main {
    static class  TreeNode{
        TreeNode(int val){
            this.val = val;
        }
        int val;
        TreeNode left;
        TreeNode right;
    }


public static TreeNode deserialize(String data) {
        if(data == null || data.length() <= 1) return null;
        if(data.charAt(0) == '#') return null;
        int[] p = {0};
        return helper(new StringBuilder(data), p);
    }
public static TreeNode helper(StringBuilder data, int[] p){
        if(p[0] >= data.length()) return null;
        if(data.charAt(p[0]) == '#') {
            p[0] += 2;
            return null;
        }
        int end = p[0];
        while(data.charAt(end) != ',') end++;
        int val = Integer.valueOf(data.substring(p[0], end));
        TreeNode node = new TreeNode(val);
        p[0] = end + 1;
        node.left = helper(data, p);
        node.right = helper(data, p);
        return node;
    }


public static void preOrder(TreeNode node, StringBuilder preStr){
        if (preStr.length() > 0) {
            preStr.append(",");
        }
        if (node == null) {
            preStr.append("#");
        } else {
            preStr.append(node.val);
            preOrder(node.left, preStr);
            preOrder(node.right, preStr);
        }

    }


public static void levelOrder2PreOrder(){
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        StringBuilder levelStr = new StringBuilder();
        while (num > 0) {
            num--;
            if (levelStr.length() > 0) {
                levelStr.append(",");
            }
            levelStr.append(in.next());
        }

        TreeNode root = deserialize(levelStr.toString());
        StringBuilder str = new StringBuilder();
        preOrder(root, str);
        System.out.println(str.toString());
    }

public static void main(String[] args) {
        levelOrder2PreOrder();
    }
}