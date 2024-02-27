class Node:
    def __init__(self):
        self.key = key
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None
    
    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert_recursive(key, self.root)

    def _insert_recursive(self, key, current_node):
        if key <= current_node.key:
            if current_node.left is None:
                current_node.left = Node(key)
            else:
                self._insert_recursive(key, current_node.left)
        elif key > current_node.key:
            if current_node.right is None:
                current_node.right = Node(key)
            else:
                self._insert_recursive(key, current_node.right)
    
    def search(self, key):
        return self._search_resursive(key, self.root)

    def _search_recursive(self, key, current_node):
        if current_node is None:
            return False
        elif current_node.key == key:
            return True
        elif key < current_node.key:
            return self._search_recursive(key, current_node.left)
        else:
            return self._search_recursive(key, current_node.right)
    
    def inorder_traversal(self):
        result = []
        self._inorder_traversal_recursive(self.root, result)
        return result
    
    def _inorder_traversal_recursive(self, current_node, result):
        if current_node is not None:
            self._inorder_traversal_recursive(current_node.left, result)
            result.append(current_node.key)
            self._inorder_traversal_recursive(current_node.right, result)