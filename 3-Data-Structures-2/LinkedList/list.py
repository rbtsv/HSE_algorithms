#!/usr/bin/env python3

class ListItem:
    def __init__(self, key, val=None):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None
        
    def __str__(self):
        if self.val:
            return f"({self.key}, {self.val})"
        return f"({self.key})"

l1 = ListItem("k1", 1)
l2 = ListItem("k2", 2)
l3 = ListItem("k3")

l1.next = l2
l2.prev = l1

l2.next = l3
l3.prev = l2

li = l1
while li:
    print(li, end=" ")
    li = li.next

print()    
    
li = l3
while li:
    print(li, end=" ")
    li = li.prev

print()        
    
a = [1,2,3]    

a[0] = a
    
print(a)
print(a[0][1])    
    
