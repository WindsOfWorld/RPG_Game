#include <stdio.h>
#include <stdlib.h>

#include "Function_Selection_Module.h"


void MainUI_Close()
{
    system("clear");
}

void static DisplayProperty(PSRole role)
{
    MainUI_Close();
    printf("name: %s\n",role->name);
    printf("level : %d\n",role->level);
    printf("floor : %d\n",role->floor);
    printf("profession : %d\n",role->profession);
    printf("brain|physi|root |spirit|agili|ocatable\n");
    printf(" %2d  | %2d  | %2d  |  %2d  | %2d  | %2d \n",\
                                                             role->baseProperty->brains,\
                                                             role->baseProperty->physical,\
                                                             role->baseProperty->rootbone,\
                                                             role->baseProperty->spirit,\
                                                             role->baseProperty->agility,\
                                                             role->baseProperty->allocatable);
    printf("empirical : %d / %d\n",role->empiricalOfValue,role->empiricalOfValueOfUpgrade);
}







void PrecedenceTableUI_Open()
{
    MainUI_Close();
    printf("Net Error!!!!!!!\n");
}

void PrecedenceTableUI_Close()
{
    
}

void Property_Open(PSRole role)
{
    DisplayProperty(role);
}

void PropretyUI_Close()
{
    system("clear");
}

void Packsack_Open(PSRole role)
{
    MainUI_Close();
    return ;
}

void Packsack_Close()
{
    system("clear");
}


void MainUI_Open(PSRole role)
{
    u8 choose =0;
    FILE *fp;
    for(;;)
    {
        RL_RegisterOrLogon_Close();
        choose =0;
        printf("[q] PrecedenceTable\n");
        printf("[w] Property\n");
        printf("[e] Packsack\n");
        printf("[r] Battle\n");
        printf("[p] quit!\n");
        
        scanf("%1[q/w/e/r/t/y/u]c",&choose);
        for(;;)
        {
            if('\n'==getchar())
                break;
        }
        switch(choose)
        {
            case 'q': PrecedenceTableUI_Open();
                          break;
            case 'w': Property_Open(role);
                          break;
            case 'e': Packsack_Open(role);
                          break;
            case 'r': Battle_Module_main(role);
                          break;
            case 'p': return ;
            default:break;
        }
        for(;;)
        {
            if('\n'==getchar())
                break;
        }
    }
    return ;
}

