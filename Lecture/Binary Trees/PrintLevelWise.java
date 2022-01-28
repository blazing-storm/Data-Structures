/*
Time complexity: O(N)
Space complexity: O(N)
where N is the number of nodes in the input tree
*/
import java.util.Queue;
import java.util.LinkedList;

public class PrintLevelWise {

    class BinaryTreeNode<T> {
        T data;
        BinaryTreeNode<T> left;
        BinaryTreeNode<T> right;
    
        public BinaryTreeNode(T data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    
    public static void printLevelWise(BinaryTreeNode<Integer> root) {
        Queue<BinaryTreeNode<Integer>> pendingNodes = new LinkedList<>();
        pendingNodes.add(root);
        while (!pendingNodes.isEmpty()) {
            BinaryTreeNode<Integer> frontNode = pendingNodes.poll();
            if (frontNode == null) {
                System.out.println();
                if (!pendingNodes.isEmpty()) {
                    pendingNodes.add(null);
                }
            } else {
                System.out.print(frontNode.data + ":L:");
                if (frontNode.left != null) {
                    pendingNodes.add(frontNode.left);
                    System.out.print(frontNode.left.data + ",R:");
                } else {
                    System.out.print(-1 + ",R:");
                }
                if (frontNode.right != null) {
                    pendingNodes.add(frontNode.right);
                    System.out.println(frontNode.right.data);
                } else {
                    System.out.println(-1);
                }
            }
        }
    }
}