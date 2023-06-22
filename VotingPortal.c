#include<stdio.h>
#include <conio.h>
#include<stdio.h>
#include<windows.h>

void voter(void);
void admin(void);
void gotoxy(int x, int y);
int checkAadhar(char * num);
int saveAadhar(char * num1);
int dateCheck(int d,int m,int y);
void votePortal(void);
void votePortal(void);
int filevote(void);
int menuChoice(void);
FILE *file;

int main(){
    int choice;
    gotoxy(55,9);
    printf("WELCOME \n");
    gotoxy(66,9);
    sleep(3);
    L1: system("cls");
    gotoxy(42,10);
    printf("ENTER WHICH SITE YOU WISH TO VISIT");
    gotoxy(50,12);
    printf("VOTER : PRESS 1 \n");
    gotoxy(50,14);
    printf("ADMIN : PRESS 2 \n");
    gotoxy(50,16);
    scanf("%d",&choice);
    if(choice==1)
    {
        system("cls");
        gotoxy(48,16);
        printf(" WELCOME TO THE VOTING PORTAL");
        voter();

    }
    else if(choice==2)
    {
        system("cls");
        gotoxy(48,10);
        printf("WELCOME TO ADMIN PORTAL");
        sleep(3);
        admin();
    }
    else
    {
        system("cls");
        gotoxy(48,16);
        printf("INVALID INPUT \n RE-ENTER YOUR CHOICE ");
        goto L1;
        //clrscr();


    }
}

void voter()
{
    FILE *voting;
    char name[50];
    char gen[2];
    int val,dateReturn;
    char aadhar[20];
    int d,m,y,ckaadhar;

    gotoxy(49,19);
    printf("THE PORTAL IS GETTING READY");
    gotoxy(35,20);
    for(int k=0;k<60;k++)
    {
        usleep(10000);
        printf("_");
    }

    re_enter: system("cls");
    printf("\n");

    gotoxy(40,10);
    printf("Enter your full name: \t");
    scanf("\n");
    gets(name);

    gotoxy(10,12);
    printf("Enter your date of birth in the format(dd/mm/yyyy): \t");
    scanf("%d%d%d",&d,&m,&y);
    dateReturn=dateCheck(d,m,y);
    switch(dateReturn)
    {
        case 1:
                 gotoxy(38,14);
                 printf("THE DATE YOU ENTERED DOES NOT EXIST");
                 gotoxy(40,15);
                 printf(" PLEASE RE-ENTER YOUR DATE OF BIRTH");
                 sleep(3);
                 system("cls");
                 goto re_enter; break;
        case 2:
                  gotoxy(38,14);
                  printf("THE MONTH YOU ENTERED DOES NOT EXIST");
                  gotoxy(40,15);
                  printf(" PLEASE RE-ENTER YOUR DATE OF BIRTH");
                  sleep(3);
                  system("cls");
                  goto re_enter; break;
        case 3:
                  gotoxy(38,14);
                  printf("YOU ARE NOT 18 YEARS OLD AND HENCE NOT ELIGIBLE TO VOTE");
                  gotoxy(40,15);
                  printf(" PLEASE RE-ENTER YOUR DATE OF BIRTH");
                  sleep(3);
                  system("cls");
                  goto re_enter; break;
    }

    gotoxy(38,14);
    printf("Enter your gender(f/m): \t");
    scanf("\n");
    scanf("%[^\n]s",gen);

    gotoxy(36,16);
    printf("Enter your aadhar number: \t");
    scanf("\n");
    scanf("%[^\n]s",aadhar);
    val=checkAadhar(aadhar);
    if(val==0)
    {
        saveAadhar(aadhar);
    }
    else
    {
        gotoxy(12,18);
        printf("AADHAR NUMBER IS NOT 12 DIGITS PLEASE RE--NTER");
        sleep(3);
        goto re_enter;
    }
    if(gen[0]=='f')
    {
            int genCount;
            voting=fopen("genf.txt","r");
            if(voting==NULL)
            {
                printf("cant open the file");
                exit(1);
            }
            fscanf(voting,"%d",&genCount);
            genCount+=1;
            fclose(voting);
            voting=fopen("genf.txt","w");
            fprintf(voting,"%d",genCount);
            fclose(voting);
    }
    else if(gen[0]=='m')
    {
            int genCount;
            voting=fopen("genm.txt","r");
            if(voting==NULL)
            {
                printf("cant open the file");
                exit(1);
            }
            fscanf(voting,"%d",&genCount);
            genCount+=1;
            voting=fopen("genm.txt","w");
            fprintf(voting,"%d",genCount);
            fclose(voting);
    }
    file=fopen("name.txt","ab");
    fprintf(file,"%s\n",name);
    fclose(file);
    system("cls");
    gotoxy(50,10);
    printf("Information is being verified");
    gotoxy(35,12);
    for(int k=0;k<60;k++)
    {
        usleep(10000);
        printf("_");
    }
    system("cls");
    gotoxy(45,14);
    printf("All information sucessfully verified");
    gotoxy(45,16);
    printf("YOU ARE ELIGIBLE TO VOTE");
    sleep(3);
    votePortal();
}


