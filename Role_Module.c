#include <stdio.h>

#include "Role_Module.h"

const SSkill skills[18]   ={{0,0,1,1, 0,1,1,0},/*��ͨ����*/
                                    {0,0,4,1, 0,0,1,0},/*�Ժ�ҩ*/
                                    {0,0,4,1, 0,0,1,0},/*����ҩ*/
                                    {0,0,3,1,20,0,1,3},/*��Ѫ*/
                                    {0,0,3,1,20,0,1,4},/*����*/
                                    {0,0,9,4,20,0,1,9},/*��������*/
                                    {0,0,2,1,20,2,1,0},/*������*/
                                    {0,0,3,1,20,0,1,0},/*����*/
                                    {0,0,5,3,20,1,1,5},/*�Ƽ�*/
                                    {0,0,4,2,20,0,1,6},/*ѣ��*/
                                    {0,0,4,2,20,0,1,7},/*����*/
                                    {0,0,1,1,20,2,1,0},/*�ػ�*/
                                    {0,0,0,0,20,0,1,0},/*Ѫ������*/
                                    {0,0,3,2,20,0,1,2},/*���ӷ���*/
                                    {0,0,1,1,20,2,1,0},/*�ػ�*/
                                    {0,0,3,2,20,0,1,1},/*�ӹ���*/
                                    {0,0,5,2,20,0,1,8},/*��һ�αض�����*/
                                    {0,0,3,1,20,2,1,0}};/*�ػ�*/

                                    
int InsertItemIntoPacksack(PSEquipOfKey  key_all,
                                                  PSPacksackOfEquip *packsack)
{
    int  key =0;
    PSPacksackOfEquip newPacksack =*packsack;
    PSPacksackOfEquip tempPacksack=NULL;
    *packsack = newPacksack->next;
    newPacksack->next =NULL;
    
    key= newPacksack->equip.part_ID;
    key_all = key_all+key;
    

    for(tempPacksack =(PSPacksackOfEquip)(key_all->next);tempPacksack !=NULL;\
        tempPacksack = tempPacksack->next);
    
    tempPacksack = newPacksack;


    return 1;
}

int FindAndRemoveItemFromPacksack()
{
    return 1;
}


