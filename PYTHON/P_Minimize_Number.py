t = int(input())
number = list(map(int,input().split()))
flag = False
for num in number:
    if(num%2 != 0):
        flag = True

if(flag):
    print(0)

else:
    cnt = 0

    while True:
        for i,num in enumerate(number):
            number[i] = num/2
            flag = False
        for num in number:
            if(num%2 != 0):
                flag = True
            
        cnt+=1
        if flag:
            break

    print(cnt)

          
            