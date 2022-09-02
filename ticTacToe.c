#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void createMatrix(int arr[][3]);
void printfMatrix(int arr[][3]);
void gameRule();
void FirstInput(int arr[][3]);
void secondInput(int arr[][3]);
void changeValue1(int *p);
void changeValue2(int *q);
int checkWinning(int arr[][3]);
void gameRule1();
void computerTurn(int arr[][3]);
void compValue(int *p);
void evilComputer(int arr[][3]);

//*********Main() Function Start**********//
int main()
{
    int choice;
    int arr[3][3];
    int i=0,j;
    system("cls");
    printf("Enter Your Choice\n");
    printf("1. Want to play with Smart Computer\n");
    printf("2. Want to play with Evil Computer\n");
    printf("3. Want to play with player\\Friends\n");
    printf("4. Exit     ");
    scanf("%d",&choice);
    createMatrix(arr);
   system("cls");
   gameRule();
   //*********Play with Smart computer option 1 start**********//
     if(choice==1)
     {
        int t=0;
        system("cls");
        gameRule1();
        printfMatrix(arr);
        while(1)
        {
           FirstInput(arr);
           if(checkWinning(arr))
           {
            system("cls");
            gameRule1();
            printfMatrix(arr);
            printf("\nPlayer 1 Win !!\n");
            printf("####################################################################\n");
            exit(0);
           }
          else
          {
            computerTurn(arr);
            system("cls");
            gameRule1();
            printfMatrix(arr);
            if(checkWinning(arr))
            {
               gameRule();
               printfMatrix(arr);
               printf("\n Smart Computer Win !!\n");
              printf("####################################################################\n");
            exit(0);
            }
            t++;
            if(t==6)
            break;
          }
        }
        
        
     }
   //*********Play with Smart computer option 1 end**********//

   //*********Play with Evil computer option 2 start**********//
        if(choice==2)
        {
          int x=0;
            system("cls");
            gameRule1();
            printfMatrix(arr);
            while(1)
            {
               FirstInput(arr);
               if(checkWinning(arr))
               {
                 system("cls");
                 gameRule1();
                 printfMatrix(arr);
                  printf("\n Player 1 win !!\n");
                  break;
               }
               else
               {
                 evilComputer(arr);
                 system("cls");
                 gameRule1();
                 printfMatrix(arr);
                 if(checkWinning(arr))
                  {
                    gameRule();
                    printfMatrix(arr);
                    printf("\n Evil Computer Win !!\n");
                    printf("####################################################################\n");
                    exit(0);
                  }
               }
               x++;
               if(x==6)
               break;
            }
            
        }

   //*********Play with Evil computer option 2 end**********//

   //*********Play with player/Friends option 3 start**********//
if(choice==3)
{

   printfMatrix(arr);
   while(1)
   {
    
      FirstInput(arr);
      if(checkWinning(arr))
      {
        system("cls");
        gameRule();
        printfMatrix(arr);
        printf("\nPlayer 1 Win !!\n");
        printf("####################################################################\n");
        break;
      }
      else
      {
        system("cls");
        gameRule();
        printfMatrix(arr);
         i++;
        
      }
        if(i==9)
         {
           printf("Game dram\n");
           break;
         }
      
     
      secondInput(arr);
      if(checkWinning(arr))
      {
         system("cls");
        gameRule();
        printfMatrix(arr);
        printf("\nPlayer 2 Win !!\n");
        printf("####################################################################\n");

        break;
      }
      else
      {
        system("cls");
        gameRule();
        printfMatrix(arr);
         i++;
        
      }
        if(i==9)
         {
           printf("            !!!   Game dram\n  !!!\n");
           printf("####################################################################\n");
           break;
         }
         //lats
   }
  
}
//*********Play with player/Friends option 3 end**********//

//*********Exit option 4 start**********//
if(choice==4)
{
    exit(0);
}
//*********Exit option 4 end**********// 
    return 0;
}

//*********Main() Function End**********//


//*********Play with player/Friends option 3 start**********//

void createMatrix(int arr[][3])
{
    int i,j;
for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            arr[i][j]=3*i+j+1;
        }
    }
}

