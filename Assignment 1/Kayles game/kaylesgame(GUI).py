import sys, pygame
FPS = 100
fpsClock = pygame.time.Clock()
pygame.init()
counter = 20
changer = 2
know = 1
cary = 0
player1 = False
player2 = False
saver = 0
one = False
two = False
three = False
four = False
five = False
six = False
seven = False
eigth = False
nine = False
ten = False
eleven = False
twelve = False
thirteen = False
fourteen = False
fiveteen = False
sixteen = False
seventeen = False
eigthteen = False
nineteen = False
twenty = False
my_list = ['False','False','False','False','False','False','False','False','False','False','False','False','False','False','False','False','False','False','False','False']
x = 0
y = 0
size = width, height = 1120, 200
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Kayles Game")
pattern = False
clock = pygame.time.Clock()
font = pygame.font.Font(None,50)
font1 = pygame.font.Font(None,90)
def play(first , second):
    global my_list
    for i in range (0,20,1):
        my_list[i] = 'True'
    my_list[first] = 'False'
    my_list[second] = 'False'

def play_back():
    global my_list
    for i in range (0,20,1):
        my_list[i] = 'False'
    
def draw_text(mes,color,pos):
    text = font.render(mes,True,color)
    screen.blit(text,[pos,80])
    
def draw_text1(mes,color,pos):
    text = font1.render(mes,True,color)
    screen.blit(text,[pos,67])
def player(tex):
    text = font.render(tex, True , (0,0,255))
    screen.blit(text,[10,5])
def was_choosen():
    text = font.render('the number was choosen before!',True, (255,0,0))
    screen.blit(text,[210,5])
def color(colour , tex , pos , poss ,colour1):
    pygame.draw.rect(screen,colour,pos)
    text = font.render(tex, True , colour1)
    screen.blit(text,poss)
