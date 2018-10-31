#include <stdio.h>

#include "Role_Module.h"

const SSkill skills[18]   ={{0,0,1,1, 0,1,1,0},/*ÆÕÍ¨¹¥»÷*/
                                    {0,0,4,1, 0,0,1,0},/*³ÔºìÒ©*/
                                    {0,0,4,1, 0,0,1,0},/*³ÔÀ¶Ò©*/
                                    {0,0,3,1,20,0,1,3},/*»ØÑª*/
                                    {0,0,3,1,20,0,1,4},/*»ØÀ¶*/
                                    {0,0,9,4,20,0,1,9},/*ËÀ¶ø¸´Éú*/
                                    {0,0,2,1,20,2,1,0},/*»ðÇòÊõ*/
                                    {0,0,3,1,20,0,1,0},/*»¤¶Ü*/
                                    {0,0,5,3,20,1,1,5},/*ÆÆ¼×*/
                                    {0,0,4,2,20,0,1,6},/*Ñ£ÔÎ*/
                                    {0,0,4,2,20,0,1,7},/*»ìÂÒ*/
                                    {0,0,1,1,20,2,1,0},/*ÖØ»÷*/
                                    {0,0,0,0,20,0,1,0},/*ÑªÁ¿ÌáÉý*/
                                    {0,0,3,2,20,0,1,2},/*Ôö¼Ó·ÀÓù*/
                                    {0,0,1,1,20,2,1,0},/*ÖØ»÷*/
                                    {0,0,3,2,20,0,1,1},/*¼Ó¹¥»÷*/
                                    {0,0,5,2,20,0,1,8},/*ÏÂÒ»´Î±Ø¶¨±©»÷*/
                                    {0,0,3,1,20,2,1,0}};/*ÖØ»÷*/

                                    
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


