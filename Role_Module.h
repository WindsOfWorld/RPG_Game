#ifndef _ROLE_MODULE_H_
#define _ROLE_MODULE_H_

#define SUM_OF_SKILL 6
#define SUM_OF_EQUIP 7
#define SUM_OF_PACKSACK 100
#define LENGTH_MAX_OF_NAME 16
#define SUM_OF_PROPERTY_EQUIP 8

typedef char i8;
typedef unsigned char u8;

typedef short i16;
typedef unsigned short u16;

typedef int i32;
typedef unsigned int u32;


typedef enum EBool
{
    EBool_no =0,
    EBool_yes,
}EBool;

typedef enum EResultOfSkill
{
    EResultOfSkill_no = 0,      
    EResultOfSkill_addAttack,       /*加攻击的效果*/
    EResultOfSkill_addDefense,    /*加防御的效果*/
    EResultOfSkill_addBlood,        /*加血的效果*/
    EResultOfSkill_addMagic,        /*加蓝效果*/
    EResultOfSkill_subDefense,     /*减防御的效果*/ 
    EResultOfSkill_faint,               /*眩晕的效果*/
    EResultOfSkill_chaos,             /*混乱的效果*/
    EResultOfSkill_thump,            /*下一次必定暴击的效果*/
    EResultOfSkill_again,              /*死而复生的效果*/
}EResultOfSkill;                    /*技能附带的效果*/

typedef struct SSkill
{
    u8 level;                               /*技能的等级*/
    u8 timeOfSurplse;                 /*技能剩余冷却时间*/
    u8 timeOfCooling;                 /*技能冷却时间*/
    u8 timeOfContinue;               /*技能持续时间*/
    i16 expendOfMagic;              /*技能消耗的蓝*/
    i16 Attack;                            /*伤害加成*/
    EBool skillBool;                       /*技能状态*/
    EResultOfSkill result;              /*技能附带的效果*/
}SSkill,*PSSkill;                   /*技能*/


typedef enum EProfession
{
    EProfession_no =0,
    EProfession_Doctor,     /* 医生*/
    EProfession_Master,     /* 法师*/
    EProfession_Knight,      /*骑士 */
    EProfession_Warrior,    /*战士 */
    EProfession_Shooter,    /*弓箭手 */
}EProfession;   /*职业 */


typedef struct SBaseProperty
{
    i16 brains;     /*智力*/
    i16 physical;   /*力量*/
    i16 rootbone;   /* 根骨*/
    i16 spirit;           /*体力 */
    i16 agility;         /*敏捷 */
    i16 allocatable;/*可分配 */
}SBaseProperty,*PSBaseProperty; /* 基础属性*/

typedef struct SExtendProperty
{
    i16 magicOfAttack;/*法术攻击 */
    i16 physicsOfAttack;/* 物理攻击*/
    i16 magicOfDefense;/* 法术防御*/
    i16 physicsOfDefense;/*物理防御 */
    i16 agility;                    /* 敏捷*/
    i16 allOfBlood;             /*总血量 */
    i16 surplusOfBlood;     /*剩余血量 */
    i16 allOfMagic;             /*总魔法值*/
    i16 surplusOfMagic;     /*剩余魔法值 */
    i16 deadly;                 /*致命 */
}SExtendProperty,*PSExtendProperty; /* 扩展属性*/


