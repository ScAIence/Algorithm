import sys
n = sys.stdin.readline()

for i in range(int(n)):
    tot = int(sys.stdin.readline())
    
    a = tot // 25
    tot -= 25 * a
    
    b = tot // 10
    tot -= 10 * b
    
    c = tot // 5
    tot -= 5 * c
    
    d = tot // 1
    tot -= 1 * c
    
    print(f"{a} {b} {c} {d}")