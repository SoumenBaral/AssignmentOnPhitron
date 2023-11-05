import pyautogui 

t = int(input())
if(t==1):
    print("#")
else:

    for i in range(t+1):
        for j in range(i):
            pyautogui.write('#',interval=0.5)
        pyautogui.press('enter')


#
##
###
####
#####



