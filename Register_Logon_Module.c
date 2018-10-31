#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <pthread.h>

#include "Role_Module.h"
#include "Register_logon_Module.h"

void RL_RegisterOrLogon_Close()
{
    system("clear");
}


void RL_Register_Into_InitOfSkill(PSSkill newskill,int i)
{   
    extern SSkill skills[18];
    newskill->Attack = skills[i].Attack;
    newskill->expendOfMagic =skills[i].expendOfMagic;
    newskill->level =skills[i].level;
    newskill->result =skills[i].result;
    newskill->skillBool=skills[i].skillBool;
    newskill->timeOfContinue=skills[i].timeOfContinue;
    newskill->timeOfCooling =skills[i].timeOfCooling;
    newskill->timeOfSurplse =skills[i].timeOfSurplse;
    
}


void RegisterOrLogon_Close(PSRole role)
{
    free(role->packsackHead->packsackkey);    
    free(role->packsackHead->packsack);
    free(role->packsackHead);
    free(role->equip);
    free(role->skill);
    free(role->extendProperty);
    free(role->baseProperty);
    free(role);
    exit(-1);
}

void RL_Register_Into(PSRole role)
{
    int i =0;    
    
    
    //注册界面，返回注册结果。
    //角色名和职业选择
    printf("Please input you name:");
    scanf("%s",role->name);
    getchar();
    printf("Please input you profession:(1.Doctor2.Master3.Knight4.Warrior5.Shooter)");
    scanf("%d",&i);
    role->profession = (EProfession)i;
    getchar();   
    
    File_CrestionFileOfRole(role);

    role->level  = 1;
    role->empiricalOfValue =0;
    role->empiricalOfValueOfUpgrade =EmpiricalOfValueOfUpgrade(role->level);
    role->baseProperty->allocatable = 0;
    role->floor =1;
    
    PSSkill newskill =role->skill;
    for(i=0;i<3;i++,newskill++)
    {
        RL_Register_Into_InitOfSkill(newskill,i);
    }
            
    if(EProfession_Doctor == role->profession )
    {
        role->baseProperty->brains = POINT_OF_DOCTOR_BRAINS;
        role->baseProperty->physical =POINT_OF_DOCTOR_PHYSICAL;
        role->baseProperty->rootbone =POINT_OF_DOCTOR_ROOTBONE;
        role->baseProperty->spirit      =POINT_OF_DOCTOR_SPIRIT;
        role->baseProperty->agility    =POINT_OF_DOCTOR_AGILITY;

        role->extendProperty->magicOfAttack = \
            BASE_EXTEND_TRANSITION_DOCTOR_MATTACK(role->baseProperty->brains);
        role->extendProperty->physicsOfAttack=\
            BASE_EXTEND_TRANSITION_DOCTOR_PATTACK(role->baseProperty->physical);
        role->extendProperty->magicOfDefense=\
            BASE_EXTEND_TRANSITION_DOCTOR_MDEFENSE(role->baseProperty->brains);
        role->extendProperty->physicsOfDefense=\
            BASE_EXTEND_TRANSITION_DOCTOR_PDEFENSE(role->baseProperty->physical);
        role->extendProperty->agility=\
            BASE_EXTEND_TRANSITION_DOCTOR_AGILITY(role->baseProperty->agility);
        role->extendProperty->allOfBlood=\
            BASE_EXTEND_TRANSITION_DOCTOR_ALLBLOOD(role->baseProperty->rootbone);
        role->extendProperty->allOfMagic=\
            BASE_EXTEND_TRANSITION_DOCTOR_ALLMAGIC(role->baseProperty->spirit);
        role->extendProperty->deadly=\
            BASE_EXTEND_TRANSITION_DOCTOR_DEADLY(role->baseProperty->allocatable);

        
        i=3;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=4;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=5;
        RL_Register_Into_InitOfSkill(newskill,i);


    }
    else if(EProfession_Master ==role->profession)
    {
        role->baseProperty->brains =POINT_OF_MASTER_BRAINS;
        role->baseProperty->physical =POINT_OF_MASTER_PHYSICAL;
        role->baseProperty->rootbone =POINT_OF_MASTER_ROOTBONE;
        role->baseProperty->spirit      =POINT_OF_MASTER_SPIRIT;
        role->baseProperty->agility    =POINT_OF_MASTER_AGILITY;

        role->extendProperty->magicOfAttack = \
            BASE_EXTEND_TRANSITION_MASTER_MATTACK(role->baseProperty->brains);
        role->extendProperty->physicsOfAttack=\
            BASE_EXTEND_TRANSITION_MASTER_PATTACK(role->baseProperty->physical);
        role->extendProperty->magicOfDefense=\
            BASE_EXTEND_TRANSITION_MASTER_MDEFENSE(role->baseProperty->brains);
        role->extendProperty->physicsOfDefense=\
            BASE_EXTEND_TRANSITION_MASTER_PDEFENSE(role->baseProperty->physical);
        role->extendProperty->agility=\
            BASE_EXTEND_TRANSITION_MASTER_AGILITY(role->baseProperty->agility);
        role->extendProperty->allOfBlood=\
            BASE_EXTEND_TRANSITION_MASTER_ALLBLOOD(role->baseProperty->rootbone);
        role->extendProperty->allOfMagic=\
            BASE_EXTEND_TRANSITION_MASTER_ALLMAGIC(role->baseProperty->spirit);
        role->extendProperty->deadly=\
            BASE_EXTEND_TRANSITION_MASTER_DEADLY(role->baseProperty->allocatable);
        
        i=6;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=7;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=8;
        RL_Register_Into_InitOfSkill(newskill,i);        
        
    }
    else if(EProfession_Knight == role->profession)
    {
        role->baseProperty->brains =POINT_OF_KNIGHT_BRAINS;
        role->baseProperty->physical = POINT_OF_KNIGHT_PHYSICAL;
        role->baseProperty->rootbone =POINT_OF_KNIGHT_ROOTBONE;
        role->baseProperty->spirit     =POINT_OF_KNIGHT_SPIRIT;
        role->baseProperty->agility   =POINT_OF_KNIGHT_AGILITY;

        role->extendProperty->magicOfAttack = \
            BASE_EXTEND_TRANSITION_KNIGHT_MATTACK(role->baseProperty->brains);
        role->extendProperty->physicsOfAttack=\
            BASE_EXTEND_TRANSITION_KNIGHT_PATTACK(role->baseProperty->physical);
        role->extendProperty->magicOfDefense=\
            BASE_EXTEND_TRANSITION_KNIGHT_MDEFENSE(role->baseProperty->brains);
        role->extendProperty->physicsOfDefense=\
            BASE_EXTEND_TRANSITION_KNIGHT_PDEFENSE(role->baseProperty->physical);
        role->extendProperty->agility=\
            BASE_EXTEND_TRANSITION_KNIGHT_AGILITY(role->baseProperty->agility);
        role->extendProperty->allOfBlood=\
            BASE_EXTEND_TRANSITION_KNIGHT_ALLBLOOD(role->baseProperty->rootbone);
        role->extendProperty->allOfMagic=\
            BASE_EXTEND_TRANSITION_KNIGHT_ALLMAGIC(role->baseProperty->spirit);
        role->extendProperty->deadly=\
            BASE_EXTEND_TRANSITION_KNIGHT_DEADLY(role->baseProperty->allocatable);
            
        i=9;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=10;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=11;
       RL_Register_Into_InitOfSkill(newskill,i);
        
    }
    else if(EProfession_Warrior == role->profession)
    {
        role->baseProperty->brains =POINT_OF_WARRIOR_BRAINS;
        role->baseProperty->physical =POINT_OF_WARRIOR_PHYSICAL;
        role->baseProperty->rootbone =POINT_OF_WARRIOR_ROOTBONE;
        role->baseProperty->spirit     =POINT_OF_WARRIOR_SPIRIT;
        role->baseProperty->agility   =POINT_OF_WARRIOR_AGILITY;

        role->extendProperty->magicOfAttack = \
            BASE_EXTEND_TRANSITION_WARRIOR_MATTACK(role->baseProperty->brains);
        role->extendProperty->physicsOfAttack=\
            BASE_EXTEND_TRANSITION_WARRIOR_PATTACK(role->baseProperty->physical);
        role->extendProperty->magicOfDefense=\
            BASE_EXTEND_TRANSITION_WARRIOR_MDEFENSE(role->baseProperty->brains);
        role->extendProperty->physicsOfDefense=\
            BASE_EXTEND_TRANSITION_WARRIOR_PDEFENSE(role->baseProperty->physical);
        role->extendProperty->agility=\
            BASE_EXTEND_TRANSITION_WARRIOR_AGILITY(role->baseProperty->agility);
        role->extendProperty->allOfBlood=\
            BASE_EXTEND_TRANSITION_WARRIOR_ALLBLOOD(role->baseProperty->rootbone);
        role->extendProperty->allOfMagic=\
            BASE_EXTEND_TRANSITION_WARRIOR_ALLMAGIC(role->baseProperty->spirit);
        role->extendProperty->deadly=\
            BASE_EXTEND_TRANSITION_WARRIOR_DEADLY(role->baseProperty->allocatable);
        
        i=12;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=13;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=14;
        RL_Register_Into_InitOfSkill(newskill,i);

        
    }
    else
    {
        role->baseProperty->brains =POINT_OF_SHOOTER_BRAINS;
        role->baseProperty->physical =POINT_OF_SHOOTER_PHYSICAL;
        role->baseProperty->rootbone =POINT_OF_SHOOTER_ROOTBONE;
        role->baseProperty->spirit      =POINT_OF_SHOOTER_SPIRIT;
        role->baseProperty->agility     =POINT_OF_SHOOTER_AGILITY;

        role->extendProperty->magicOfAttack = \
            BASE_EXTEND_TRANSITION_SHOOTER_MATTACK(role->baseProperty->brains);
        role->extendProperty->physicsOfAttack=\
            BASE_EXTEND_TRANSITION_SHOOTER_PATTACK(role->baseProperty->physical);
        role->extendProperty->magicOfDefense=\
            BASE_EXTEND_TRANSITION_SHOOTER_MDEFENSE(role->baseProperty->brains);
        role->extendProperty->physicsOfDefense=\
            BASE_EXTEND_TRANSITION_SHOOTER_PDEFENSE(role->baseProperty->physical);
        role->extendProperty->agility=\
            BASE_EXTEND_TRANSITION_SHOOTER_AGILITY(role->baseProperty->agility);
        role->extendProperty->allOfBlood=\
            BASE_EXTEND_TRANSITION_SHOOTER_ALLBLOOD(role->baseProperty->rootbone);
        role->extendProperty->allOfMagic=\
            BASE_EXTEND_TRANSITION_SHOOTER_ALLMAGIC(role->baseProperty->spirit);
        role->extendProperty->deadly=\
            BASE_EXTEND_TRANSITION_SHOOTER_DEADLY(role->baseProperty->allocatable);
        
        i=15;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=16;
        RL_Register_Into_InitOfSkill(newskill,i);
        
        newskill++;
        i=17;
        RL_Register_Into_InitOfSkill(newskill,i);
        
    }

    File_SaveOfRole(role);

#if 0
        printf("role->->magicOfAttack is %d\n",role->extendProperty->magicOfAttack);
        printf("role->timeOfCooling is %d\n",role->skill[5].timeOfCooling);
        printf("role->result is %d\n",role->skill[5].result);
#endif


    
}

