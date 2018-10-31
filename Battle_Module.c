#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#include "Battle_Module.h"


/*display character frame*/
WINDOW *Battle_WinOne(int l,int r,int x,int y,SRole1 *characterPtr)
{
    WINDOW * win = NULL;   

    /*set character frame size and color*/
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    win = newwin(l,r,x,y); 
    wbkgd(win,COLOR_PAIR(1));  
    box(win,0,0);  
    wrefresh(win);

    /*display character name*/
    mvprintw(5,10,"%s",characterPtr->name);    

    /*display blood and magic*/
    mvprintw(6,8,"blood:%d/100",characterPtr->blood);
    mvprintw(7,8,"magic:%d/300",characterPtr->blueblood);

    /*display character icon*/
    mvprintw(13,11,"character");
    
    return win;
}

/*display monster frame*/
WINDOW *Battle_WinTwo(int l,int r,int x,int y,SMonster *monsterPtr)
{
    WINDOW * win = NULL;   

    /*set monster frame size and color*/
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    win = newwin(l,r,x,y); 
    wbkgd(win,COLOR_PAIR(1));  
    box(win,0,0);   
    wrefresh(win);

    /*display monster name*/
    mvprintw(5,60,"%s",monsterPtr->name);    

    /*display blood and magic*/
    mvprintw(6,56,"blood:%d/100",monsterPtr->blood);
    mvprintw(7,56,"magic:%d/400",monsterPtr->blueblood);

    /*display monster icon*/
    mvprintw(13,59,"monster");
    
    return win;
}

/*display state frame*/
WINDOW *Battle_WinThree(int l,int r,int x,int y)
{
    WINDOW * win = NULL;   

    // set state frame size and color
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    win = newwin(l,r,x,y); 
    wbkgd(win,COLOR_PAIR(1));  
    box(win,0,0);   
    wrefresh(win);
    mvprintw(21,24,"z.attack  x.blue  c.treat");
    mvprintw(22,24,"v.medicine  b.revive");
    return win;
}

/*display escap key frame*/
WINDOW *Battle_WinFour(int l,int r,int x,int y)
{
    WINDOW * winEscap;   

    /*display battle process escap key*/
    mvprintw(21,70,"y/n");

    /*display character all skills*/
    mvprintw(18,4,"skill1(z)");
    mvprintw(18,16,"skill2(x)");
    mvprintw(18,28,"skill3(c)");
    mvprintw(18,40,"skill4(v)");
    mvprintw(18,52,"skill5(b)");

    /*set escap frame size and color*/
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    winEscap = newwin(l,r,x,y); 
    wbkgd(winEscap,COLOR_PAIR(1));  
    box(winEscap,0,0);   
    wrefresh(winEscap);
}

/*judge character whether escape*/
EBool1 Battle_Judge_Character_Escape(SRole1 * characterPtr)
{
    initscr();
    i8 inputKey = 0;
    EBool1 resultFlag = EBool_None;
    mvprintw(19,3,"character whether escape ? (y/n)\n");
    do
    {
        inputKey = getch();
        //scanf("%c",&inputKey);
        //getchar();
        if(inputKey == 'y' || inputKey == 'Y')
        {
            resultFlag = EBool_Escape;
            break;
        }
        else if(inputKey == 'n' || inputKey == 'N')
        {
            resultFlag = EBool_None;
            break;
        }
        else
        {
            mvprintw(19,3,"input error !re-input:(y/n)            \n");
        }
    }while(1);
    
    
    return resultFlag;
    refresh();

    endwin();
}

/*example:doctor role have five skills,ÆÕÍ¨¹¥»÷¡¢³éÀ¶¡¢ÖÎÁÆ¡¢¸´»î¡¢³ÔÒ©*/
/*character use a skill*/
void Battle_Character_Use_Skill(SRole1 *characterPtr,SMonster *monster)
{
    initscr();
    i8 skillkey  = 0;
    mvprintw(19,3,"character use a skill !            \n");

    do
    {   
        skillkey = getch();

        if(skillkey == 'z' ||skillkey == 'Z')
        {
            monster->blood = monster->blood - 30;
            break;
        }
        else if(skillkey == 'x' || skillkey == 'X')
        {
            monster->blood = monster->blood - C_SKILL_X_BLOOD;
            monster->blueblood = monster->blueblood -C_SKILL_Z_BLOOD;
            characterPtr->blueblood = characterPtr->blueblood - 20 + C_SKILL_Z_BLOOD;
            break;
        }
        else if(skillkey == 'c' || skillkey == 'C')
        {
            monster->blood = monster->blood - C_SKILL_X_BLOOD;
            characterPtr->blood = characterPtr->blood + C_SKILL_X_BLOOD;
            characterPtr->blueblood = characterPtr->blueblood - C_SKILL_C_BLUE;
            break;
        }
        else if(skillkey == 'v' || skillkey == 'V')
        {
            if(characterPtr->blood  <=  BLOOD_ZERO)
            {
                characterPtr->blueblood = characterPtr->blueblood - C_SKILL_C_BLUE;
                characterPtr->blood = characterPtr->blood + C_SKILL_V_BLOOD;
            }
            else
            {
                mvprintw(19,3,"you are alive ! select other skill  !   \n");
            }
            
        }
        else if(skillkey == 'b' || skillkey == 'B')
        {
            characterPtr->blueblood = characterPtr->blueblood - C_SKILL_C_BLUE;
            characterPtr->blood = characterPtr->blood + C_SKILL_B_BLOOD;
            break;
        }
        else
        {
            mvprintw(19,3,"you input skill error !re-input:        \n");
        }        
        
    }while(1);

    endwin();
}

