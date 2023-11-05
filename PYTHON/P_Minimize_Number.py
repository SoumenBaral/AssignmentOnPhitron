t = int(input())
number = list(map(int,input().split()))
print(number)
flag = False
for num in number:
    if(num%2 != 0):
        flag = true