int dateCheck(int d,int m,int y)
{
    if(d<0 || d>31)
         {
             return 1;
         }
        else if(m<0 || m>12)
          {
              return 2;
          }
        else if(y<0 || y>2003)
          {
              return 3;
          }
        else
        {
            return 4;
        }
}


int checkAadhar(char * num)
{
    int length;
    char *adpointer;
    adpointer=num;
    length=strlen(adpointer);
    if(length==12)
    {

        return 0;
    }
    else
    {
        return 1;
    }
}


int saveAadhar(char * num1)
{
    FILE *file;
    char * saveAadhar1;
    saveAadhar1=num1;
    char s_aadhar[15];
    int check;
    file=fopen("aadhar.txt","r");
    while(1)
    {
            if(feof(file))
                    break;
            fscanf(file,"%s",&s_aadhar);
            check=strcmp(s_aadhar,saveAadhar1);
            if(check==0)
            {
                gotoxy(20,19);
                printf("Invalid aadhar no (account used)\n");
                gotoxy(20,20);
                printf("please enter the details from the first\n");
                sleep(3);
                fclose(file);
                voter();
            }
            else
            {
                    file=fopen("aadhar.txt","a");
                    fprintf(file,"\n%s",saveAadhar1);
                    system("cls");
                    gotoxy(40,14);
                    printf("RECORD ADDED SUCCESSFULLY");
                    sleep(2);
                    fclose(file);
                    break;
            }
    }
    fclose(file);
}


void votePortal(void)
{
    char cdName[50];
    int i=0,response;
    system("cls");
    gotoxy(60,10);
    printf("WELCOME TO THE VOTING PORTAL\n\n\n\n");
    FILE *candidate;
    candidate=fopen("candidate_names.txt","r");
    while(1)
    {
        i++;
        if( fgets (cdName, 60, candidate)!=NULL )
        {
        printf("\t\t\t\t\t%d . \t%s \n",i,cdName);
        }
        else
                break;
    }
    response=filevote();
    system("cls");
    switch(response)
    {
        case 1: {
                    gotoxy(45,10);
                    printf("YOU HAVE VOTED FOR THE 1ST CANDIDATE");
                } break;
        case 2: {
                    gotoxy(45,10);
                    printf("YOU HAVE VOTED FOR THE 2Nd CANDIDATE");
                } break;
        case 3: {
                    gotoxy(45,10);
                    printf("YOU HAVE VOTED FOR THE 3RD CANDIDATE");
                } break;
        case 4: {
                    gotoxy(45,10);
                    printf("YOU HAVE VOTED FOR THE 4Th CANDIDATE");
                } break;
    }
    gotoxy(50,20);
    printf("YOUR VOTE HAS BEEN SUCESSFULLY RECORDED");
    gotoxy(60,22);
    printf("THANK YOU FOR VOTING");
    gotoxy(50,40);
}


