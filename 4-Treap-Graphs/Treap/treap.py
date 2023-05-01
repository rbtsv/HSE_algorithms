#!/usr/bin/env python3
import sys
input = sys.stdin.buffer.readline
import random
random.seed('codeforces!!111!')
#print(random.random())


#For demo
#f = open("t0", "r")
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
        
    
class Treap:
    def __init__(self, key=None, priority=None):
        if key is not None:
            self.root = TreapNode(key, priority)
        else:
            self.root = None
        
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
        
    def insert(self, key, priority):
        if self.root is None:
            self.root = TreapNode(key,priority)
        else:
            self._insert(TreapNode(key,priority))


class TreapNodeIndexed(TreapNode):
    def __init__(self, key, priority, idx):
        super().__init__(key, priority)
        self.idx = idx

            
class TreapIndexed(Treap):
    def __init__(self, key=None, priority=None, idx=None):
        self.nodes = []
        if key is not None:
            self.root = TreapNodeIndexed(key, priority, idx)
        else:
            self.root = None
    
    def insert(self, key, priority, idx):
        node = TreapNodeIndexed(key, priority, idx)
        if self.root is None:
            self.root = node
        else:
            self._insert(node)
        self.nodes.append(node)
    
    
    
    
    
    
        
t = TreapIndexed()        
n = read_int()
kpis = []
for i in range(n):
    k, p = read_int_array()
    kpis.append((k,-p,i+1))
    #t.insert(k,-p,i+1)  

kpis.sort(key=lambda kpi: kpi[1])

for kpi in kpis:
     t.insert(*kpi)      

print("YES")
for node in sorted(t.nodes, key=lambda node: node.idx):
    print((node.parent.idx if node.parent else 0),
          (node.left.idx if node.left else 0),
          (node.right.idx if node.right else 0))
exit(0)

print("======")        
     
print(f"({t.root.key}, {t.root.priority})", sep = " ")        
print(f"({t.root.left.key}, {t.root.left.priority})", sep = " ")        
print(f"({t.root.right.key}, {t.root.right.priority})", sep = " ")        

print("======")        
for node in t.root.lnr_traversal():
    print(f"({node.key}, {node.priority})", sep = " ")        
        
            