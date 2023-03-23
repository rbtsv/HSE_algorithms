#!/usr/bin/env python3
import sys
input = sys.stdin.buffer.readline
stdout=sys.stdout

#it_lines = iter(open('t1', 'r').readlines())
#input = lambda: next(it_lines)

def read_int():
    return int(input())

def read_int_arr():
    return [int(c) for c in input().split()]
    
def write(*args, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    stdout.write(sep.join(str(a) for a in args) + end)

def write_array(array, **kwargs):
    sep = kwargs.get('sep', ' ')
    end = kwargs.get('end', '\n')
    stdout.write(sep.join(str(a) for a in array) + end)    

n = read_int()
# print(n)

b = [0]*10**4

def ms(a, l, r):
    global b;
    n = r - l + 1 
    if n <= 1:
        return
        
    ms(a, l, l+n//2-1)
    ms(a, l+n//2, r)
        
    i, j = l, l+n//2
    c = 0
    #print(l,r,n,i,j)
    while not (i == l+n//2 and j == r+1):
        if i == l+n//2 or (j <= r and a[i] > a[j]):
             b[c] = a[j]
             j += 1
        elif j == r+1 or a[i] <= a[j]:
            b[c] = a[i]
            i += 1  
        c += 1              
    #print(b)
    for i in range(n):
        a[l+i] = b[i]

for _ in range(n):    
    l = read_int()
    a = read_int_arr()
    ms(a, 0, l-1)
    write_array(a)
    del a