void printfMatrix(int arr[][3])
{
    int i,j;
 printf("------------\n");
    for(i=0;i<3;i++)
    {
        printf("| ");
        for(j=0;j<3;j++)
        {
            if(arr[i][j]==88)
             printf("%c |",arr[i][j]);
             else
            printf("%d |",arr[i][j]);
        }
        printf("\n");
    }
    printf("------------\n\n");
    printf("####################################################################\n");
}


void gameRule()
{
    printf("############### Tic Tac Toe ###########################\n\n");
    printf("First Player X\n");
    printf("Second Player O\n\n\n");
}

void FirstInput(int arr[][3])
{
    
    
      int n;
    printf("\nPlayer 1, Enter Markng Place : ");
    scanf("%d",&n);
    if(n>=1 && n<=3)
    {
       
        changeValue1(&arr[0][n-1]);
    }
    else if(n>=4 && n<=6)
    {
        
        changeValue1(&arr[1][n-4]);
    }
    else if(n>=7 && n<=9)
    {
        
       changeValue1(&arr[2][n-7]);
    }
   
   
}

void secondInput(int arr[][3])
{
    int n;
     printf("\nPlayer 2, Enter Markng Place : ");
    scanf("%d",&n);
    if(n>=1 && n<=3)
    {
       
        changeValue2(&arr[0][n-1]);
    }
    else if(n>=4 && n<=6)
    {
        
        changeValue2(&arr[1][n-4]);
    }
    else if(n>=7 && n<=9)
    {
        
       changeValue2(&arr[2][n-7]);
    }
}

void changeValue1(int *p)
{
  *p='X';
}

void changeValue2(int *q)
{
    *q=0;
}

int checkWinning(int arr[][3])
{
   if(arr[0][0]==arr[0][1] && arr[0][0]==arr[0][2])
   return 1;
   else if(arr[1][0]==arr[1][1] && arr[1][0]==arr[1][2])
   return 1;
   else if(arr[2][0]==arr[2][1] && arr[2][0]==arr[2][2])
   return 1;
   else if(arr[0][0]==arr[1][0] && arr[0][0]==arr[2][0])
   return 1;
   else if(arr[0][1]==arr[1][1] && arr[0][1]==arr[2][1])
   return 1;
   else if(arr[0][2]==arr[1][2] && arr[0][2]==arr[2][2])
   return 1;
   else if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2])
   return 1;
   else if(arr[2][0]==arr[1][1] && arr[2][0]==arr[0][2])
   return 1;
   else
   return 0;
}

//*********Play with player/Friends option 3 end**********//

//*********Play with smart computer option 1 function definition start**********//
void gameRule1()
{
    printf("############### Tic Tac Toe ###########################\n\n");
     printf("First Player X\n\n");
}

void computerTurn(int arr[][3])
{
   if(arr[0][0]==arr[0][1])
    compValue(&arr[0][2]);

    else if(arr[0][1]==arr[0][2])
    compValue(&arr[0][0]);

    else if(arr[0][0]==arr[0][2])
    compValue(&arr[0][1]);

    else if(arr[1][0]==arr[1][1])
    compValue(&arr[1][2]);

    else if(arr[1][1]==arr[1][2])
    compValue(&arr[1][0]);

    else if(arr[1][0]==arr[1][2])
    compValue(&arr[1][1]);

    else if(arr[2][0]==arr[2][1])
    compValue(&arr[2][2]);

    else if(arr[2][1]==arr[2][2])
    compValue(&arr[2][0]);

    else if(arr[2][0]==arr[2][2])
    compValue(&arr[2][1]);

    else if(arr[0][0]==arr[1][0])
    compValue(&arr[2][0]);

    else if(arr[0][0]==arr[2][0])
    compValue(&arr[1][0]);

    else if(arr[1][0]==arr[2][0])
    compValue(&arr[0][0]);

    else if(arr[0][1]==arr[1][1])
    compValue(&arr[2][1]);

    else if(arr[0][1]==arr[2][1])
    compValue(&arr[1][1]);

    else if(arr[1][1]==arr[2][1])
    compValue(&arr[0][1]);

    else if(arr[0][2]==arr[1][2])
    compValue(&arr[2][2]);

    else if(arr[0][2]==arr[2][2])
    compValue(&arr[1][2]);

    else if(arr[1][2]==arr[2][2])
    compValue(&arr[0][2]);

    else if(arr[0][0]==arr[1][1])
    compValue(&arr[2][2]);

    else if(arr[1][1]==arr[2][2])
    compValue(&arr[0][0]);

    else if(arr[0][0]==arr[2][2])
    compValue(&arr[1][1]);

else if(arr[2][0]==arr[1][1])
    compValue(&arr[0][2]);

    else if(arr[1][1]==arr[0][2])
    compValue(&arr[2][0]);

    else if(arr[2][0]==arr[0][2])
    compValue(&arr[1][1]);

    else{
          int n,l=1,h=9;
          srand(time(NULL));
          n=(rand() % (h-l+1))+l;

          if(n>=1 && n<=3)
           {
             compValue(&arr[0][n-1]);
           }
          else if(n>=4 && n<=6)
          {
            compValue(&arr[1][n-3]);
          }
         else if(n>=7 && n<=9)
         {
            compValue(&arr[2][n-7]);
         } 
        }
}