int filevote()
{
    int vote ;
    //Assume that votes have been got as input as vote
    x: gotoxy(40,22);
    printf("ENTER YOUR CHOICE");
    gotoxy(70,22);
    scanf("%d",&vote);

    int voteount;
    FILE *fp;
    if(vote==1)
    {
        fp=fopen("candidate1.txt","r");
        if(fp==NULL)
        {
            printf("cant open the file");
            exit(1);
        }
        fscanf(fp,"%d",&voteount);
        voteount=voteount+1;
        fp=fopen("candidate1.txt","w");
        fprintf(fp,"%d",voteount);
        fclose(fp);
    }

    else if(vote==2)
    {
        fp=fopen("candidate2.txt","r");
        if(fp==NULL)
        {
            printf("cant open the file");
            exit(1);
        }
        fscanf(fp,"%d",&voteount);
        voteount=voteount+1;
        fp=fopen("candidate2.txt","w");
        fprintf(fp,"%d",voteount);
        fclose(fp);
    }

    else if(vote==3)
    {
        fp=fopen("candidate3.txt","r");
        if(fp==NULL)
        {
            printf("cant open the file");
            exit(1);
        }
        fscanf(fp,"%d",&voteount);
        voteount=voteount+1;
        fp=fopen("candidate3.txt","w");
        fprintf(fp,"%d",voteount);
        fclose(fp);
    }


    else if(vote==4)
    {
        fp=fopen("candidate4.txt","r");
        if(fp==NULL)
        {
            printf("cant open the file");
            exit(1);
        }
        fscanf(fp,"%d",&voteount);
        voteount=voteount+1;
        fp=fopen("candidate4.txt","w");
        fprintf(fp,"%d",voteount);
        fclose(fp);
    }

    else
    {
        gotoxy(50,25);
        printf("INVALID OPTION PLEASE ENTER THE VOTE AGAIN");
        goto x;
    }
}


void admin(void){
    int tries=3;
    FILE *userFile;
    FILE *passFile;
    int flagUser,ck1,ck2,flagRepeat=0;
    char enterUser[20];
    l1 : userFile=fopen("username.txt","r");
    system("cls");

    gotoxy(40,10);
    printf("Enter the Username:");
    scanf("\n");
    gets(enterUser);

    if(userFile==NULL)
    {
        gotoxy(50,11);
        printf("unable to open the file");
    }
    char line[100];
    while(1)
    {
            if(feof(userFile))
                    break;
            fscanf(userFile,"%s",line);
          {
              ck1=strcmp(enterUser,line);
              if(ck1 ==0)
              {
                  flagUser=1;
              }
          }
    }
    int flagPass=0;
    passFile=fopen("password.txt","r");
    char enterPass[20];

    gotoxy(40,12);
    printf("Enter the password:");
    gets(enterPass);
    if(passFile==NULL)
    {
        gotoxy(40,14);
        printf("unable to open the file");
    }
    char lines[100];
    while(1)
    {
            if(feof(passFile))
                    break;
            fscanf(passFile,"%s",lines);
          {
              ck2=strcmp(enterPass,lines);
              if(ck2 ==0)
              {
                  flagPass=1;
              }
          }
    }
    //what to do code
    if(flagPass==1 && flagUser==1)
    {
        gotoxy(45,16);
        printf("LOGIN SUCCESFULL \n");
        flagRepeat=1;
        gotoxy(45,17);
        printf("WELCOME %s ",enterUser);
        sleep(2);
        mainMenu();


    }
    else
    {
        gotoxy(45,18);
        printf("INVALID LOGIN \n");
        gotoxy(42,20);
        printf("YOU HAVE %d TRIES LEFT\n",--tries);
        sleep(3);
    }
    if(flagRepeat==0)
    {
        if(tries==0)
        {
            gotoxy(25,22);
            printf("TOO MANY INVALID LOGINS...PLEASE CONTACT THE ADMINISTRATION");
            sleep(5);
            system("cls");
            exit(1);
        }
        else if(tries>0)
        {
            printf("\n");
            goto l1;
        }
    }
    return 0;
}


