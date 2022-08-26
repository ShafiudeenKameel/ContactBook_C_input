#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct contact
{
    long ph;
    char name[20],add[20],email[30];
} list;
char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l,found;
int main()
{
main:
    system("cls");  
    printf("\n\t ** Welcome to Personal Contact Console Application **");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] Edit a Contact\n\t\t[3] View Contact\n\t\t[4] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 0:
        printf("\n\n\t\tAre you sure you want to exit?");
        break;
    /*adding new contacts*/
    case 1:
        system("cls");
        fp=fopen("MyContactInfo.txt","a");
        for (;;)
        {
            fflush(stdin);
            printf("To exit enter blank space in the name input\nName:");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone:");
            scanf("%ld",&list.ph);
            fflush(stdin);
            printf("address:");
            scanf("%[^\n]",&list.add);
            fflush(stdin);
            printf("email address:");
            gets(list.email);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;		
		case 2:
        system("cls");
        fp=fopen("MyContactInfo.txt","r");
        ft=fopen("temp.txt","w");
        fflush(stdin);
        printf("Edit contact\n===============================\n\n\tEnter the name of contact to edit:");
        scanf("%[^\n]",name);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }
        fflush(stdin);
        printf("\n\nEditing '%s'\n\n",name);
        printf("Name:");
        scanf("%[^\n]",&list.name);
        fflush(stdin);
        printf("Phone:");
        scanf("%ld",&list.ph);
        fflush(stdin);
        printf("address:");
        scanf("%[^\n]",&list.add);
        fflush(stdin);
        printf("email address:");
        gets(list.email);
        printf("\n");
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("MyContactInfo.txt");
        rename("temp.txt","MyContactInfo.txt");
        break;
    case 3:
        system("cls");
        do
        {
            found=0;
            printf("\n\n\tCONTACT View\n\t===========================\n\tName of contact to view: ");
            fflush(stdin);
            scanf("%[^\n]",&query);
            l=strlen(query);
            fp=fopen("MyContactInfo.txt","r");
            system("cls");
            printf("\n\nView result for '%s' \n===================================================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    name[i]=list.name[i];
                name[l]='\0';
                if(stricmp(name,query)==0)
                {
                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",list.name,list.ph,list.add,list.email);
                    found++;                   
                }
            }
            if(found==0)
                printf("\nNo match found!");
            else
                printf("\n%d match(s) found!",found);
            fclose(fp);
            printf("\n Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
            scanf("%d",&ch);
        }
        while(ch==1);
        break;    
        /* ********************delete contacts**********************/
    case 4:
        system("cls");
        fflush(stdin);
        printf("\n\n\tDELETE A CONTACT\n\t==========================\n\tEnter the name of contact to delete:");
        scanf("%[^\n]",&name);
        fp=fopen("MyContactInfo.txt","r");
        ft=fopen("temp.txt","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if (stricmp(name,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("MyContactInfo.txt");
        rename("temp.txt","MyContactInfo.txt");
        break;
	default:
        printf("Invalid choice");
        break;
    }
    printf("\n\n\nEnter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;
    }
	
    return 0;
}