typedef enum EPropertyOfEquip  /*装备属性*/
{
    EPropertyOfEquip_no = -1,
    EPropertyOfEquip_brains_14 = 0,
    EPropertyOfEquip_brains_15,
    EPropertyOfEquip_brains_16,
    EPropertyOfEquip_brains_17,
    EPropertyOfEquip_brains_18,
    EPropertyOfEquip_brains_19,
    EPropertyOfEquip_brains_20,
    EPropertyOfEquip_brains_21,
    EPropertyOfEquip_brains_22,
    EPropertyOfEquip_brains_23,
    EPropertyOfEquip_physical_14,
    EPropertyOfEquip_physical_15,
    EPropertyOfEquip_physical_16,
    EPropertyOfEquip_physical_17,
    EPropertyOfEquip_physical_18,
    EPropertyOfEquip_physical_19,
    EPropertyOfEquip_physical_20,
    EPropertyOfEquip_physical_21,
    EPropertyOfEquip_physical_22,
    EPropertyOfEquip_physical_23,
    EPropertyOfEquip_rootbone_14,
    EPropertyOfEquip_rootbone_15,
    EPropertyOfEquip_rootbone_16,
    EPropertyOfEquip_rootbone_17,
    EPropertyOfEquip_rootbone_18,
    EPropertyOfEquip_rootbone_19,
    EPropertyOfEquip_rootbone_20,
    EPropertyOfEquip_rootbone_21,
    EPropertyOfEquip_rootbone_22,
    EPropertyOfEquip_rootbone_23,
    EPropertyOfEquip_spirit_14,
    EPropertyOfEquip_spirit_15,
    EPropertyOfEquip_spirit_16,
    EPropertyOfEquip_spirit_17,
    EPropertyOfEquip_spirit_18,
    EPropertyOfEquip_spirit_19,
    EPropertyOfEquip_spirit_20,
    EPropertyOfEquip_spirit_21,
    EPropertyOfEquip_spirit_22,
    EPropertyOfEquip_spirit_23,
    EPropertyOfEquip_agility_14,
    EPropertyOfEquip_agility_15,
    EPropertyOfEquip_agility_16,
    EPropertyOfEquip_agility_17,
    EPropertyOfEquip_agility_18,
    EPropertyOfEquip_agility_19,
    EPropertyOfEquip_agility_20,
    EPropertyOfEquip_agility_21,
    EPropertyOfEquip_agility_22,
    EPropertyOfEquip_agility_23,
    EPropertyOfEquip_magicOfAttack_170,
    EPropertyOfEquip_magicOfAttack_180,
    EPropertyOfEquip_magicOfAttack_190,
    EPropertyOfEquip_magicOfAttack_200,
    EPropertyOfEquip_magicOfAttack_210,
    EPropertyOfEquip_magicOfAttack_220,
    EPropertyOfEquip_magicOfAttack_230,
    EPropertyOfEquip_magicOfAttack_240,
    EPropertyOfEquip_magicOfAttack_250,
    EPropertyOfEquip_magicOfAttack_260,
    EPropertyOfEquip_physicsOfAttack_170,
    EPropertyOfEquip_physicsOfAttack_180,
    EPropertyOfEquip_physicsOfAttack_190,
    EPropertyOfEquip_physicsOfAttack_200,
    EPropertyOfEquip_physicsOfAttack_210,
    EPropertyOfEquip_physicsOfAttack_220,
    EPropertyOfEquip_physicsOfAttack_230,
    EPropertyOfEquip_physicsOfAttack_240,
    EPropertyOfEquip_physicsOfAttack_250,
    EPropertyOfEquip_physicsOfAttack_260,
    EPropertyOfEquip_magicOfDefense_170,
    EPropertyOfEquip_magicOfDefense_180,
    EPropertyOfEquip_magicOfDefense_190,
    EPropertyOfEquip_magicOfDefense_200,
    EPropertyOfEquip_magicOfDefense_210,
    EPropertyOfEquip_magicOfDefense_220,
    EPropertyOfEquip_magicOfDefense_230,
    EPropertyOfEquip_magicOfDefense_240,
    EPropertyOfEquip_magicOfDefense_250,
    EPropertyOfEquip_magicOfDefense_260,
    EPropertyOfEquip_physicsOfDefense_170,
    EPropertyOfEquip_physicsOfDefense_180,
    EPropertyOfEquip_physicsOfDefense_190,
    EPropertyOfEquip_physicsOfDefense_200,
    EPropertyOfEquip_physicsOfDefense_210,
    EPropertyOfEquip_physicsOfDefense_220,
    EPropertyOfEquip_physicsOfDefense_230,
    EPropertyOfEquip_physicsOfDefense_240,
    EPropertyOfEquip_physicsOfDefense_250,
    EPropertyOfEquip_physicsOfDefense_260,
    EPropertyOfEquip_allOfBlood_150,
    EPropertyOfEquip_allOfBlood_160,
    EPropertyOfEquip_allOfBlood_170,
    EPropertyOfEquip_allOfBlood_180,
    EPropertyOfEquip_allOfBlood_190,
    EPropertyOfEquip_allOfBlood_200,
    EPropertyOfEquip_allOfBlood_210,
    EPropertyOfEquip_allOfBlood_220,
    EPropertyOfEquip_allOfBlood_230,
    EPropertyOfEquip_allOfBlood_240,
    EPropertyOfEquip_allOfMagic_60,
    EPropertyOfEquip_allOfMagic_65,
    EPropertyOfEquip_allOfMagic_70,
    EPropertyOfEquip_allOfMagic_75,
    EPropertyOfEquip_allOfMagic_80,
    EPropertyOfEquip_allOfMagic_85,
    EPropertyOfEquip_allOfMagic_90,
    EPropertyOfEquip_allOfMagic_95,
    EPropertyOfEquip_allOfMagic_100,
    EPropertyOfEquip_allOfMagic_105,
    EPropertyOfEquip_deadly_11,
    EPropertyOfEquip_deadly_12,
    EPropertyOfEquip_deadly_13,
    EPropertyOfEquip_deadly_14,
    EPropertyOfEquip_deadly_15,
    EPropertyOfEquip_deadly_16,
    EPropertyOfEquip_deadly_17,
    EPropertyOfEquip_deadly_18,
    EPropertyOfEquip_deadly_19,
    EPropertyOfEquip_deadly_20 ,
}EPropertyOfEquip;

