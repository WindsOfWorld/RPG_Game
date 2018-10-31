#ifndef _BATTLE_MODULE_H_
#define _BATTLE_MODULE_H_

#include "Role_Module.h"

#define BLOOD_ZERO 0
#define SIZE_OF_NAME_LENGTH 20
#define SIZE_OF_MONSTER_BLUE 400
#define SIZE_OF_MONSTER_BLOOD 100
#define SIZE_OF_CHARACTER_BLUE 300
#define SIZE_OF_CHARACTER_BLOOD 100
#define SIZE_OF_CHARACTER_MONEY 200

#define M_SKILL_OF_BLUE_REDUCE 20
#define M_SKILL_OF_BLOOD_REDUCE 20
#define C_SKILL_Z_BLOOD 10
#define C_SKILL_X_BLOOD 30
#define C_SKILL_C_BLUE 20
#define C_SKILL_B_BLOOD 35
#define C_SKILL_V_BLOOD 120


typedef enum EBool1
{
    EBool_None = 0,
    EBool_Win,
    EBool_Lose,
    EBool_Escape,
}EBool1;

typedef enum EBloodFlag
{
    EBloodFlag_No = 0,
    EBloodFlag_Yes,
}EBloodFlag;


typedef enum EIdentity
{
    EIdentity_None = 0,
    EIdentity_Character,
    EIdentity_Monster,
}EIdentity;

/*for play one game,private add some struct*/

typedef struct SMonster
{
    i8 name[SIZE_OF_NAME_LENGTH];
    i16 blood;
    i16 blueblood;
}SMonster;


typedef struct SRole1
{
    i8 name[SIZE_OF_NAME_LENGTH];
    i16 blood;
    u32 money;
    i16 blueblood;
}SRole1;

//void Customas_Close();

//void Battle_Open(void,void);

//void Battle_Initialize_Ui(void,void);

int Battle_Module_main(PSRole role);

EBool1 Battle_Fighting_One_Process(SRole1 *,SMonster*);

void Battle_Judge_Result(EBool1);



#endif

