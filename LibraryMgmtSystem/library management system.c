#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define IN 1
#define OUT 0

void Addbook();
void Searchbook();
void Displaybook();
void Author();
void Titlelist();
void Stock();
void Issue();
void bookret();
void Addmembr();
void Exit();

char info[500];

struct
{
  int bid;
  char bname[25] ;
  char author[25];
  int nooftitles;
  char titles[500];
  int status;
}book;
struct
{
  int mid;
  char mname[25] ;
  char department[25];
  int availibcard;
  int phno;

}membr;

//initializing the files used in the program

FILE *librecord;
FILE *membrrecord;
FILE *fp1;
FILE *fp2;
FILE *temp1;
FILE *temp2;
int main()
{
    int choice=0,i;

    printf("\n\t\t---Library Management System by Asif Ahmed Neloy---\n");
    do{
    printf("\n\t--MENU--\n \n 1. Add A New Book\n 2. Search a book \n 3. Display Complete Information\n 4. Display All Books of An Author\n 5. List Titles of a Book\n 6. List Count of Books (Issued & On Stock)\n 7. To Issue a Book \n 8. To Return a Book \n 9. Add A New Member\n 10.Exit the program\n\n\t Enter your choice <1-10>: ");
    scanf("%i",&choice);

    switch (choice)
    {
        case 1:
            Addbook();
            break;
        case 2:
            Searchbook();
            break;
        case 3:
            Displaybook();
            break;
        case 4:
            Author();
            break;
        case 5:
            Titlelist();
            break;
        case 6:
            Stock();
            break;
        case 7:
            Issue();
            break;
        case 8:
            bookret();
            break;
        case 9:
            Addmembr();
            break;
        case 10:
            Exit();
        default:
            printf(" ! Invalid Input...\n");
    }
}while(choice!=10);
 return (0);
}

void Addbook()
{
    int i;book.status=IN;
            //opening the librecord file
    librecord = fopen("librecord.txt","a+");
    printf("Enter The number of The Book :(Integer) \n");
        scanf("%d",&book.bid);
    printf("Enter The Name of The Book :\n");
        scanf("%s",book.bname);
    printf("Enter The Name of Author :\n");
        scanf("%s",book.author);
    printf("Enter The Number of Titles Of The Book:(Integer)\n");
        scanf("%d",&book.nooftitles);
    fprintf(librecord,"\n%d\t%s\t%s\t%d\t%d\t",book.bid,book.bname,book.author,book.status,book.nooftitles);
    printf("Enter The Titles Of The Book : \n");
    for(i=0;i<book.nooftitles;i++)
    {
        scanf("%s",book.titles);
        fprintf(librecord,"%s\t",book.titles);
    }
    fclose(librecord);
    printf(" (' ' ) A New Book has been Added Successfully...\n");

}

void Displaybook()
{
    librecord = fopen("librecord.txt","a+");
    printf("\nBookid\tName\tAuthor\tStatus\tNo.\tTitles\n",info);
    do
    {
        fgets(info,500,librecord);
        printf("%s\n",info);
    }while(!feof(librecord));
    fclose(librecord);
    membrrecord = fopen("membrrecord.txt","a+");
    printf("\nMid\tName\tDept\tPh.no\tAvailablecards\n");
    do
    {
        fgets(info,500,membrrecord);
        printf("%s\n",info);
    }while(!feof(membrrecord));
    fclose(membrrecord);

}

void Searchbook()
{
    int i;
    char Target[25],stats[3];
    int Found=0;
    if((librecord=fopen("librecord.txt","r"))==NULL)
        printf(" ! The File is Empty...\n\n");
    else
    {
        printf("\nEnter The Name Of Book : ");
            scanf("%s",Target);
        while(!feof(librecord)&& Found==0)
        {
        fscanf(librecord,"%d %s %s %d %d", &book.bid,book.bname,book.author,&book.status,&book.nooftitles);
            if(strcmp(Target,book.bname)==0)
                Found=1;
            for(i=0;i<book.nooftitles;i++)
                fscanf(librecord,"%s",book.titles);
        }
        if(Found)
        {
            if(book.status==IN)
                strcpy(stats,"IN");
            else
                strcpy(stats,"OUT");

            printf("\nThe Unique ID of The Book:  %d\nThe Name of Book is:  %s\nThe Author is:  %s\nThe Book Status:%s\n\n",book.bid,book.bname,book.author,stats);
            }
        else if(!Found)
            printf("! There is no such Entry...\n");
        fclose(librecord);
    }

}

