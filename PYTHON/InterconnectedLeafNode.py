#Hithesh1334 
"""
Given a binary tree in which leaf nodes are connected through both left and right pointers, with right leaf nodes linked via right pointers and left leaf nodes connected through left pointers, determine and provide a list of all the leaf nodes present in the tree. 
                1
        2               1
    3       4       6       5

for the above tree leaft nodes are interconnected such as 
1.node 3's left is 5 and right is 4
2.node 4's left is 3 and right is 6
3.node 6's left is 4 and right is 5
4.node 5's left is 6 and right is 3

solution for the above tree is [3,2,6,5]
"""

class TreeNode:
    def __init__(self,val,left=None,right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createNode(self,val:int) -> TreeNode:
        node = TreeNode(val)
        return node
    def findLeafNodes(self,root:TreeNode)->list[int]:
        ans = []
        def solve(root):
            if root.right.left == root or root.left.right == root:
                ans.append(root.val)
                return
            solve(root.left)
            solve(root.right)

        solve(root) 
        return ans


tree = Solution()

#For the below part of the code we can write a code that return root node of binary tree
root = tree.createNode(1)
root.left = tree.createNode(2)
root.right = tree.createNode(1)
root.left.left = tree.createNode(3)
root.left.right = tree.createNode(4)
root.right.left = tree.createNode(5)
root.right.right = tree.createNode(5)
root.left.left.left = root.right.right
root.left.left.right = root.left.right
root.left.right.left = root.left.left
root.left.right.right = root.right.left 
root.right.left.left = root.left.right
root.right.left.right = root.right.right
root.right.right.left = root.right.left
root.right.right.right = root.left.left

ans = tree.findLeafNodes(root)
print(ans)