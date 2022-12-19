#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct contacts
{
    char name[25];
    char fname[25];
    char mname[25];
    char sex[10];
    char address[60];
    char mobileNo[11];
    char email[30];
};
void newcontact()
{
    FILE *fp;
    struct contacts con;
    char a='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(a=='y')
    {

        printf("\n\t\t\t\t************************************************************************************************************");
        printf("\n\t\t\t\t*\t\t<---------------------------:  Add New Contact  :-------------------------->\t\t   *");
        printf("\n\t\t\t\t************************************************************************************************************");

        printf("\n\n\t\t\t\t\t\t\t\tEnter details of Contact.\n");

        printf("\n\t\t\t\t\t\t\t\tEnter Name : ");

        gets(con.name);

        printf("\n\t\t\t\t\t\t\t\tEnter Mobile Number : ");
        gets(con.mobileNo);

        printf("\n\t\t\t\t\t\t\t\tEnter Father name : ");
        gets(con.fname);
        fflush(stdin);

        printf("\n\t\t\t\t\t\t\t\tEnter Mother Name : ");
        gets(con.mname);

        printf("\n\t\t\t\t\t\t\t\tEnter Sex : ");
        gets(con.sex);

        printf("\n\t\t\t\t\t\t\t\tEnter E-mail : ");
        gets(con.email);

        printf("\n\t\t\t\t\t\t\t\tEnter Address : ");
        gets(con.address);
        fflush(stdin);

        fwrite(&con,sizeof(con),1,fp);
        fflush(stdin);
        printf("\n\t\t\t\t\t\t\t\tContact Saved Successfully.\n\n\t\t\t\t\t\t\t\tPress Y to add another contact.\n\n\t\t\t\t\t\t\t\tElse press any key to continue: ");
        a=getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    printf("\n\t\t\t\t\t\t\t\tPress any key to continue.");
    getch();
    menu();
}


void list()
{
    FILE *fp;
    int i=1;
    struct contacts con;
    system("cls");
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  PhoneBook RECORDS  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************");

    printf("\n\n\n\t\tS.No\t\tName\t\tMobileNo\t\tFatherName\t\tMotherName\t\tSex\t\tE-mail\t\t\tAddress");

    printf("\n\t||--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------||");

    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file.");
        exit(1);
    }

    while(fread(&con,sizeof(con),1,fp) == 1){

        printf("\n\n\t\t%d\t       %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s",i,con.name,con.mobileNo,con.fname,con.mname,con.sex,con.email,con.address);
        i++;
    }
    fclose(fp);

    printf("\n\n\n\n\n\tPress any key to continue.");
    getch();
    menu();
}

void modify()
{
    char cname[25];
    FILE *fp;
    struct contacts con;
    system("cls");
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  Modify RECORDS  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************");

    printf("\n\n\t\t\t\t\t\t\tEnter the contact name you want to modify: ");
    fflush(stdin);
    gets(cname);
    fp=fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("\n\n\t\t\t\t\t\t\t\tError in opening the file.");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp)==1)
    {
        if(strcmp(cname,con.name)==0)
        {
           printf("\n\t\t\t\t\t\t\t\tEnter Name : ");

        gets(con.name);

        printf("\n\t\t\t\t\t\t\t\tEnter Mobile Number : ");
        gets(con.mobileNo);

        printf("\n\t\t\t\t\t\t\t\tEnter Father name : ");
        gets(con.fname);
        fflush(stdin);

        printf("\n\t\t\t\t\t\t\t\tEnter Mother Name : ");
        gets(con.mname);

        printf("\n\t\t\t\t\t\t\t\tEnter Sex : ");
        gets(con.sex);

        printf("\n\t\t\t\t\t\t\t\tEnter E-mail : ");
        gets(con.email);
        fflush(stdin);

        printf("\n\t\t\t\t\t\t\t\tEnter Address : ");
        gets(con.address);

        fseek(fp, -sizeof(con),SEEK_CUR);
        fwrite(&con,sizeof(con),1,fp);
        printf("\n\n\t\t\t\t\t\t\t\tContact modified successfully.\n");
        break;
        }


    }
    fclose(fp);
    printf("\t\t\t\t\t\t\t\tEnter any key to continue : ");
    getch();
    menu();
}

