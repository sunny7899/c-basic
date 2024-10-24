#include<stdio.h>
#include<ctype.h>
int main()
{
     int i,n,m;
     char _1=' ',_2=' ',_3=' ',_4=' ',_5=' ',_6=' ',_7=' ',_8=' ',_9=' ';
     char name_1[20];
     char name_2[20];
     printf("Pleayer 1 enter your name : ");     gets(name_1);
     printf("Pleayer 2 enter your name : ");   gets(name_2);
     
     printf("\n");
     printf(" 1 | 2 | 3 \n------------\n");
     printf(" 4 | 5 | 6 \n------------\n");
     printf(" 7 | 8 | 9 \n");
     printf("'X' this symbol for %s\n",name_1);
     printf("'0' this symbol for %s\n",name_2);

     for(i=1;i<=9;i++)
     {
       if(i%2!=0)
       {
          l1:
          printf("\n%s Enter your index : ",name_1);
          scanf("%d",&n);
          switch(n)
          {
            case 1 : if(_1==' ')
                    {
                     _1='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
            case 2 : if(_2==' ')
                    {
                     _2='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
             case 3 : if(_3==' ')
                    {
                     _3='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
             case 4 : if(_4==' ')
                    {
                     _4='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
             case 5 : if(_5==' ')
                    {
                     _5='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
             case 6 : if(_6==' ')
                    {
                     _6='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
             case 7 : if(_7==' ')
                    {
                     _7='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
             case 8 : if(_8==' ')
                    {
                     _8='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }
             case 9 : if(_9==' ')
                    {
                     _1='X';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l1;
                    }          
          }
       }
         else
         {
          l2:
          printf("\n%s Enter your index : ",name_2);
          scanf("%d",&m);
          switch(m)
          {
          
            case 1 : if(_1==' ')
                    {
                     _1='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
            case 2 : if(_2==' ')
                    {
                     _2='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
            case 3 : if(_3==' ')
                    {
                     _3='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
            case 4 : if(_4==' ')
                    {
                     _4='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
            case 5 : if(_5==' ')
                    {
                     _5='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
            case 6 : if(_6==' ')
                    {
                     _6='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
            case 7 : if(_7==' ')
                    {
                     _7='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
            case 8 : if(_8==' ')
                    {
                     _8='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    } 
            case 9 : if(_9==' ')
                    {
                     _9='0';
                     break;
                    }
                    else
                    {
                    	printf("This index have alrady any symbol \nplease try again\n");
                    	goto l2;
                    }
                      
            }
        
      }
     
       printf("\n\n %c | %c | %c \n------------\n",_1,_2,_3);
     printf(" %c | %c | %c \n------------\n",_4,_5,_6);
     printf(" %c | %c | %c \n\n",_7,_8,_9);

     if(_1==_2 && _2==_3 && _3=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }
     else if(_4==_5 && _5==_6 && _6=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }
     else if(_7==_8 && _8==_9 && _9=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }
     else if(_1==_4 && _4==_7 && _7=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }
     else if(_2==_5 && _5==_8 && _8=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }
     else if(_3==_6 && _6==9 && _9=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }
     else if(_1==_5 && _5==_9 && _9=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }
     else if(_3==_5 && _5==_7 && _7=='X')
     {
       printf("%s is win ",name_1);
       return 0;
     }



     if(_1==_2 && _2==_3 && _3=='0')
     {
       printf("%s is win ",name_2);
       return 0;
     }
     else if(_4==_5 && _5==_6 && _6=='0')
     {
       printf("%s is win ",name_2);
       return 0;
     }
     else if(_7==_8 && _8==_9 && _9=='0')
     {
       printf("%s is win ",name_2);
       return 0;
     }
     else if(_1==_4 && _4==_7 && _7=='0')
     {
       printf("%s is win ",name_2);
       return 0;
     }
     else if(_2==_5 && _5==_8 && _8=='0')
     {
       printf("%s is win ",name_2);
       return 0;
     }
     else if(_3==_6 && _6==9 && _9=='0')
     {
       printf("%s is win ",name_2);
       return 0;
     }
     else if(_1==_5 && _5==_9 && _9=='0')
     {
       printf("%s is win ",name_2);
       return 0;
     }
     else if(_3==_5 && _5==_7 && _7=='0')
     {
      printf("%s is win ",name_2);
       return 0;
     }
     
}

  printf("No one win\nPlease play again");
  return 0;

}