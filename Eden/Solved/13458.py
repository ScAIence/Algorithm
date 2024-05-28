import math

N:int = int(input())
Ai:list[int] = list(map(int, input().split()))
B, C = map(int, input().split())

ans:int = 0

for a in Ai:
    ans += max(0,math.ceil((a-B)/C))+1

print(ans)