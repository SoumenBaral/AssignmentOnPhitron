words=input()
length  = len(words)
tmp = ''
lst = []
for i in range(length):
    tmp += words[i]
    if(tmp.count('L') == tmp.count('R')):
        lst.append(tmp)
        tmp = ""


print(len(lst))
for val in lst : 
    print(val)
    
