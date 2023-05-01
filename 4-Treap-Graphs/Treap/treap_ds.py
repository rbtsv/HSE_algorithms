#!/usr/bin/env python3
import sys
input = sys.stdin.buffer.readline
import random
random.seed('codeforces!!111!')
#print(random.random())


#For demo
#f = open("t_ub", "r")
#input = f.readline


def read_int():
    return int(input())


def read_array(sep=None, maxsplit=-1):
    return input().split(sep, maxsplit)

    
def read_int_array(sep=None, maxsplit=-1):
    return [int(x) for x in input().split(sep, maxsplit)]
    

def write(*args, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    sys.stdout.write(sep.join(str(a) for a in args) + end)


def write_array(array, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    sys.stdout.write(sep.join(str(a) for a in array) + end)
    
    
    
class TreapNode:
    def __init__(self, key, priority):
        self.key = key
        self.priority = priority
        self._left = None
        self._right = None 
        self._parent = None
        
    @property
    def left(self):
        return self._left
        
    @left.setter # node.left = node1 => we shall set parent of node1 to node        
    def left(self, l):
        self._left = l
        if l is not None:  # node.left = None
            l._parent = self
            
            
    @property
    def right(self):
        return self._right
        
    @right.setter
    def right(self, r):
        self._right = r
        if r is not None:  # node.right = None
            r._parent = self
            
    @property
    def parent(self):
        return self._parent
        
    @staticmethod
    def _lnr_traversal(node):
        if node is None:
            return [ ]
        return TreapNode._lnr_traversal(node.left) + [node] + TreapNode._lnr_traversal(node.right)
        
    def lnr_traversal(self):
        return self._lnr_traversal(self)
       
    @property    
    def min_node(self):
        cur = self
        while cur.left is not None:
            cur = cur.left
        return cur
     
    @property   
    def max_node(self):
        cur = self
        while cur.right is not None:
            cur = cur.right
        return cur
        
    
class Treap:
    def __init__(self, key=None, priority=None):
        if key is not None:
            self.root = TreapNode(key, priority)
        else:
            self.root = None
            
    def insert(self, key, priority):
        if self.root is None:
            self.root = TreapNode(key,priority)
        else:
            self._insert(TreapNode(key,priority))
            
    def find(self, key):
        cur = self.root
        while cur is not None and cur.key != key:
            if key > cur.key:
                cur = cur.right
            else: 
                cur = cur.left
        return cur
        
    def upper_bound(self, key):
        t1, t2 = self.split(self.root, key)
        answ = None if t2 is None else t2.min_node
        self.root = self.merge(t1, t2)
        return answ
        
        
    @staticmethod
    def split(t, k):
        if t is None:
            return (None, None)
        if k > t.key:
            t1, t2 = Treap.split(t.right, k)
            t.right = t1
            return (t, t2)
        else:
            t1, t2 = Treap.split(t.left, k)
            t.left = t2
            return (t1, t)
            
    @staticmethod
    def merge(t1, t2):
        if t1 is None:
            return t2
        if t2 is None:
            return t1
        if t1.priority > t2.priority:
            t1.right = Treap.merge(t1.right, t2)
            return t1
        else:
            t2.left = Treap.merge(t1, t2.left)
            return t2
            
    def _insert(self, node):
        t1, t2 = self.split(self.root, node.key)
        self.root = self.merge(self.merge(t1, node), t2)
            


class TreapNodeDS(TreapNode):
    def __init__(self, key, val=None):
        super().__init__(key, random.random())
        self.val = val
        

class TreapDS(Treap):        
    def __init__(self, key=None, val=None, treap_node=TreapNodeDS):
        self.treap_node = treap_node
        if key is not None:
            self.root = self.treap_node(key, val)
        else:
            self.root = None
            
    def insert(self, key, val=None):
        node = self.treap_node(key, val)
        if self.root is None:
            self.root = node
        else:
            self._insert(node)   
            
    
t = TreapDS()     
y = 0       
for _ in range(read_int()):
    s = input().decode('UTF-8')
    x = int(s[1:])    
    if s[0] == '?':
        #print("? ", x)
        node = t.upper_bound(x)
        #print(t.find(x))
        y = -1 if node is None else node.key  
        print(y)      
    else: # s[0] == '+'
        #print("+ ", x)
        #print("y: ", y)
        z = (x+y) % 10**9
        t.insert( z )
        #print("add ", z)
        #print("add ", z)
        y = 0

#print("t.find(0): ", t.find(0).key)
exit(0) 
        
print("======")        
     
print(f"({t.root.key}, {t.root.priority})", sep = " ")        
print(f"({t.root.left.key}, {t.root.left.priority})", sep = " ")        
print(f"({t.root.right.key}, {t.root.right.priority})", sep = " ")        

print("======")        
for node in t.root.lnr_traversal():
    print(f"({node.key}, {node.priority})", sep = " ")        
        
            