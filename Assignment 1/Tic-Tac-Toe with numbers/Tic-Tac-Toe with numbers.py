SIZE = 3
TARGET = SIZE*SIZE*SIZE + SIZE / 2

board = [TARGET] * (SIZE * SIZE)

def checkSuccess():
    for i in range(0,SIZE*SIZE,SIZE):
        if sum(board[i:i+SIZE]) == TARGET: return True

    for i in range(0,SIZE):
        mysum = 0
        for j in range(0,SIZE):
            mysum += board[i+j*SIZE]
        if mysum == TARGET: return True

    return False

def printBoard():
    print("-"*(SIZE*4+1))
    for i in range(0,SIZE*SIZE,SIZE):
        print("| ",end="")
        new_items = (x if x != TARGET else ' ' for x in board[i:i+SIZE])
        print(*new_items,sep = " : ",end="")
        print(" |")
    print("-"*(SIZE*4+1))

def varifyInput(x,player=None):
    try:
        myint = int(x)
        if myint < 1 or myint > SIZE*SIZE:
            print("Number out of range, please input a number from", 1, "to",SIZE*SIZE)
        elif player == 1 and myint % 2 == 0:
            print("Player", player, "has to play an odd number.")
        elif player == 2 and myint % 2 == 1:
            print("Player", player, "has to play an even number.")
        elif player == None and board[myint-1] != TARGET:
            print("Cell already taken!")
        elif player != None and myint in board:
            print("Number already taken!")
        else:
            return myint
    except:
        print("Please enter a proper number.")
    return False

def main():
    print("""Tic-Tac-Toe with numbers. A board of 3 x 3 is displayed and player 1 takes odd numbers 1, 3, 5, 7, 9 and player 2 takes even numbers 0, 2, 4, 6, 8. Players take turns to write their numbers. Odd numbers start. Use each number only once. The first person to complete a line that adds up to 15 is the winner. The line can have both odd and even numbers.""")
    changer = None

    turns = 0
    while turns < SIZE*SIZE:
        if changer == 1:
            changer = 2
        else:
            changer = 1
            
        printBoard()
        print("Player",changer,"'s turn!")
        location = False
        while location == False:
            location = varifyInput(input("Where do you want to put your number?: "))

        num = False
        while num == False:
            num = varifyInput(input("What is your number?: "),changer)
            
        board[location-1] = num

        if checkSuccess(): break
        turns+=1

    printBoard()
    if turns != SIZE*SIZE:
        print("Player",changer,"won!!! Congratulations")
    else:
        print("Draw!!")

if __name__ == "__main__":
    main()