void mainMenu(void)
{
        int op;
        system("cls");
        gotoxy(40,10);
        printf(" PRESS 1 TO VIEW THE VOTES \n");
        gotoxy(40,11);
        printf(" PRESS 2 TO VIEW THE TOTAL  VOTES \n");
        gotoxy(40,12);
        printf(" PRESS 3 TO VIEW MALE AND FEMALE VOTES \n");
        gotoxy(40,13);
        printf(" PRESS 4 TO FOR FEEDBACK or COMPLAINT \n");
        gotoxy(40,14);
        printf(" PRESS 5 to EXIT\n ");
        gotoxy(45,18);
        printf("ENTER YOUR CHOICE ");
        gotoxy(65,18);
        scanf("%d",&op);
        usleep(100000);
        menuChoise(op);
}


int menuChoise(int op)
{
    int total;
    char choice;
    int n1,n2,n3,n4,n5;
    system("cls");
    if (op==1)
    {
        FILE *fp;
        fp=fopen("candidate1.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 1");
            exit(0);
        }
        fscanf(fp,"%d",&n1);
        gotoxy(30,8);
        printf(" The total votes for the candidate 1 \t : \t %d",n1);
        fclose(fp);

        fp=fopen("candidate2.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 2");
            exit(0);
        }
        fscanf(fp,"%d",&n2);
        gotoxy(30,9);
        printf(" The total votes for the candidate 2 \t : \t %d",n2);
        fclose(fp);


        fp=fopen("candidate3.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 3");
            exit(0);
        }
        fscanf(fp,"%d",&n3);
        gotoxy(30,10);
        printf(" The total votes for the candidate 3 \t : \t %d",n3);
        fclose(fp);

        fp=fopen("candidate4.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 4");
            exit(0);
        }
        fscanf(fp,"%d",&n4);
        gotoxy(30,11);
        printf(" The total votes for the candidate 4 \t : \t %d",n4);
        fclose(fp);

        fp=fopen("candidate5.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 5");
            exit(0);
        }
        fscanf(fp,"%d",&n5);
        gotoxy(30,12);
        printf(" The total votes for the candidate 5 \t : \t %d",n5);
        fclose(fp);
        sleep(4);
        gotoxy(35,14);
        printf("ENTER B TO GO BACK TO THE MENU");
        gotoxy(35,15);
        printf("ENTER ANY OTHER CHARACTER TO EXIT THE PROGRAM");
        gotoxy(35,16);
        scanf("\n");
        gotoxy(35,17);
        scanf("%c",&choice);
        if(choice=='b' || choice=='B')
        {
            mainMenu();
        }
        else
        {
            exit(0);
        }
    }


    else if(op==2)
    {

        FILE *fp;
        fp=fopen("candidate1.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 1");
        }
        fscanf(fp,"%d",&n1);
        fclose(fp);

        fp=fopen("candidate2.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 2");
        }
        fscanf(fp,"%d",&n2);
        fclose(fp);


        fp=fopen("candidate3.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 3");
        }
        fscanf(fp,"%d",&n3);
        fclose(fp);

        fp=fopen("candidate4.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 4");
        }
        fscanf(fp,"%d",&n4);
        fclose(fp);

        fp=fopen("candidate5.txt","r");
        if (fp==NULL)
        {
            printf ("\nCan't open the file 5");
        }
        fscanf(fp,"%d",&n5);
        fclose(fp);

        total=n1+n2+n3+n4+n5;
        gotoxy(35,10);
        printf("CALCULATING THE TOTAL VOTES");
        gotoxy(25,11);
        for(int k=0;k<60;k++)
        {
            usleep(10000);
            printf("_");
        }
        system("cls");
        gotoxy(35,10);
        printf("TOTAL NO OF CITIZENS WHO VOTED ARE : %d ",total);
        sleep(3);
        gotoxy(35,14);
        printf("ENTER B TO GO BACK TO THE MENU");
        gotoxy(35,15);
        printf("ENTER ANY OTHER CHARACTER TO EXIT THE PROGRAM");
        gotoxy(35,16);
        scanf("\n");
        gotoxy(35,17);
        scanf("%d",&choice);
        if(choice=='b' || choice=='B')
        {
            mainMenu();
        }
        else
        {
            exit(0);
        }

    }
    /*else if(op==3)
    {
        fscanf(fpr,"%d",&mc);

        fscanf(fpr,"%d",&fc);


        printf("the number of female voters are %d",fc);
        printf("the number of male voters are %d",mc);


    }*/

    else if(op==3)
        {
            gender();
        }
    else if(op==4)
        {
            query();
        }
    else if(op==5)
        {
            system("cls");
            gotoxy(50,50);
            exit(1);
        }
}


