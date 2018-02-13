from random import *
print ("Welcome to SUM-100 game..\n you and the second player will choose a number from 1 to 10 \n then your numbers will be added to each other \n when the sum reaches 100 the last one who played is the winner \n") 
typ = int (input("Please choose number of players : "))
while (True):
    if (typ!=1 and typ!=2):
        print ("Error please try again.")
        typ = int (input("Please choose number of players : "))
    else:
        break
    
if (typ==2):
            now = 100
            while (True):
                while (True):
                    p1 = int (input ("Player 1 : "))
                    now-=p1
                    if (now<0 or p1<=0 or p1>10):
                        print ("Error please try again")
                        now+=p1
                    elif (now >= 0 ):
                        break
            
                if (now==0):
                     print ("Player 1 wins")
                     break
                print ("sum : ",100-now)   

        
                while (True):
                    p1 = int (input ("Player 2 : "))
                    now-=p1
                    if (now<0 or p1<=0 or p1>10):
                        print ("Error please try again")
                        now+=p1
                    elif (now >= 0 ):
                        break
        
                if (now==0):
                     print ("Player 2 wins")
                     break
                print ("sum : ",100-now)

elif (typ==1):
            c=0
            ran = False
            now = 100
            while (True):
                while (True):
                    p1 = int (input ("You : "))
                    test = p1
                    now-=p1
                    if (now<0 or p1<=0 or p1>10):
                        print ("Error please try again")
                        now+=p1
                    elif (now >= 0 ):
                        break
            
                if (now==0):
                     print ("You win")
                     break
                print ("sum : ",100-now)   

        
            
                pc = 11-test
                if (c==0):
                        pc=12-test
                if ((pc>10 or ran) and now - pc >11):
                        pc = randint(1,10)
                        ran = True
                if (now<=10):
                        pc = now

                now-=pc
                c+=1
                
                print ("PC : ",pc)
                if (now==0):
                     print ("PC wins")
                     break
                print ("sum : ",100-now)
                
    
        
        
