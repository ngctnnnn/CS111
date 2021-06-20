import random
arr = []
maxx = int(input())
cnt = 0
while cnt < maxx:
    cnt+=1
    arr.append(random.randint(-maxx, maxx))
arr.sort()
for i in arr:
    print(i, end = ' ')