int gender()
{
    system("cls");
	FILE *fpr1,*fp;
	int gc,mc;
	char choice;
    fpr1=fopen("genm.txt","r");
    if (fpr1==NULL)
	{
        gotoxy(30,10);
        printf ("\nCan't open the file");
        exit(0);
	}
    fscanf(fpr1,"%d",&mc);
    gotoxy(35,10);
	printf("THE TOTAL NO OF MALE VOTES  :%d",mc);
	fp=fopen("genf.txt","r");
    if (fpr1==NULL)
	{
	    gotoxy(30,10);
        printf ("\nCan't open the file");
        exit(0);
	}
	fscanf(fp,"%d",&gc);
	gotoxy(29,11);
	printf("THE TOTAL NUMBER OF FEMALE VOTES  :%d",gc);
	sleep(2);

	gotoxy(35,15);
    printf("ENTER B TO GO BACK TO THE MENU");
    gotoxy(35,16);
    printf("ENTER ANY OTHER CHARACTER TO EXIT THE PROGRAM");
    gotoxy(35,17);
    scanf("\n");
    gotoxy(35,18);
    scanf("%c",&choice);

    if(choice=='b' || choice=='B')
    {
        mainMenu();
    }
    else
    {
        exit(0);
    }

}


void query()
{
    system("cls");
	int qt;
	char choice;
	FILE *fpr1,*fpr2;
	char feedback[100];
	char complain[100];
	gotoxy(45,10);
	printf("1.WRITE FEEDBACK");
	gotoxy(45,11);
	printf("2.COMPLAIN ERRORS");
	gotoxy(45,12);
	scanf("%d",&qt);
	if(qt==1)
	{
	    system("cls");
	    gotoxy(35,10);
	    printf("WELCOME TO THE FEEDBACK FORM");
        fpr1=fopen("feedback.txt","a");
        if (fpr1==NULL)
        {
            system("cls");
            gotoxy(35,11);
            printf ("\nCan't open the file");
            exit(0);
        }
        gotoxy(30,12);
        printf("Enter your feedback ");
        scanf("\n");
        gets(feedback);
        fprintf(fpr1,"\n%s",feedback);
        gotoxy(30,14);
        printf("YOUR FEEDBACK HAS BEEN RECORDED!!");
        fclose(fpr1);


        gotoxy(35,16);
        printf("ENTER B TO GO BACK TO THE MENU");
        gotoxy(35,17);
        printf("ENTER ANY OTHER CHARACTER TO EXIT THE PROGRAM");
        gotoxy(35,18);
        scanf("\n");
        gotoxy(35,19);
        scanf("%c",&choice);

        if(choice=='b' || choice=='B')
        {
            mainMenu();
        }
        else
        {
            exit(0);
        }
	}

    else if(qt==2)
	{
	    system("cls");
	    gotoxy(35,10);
	    printf("WELCOME TO THE COMPLAIN FORM");
        fpr2=fopen("complain.txt","a");
        if (fpr2==NULL)
        {
            system("cls");
            gotoxy(35,11);
            printf ("\nCan't open the file");
            exit(0);
        }
        gotoxy(30,12);
        printf("Enter your complain ");
        scanf("\n");
        gets(complain);
        fprintf(fpr2,"\n%s",complain);
        gotoxy(30,14);
        printf("YOUR COMPLAIN HAS BEEN RECORDED!!");
        fclose(fpr2);


        gotoxy(35,15);
        printf("ENTER B TO GO BACK TO THE MENU");
        gotoxy(35,16);
        printf("ENTER ANY OTHER CHARACTER TO EXIT THE PROGRAM");
        gotoxy(35,17);
        scanf("\n");
        gotoxy(35,18);
        scanf("%c",&choice);

        if(choice=='b' || choice=='B')
        {
            mainMenu();
        }
        else
        {
            exit(0);
        }
	}

}


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