/*judge the monster blood whether is null*/
EBloodFlag Battle_Judge_Monster_Blood_Null(SMonster*monsterPtr)
{
    EBloodFlag bloodFlag =EBloodFlag_No;
    if(monsterPtr->blood <= BLOOD_ZERO)
    {
        bloodFlag = EBloodFlag_Yes;
    }
    else
    {
        bloodFlag = EBloodFlag_No;
    }
    return bloodFlag;
}

/*display all info*/
void Battle_Display_All_Info(EIdentity identityFlag,SRole1*characterPtr,SMonster*monsterPtr)
{
    initscr();
    if(identityFlag == EIdentity_Character)
    { 
        if(monsterPtr->blood < BLOOD_ZERO)
        {
            mvprintw(6,56,"blood:000/100");
            mvprintw(7,56,"magic:%3d/400",monsterPtr->blueblood); 
            mvprintw(6,8,"blood:%3d/100",characterPtr->blood);
            mvprintw(7,8,"magic:%3d/300",characterPtr->blueblood);  
        }
        else if(characterPtr->blood > SIZE_OF_CHARACTER_BLOOD)
        {
            characterPtr->blood = SIZE_OF_CHARACTER_BLOOD;
            mvprintw(6,56,"blood:%3d/100",monsterPtr->blood);
            mvprintw(7,56,"magic:%3d/400",monsterPtr->blueblood); 
            mvprintw(6,8,"blood:%3d/100",characterPtr->blood);
            mvprintw(7,8,"magic:%3d/300",characterPtr->blueblood); 
        
        }
        else
        {
            mvprintw(6,56,"blood:%3d/100",monsterPtr->blood);
            mvprintw(7,56,"magic:%3d/400",monsterPtr->blueblood);   
            mvprintw(6,8,"blood:%3d/100",characterPtr->blood);
            mvprintw(7,8,"magic:%3d/300",characterPtr->blueblood); 
        }
           
    }
    else if(identityFlag == EIdentity_Monster)
    {
        if(characterPtr->blood >SIZE_OF_CHARACTER_BLOOD)
        {
            characterPtr->blood = SIZE_OF_CHARACTER_BLOOD;
            mvprintw(6,8,"blood:100/100");
            mvprintw(7,8,"magic:%3d/300",characterPtr->blueblood);            

        }
        else if(characterPtr->blueblood > SIZE_OF_CHARACTER_BLUE)
        {
            characterPtr->blueblood = SIZE_OF_CHARACTER_BLUE;
            mvprintw(6,8,"blood:%3d/100",characterPtr->blood);
            mvprintw(7,8,"magic:300/300");  
        }
        else if(characterPtr->blood <BLOOD_ZERO)
        {
            mvprintw(6,8,"blood:000/100");
            mvprintw(7,8,"magic:%3d/300",characterPtr->blueblood);   
        }
        else
        {
            mvprintw(6,8,"blood:%3d/100",characterPtr->blood);
            mvprintw(7,8,"magic:%3d/300",characterPtr->blueblood);            
        }
        
    }
    else
    {
        mvprintw(19,3,"error!");
    }
    
    endwin();
}

/*monster use a skill*/
void Battle_Monster_Use_Skill(SRole1*characterPtr,SMonster *monsterPtr)
{
    initscr();
    i8 skillFlag = 0;    
    mvprintw(19,3,"monster use a skill !                         \n");

    do
    {
        skillFlag = getch();
        if(skillFlag == 'p' || skillFlag == 'P')
        {
            characterPtr->blood = characterPtr->blood - M_SKILL_OF_BLOOD_REDUCE;
            break;
        }
        else
        {   
            mvprintw(19,3,"monster input is error!re-input(p)\n");
        }    
    }while(1);

    endwin();
}

/*judge character blood whether is null*/
EBloodFlag Battle_Judge_Character_Blood_Null(SRole1*characterPtr)
{
    EBloodFlag bloodFlag =EBloodFlag_No;    
    if(characterPtr->blood <= BLOOD_ZERO)
    {
        bloodFlag = EBloodFlag_Yes;
    }
    else
    {
        bloodFlag = EBloodFlag_No;
    }
    return bloodFlag;
}

