import pygame, sys, random, time
from pygame.locals import *


FPS = 30 # frames per second setting
SURF = pygame.display.set_mode((500, 700))
FPSCLOCK = pygame.time.Clock()


CELLCOUNT = 4
pygame.init()
#ENUMS-------------------------------------
class gamestate:
    notstarted = 1
    running = 2
    stopped = 3

class colors:
    white       = (255, 255, 255)
    lightyellow = (255, 230, 150)
    
    red         = (255, 0  , 0  )
    orange      = (255, 165, 0  )
    pink        = (255, 192, 203)
    
    green       = (0  , 255, 0  )
    cyan        = (0  , 200, 200)
    blue        = (0  , 0  , 255)
    indigo      = (75 , 0  , 130)
    
    gray        = (128, 128, 128)
    
    black       = (0  , 0  , 0  )
    navyblue    = (60 , 60 , 100)

class cellstate:
    used = 1
    highlighted = 2
    normal = 3
#------------------------------------------
    
class Board:
            
    def __init__(self,count, screen,validity,color1,color2):
        self._cellcount = count
        self._cellcount2 = self._cellcount * self._cellcount
        self._bordersize = 3
        self._margin = 2
        self._cellsize = 60

        self._cellmargin = 4

        self.validityCheck = validity
        
        self.selected = [None, None]
        self.rectangles = []
        
        self.cells = [cellstate.normal] * self._cellcount2
        
        self.borderColor = colors.black

        self.cellColor = colors.white
        self.cellHighlightedColor = colors.lightyellow
        self.cellPlayer1Color = color1
        self.cellPlayer2Color = color2
        
        self.setScreen(screen)

    def getMargin(self): return self._margin * self._drawconst
    def getBorderSize(self): return self._bordersize * self._drawconst
    def getCellSize(self): return self._cellsize * self._drawconst
    def getTotalSize(self): return self._totalsize * self._drawconst
    
    def setScreen(self,screen):
        self._totalsize = 2 * self._bordersize + self._margin*(self._cellcount - 1) + self._cellcount * self._cellsize
        self._drawconst = screen[2] / self._totalsize
        self._offsetx = screen[0]
        self._offsety = screen[1]

    def getCellAt(self,x,y):
        if self.getBoardBounds().collidepoint(x,y) == False: return
        for i in range(self._cellcount2):
            bounds = self.getBounds(i)
            if bounds.collidepoint(x, y):
                return i
        return None

    def getState(self, ind):
        return self.cells[ind]

    #returns True if the selection was successful
    def setSelected(self, ind, player):
        if self.getState(ind) == cellstate.used:
            self.selected = [None, None]
            return False
            
        if self.selected[0] is None:
            self.selected[0] = (ind,player)
            return False
        elif self.selected[1] is None:
            if (self.selected[0][0] == ind):
                self.selected = [None, None]
                return False
            self.selected[1] = (ind,player)
            a = self.selected[0][0]
            b = self.selected[1][0]
            if a > b: a,b = b,a
            
            self.selected = [None, None]
            
            if self.validityCheck(self,a,b):
                self.rectangles.append((a,b,player))
                self.cells[a]=cellstate.used
                self.cells[b]=cellstate.used
                return True
            else:
                return False
            
        else:
            raise Exception
            
    def setHighlighted(self,ind):
        for i in range(self._cellcount2):
            if self.cells[i] == cellstate.highlighted:
                self.cells[i] = cellstate.normal
        if ind==None: return
        elif self.cells[ind] == cellstate.normal:
            self.cells[ind] = cellstate.highlighted
        

    def getBounds(self, ind):
        x = self._offsetx + self.getBorderSize() + (self.getMargin() + self.getCellSize()) * (ind % self._cellcount)
        y = self._offsety + self.getBorderSize() + (self.getMargin() + self.getCellSize()) * (ind// self._cellcount)
        return pygame.Rect(x, y, self.getCellSize(), self.getCellSize())
    
    def getBoardBounds(self):
        return pygame.Rect(self._offsetx, self._offsety, self.getTotalSize(), self.getTotalSize())

    def draw(self,SURF):
        pygame.draw.rect(SURF, self.borderColor, self.getBoardBounds())
        for i in range(self._cellcount2):
            mycolor = self.cellColor
            if self.getState(i) == cellstate.highlighted:
                mycolor = self.cellHighlightedColor

            pygame.draw.rect(SURF, mycolor, self.getBounds(i))

        for i in self.selected:
            if (i is not None):
                myrect = self.getBounds(i[0])
                myrect.width-=self._cellmargin
                myrect.height-=self._cellmargin
                mycolor = self.cellPlayer1Color
                if i[1] == 2: mycolor = self.cellPlayer2Color
                pygame.draw.rect(SURF, mycolor, self.getBounds(i[0]),self._cellmargin)
                   
        for i in self.rectangles:
            x1,y1 = self.getBounds(i[0]).topleft
            x1 += self._cellmargin
            y1 += self._cellmargin
            x2,y2 = self.getBounds(i[1]).bottomright
            x2 -= self._cellmargin
            y2 -= self._cellmargin
            myrect = pygame.Rect(x1,y1,x2-x1,y2-y1)
            mycolor = self.cellPlayer1Color
            if i[2] == 2: mycolor = self.cellPlayer2Color
            pygame.draw.rect(SURF, mycolor, myrect)


def isvalid(self,a,b):
               
    if ((b-a == self._cellcount) or (b-a == 1 and (a+1) % self._cellcount != 0)):
        return True
    else:
        return False

def checkPossible(myBoard):
    for i in range(myBoard._cellcount2-1):
        if ((i+1) % myBoard._cellcount != 0 and (i+1)<myBoard._cellcount2 and myBoard.cells[i] != cellstate.used and myBoard.cells[i+1] != cellstate.used):             #horizontal stick
            return True
        elif ((i + myBoard._cellcount) < myBoard._cellcount2 and myBoard.cells[i] != cellstate.used and myBoard.cells[i+myBoard._cellcount] != cellstate.used):         #vertical stick
            return True
    return False
    
def getAImove(myBoard):
    assert myBoard._cellcount2 % 2 == 0
    a = myBoard._cellcount2 - myBoard.rectangles[-1][0] - 1
    b = myBoard._cellcount2 - myBoard.rectangles[-1][1] - 1
    return a,b

def getAIrandommove(myBoard):
    a = 0
    b = 0
    while True:
        shift1 = random.randint(0,myBoard._cellcount-2)
        shift2 = random.randint(0,myBoard._cellcount-1)
        vertical = bool(random.getrandbits(1))

        if (vertical):
            a = myBoard._cellcount * shift1 + shift2
            b = a + myBoard._cellcount
        else:
            a = shift1 + myBoard._cellcount * shift2
            b = a + 1
		
        if (myBoard.cells[a] != cellstate.used and myBoard.cells[b] != cellstate.used):
            break

    return a,b


def printMessage(content, fontsize, forecolor, backcolor, coords):
    myFont = pygame.font.Font('freesansbold.ttf', fontsize)
    msgObj = myFont.render(content, True, forecolor, backcolor)
    msgRect = msgObj.get_rect()
    msgRect.topleft = coords
    SURF.blit(msgObj, msgRect)
    return msgRect



def main():
    color1 = colors.red
    color2 = colors.blue
    
    def newGame(ai):
        nonlocal AIplayer,player,myBoard,myGameState
        myBoard = Board(CELLCOUNT,(25,25,450,450),isvalid,color1,color2)
        myGameState = gamestate.running
        player = 1
        AIplayer = ai
    
    pygame.display.set_caption('Two squares game!')

    
    mousex = 0
    mousey = 0

    AIplayer = None
    player = None
    myBoard = None
    myGameState = None
    newGame(0)

    
    
    while True: # main game loop
        
        SURF.fill(colors.navyblue)
        rctNewGame2p = printMessage("New Game (2 players)",17,colors.white,colors.black,(300,560))
        rctNewGameAI1 = printMessage("New Game (vs. Easy AI)",17,colors.white,colors.black,(300,600))
        rctNewGameAI2 = printMessage("New Game (vs. Hard AI)",17,colors.white,colors.black,(300,640))
        rctP1Color = printMessage("P1",25,colors.white,color1,(70,630))
        rctP2Color = printMessage("P2",25,colors.white,color2,(130,630))
            
        mouseclicked = False
        mymessage = "Player " + str(player) + " 's Turn"
        
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == MOUSEMOTION:
                mousex, mousey = event.pos
                
            elif event.type == MOUSEBUTTONDOWN:
                mousex, mousey = event.pos
                mouseclicked = True

        mycell = myBoard.getCellAt(mousex, mousey)

        if mouseclicked:
            if rctNewGame2p.collidepoint(mousex, mousey):
                newGame(0)
                continue
            elif rctNewGameAI1.collidepoint(mousex, mousey):
                newGame(1)
                continue
            elif rctNewGameAI2.collidepoint(mousex, mousey):
                newGame(2)
                continue
            elif rctP1Color.collidepoint(mousex, mousey):
                if myBoard.cellPlayer1Color == colors.red:
                    myBoard.cellPlayer1Color = colors.orange
                elif myBoard.cellPlayer1Color == colors.orange:
                    myBoard.cellPlayer1Color = colors.pink
                elif myBoard.cellPlayer1Color == colors.pink:
                    myBoard.cellPlayer1Color = colors.gray
                else:
                    myBoard.cellPlayer1Color = colors.red

                color1 = myBoard.cellPlayer1Color
                continue
            elif rctP2Color.collidepoint(mousex, mousey):
                if myBoard.cellPlayer2Color == colors.blue:
                    myBoard.cellPlayer2Color = colors.indigo
                elif myBoard.cellPlayer2Color == colors.indigo:
                    myBoard.cellPlayer2Color = colors.cyan
                elif myBoard.cellPlayer2Color == colors.cyan:
                    myBoard.cellPlayer2Color = colors.gray
                else:
                    myBoard.cellPlayer2Color = colors.blue
                color2 = myBoard.cellPlayer2Color
                continue

            
            if myGameState == gamestate.running and mycell != None :
                if myBoard.setSelected(mycell,player) == True:
                    if checkPossible(myBoard) == False:
                        myGameState = gamestate.stopped
                    else:
                        if AIplayer == 1:
                            a,b = getAIrandommove(myBoard)
                        elif AIplayer == 2:
                            a,b = getAImove(myBoard)
                            
                        if AIplayer != 0:
                            drawstuff()
                            time.sleep(0.5)
                            myBoard.setSelected(a,2)
                            drawstuff()
                            time.sleep(0.3)
                            myBoard.setSelected(b,2)
                            if checkPossible(myBoard) == False:
                                myGameState = gamestate.stopped
                                player = "AI"
                        else:        #Human player
                            if player == 1:
                                player = 2
                            else:
                                player = 1

        else:
            if myGameState == gamestate.running:
                myBoard.setHighlighted(mycell)

        if myGameState == gamestate.running:
            mymessage = "Player " + str(player) + "'s Turn"
        else:
            if player == "AI":
                mymessage = "The AI has won :P Haha!"
            else:
                mymessage = "Player " + str(player) + " Won!!! Congratulations!!!"
        #drawing stuff
        def drawstuff():
        
            myBoard.draw(SURF)

            printMessage(mymessage,25,colors.white,None,(25,500))
        
            pygame.display.update()

        drawstuff()
        FPSCLOCK.tick(FPS)

if __name__ == '__main__':
    main()
