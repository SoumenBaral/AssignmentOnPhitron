import pyautogui


n = int(input())
if n == 1:
    print('#')
else: 
    for i in range(n+1):
        for j in range(0,i,1):
            pyautogui.write('#',interval=0.25)
        pyautogui.press('enter')



#
##
###
####
#####
######
#######
