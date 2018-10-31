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
    EResultOfSkill_addAttack,       /*�ӹ�����Ч��*/
    EResultOfSkill_addDefense,    /*�ӷ�����Ч��*/
    EResultOfSkill_addBlood,        /*��Ѫ��Ч��*/
    EResultOfSkill_addMagic,        /*����Ч��*/
    EResultOfSkill_subDefense,     /*��������Ч��*/ 
    EResultOfSkill_faint,               /*ѣ�ε�Ч��*/
    EResultOfSkill_chaos,             /*���ҵ�Ч��*/
    EResultOfSkill_thump,            /*��һ�αض�������Ч��*/
    EResultOfSkill_again,              /*����������Ч��*/
}EResultOfSkill;                    /*���ܸ�����Ч��*/

typedef struct SSkill
{
    u8 level;                               /*���ܵĵȼ�*/
    u8 timeOfSurplse;                 /*����ʣ����ȴʱ��*/
    u8 timeOfCooling;                 /*������ȴʱ��*/
    u8 timeOfContinue;               /*���ܳ���ʱ��*/
    i16 expendOfMagic;              /*�������ĵ���*/
    i16 Attack;                            /*�˺��ӳ�*/
    EBool skillBool;                       /*����״̬*/
    EResultOfSkill result;              /*���ܸ�����Ч��*/
}SSkill,*PSSkill;                   /*����*/


typedef enum EProfession
{
    EProfession_no =0,
    EProfession_Doctor,     /* ҽ��*/
    EProfession_Master,     /* ��ʦ*/
    EProfession_Knight,      /*��ʿ */
    EProfession_Warrior,    /*սʿ */
    EProfession_Shooter,    /*������ */
}EProfession;   /*ְҵ */


typedef struct SBaseProperty
{
    i16 brains;     /*����*/
    i16 physical;   /*����*/
    i16 rootbone;   /* ����*/
    i16 spirit;           /*���� */
    i16 agility;         /*���� */
    i16 allocatable;/*�ɷ��� */
}SBaseProperty,*PSBaseProperty; /* ��������*/

typedef struct SExtendProperty
{
    i16 magicOfAttack;/*�������� */
    i16 physicsOfAttack;/* ������*/
    i16 magicOfDefense;/* ��������*/
    i16 physicsOfDefense;/*������� */
    i16 agility;                    /* ����*/
    i16 allOfBlood;             /*��Ѫ�� */
    i16 surplusOfBlood;     /*ʣ��Ѫ�� */
    i16 allOfMagic;             /*��ħ��ֵ*/
    i16 surplusOfMagic;     /*ʣ��ħ��ֵ */
    i16 deadly;                 /*���� */
}SExtendProperty,*PSExtendProperty; /* ��չ����*/


typedef enum EPropertyOfEquip  /*װ������*/
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
    u8 part_ID;              /*��ͬ��ID ��Ӧ��ͬ�Ĳ�������ͬ��ID
                                        ��ͬһ���� */
    u8 level;                   /*װ���ȼ�*/
    u16 base;                 /*װ����������=N*level*/
    u32 money;              /*����Ǯ*/
    EPropertyOfEquip propertyOfEquip[SUM_OF_PROPERTY_EQUIP];  /*������*/
}SEquip,*PSEquip;

typedef struct SPacksackOfEquip
{
    SEquip equip;
    struct SPacksackOfEquip * next;
}SPacksackOfEquip,*PSPacksackOfEquip;/*װ������ÿ����λ*/

typedef struct SPacksackOfAll
{
    SPacksackOfEquip packsack[SUM_OF_PACKSACK];
}SPacksackOfAll,*PSPacksackOfAll;/*���������ܷ�100��װ��*/

typedef struct SEquipOfKey
{
    PSPacksackOfEquip next;
}SEquipOfKey,*PSEquipOfKey;/*װ���Ĺؼ��룬��ID */

typedef struct SEquipOfKey_All
{
    SEquipOfKey key[SUM_OF_EQUIP];
}SEquipOfKey_All,*PSEquipOfKey_All;/*���еĹؼ���*/

typedef struct SPacksackHead
{
    u16 renpotion;                              /*��ҩ��Ŀ*/
    u16 bluepotion;                             /*��ҩ��Ŀ*/
    u32 money;                                  /*Ǯ*/
    PSPacksackOfAll  packsack;             /*����ָ��*/
    PSPacksackOfEquip emptyPacksack;/*������δ��ռ�õĿռ�*/
    PSEquipOfKey_All packsackkey;       /*�ؼ���ָ��*/
}SPacksackHead,*PSPacksackHead;/*����*/

typedef struct SRole
{
    i8 name[LENGTH_MAX_OF_NAME];    /*�����ɫ��*/
    u16 level;                                      /*����ȼ�*/
    u16 floor;                                      /*����ͨ�صȼ�*/
    i32 empiricalOfValue;                   /*���ﵱǰ����*/
    i32 empiricalOfValueOfUpgrade;   /*�����������辭��*/
    EProfession profession;                 /*ְҵ*/
    PSBaseProperty baseProperty;       /*��������*/
    PSExtendProperty extendProperty; /*��չ����*/
    PSPacksackHead packsackHead;     /*����ָ��*/
    PSSkill skill;                                /*����*/
    PSEquip equip;                           /*���ϴ�����װ��*/
}SRole,*PSRole;





int InsertItemIntoPacksack(PSEquipOfKey  key_all,
                                                  PSPacksackOfEquip * packsack);

int FindAndRemoveItemFromPacksack();





#endif