void Author()
{
    int i;
    char Target[500];
    int Found=0;
    if((librecord=fopen("librecord.txt","r"))==NULL)
    printf(" ! The file is empty... \n\n");
    else
    {
        printf("\nEnter The Name Of Author : ");
            scanf("%s",Target);
        printf("\nBooks:");
        while(!feof(librecord))
        {
            fscanf(librecord,"%d %s %s %d %d",&book.bid,book.bname,book.author,&book.status,&book.nooftitles);
            if(strcmp(Target,book.author)==0)
            {
                Found=1;
                printf("\n\t%s",book.bname);
            }
            for(i=0;i<book.nooftitles;i++)
                fscanf(librecord,"%s",book.titles);
        }
        if(!Found)
            printf(" ! There is no such Entry...\n");
        fclose(librecord);
    }

}
void Titlelist()
{
    int i;
    char Target[500];
    int Found=0;
    if((librecord=fopen("librecord.txt","r"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        printf("\nEnter The Book Name :");
        scanf("%s",Target);
        while(!feof(librecord)&& Found==0)
        {
            fscanf(librecord,"%d %s %s %d %d",&book.bid,book.bname,book.author,&book.status,&book.nooftitles);
            if(strcmp(Target,book.bname)==0)
                {
                    Found=1;
                    break;
                }
            for(i=0;i<book.nooftitles;i++)
                fscanf(librecord,"%s",book.titles);
        }
        if(Found)
        {
            //printf("The Name of book is:               %s\n",book.bname);
            printf("\nThe Titles:\n");
            for(i=0;i<book.nooftitles;i++)
            {
                fscanf(librecord,"%s",book.titles);
                    printf("%d.%s......\n",i+1,book.titles);
            }
        }
        else if(!Found)
            printf(" ! There is no such Entry...\n");
        fclose(librecord);
    }

}
void Stock()
{
    int i,issuecount=0,stockcount=0;
    char Issued[100][20];
    int Found=0;
    if((librecord=fopen("librecord.txt","r"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        while(!feof(librecord))
        {
            fscanf(librecord,"%d %s %s %d %d",&book.bid,book.bname,book.author,&book.status,&book.nooftitles);
            if(book.status==IN)
            {
                stockcount++;
            }
            else
            {
                issuecount++;
            }
            for(i=0;i<book.nooftitles;i++)
                fscanf(librecord,"%s",book.titles);
        }
        fclose(librecord);
    printf("\nCount of issued Books:%d\nCount of Books in Stock:%d\n",issuecount,stockcount-1);
    }

}
void Addmembr()
{
    int i;

    membrrecord = fopen("membrrecord.txt","a+");
    printf("Enter The userid of the Member(Integer) :\n");
        scanf("%d",&membr.mid);
    printf("Enter The Name of the Member :\n");
        scanf("%s",membr.mname);
    printf("Enter The Department\n");
        scanf("%s",membr.department);

    printf("Enter The phone number of the member:\n");
        scanf("%d",&membr.phno);
    membr.availibcard=5;
    fprintf(membrrecord,"\n%d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,    membr.availibcard);
    fclose(membrrecord);
    printf("\n (' ') Added  A New member Successfully...\n");


}
void Issue()
{
    int mid,i,Found1=0,Found2=0;char issubookname[20];
    //temp1=librecord;temp2=membrrecord;
    printf("\nEnter The userid of the Member : \n");
        scanf("%d",&mid);
    if((membrrecord=fopen("membrrecord.txt","r"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        while(!feof(membrrecord)&& Found1==0)
        {
            fscanf(membrrecord,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);
            if(mid==membr.mid)
            {
                Found1=1;
            }
        }
        if(Found1)
        {
            if(membr.availibcard<1)
            {
                printf(" ! Library card not available...\n");
            }
            else
            {    printf("\nEnter The Name of book :");
                scanf("%s",issubookname);
                if((librecord=fopen("librecord.txt","r"))==NULL)
                    printf(" ! The file is empty...\n\n");
                else
                {
                    while(!feof(librecord)&& Found2==0)
                    {
                        fscanf(librecord,"%d %s %s %d %d", &book.bid,book.bname,book.author,&book.status,&book.nooftitles);
                        if(strcmp(issubookname,book.bname)==0)
                            Found2=1;
                        for(i=0;i<book.nooftitles;i++)
                            fscanf(librecord,"%s",book.titles);
                    }
                    if(Found2)
                    {
                        if(book.status==0)
                        {
                            printf(" ! Book already issued...\n");
                        }
                        else
                        {

                            fp2=fopen("fp2.txt","w");
                            if((temp2=fopen("membrrecord.txt","r"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp2))
                                {
                                    fscanf(temp2,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);


                                    if(mid==membr.mid)
                                    {
                                        membr.availibcard--;
                                        fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,    membr.availibcard);
                                    }
                                    else{
                                        fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,membr.availibcard);}
                                    if(feof(temp2))
                                        break;
                                }
                            }
                            fclose(temp2);
                            fclose(fp2);


                            fp1=fopen("fp1.txt","w");
                            if((temp1=fopen("librecord.txt","r"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp1))
                                {
                                      fscanf(temp1,"%d %s %s %d %d", &book.bid,book.bname,book.author,&book.status,&book.nooftitles);
                                    if(feof(temp1))
                                        break;
                                    if(strcmp(issubookname,book.bname)!=0)
                                    {
                                        fprintf(fp1,"\n%d\t%s\t%s\t%d\t%d    \t",book.bid,book.bname,book.author,book.status,book.nooftitles);
                                    }
                                    else
                                    {
                                        fprintf(fp1,"\n%d\t%s\t%s\t%d\t%d\t",book.bid,book.bname,book.author,0,book.nooftitles);
                                    }
                                    for(i=0;i<book.nooftitles;i++)
                                    {
                                        fscanf(temp1,"%s",book.titles);
                                        fprintf(fp1,"%s\t",book.titles);
                                    }
                                }
                            }
                            fclose(temp1);
                            fclose(fp1);
                            fclose(librecord);
                            fclose(membrrecord);
                            remove("librecord.txt");
                            rename("fp1.txt","librecord.txt");
                            remove("membrrecord.txt");
                            rename("fp2.txt","membrrecord.txt");
                            printf(" (' ') Book Successfully issued...\n");
                        }
                    }
                    else if(!Found2)
                        printf(" ! There is no such Book...\n");

                }
            }
        }
        else if(!Found1)
            printf(" ! Invalid User id...\n");


    }

}
void bookret()
{
int mid,i,Found1=0,Found2=0,flag=0;char retbookname[20];
    temp1=librecord;temp2=membrrecord;
    printf("\nEnter The userid of the Member :\n");
        scanf("%d",&mid);
    if((membrrecord=fopen("membrrecord.txt","r"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        while(!feof(membrrecord)&& Found1==0)
        {
            fscanf(membrrecord,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);
            if(mid==membr.mid)
            {
                Found1=1;
            }
        }
        if(Found1)
        {
            if(membr.availibcard>=5)
            {
                printf(" ! Error...\n");
            }
            else
            {    printf("\nEnter The Name of book :");
                scanf("%s",retbookname);
                if((librecord=fopen("librecord.txt","r"))==NULL)
                    printf(" ! The file is empty\n\n");
                else
                {
                    while(!feof(librecord)&& Found2==0)
                    {
                        fscanf(librecord,"%d %s %s %d %d", &book.bid,book.bname,book.author,&book.status,&book.nooftitles);
                        if(strcmp(retbookname,book.bname)==0)
                        Found2=1;
                        for(i=0;i<book.nooftitles;i++)
                            fscanf(librecord,"%s",book.titles);
                    }
                    if(Found2)
                    {
                        if(book.status==1)
                        {
                            printf(" ! Error:Book already in stock...\n");
                        }
                        else
                        {

                            fp2=fopen("fp2.txt","w");
                            if((temp2=fopen("membrrecord.txt","a+"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp2))
                                {
                                    fscanf(temp2,"%d %s %s %d %d ",&membr.mid,membr.mname,membr.department,&membr.phno,&membr.availibcard);


                                    if(mid==membr.mid)
                                    {
                                        membr.availibcard++;
                                        fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,    membr.availibcard);
                                    }
                                    else
                                    {
                                        fprintf(fp2,"\n %d\t%s\t%s\t%d\t%d\t",membr.mid,membr.mname,membr.department,membr.phno,membr.availibcard);
                                    }
                                    if(feof(temp2))
                                        break;
                                }
                            }
                            fclose(temp2);
                            fclose(fp2);


                            fp1=fopen("fp1.txt","w");
                            if((temp1=fopen("librecord.txt","r"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp1))
                                {
                                      fscanf(temp1,"%d %s %s %d %d", &book.bid,book.bname,book.author,&book.status,&book.nooftitles);
                                    if(feof(temp1))
                                        break;
                                    if(strcmp(retbookname,book.bname)!=0)
                                    {
                                        fprintf(fp1,"\n%d\t%s\t%s\t%d\t%d    \t",book.bid,book.bname,book.author,book.status,book.nooftitles);
                                    }
                                    else
                                    {
                                        fprintf(fp1,"\n%d\t%s\t%s\t%d\t%d\t",book.bid,book.bname,book.author,1,book.nooftitles);
                                    }
                                    for(i=0;i<book.nooftitles;i++)
                                    {
                                        fscanf(temp1,"%s",book.titles);
                                        fprintf(fp1,"%s\t",book.titles);
                                    }
                                }
                            }
                            fclose(temp1);
                            fclose(fp1);
                            fclose(librecord);
                            fclose(membrrecord);
                            printf("('') Book Successfully Returned...\n");
                            remove("librecord.txt");
                            rename("fp1.txt","librecord.txt");
                            remove("membrrecord.txt");
                            rename("fp2.txt","membrrecord.txt");

                        }
                    }
                    else if(!Found2)
                        printf("! There is no such Book...\n");

                }
            }
        }
        else if(!Found1)
            printf("! Invalid User id...\n");
    }

}
void Exit()
{
  exit(0);
}
