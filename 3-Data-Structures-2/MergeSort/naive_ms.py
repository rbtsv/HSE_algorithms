import sys
input = sys.stdin.buffer.readline
stdout=sys.stdout

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



def merge(a,b):
    res = []
    i, j = 0, 0
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            res.append(a[i])
            i += 1
        else:
            res.append(b[j])
            j+=1
    return res + a[i:] + b[j:] 


def merge_sort(a):
    if len(a) == 1:
        return a
    return merge(merge_sort(a[:len(a) // 2]), merge_sort(a[len(a) // 2:]) )



n = read_int()
for _ in range(n):    
    l = read_int()
    a = read_int_arr()    
    write_array(merge_sort(a))