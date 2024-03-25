
#
#   字典树(前缀数) Trie
#
#   快速检索字符串
#

class Node:
    def __init__(self):
        self.children = [None] * 26
        self.end = False

class Trie:

    def __init__(self):
        self.root = Node()

    # 插入字符串
    def insert(self, word: str) -> None:
        node = self.root
        for x in word:
            k = ord(x) - ord('a')
            if node.children[k] == None:
                node.children = Node()
            node = node.children[k]
        node.end = True

    # 搜索 字典树 中是否有完整的 word
    def search(self, word: str) -> bool:
        node = self.root
        i = 0
        for x in word:
            k = ord(x) - ord('a')
            if node.children[k] == None:
                break
            node = node.children[k]
            i+=1
        return i==n and node.end

    # 搜索 字典树 中是否存在 该前缀字符串
    def startsWith(self, prefix: str) -> bool:
        node = self.root
        i = 0
        for x in word:
            k = ord(x) - ord('a')
            if node.children[k] == None:
                break
            node = node.children[k]
            i+=1
        return i==n