void compValue(int *p)
{
    *p=0;
}

//*********Play with smart computer option 1 function definition end**********//

//*********Play with Evil computer option 2 function definition Start**********//

void evilComputer(int arr[][3])
{
   if(arr[0][0]==arr[1][0] && arr[1][0]==arr[1][1])
   {
      compValue(&arr[2][0]);
      compValue(&arr[1][2]);
   }

   else if(arr[0][0]==arr[1][0] && arr[0][0]==arr[0][1])
   {
      compValue(&arr[2][0]);
      compValue(&arr[0][2]);
   }

   else if(arr[0][0]==arr[0][1])
    compValue(&arr[0][2]);

    else if(arr[0][1]==arr[0][2])
    compValue(&arr[0][0]);

    else if(arr[0][0]==arr[0][2])
    compValue(&arr[0][1]);

    else if(arr[1][0]==arr[1][1])
    compValue(&arr[1][2]);

    else if(arr[1][1]==arr[1][2])
    compValue(&arr[1][0]);

    else if(arr[1][0]==arr[1][2])
    compValue(&arr[1][1]);

    else if(arr[2][0]==arr[2][1])
    compValue(&arr[2][2]);

    
    else if(arr[2][1]==arr[2][2])
    compValue(&arr[2][0]);

    else if(arr[2][0]==arr[2][2])
    compValue(&arr[2][1]);

    else if(arr[0][0]==arr[1][0])
    compValue(&arr[2][0]);

    else if(arr[0][0]==arr[2][0])
    compValue(&arr[1][0]);

    else if(arr[1][0]==arr[2][0])
    compValue(&arr[0][0]);

    else if(arr[0][1]==arr[1][1])
    compValue(&arr[2][1]);

   else if(arr[0][1]==arr[2][1])
    compValue(&arr[1][1]);

    else if(arr[1][1]==arr[2][1])
    compValue(&arr[0][1]);

    else if(arr[0][2]==arr[1][2])
    compValue(&arr[2][2]);

    else if(arr[0][2]==arr[2][2])
    compValue(&arr[1][2]);

    else if(arr[1][2]==arr[2][2])
    compValue(&arr[0][2]);

    else if(arr[0][0]==arr[1][1])
    compValue(&arr[2][2]);

    else if(arr[1][1]==arr[2][2])
    compValue(&arr[0][0]);

    
    else if(arr[0][0]==arr[2][2])
    compValue(&arr[1][1]);

else if(arr[2][0]==arr[1][1])
    compValue(&arr[0][2]);

    else if(arr[1][1]==arr[0][2])
    compValue(&arr[2][0]);

    else if(arr[2][0]==arr[0][2])
    compValue(&arr[1][1]);

   else{
          int n,l=1,h=9;
          srand(time(NULL));
          n=(rand() % (h-l+1))+l;

          if(n>=1 && n<=3)
           {
             compValue(&arr[0][n-1]);
           }
          else if(n>=4 && n<=6)
          {
            compValue(&arr[1][n-3]);
          }
         else if(n>=7 && n<=9)
         {
            compValue(&arr[2][n-7]);
         } 
        }
}

//*********Play with Evil computer option 2 function definition end**********//