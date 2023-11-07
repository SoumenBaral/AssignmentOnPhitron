n = int(input())
if n == 1:
    number = int(input())
    if number != 1:
        print(1)
    else:
        print(0)

else:
    number = list(map(int,input().split()))
    dic = {}
    for i in number:
        if i in dic :
            dic[i] += 1 
        else:
            dic[i] = 1
    dlt = 0
    for num , count in dic.items():
        if(num == count):
            continue
        else:
            if num > count:
                dlt += count
            else:
                dlt +=  count - num
    print(dlt)