void RL_Logon_Into(PSRole role)
{
    File_ReadOfRole(role);
}


void RL_DelRole_Into(PSRole role)
{
    File_DelOfRole(role);
}


PSRole RegisterOrLogon_Into()
{
    int i                                                  =0;
    PSRole newRole                                = NULL;
    PSBaseProperty newBaseProperty       =NULL;
    PSExtendProperty newExtendProperty =NULL;    
    PSEquip newEquip                              = NULL;
    PSSkill newSkill                                   = NULL;
    PSPacksackHead newPacksackHead      =NULL;
    PSPacksackOfAll newPacksackOfAll        = NULL;
    PSPacksackOfEquip newPacksackOfEquip  =NULL;
    PSEquipOfKey_All newEquipOfKey_All      =NULL;
    
    newRole = (PSRole)malloc(sizeof(SRole));
    if(NULL ==newRole)
    {
        printf("error !!!,newRole malloc no success!!!!\n");
        goto end1;
    }
    memset(newRole,0,sizeof(SRole));
    
    newBaseProperty =(PSBaseProperty)malloc(sizeof(SBaseProperty));
    if(NULL == newBaseProperty)
    {
        printf("error !!!,newBaseProperty malloc no success!!!!\n");
        goto end2;
    }
    memset(newBaseProperty,0,sizeof(SBaseProperty));
    newRole->baseProperty = newBaseProperty;

    newExtendProperty=(PSExtendProperty)malloc(sizeof(SExtendProperty));
    if(NULL == newExtendProperty)
    {
        printf("error !!!,newExtendProperty malloc no success!!!!\n");
        goto end3;
    }
    memset(newExtendProperty,0,sizeof(SExtendProperty));
    newRole->extendProperty = newExtendProperty;
    
    newEquip= (PSEquip)malloc(sizeof(SEquip)*SUM_OF_EQUIP);
    if(NULL == newEquip)
    {
        printf("error !!!,newEquip malloc no success!!!!\n");
        goto end4;
    }
    memset(newEquip,0,(sizeof(SEquip)*SUM_OF_EQUIP));
    newRole->equip= newEquip;

    newSkill =(PSSkill)malloc(sizeof(SSkill)*SUM_OF_SKILL);
    if(NULL == newSkill)
    {
        printf("error !!!,newSkill malloc no success!!!!\n");
        goto end5;
    }
    memset(newSkill,0,(sizeof(SSkill)*SUM_OF_SKILL));
    newRole->skill=newSkill;

    newPacksackHead =(PSPacksackHead)malloc(sizeof(SPacksackHead));
    if(NULL == newPacksackHead)
    {
        printf("error !!!,newPacksackHead malloc no success!!!!\n");
        goto end6;
    }
    memset(newPacksackHead,0,sizeof(SPacksackHead));
    newRole->packsackHead = newPacksackHead;

    newPacksackOfAll = (PSPacksackOfAll)malloc(sizeof(SPacksackOfAll));
    if(NULL == newPacksackOfAll)
    {
        printf("error !!!,newPacksackOfAll malloc no success!!!!\n");
        goto end7;
    }
    memset(newPacksackOfAll,0,sizeof(SPacksackHead));   
    newPacksackHead->emptyPacksack =(PSPacksackOfEquip)newPacksackOfAll;
    newPacksackHead->packsack = newPacksackOfAll;
    newPacksackOfEquip = (PSPacksackOfEquip)newPacksackOfAll;
    for(i=1;i<SUM_OF_PACKSACK;i++)
    {
        newPacksackOfEquip->next = 1+newPacksackOfEquip;
        newPacksackOfEquip++;
    }
    
    newEquipOfKey_All = (PSEquipOfKey_All)malloc(sizeof(SEquipOfKey_All));
    if(NULL == newEquipOfKey_All)
    {
        printf("error !!!,newEquipOfKey_All malloc no success!!!!\n");
        goto end8;
    }
    memset(newEquipOfKey_All,0,sizeof(SEquipOfKey_All));
    newPacksackHead->packsackkey =newEquipOfKey_All;

    //选择注册还是登陆

    char a= 0;
    a=getchar();
    getchar();
    if('a' ==a)
    {
        RL_Register_Into(newRole);
    }
    else if('b' == a)
    {
        RL_Logon_Into(newRole);
    }
    else if('c' == a)
    {
        RL_DelRole_Into(newRole);
    }
    else
    {
        RegisterOrLogon_Close(newRole);
        newRole =NULL;
    }
    return newRole;
    
end9:
    free(newEquipOfKey_All);    
end8:
    free(newPacksackOfAll);
end7:
    free(newPacksackHead);
end6:
    free(newSkill);
end5:
    free(newEquip);
end4:
    free(newExtendProperty);
end3:
    free(newBaseProperty);
end2:
    free(newRole);
end1:
    exit(-1);
}

main()
{
    PSRole role;
    role = RegisterOrLogon_Into();
    MainUI_Open(role);
}

