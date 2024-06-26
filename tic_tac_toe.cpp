#include<iostream>
#include <windows.h>
# include <stdlib.h>
using namespace std;
int gameHeader();
void makeBox();
void adddata();
void adddataA(int a , int b);
int  checkWinner();
int rowGrid(char symbol);
int columnGrid(char symbol);
int rightDiagonal(char symbol);
int leftDiagonal(char symbol);
int count =0;
const int value = 3 ; 
char array[value][value] =  {' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' , };
main()
{  system("Color 0A");
 system("CLS");
    while (true)
   {
       
    int option ;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    option = gameHeader();
   for (int i=0;i<3;i++)
   {
       for (int j = 0 ; j<3 ; j++)
       {
       array[i][j] = ' ';
       }
   }
   count =0;
       if (option == 1)
       {
           while(true)
           {
        int result;
        cout<<endl;
        cout<<endl;
         makeBox();
         // adddata();
         int a , b;
   cout<<"enter by the turn O"<<endl;
   cout<<"enter the row index";
   cin>>a;
   cout<<"enter the coloumn index";
   cin>>b; 
   count ++;
    adddataA(a,b);
   makeBox();
    if (rowGrid('o') ||  columnGrid('o') || rightDiagonal('o') || leftDiagonal('o'))
  {
      cout<<endl;
      cout<<endl;
      cout<<"player 1 who enter 'o' in table is the winner  "<<endl;
      // return 1;
      break;
  }
  if (count == 5)
  {
      result = checkWinner();
      if (result == 0 )
      {
          cout<<"The Game is Draw"<<endl;
      }
      break;
  }
 
   // checkWinner();
   cout<<"enter by the turn X"<<endl;
   cout<<"enter the row index";
   cin>>a;
   cout<<"enter the coloumn index";
   cin>>b; 
    adddataA(a,b);
   makeBox();
    if (rowGrid('x') ||  columnGrid('x') || rightDiagonal('x') || leftDiagonal('x'))
  {
      cout<<endl;
      cout<<endl;
      cout<<"player 2 who enter 'x' in table is the winner  "<<endl;
      // return 1;
      break;
  }
  
  //  checkWinner();
       /*  result = checkWinner();
         if (result == 0)
         {
             break;
         }*/


       }// end of option while
       }// end of option 1
       else if (option == 2)
       {
          break ; 
       }
   }// end of while loop


    
}
int gameHeader()
{
   cout<<endl;
   cout<<"*********************************************"<<endl;
   cout<<"*********************************************"<<endl;
   cout<<"*********** TIC  -   TAC  -   TOE ***********"<<endl;
   cout<<"*********************************************"<<endl;
   cout<<"*********************************************"<<endl;
   cout<<"1 . Play the tic - tac - toe  game .."<<endl;
   cout<<"2 . Exists the game .."<<endl;
   int option ;
   cout<<"enter the option "<<endl;
   cin>>option;
   return option ;
   cout<<endl;
}

void makeBox()
{    cout<<"        _____________________________________________"<<endl;
  cout<<"       |              |                  |     "<<"      |"<<endl;
    cout<<"       |      "<<array[0][0]<<"       |       "<<array[0][1]<<"          |    "<<array[0][2]<<"      |"<<endl;
    cout<<"       |______________|__________________|___________"<<"|"<<endl;
    cout<<"       |              |                  |     "<<"      |"<<endl;
    cout<<"       |      "<<array[1][0]<<"       |       "<<array[1][1]<<"          |    "<<array[1][2]<<"      |"<<endl;
    cout<<"       |______________|__________________|___________"<<"|"<<endl;
    cout<<"       |              |                  |     "<<"      |"<<endl;
    cout<<"       |      "<<array[2][0]<<"       |       "<<array[2][1]<<"          |    "<<array[2][2]<<"      |"<<endl;
    cout<<"       |______________|__________________|___________|"<<endl;

}

/*void adddata()
{
    int a , b;
    cout<<"enter the indexes of row and coloumn on which you want to store symbols "<<endl;
    for (int i = 0 ; i < 3 ; i++)
    {
   cout<<"enter by the turn O"<<endl;
   cout<<"enter the row index";
   cin>>a;
   cout<<"enter the coloumn index";
   cin>>b; 
   adddataA(a,b);
   makeBox();
   cout<<"enter by the turn X"<<endl;
   cout<<"enter the row index";
   cin>>a;
   cout<<"enter the coloumn index";
   cin>>b; 
   adddataA(a,b);
   makeBox();

    }

}*/
void adddataA(int a , int b)
{
    char symbol;
  cout<<"enter the the symbol  o / x"<<endl;
  cin>>symbol;
  array[a][b] = symbol;
}

int  checkWinner()
{
  if (rowGrid('o') ||  columnGrid('o') || rightDiagonal('o') || leftDiagonal('o'))
  {
      cout<<endl;
      cout<<endl;
      cout<<"player 1 who enter 'o' in table is the winner  "<<endl;
      return 1;
  }
 else if (rowGrid('x') ||  columnGrid('x') || rightDiagonal('x') || leftDiagonal('x'))
  {
      cout<<endl;
      cout<<endl;
      cout<<"player 2 who enter 'x' in table is the winner  "<<endl;
      return 1;
  }
  else 
  {
      return 0;
  }
}
int rowGrid(char symbol)
{
    int count = 0;
    for (int x = 0 ; x < 3 ; x++ )
    {
         count =0;
        for (int y = 0 ; y<3 ; y++)
        {
          if (array[x][y] == symbol) 
          {
          count++; 
          }
        }// end of inner for
    
    if (count == 3)
    {
        return 1;
    }
    else if (count != 3)
    {
        return 0;
    }
    
    } // end of outer for 
}
int columnGrid(char symbol)
{
    int count = 0;
    for (int x = 0 ; x < 3 ; x++ )
    {
        count = 0;
        for (int y = 0 ; y<3 ; y++)
        {
          if (array[y][x] == symbol) 
          count++; 
        }
    
    if (count == 3)
    {
        return 1;
    }
    else if (count != 3)
    {
        return 0;
    }
    }// end of outer for 
} 
int rightDiagonal(char symbol)
{
    int count = 0;
      for (int x = 0 , y = 0 ; x<3 , y<3 ; x++ , y++)
      {
          if (array[x][y] == symbol) 
          count++; 
      }
    
    if (count == 3)
    {
        return 1;
    }
    else if (count != 3)
    {
        return 0;
    }
} 
int leftDiagonal(char symbol)
{
     int count = 0;
      for (int x = 0 , y = 2 ; x<3 , y>=0 ; x++ , y--)
      {
        if (array[x][y] == symbol) 
        count++; 
      }
    
    if (count == 3)
    {
        return 1;
    }
    else if (count != 3)
    {
        return 0;
    }
} 