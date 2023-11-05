n = int(input())
if n == 1:
    number = int(input())
    if number != 1:
        print(1)
    else:
        print(0)

else:
    number = list(map(int,input().split()))
    ls = []
    for num in number:
        if num ==  number.count(num) :
           ls.append(num)
        
    print(len(ls)) 