void search()
{   system("cls");
    FILE *fp;
    char cname[25];
    struct contacts con;
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  Search Contact  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************\n\n");
    printf("\n\t\t\t\t\t\t\t\tEnter the contact name: ");
    fflush(stdin);
    gets(cname);
    fp=fopen("record.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tError in Opening File.");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp)==1)
    {
        if(strcmp(cname,con.name)==0)
        {
             printf("\n\t\t\t\t\t\t\t\tContact Name : %s",con.name);

        printf("\n\n\t\t\t\t\t\t\t\tMobile Number : %s",con.mobileNo);

        printf("\n\n\t\t\t\t\t\t\t\tFather name : %s",con.fname);

        printf("\n\n\t\t\t\t\t\t\t\tMother Name : %s",con.mname);

        printf("\n\n\t\t\t\t\t\t\t\tSex : %s",con.sex);

        printf("\n\n\t\t\t\t\t\t\t\tE-mail : %s",con.email);

        printf("\n\n\t\t\t\t\t\t\t\tAddress : %s",con.address);
        }

    }
    fclose(fp);
    printf("\n\n\t\t\t\t\t\t\t\tPress any key to continue. ");
    getch();
    menu();
}

void deleter()
{
    system("cls");
    FILE *fp,*f;
    char cname[25];
    struct contacts con;
    printf("\n\t\t\t\t************************************************************************************************************");
    printf("\n\t\t\t\t*\t\t<---------------------------:  Delete Contact  :-------------------------->\t\t   *");
    printf("\n\t\t\t\t************************************************************************************************************\n\n");
    printf("\n\t\t\t\t\t\t\t\tEnter contact name to be deleted: ");
    fflush(stdin);
    gets(cname);
    fp=fopen("record.txt","rb+");
    if(fp==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tError in Opening File.");
        exit(1);
    }
    f=fopen("rec.txt","wb+");
    if(f==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tError in Opening File.");
        exit(1);
    }
    while(fread(&con,sizeof(con),1,fp)==1)
    {
        if(strcmp(cname,con.name)!=0)
        {
            fwrite(&con,sizeof(con),1,f);
        }

    }
    fclose(fp); fclose(f);
    printf("\n\n\t\t\t\t\t\t\t\tContact deleted successfully.\n\n\t\t\t\t\t\t\t\tPress any key to continue.");
    remove("record.txt");
    rename("rec.txt","record.txt");
    getch();
    menu();
}
void menu()
{   system("color 4f");


    system("cls");
    int choice;

    printf("\n\n\n\n\n\n");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t-------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t  *** Welcome to the Phone Book Application ***");
    printf("\n\t\t\t\t\t\t\t\t\t-------------------------------------------------");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t|| MENU ||");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t========================");
    printf("\n\t\t\t\t\t\t\t\t\t\t[1] Add New Contact");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t[2] List of Contacts");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t[3] Modify Contact");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t[4] Search Contact");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t[5] Delete Contact");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t[6] EXIT");
    printf("\n\t\t\t\t\t\t\t\t\t\t========================");
    printf("\n\n\t\t\t\t\t\t\t\t\t\tEnter your Selection: ");
    scanf("%d",&choice);


    switch(choice)
    {
        case 1: newcontact(); break;
        case 2: list(); break;
        case 3: modify(); break;
        case 4: search(); break;
        case 5: deleter(); break;
        case 6: break;
        default: printf("\n\n\n\t\t\t\t\t\t\t\t\tPlease Enter correct selection: "); getch(); menu();
    }
}
int main()
{

    menu();
    return 0;
}

