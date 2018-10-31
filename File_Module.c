#include <stdio.h>
#include <string.h>

#include "File_Module.h"

static void ChooseRole(PSRole role)
{
    FILE *fp;
    int i =0;

    char name[10][LENGTH_MAX_OF_NAME];
    
    if(NULL ==(fp=fopen("main","rb")))
    {
        printf("Cannot open this file!\n");
        return ;
    }
    
    for(i=0;i<10;i++)
    {
        if(feof(fp))
            break;
        fscanf(fp,"%s\n",name[i]);
        printf("%d : %s\n",i+1,name[i]);
    }
    scanf("%d",&i);
    getchar();
    i--;
    strcpy(role->name,name[i]);
    fclose(fp);
    return ;
    
    
}


void File_DelOfRole(PSRole const role)
{
    ChooseRole(role);
}

void File_ReadOfRole(PSRole const role)
{
    FILE *fp;
    
    int i = 0;
    PSSkill newskill =role->skill;
    PSEquip equip =role->equip;
    PSEquipOfKey key =(PSEquipOfKey) role->packsackHead->packsackkey;
    PSPacksackOfEquip packsack =(PSPacksackOfEquip)role->packsackHead->packsack;
    
    
    //Ñ¡Ôñ½ÇÉ«
    ChooseRole(role);
    
    
    if(NULL ==(fp=fopen(role->name,"rb")))
    {
        printf("Cannot open this file!\n");
        return ;
    }

    for(;;)
    {
        if('\n' == fgetc(fp))
        {
            break;
        }
    }

    fread(&(role->level),sizeof(u16),1,fp);
    fseek(fp,1L,1);
    fread(&(role->floor),sizeof(u16),1,fp);
    fseek(fp,1L,1);
    fread(&(role->empiricalOfValue),sizeof(u32),1,fp);
    fseek(fp,1L,1);
    fread(&(role->empiricalOfValueOfUpgrade),sizeof(u32),1,fp);
    fseek(fp,1L,1);
    fread(&(role->profession),sizeof(EProfession),1,fp);
    fseek(fp,1L,1);
    fread(role->baseProperty,sizeof(SBaseProperty),1,fp);
    fseek(fp,1L,1);
    
    fread(role->extendProperty,sizeof(SExtendProperty),1,fp);
    fseek(fp,1L,1);
    
    for(i=0;i<SUM_OF_SKILL;i++,newskill++)
    {
        fread(newskill,sizeof(SSkill),1,fp);
        fseek(fp,1L,1);
    }

    for(i=0;i<SUM_OF_EQUIP;i++,equip++)
    {
        fread(equip,sizeof(SEquip),1,fp);
        fseek(fp,1L,1);
    }    
    
    for(;;)
    {
        if(feof(fp))
            break;
        fread(&(packsack->equip),sizeof(SEquip),1,fp);
        InsertItemIntoPacksack((PSEquipOfKey)(role->packsackHead->packsackkey),\
                                             &packsack);
    }

        
#if 0
    printf("%d \n",role->baseProperty->brains);
    printf("%d \n",role->baseProperty->physical);
    printf("%d \n",role->baseProperty->rootbone);
    printf("%d \n",role->baseProperty->spirit);
    printf("%d \n",role->baseProperty->agility);
#endif

    fclose(fp);

}
void File_SaveOfRole(const PSRole const role)
{
    int i = 0;
    PSSkill newskill =role->skill;
    PSEquip equip =role->equip;
    PSEquipOfKey key =(PSEquipOfKey) role->packsackHead->packsackkey;
    PSPacksackOfEquip packsack =NULL;
    
    FILE *fp;
    if(NULL ==(fp=fopen(role->name,"w")))
    {
        printf("Cannot open this file!\n");
        return ;
    }

    fprintf(fp,"%s\n",role->name);
    fwrite(&(role->level),sizeof(u16),1,fp);
    fprintf(fp,"\n");
    fwrite(&(role->floor),sizeof(u16),1,fp);
    fprintf(fp,"\n");
    fwrite(&(role->empiricalOfValue),sizeof(u32),1,fp);
    fprintf(fp,"\n");
    fwrite(&(role->empiricalOfValueOfUpgrade),sizeof(u32),1,fp);
    fprintf(fp,"\n");
    fwrite(&(role->profession),sizeof(EProfession),1,fp);
    fprintf(fp,"\n");
    
#if 0
    fprintf(fp,"%d %d %d %d %d %d\n",role->baseProperty->brains,role->baseProperty->physical,\
                                                        role->baseProperty->rootbone,role->baseProperty->spirit,\
                                                        role->baseProperty->agility,role->baseProperty->allocatable);
    fprintf(fp,"%d %d %d %d %d %d %d %d %d %d\n",role->extendProperty->magicOfAttack,\
                                                                              role->extendProperty->physicsOfAttack,\
                                                                              role->extendProperty->magicOfDefense,\
                                                                              role->extendProperty->physicsOfDefense,\
                                                                              role->extendProperty->agility,\
                                                                              role->extendProperty->allOfBlood,\
                                                                              role->extendProperty->allOfBlood,\
                                                                              role->extendProperty->allOfMagic,\
                                                                              role->extendProperty->allOfMagic,\
                                                                              role->extendProperty->deadly);
    for(packsack=(PSPacksackOfEquip)key;packsack != NULL; packsack=packsack->next)
            {
                printf("%x\n",&(packsack->equip));
                fwrite(&(packsack->equip),sizeof(SEquip),1,fp);
                fprintf(fp,"\n");
            }

#endif

    fwrite(role->baseProperty,sizeof(SBaseProperty),1,fp);
    fprintf(fp,"\n");
    fwrite(role->extendProperty,sizeof(SExtendProperty),1,fp);
    fprintf(fp,"\n");
    for(i=0;i<SUM_OF_SKILL;i++,newskill++)
    {
        fwrite(newskill,sizeof(SSkill),1,fp);
        fprintf(fp,"\n");
    }

    for(i=0;i<SUM_OF_EQUIP;i++,equip++)
    {
        fwrite(equip,sizeof(SEquip),1,fp);
        fprintf(fp,"\n");
    }

    for(i=0;i<SUM_OF_EQUIP;i++)
    {
        packsack =(PSPacksackOfEquip)(key[i].next);
        for(;packsack!=NULL;packsack=packsack->next)
        {
            write(packsack->equip,sizeof(SEquip),1,fp);
        }
    }
    fclose(fp);
}


void File_CrestionFileOfRole(const PSRole const role)
{
    FILE *fp;
    
    if(NULL == (fp=fopen("main","ab+")))
    {
        printf("Cannot open this file!\n");
        return ;
    }

    fprintf(fp,"%s\n",role->name);
    
    fclose(fp);


    if(NULL ==(fp=fopen(role->name,"ab+")))
    {
        printf("Cannot open this file!\n");
        return ;
    }

    fclose(fp);
    
}





