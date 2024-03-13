class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        q = collections.deque([root])

        while q:
            rightMost = None
            n = len(q)

            for i in range(n):
                node = q.popleft()
                if node:
                    rightMost = node
                    q.append(node.left)
                    q.append(node.right)
                
            if rightMost:
                result.append(rightMost.val)
        return result