typedef struct SEquip
{
    u8 part_ID;              /*不同的ID 对应不同的部件，相同的ID
                                        是同一部件 */
    u8 level;                   /*装备等级*/
    u16 base;                 /*装备基础属性=N*level*/
    u32 money;              /*卖的钱*/
    EPropertyOfEquip propertyOfEquip[SUM_OF_PROPERTY_EQUIP];  /*属性组*/
}SEquip,*PSEquip;

typedef struct SPacksackOfEquip
{
    SEquip equip;
    struct SPacksackOfEquip * next;
}SPacksackOfEquip,*PSPacksackOfEquip;/*装备包裹每个单位*/

typedef struct SPacksackOfAll
{
    SPacksackOfEquip packsack[SUM_OF_PACKSACK];
}SPacksackOfAll,*PSPacksackOfAll;/*整个包裹能放100个装备*/

typedef struct SEquipOfKey
{
    PSPacksackOfEquip next;
}SEquipOfKey,*PSEquipOfKey;/*装备的关键码，即ID */

typedef struct SEquipOfKey_All
{
    SEquipOfKey key[SUM_OF_EQUIP];
}SEquipOfKey_All,*PSEquipOfKey_All;/*所有的关键码*/

typedef struct SPacksackHead
{
    u16 renpotion;                              /*红药数目*/
    u16 bluepotion;                             /*蓝药数目*/
    u32 money;                                  /*钱*/
    PSPacksackOfAll  packsack;             /*背包指针*/
    PSPacksackOfEquip emptyPacksack;/*背包中未被占用的空间*/
    PSEquipOfKey_All packsackkey;       /*关键码指针*/
}SPacksackHead,*PSPacksackHead;/*背包*/

typedef struct SRole
{
    i8 name[LENGTH_MAX_OF_NAME];    /*人物角色名*/
    u16 level;                                      /*人物等级*/
    u16 floor;                                      /*人物通关等级*/
    i32 empiricalOfValue;                   /*人物当前经验*/
    i32 empiricalOfValueOfUpgrade;   /*人物升级所需经验*/
    EProfession profession;                 /*职业*/
    PSBaseProperty baseProperty;       /*基础属性*/
    PSExtendProperty extendProperty; /*扩展属性*/
    PSPacksackHead packsackHead;     /*背包指针*/
    PSSkill skill;                                /*技能*/
    PSEquip equip;                           /*身上穿戴的装备*/
}SRole,*PSRole;





int InsertItemIntoPacksack(PSEquipOfKey  key_all,
                                                  PSPacksackOfEquip * packsack);

int FindAndRemoveItemFromPacksack();





#endif
