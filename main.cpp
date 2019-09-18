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

        if(data.equals("#"))
            return null;

        String[] arr = data.split(",");

        int i = 0;
        TreeNode root = new TreeNode(Integer.parseInt(arr[i++].trim()));

        Queue<TreeNode> q = new LinkedList<>();

        q.add(root);

        while(!q.isEmpty())
        {
            int s = q.size();

            for(int j=0;j<s;j++)
            {
                TreeNode temp = q.poll();

                String s2 = arr[i++].trim();
                String s3 = arr[i++].trim();

                if(!s2.equals("#"))
                {
                    temp.left = new TreeNode(Integer.parseInt(s2));
                    q.add(temp.left);
                }


                if(!s3.equals("#"))
                {
                    temp.right = new TreeNode(Integer.parseInt(s3));
                    q.add(temp.right);
                }
            }
        }

        return root;

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
//0,1,2,3,#,#,4,#,5,6,#

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