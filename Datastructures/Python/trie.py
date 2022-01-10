class TrieNode:
    def __init__(self):
        self.is_word=False
        self.children={}

class Trie:

    def __init__(self):
        self.root=TrieNode()

    def insert(self, word: str) -> None:
        cur=self.root
        for l in word:
            if l in cur.children.keys():
                cur=cur.children[l]
            else:
                new_node=TrieNode()
                cur.children[l]=new_node
                cur=new_node
        cur.is_word=True

    def search(self, word: str) -> bool:
        cur=self.root
        for l in word:
            if l in cur.children.keys():
                cur=cur.children[l]
            else:
                return False
        return cur.is_word

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        cur=self.root
        for l in prefix:
            if l in cur.children.keys():
                cur=cur.children[l]
            else:
                return False
        return True


trie = Trie()
trie.insert("apple")
print("search1 + "+str(trie.search("apple")))        # search1 + True
print("search2 + "+str(trie.search("app")))          # search2 + False
print("startWith1 + "+str(trie.startsWith("app")))   # startWith1 + True
trie.insert("app");
print("search3 + "+str(trie.search("app")))          # search3 + True