/*play one game with monster*/
EBool1 Battle_Fighting_One_Process(SRole1 *characterPtr,SMonster *monsterPtr)
{
    WINDOW * winOne     = NULL;
    WINDOW * winTwo    = NULL;
    WINDOW * winThree = NULL;
    WINDOW * winFour    = NULL;
    WINDOW * winSkill     = NULL;

    /*init ncurses mode*/
    initscr();
    
    /*colour library*/
    start_color();  
    
    mvprintw(1,30,"Battle with monster");
    init_pair(1,COLOR_BLACK,COLOR_WHITE);
    bkgd(COLOR_PAIR(1));
    /*let us see the string*/
    refresh();  
    
    winOne = Battle_WinOne(14,25,3,3,characterPtr);
    winTwo= Battle_WinTwo(14,25,3,50,monsterPtr);
    winThree = Battle_WinThree(4,30,20,23);
    winFour = Battle_WinFour(3,6,20,68);

    refresh(); 
    EBool1 resultFlag             = EBool_None;
    EIdentity identityFlag    = EIdentity_None;
    
    while(!resultFlag)
    {
        identityFlag = EIdentity_Character;
        /*judge character whether escape*/
        if(Battle_Judge_Character_Escape(characterPtr) != EBool_Escape)
        {
            /*character use a skill*/
            Battle_Character_Use_Skill(characterPtr,monsterPtr);
            
            /*judge the monster blood whether is null*/
            if(!Battle_Judge_Monster_Blood_Null(monsterPtr))
            {
                /*display all info*/
                Battle_Display_All_Info(identityFlag,characterPtr,monsterPtr);
                identityFlag = EIdentity_Monster;
                /*monster use a skill*/
                Battle_Monster_Use_Skill(characterPtr,monsterPtr);

                /*judge character blood whether is null*/
                if(!Battle_Judge_Character_Blood_Null(characterPtr))
                {
                    /*display all info*/
                    Battle_Display_All_Info(identityFlag,characterPtr,monsterPtr); 
                    
                }
                else
                {
                    Battle_Display_All_Info(identityFlag,characterPtr,monsterPtr); 
                    resultFlag = EBool_Win;
                }
            }
            else
            {
                Battle_Display_All_Info(identityFlag,characterPtr,monsterPtr); 
                resultFlag = EBool_Lose;
            }       
        }
        else
        {
            resultFlag = EBool_Escape;
        }

    }
     return resultFlag;

    /*just hold and wait for any key pressed*/
    getch();
    /*leave ncurses mode*/
    endwin();   
}

/*judge the result,escape or win or lose*/
void Battle_Judge_Result(EBool1 resultFlag)
{
    initscr();
    
    if(resultFlag == EBool_Escape)
    {
        mvprintw(19,3,"you escape , accept some punishment !\n");
    }
    else if(resultFlag == EBool_Lose)
    {
        mvprintw(19,3,"congratulation , you are win !          \n ");
    }
    else if(resultFlag == EBool_Win)
    {
        mvprintw(19,3,"sorry , you are lose !                          \n ");
    }
    else
    {
        mvprintw(19,3,"Error   !                                                 \n ");
    }
    
    getch();
    endwin();
}


int Battle_Module_main(PSRole role)
{
    EBool1 resultFighting    = EBool_None;
    SRole1 * character       = NULL;
    SMonster * monster   = NULL;

    /*apply memory for character*/
    character = (SRole1*)malloc(sizeof(SRole1));
    /*test the apply memory whether is null*/
    if(!character)
    {
        printf("role memory is apply error !\n");
        exit(-1);
    }
    /*set initial value*/
    memset(character,0,sizeof(SRole1));

    /*apply memory for monster*/
    monster = (SMonster*)malloc(sizeof(SMonster));
    /*test the apply memory whether is null*/
    if(!monster)
    {
        printf("monster memory is apply error !\n");
        exit(-1);
    }
    
    /*set initial value*/
    memset(monster,0,sizeof(SMonster));

    /*give monster and character's attribute  assignment*/
    strcpy(monster->name,"monster");
    monster->blood = SIZE_OF_MONSTER_BLOOD;
    monster->blueblood = SIZE_OF_MONSTER_BLUE;

    strcpy(character->name,role->name);
    character->blood = SIZE_OF_CHARACTER_BLOOD;
    character->money = SIZE_OF_CHARACTER_MONEY;
    character->blueblood = SIZE_OF_CHARACTER_BLUE;

    /*close customas interface*/
    //Customas_Close();

    /*open battle interface*/
    //Battle_Open(void,void);

    /*initialize battle interface*/
    //Battle_Initialize_Ui();

    /*play one game with monster*/
    resultFighting = Battle_Fighting_One_Process(character,monster);

    /*judge the result*/
   Battle_Judge_Result(resultFighting);
            
    return 0;
}