player('player 1')
color((255,255,255),'one no.player1',(100,150,250,50),[105,160],(0,0,100))
color((255,255,255),'one no.player2',(770,150,255,50),[775,160],(20,255,50))
while not pattern:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pattern = True
    z , w = pygame.mouse.get_pos()
    if(event.type == pygame.MOUSEBUTTONDOWN):
        x , y = pygame.mouse.get_pos()
    pygame.draw.rect(screen,(255,255,255),(10,70,50,50))
    if(x >= 10 and x <= 60 and y <= 120 and y >= 70 and my_list[0] == 'False' or one == True):
        if(x >= 10 and x <= 60 and y <= 120 and y >= 70 and one == True and know != 1):
            was_choosen()
        elif(one == False):
            play(1,1)
            counter -= 1
            num = 1
            cary += 1 
            know = 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),25)
        one = True
    else:
        draw_text('1',(0,0,255),25)
    pygame.draw.rect(screen,(255,255,255),(65,70,50,50))
    if(x >= 65 and x <= 115 and y <= 120 and y >= 70 and my_list[1] == 'False' or two == True):
        if(x >= 65 and x <= 115 and y <= 120 and y >= 70 and two == True and know != 2):
            was_choosen()
        if(two == False):
            play(0,2)
            know = 2
            num = 2
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
            counter -= 1
        draw_text1('-',(60,40,70),80)
        two = True
    else:
        draw_text('2',(0,0,255),80)
    pygame.draw.rect(screen,(255,255,255),(120,70,50,50))
    if(x >= 120 and x <= 170 and y <= 120 and y >= 70 and my_list[2] == 'False' or three == True):
        if(x >= 120 and x <= 170 and y <= 120 and y >= 70 and three == True and know != 3):
            was_choosen()
        if(three == False):
            play(1,3)
            counter -= 1
            know = 3
            num = 3
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),135)
        three = True
    else:
        draw_text('3',(0,0,255),135)
    pygame.draw.rect(screen,(255,255,255),(175,70,50,50))
    if(x >= 175 and x <= 225 and y <= 120 and y >= 70 and my_list[3] == 'False' or four == True):
        if(x >= 175 and x <= 225 and y <= 120 and y >= 70 and four == True and know != 4):
            was_choosen()
        if(four == False):
            play(2,4)
            counter -= 1
            num =4
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
            know = 4
            cary += 1
        draw_text1('-',(60,40,70),190)
        four = True
    else:
        draw_text('4',(0,0,255),190)
    pygame.draw.rect(screen,(255,255,255),(230,70,50,50))
    if(x >= 230 and x <= 280 and y <= 120 and y >= 70 and my_list[4] == 'False' or five == True):
        if(x >= 230 and x <= 280 and y <= 120 and y >= 70 and five == True and know != 5):
            was_choosen()
        if(five == False):
            play(5,3)
            counter -= 1
            know = 5
            num = 5
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),245)
        five = True
    else:
        draw_text('5',(0,0,255),245)
    pygame.draw.rect(screen,(255,255,255),(285,70,50,50))
    if(x >= 285 and x <= 335 and y <= 120 and y >= 70 and my_list[5] == 'False'or six == True):
        if(x >= 285 and x <= 335 and y <= 120 and y >= 70 and six == True and know != 6):
            was_choosen()
        if(six == False):
            play(4,6)
            counter -= 1
            know = 6
            num =6
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),300)
        six = True
    else:
        draw_text('6',(0,0,255),300)
    pygame.draw.rect(screen,(255,255,255),(340,70,50,50))
    if(x >= 340 and x <= 390 and y <= 120 and y >= 70 and my_list[6] == 'False'or seven == True):
        if(x >= 340 and x <= 390 and y <= 120 and y >= 70 and seven == True and know != 7):
            was_choosen()
        if(seven == False):
            play(5,7)
            counter -= 1
            know = 7
            num =7
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),355)
        seven = True
    else:
        draw_text('7',(0,0,255),355)
    pygame.draw.rect(screen,(255,255,255),(395,70,50,50))
    if(x >= 395 and x <= 445 and y <= 120 and y >= 70 and my_list[7] == 'False' or eigth == True):
        if(x >= 395 and x <= 445 and y <= 120 and y >= 70 and eigth == True and know != 8):
            was_choosen()
        if(eigth == False):
            play(6,8)
            counter -= 1
            know = 8
            num = 8
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),410)
        eigth = True
    else:
        draw_text('8',(0,0,255),410)
    pygame.draw.rect(screen,(255,255,255),(450,70,50,50))
    if(x >= 450 and x <= 500 and y <= 120 and y >= 70 and my_list[8] == 'False' or nine == True):
        if(x >= 450 and x <= 500 and y <= 120 and y >= 70 and nine == True and know != 9):
            was_choosen()
        if(nine == False):
            play(7,9)
            counter -= 1
            know = 9
            num = 9
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),465)
        nine = True
    else:
        draw_text('9',(0,0,255),465)
    pygame.draw.rect(screen,(255,255,255),(505,70,50,50))
    if(x >= 505 and x <= 555 and y <= 120 and y >= 70 and my_list[9] == 'False' or ten == True):
        if(x >= 505 and x <= 555 and y <= 120 and y >= 70 and ten == True and know != 10):
            was_choosen
        if(ten == False):
            play(8,10)
            counter -= 1
            know = 10
            num = 10
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),520)
        ten = True
    else:
        draw_text('10',(0,0,255),510)
    pygame.draw.rect(screen,(255,255,255),(560,70,50,50))
    if(x >= 560 and x <= 610 and y <= 120 and y >= 70 and my_list[10] == 'False' or eleven == True):
        if(x >= 560 and x <= 610 and y <= 120 and y >= 70 and eleven == True and know != 11):
            was_choosen()
        if(eleven == False):
            play(9,11)
            counter -= 1
            know = 11
            num = 11
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),578)
        eleven = True
    else:
        draw_text('11',(0,0,255),568)
    pygame.draw.rect(screen,(255,255,255),(615,70,50,50))
    if(x >= 615 and x <= 665 and y <= 120 and y >= 70 and my_list[11] == 'False' or twelve == True):
        if(x >= 615 and x <= 665 and y <= 120 and y >= 70 and twelve == True and know!= 12):
            was_choosen()
        if(twelve == False):
            play(10,12)
            counter -= 1
            know = 12
            num = 12
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),630)
        twelve = True
    else:
        draw_text('12',(0,0,255),620)
    pygame.draw.rect(screen,(255,255,255),(670,70,50,50))
    if(x >= 670 and x <= 720 and y <= 120 and y >= 70 and my_list[12] == 'False' or thirteen == True):
        if(x >= 670 and x <= 720 and y <= 120 and y >= 70 and thirteen == True and know != 13):
            was_choosen()
        if(thirteen == False):
            play(11,13)
            counter -= 1
            know = 13
            num = 13
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),685)
        thirteen = True
    else:
        draw_text('13',(0,0,255),675)
    pygame.draw.rect(screen,(255,255,255),(725,70,50,50))
    if(x >= 725 and x <= 775 and y <= 120 and y >= 70 and my_list[13] == 'False' or fourteen == True):
        if(x >= 725 and x <= 775 and y <= 120 and y >= 70 and fourteen == True and know != 14):
            was_choosen()
        if(fourteen == False):
            play(12,14)
            counter -= 1
            know = 14
            num = 14
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),740)
        fourteen = True
    else:
        draw_text('14',(0,0,255),730)
    pygame.draw.rect(screen,(255,255,255),(780,70,50,50))
    if(x >= 780 and x <= 830 and y <= 120 and y >= 70 and my_list[14] == 'False' or fiveteen == True):
        if(x >= 780 and x <= 830 and y <= 120 and y >= 70 and fiveteen == True and know != 15):
            was_choosen()
        if(fiveteen == False):
            play(13,15)
            counter -= 1
            know = 15
            num = 15
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),795)
        fiveteen = True
    else:
        draw_text('15',(0,0,255),785)
    pygame.draw.rect(screen,(255,255,255),(835,70,50,50))
    if(x >= 835 and x <= 885 and y <= 120 and y >= 70 and my_list[15] == 'False' or sixteen == True):
        if(x >= 835 and x <= 885 and y <= 120 and y >= 70 and sixteen == True and know !=  16):
            was_choosen
        if(sixteen == False):
            play(14,16)
            counter -= 1
            know = 16
            num = 16
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),850)
        sixteen = True
    else:
        draw_text('16',(0,0,255),840)
    pygame.draw.rect(screen,(255,255,255),(890,70,50,50))
    if(x >= 890 and x <= 940 and y <= 120 and y >= 70 and my_list[16] == 'False' or seventeen == True):
        if(x >= 890 and x <= 940 and y <= 120 and y >= 70 and seventeen == True and know != 17):
            was_choosen
        if(seventeen == False):
            play(15,17)
            counter -= 1
            know = 17
            num = 17
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),905)
        seventeen = True
    else:
        draw_text('17',(0,0,255),895)
    pygame.draw.rect(screen,(255,255,255),(945,70,50,50))
    if(x >= 945 and x <= 995 and y <= 120 and y >= 70 and my_list[17] == 'False' or eigthteen == True):
        if(x >= 945 and x <= 995 and y <= 120 and y >= 70 and eigthteen == True and know != 18):
            was_choosen()
        if(eigthteen == False):
            play(16,18)
            counter -= 1
            know = 18
            num = 18
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),960)
        eigthteen = True
    else:
        draw_text('18',(0,0,255),950)
    pygame.draw.rect(screen,(255,255,255),(1000,70,50,50))
    if(x >= 1000 and x <= 1050 and y <= 120 and y >= 70 and my_list[18] == 'False' or nineteen == True):
        if(x >= 1000 and x <= 1050 and y <= 120 and y >= 70 and nineteen == True and know != 19):
            was_choosen()
        if(nineteen == False):
            play(17,19)
            counter -= 1
            know = 19
            num = 19
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),1015)
        nineteen = True
    else:
        draw_text('19',(0,0,255),1005)
    pygame.draw.rect(screen,(255,255,255),(1055,70,50,50))
    if(x >= 1055 and x <= 1105 and y <= 120 and y >= 70 and my_list[19] == 'False' or twenty == True):
        if(x >= 1055 and x <= 1105 and y <= 120 and y >= 70 and twenty == True and know != 20):
            was_choosen
        if(twenty == False):
            play(18,18)
            counter -= 1
            know = 20
            num = 20
            cary += 1
            pygame.draw.rect(screen,(0,0,0),(200,5,600,50))
        draw_text1('-',(60,40,70),1070)
        twenty = True
    else:
        draw_text('20',(0,0,255),1060)
    if(x >= 770 and x <= 1020 and y >= 150 and y <= 200):
        cary = 3
        changer = 1
    if(x >= 100 and x <= 350 and y >= 150 and y <= 200):
        cary = 3
        changer = 2
    if(z >= 10 and z <= 60 and w <= 120 and w >= 70 and one == False):
        pygame.draw.rect(screen,(255,255,255),(10,70,50,50))
        draw_text('1',(255,0,0),25)
    elif(z >= 65 and z <= 115 and w <= 120 and w >= 70 and two == False):
        pygame.draw.rect(screen,(255,255,255),(65,70,50,50))
        draw_text('2',(255,0,0),80)
    elif(z >= 120 and z <= 170 and w <= 120 and w >= 70 and three == False):
        pygame.draw.rect(screen,(255,255,255),(120,70,50,50))
        draw_text('3',(255,0,0),135)
    elif(z >= 175 and z <= 225 and w <= 120 and w >= 70 and four == False):
        pygame.draw.rect(screen,(255,255,255),(175,70,50,50))
        draw_text('4',(255,0,0),190)
    elif(z >= 230 and z <= 280 and w <= 120 and w >= 70 and five == False):
        pygame.draw.rect(screen,(255,255,255),(230,70,50,50))
        draw_text('5',(255,0,0),245)
    elif(z >= 285 and z <= 335 and w <= 120 and w >= 70 and six == False):
        pygame.draw.rect(screen,(255,255,255),(285,70,50,50))
        draw_text('6',(255,0,0),300)
    elif(z >= 340 and z <= 390 and w <= 120 and w >= 70 and seven == False):
        draw_text('7',(255,0,0),355)
    elif(z >= 395 and z <= 445 and w <= 120 and w >= 70 and eigth == False):
        draw_text('8',(255,0,0),410)
    elif(z >= 450 and z <= 500 and w <= 120 and w >= 70 and nine == False):
        draw_text('9',(255,0,0),465)
    elif(z >= 505 and z <= 555 and w <= 120 and w >= 70 and ten == False):
        draw_text('10',(255,0,0),510)
    elif(z >= 560 and z <= 610 and w <= 120 and w >= 70 and eleven == False):
        draw_text('11',(255,0,0),568)
    elif(z >= 615 and z <= 665 and w <= 120 and w >= 70 and twelve == False):
        draw_text('12',(255,0,0),620)
    elif(z >= 670 and z <= 720 and w <= 120 and w >= 70 and thirteen == False):
        draw_text('13',(255,0,0),675)
    elif(z >= 725 and z <= 775 and w <= 120 and w >= 70 and fourteen == False):
        draw_text('14',(255,0,0),730)
    elif(z >= 780 and z <= 830 and w <= 120 and w >= 70 and fiveteen == False):
        draw_text('15',(255,0,0),785)
    elif(z >= 835 and z <= 885 and w <= 120 and w >= 70 and sixteen == False):
        draw_text('16',(255,0,0),840)
    elif(z >= 890 and z <= 940 and w <= 120 and w >= 70 and seventeen == False):
        draw_text('17',(255,0,0),895)
    elif(z >= 945 and z <= 995 and w <= 120 and w >= 70 and eigthteen == False):
        draw_text('18',(255,0,0),950)
    elif(z >= 1000 and z <= 1050 and w <= 120 and w >= 70 and nineteen == False):
        draw_text('19',(255,0,0),1005)
    elif(z >= 1055 and z <= 1105 and w <= 120 and w >= 70 and twenty == False):
        draw_text('20',(255,0,0),1060)
    if(cary == 2 or cary == 3):
        if(changer == 1):
            pygame.draw.rect(screen,(0,0,0),(10,5,200,50))
            player('player 1')
            changer = 2
            color((255,255,255),'one no.player1',(100,150,250,50),[105,160],(0,0,100))
            color((255,255,255),'one no.player2',(770,150,255,50),[775,160],(20,255,50))
        elif(changer == 2):
            pygame.draw.rect(screen,(0,0,0),(10,5,200,50))
            player('player 2')
            changer = 1
            color((255,255,255),'one no.player1',(100,150,250,50),[105,160],(20,255,50))
            color((255,255,255),'one no.player2',(770,150,255,50),[775,160],(0,0,100))
        play_back()
        cary = 0
    if(counter == 0):
        pygame.draw.rect(screen,(0,0,0),(10,5,200,50))
        if(changer == 2):
            player('player1 is the winner')
        else:
            player('player2 is the winner')
    pygame.display.flip()
    fpsClock.tick(FPS)
pygame.guit()



