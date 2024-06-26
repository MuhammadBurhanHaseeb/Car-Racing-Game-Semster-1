// <<<<<<<<<<<<<<<<<<<<<< 2021 - CS - 129  <<<<<< Muhammad Burhan <<<<<<<<<<<<<<
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctime>
#include <sstream>
#include <fstream>
using namespace std;
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> START OF THE FUNCTION PROTOTYPES

void loadTrack();
void printTrack();
int gameHeader();
void moveCarLeft();
void moveCarRight();
void moveCarUp();
void moveCarDown();
void jumpCar();
void EmptyfirstColoum();
void EmptySecondColoum();
void EmptyThirdColoum();
void FillFirstColoum();
void FillSecondColoum();
void FillThirdColoum();
void gotoxy(int x, int y);
void checkcount();

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> END OF THE FUNCTION PROTOTYPES

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> START OF THE DATA STRUCTURES

char track[24][34];

int carLX = 20; // row left
int carMX = 20; // row mid
int carRX = 20; // row right

int carLY = 4;  // coloum left
int carMY = 14; // coloum mid
int carRY = 23; // coloum right

int count = 0; // for left side
int count2 = 0;
//int count1 = 0;
//int count2 = 0 ;
//int count3 = 0;// for right side
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> END  OF THE DATA STRUCTURES
main()
{
    system("CLS");
    loadTrack();

    track[carMX][carMY] = ' ';
        track[carMX][carMY + 1] = '#';

        track[carMX + 1][carMY] = '#';
        track[carMX + 1][carMY + 1] = '#';
        track[carMX + 1][carMY + 2] = '#';

        track[carMX + 2][carMY] = ' ';
        track[carMX + 2][carMY + 1] = '#';

        track[carMX + 3][carMY] = '#';
        track[carMX + 3][carMY + 1] = '#';
        track[carMX + 3][carMY + 2] = '#';

    gotoxy(carMY, carMX);
    cout << " #" << endl;

    gotoxy(carMY, carMX + 1);
    cout << "###" << endl;

    gotoxy(carMY, carMX + 2);
    cout << " #" << endl;

    gotoxy(carMY, carMX + 3);
    cout << "###" << endl;
    system("CLS");

    int option;

    while (true)
    {

        option = gameHeader();

        if (option == 1) // NORMAL GAME
        {
            while (true)
            {
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveCarLeft(); // Function call to move car towards left
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveCarRight(); // Function call to move car towards right
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveCarUp(); // Function call to move car towards up
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveCarDown(); // Function call to move car towards down
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    jumpCar(); // function call to jump thr car
                }
                if (GetAsyncKeyState(VK_END))
                {
                    break; // statement to break the loop
                }
            }
        }

        if (option == 2) // HARD GAME
        {
            while (true)
            {
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveCarLeft(); // Function call to move car towards left
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveCarRight(); // Function call to move car towards right
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    moveCarUp(); // Function call to move car towards up
                }
                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveCarDown(); // Function call to move car towards down
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    jumpCar(); // function call to jump thr car
                }
                if (GetAsyncKeyState(VK_END))
                {
                    break; // statement to break the loop
                }
            }
        }

        if (option == 3) // EXISTS THE GAME
        {
            break;
        }
    }
}
int gameHeader()
{

    cout << "****************************************************" << endl;
    cout << "****************************************************" << endl;
    cout << "****************************************************" << endl;
    cout << "**************** 2D  CAR  RACING  ******************" << endl;
    cout << "****************************************************" << endl;
    cout << "****************************************************" << endl;
    cout << "****************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << ">>>>>>>  LETS PLAY THE GAME <<<<<< " << endl;
    cout << endl;
    cout << ">>> 1. NORMAL GAME <<<" << endl;
    cout << ">>> 2. HARD   GAME <<<" << endl;
    cout << ">>> 3. EXIST <<<" << endl;
    cout << endl;
    cout << "enter the option .." << endl;
    int option;
    cin >> option;
    cout << ">>>> LOADING THE GAME !!  PLEASE WAIT <<<<" << endl;
    cout << endl;
    char b = 177;
    for (int x = 0; x < 1; x++)
    {
        cout << b;
        Sleep(300);
    }
    system("CLS");
    printTrack();
    return option;
}
void loadTrack()
{
    string line;
    fstream f;
    f.open("track.txt", ios ::in);
    for (int x = 0; x < 24; x++)
    {
        getline(f, line);
        for (int y = 0; y < 34; y++)
        {
            track[x][y] = line[y];
        }
    }
    f.close();
}
void printTrack()
{
    for (int x = 0; x < 24; x++)
    {
        for (int y = 0; y < 34; y++)
        {
            cout << track[x][y];
        }
        cout << endl;
    }
}
/*void moveCarLeft()
{
    //cout << count2;
   // getch();
    if (count2 = 0)
    {
        

        gotoxy(carRY, carRX);
        cout << "  " << endl;

        gotoxy(carRY, carRX + 1);
        cout << "   " << endl;

        gotoxy(carRY, carRX + 2);
        cout << "  " << endl;

        gotoxy(carRY, carRX + 3);
        cout << "   " << endl;
       // count2 = 0;

        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        

        gotoxy(carMY, carMX);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 1);
        cout << "###" << endl;

        gotoxy(carMY, carMX + 2);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 3);
        cout << "###" << endl;
       
       count1 = 1;
        EmptyThirdColoum();
        FillSecondColoum();

    }
 //   cout << carMX;
    //getch();
   else if(count3 = 1)
    {
         if ( )
         {

         }
        // cout <<"G";
        

        gotoxy(carMY, carMX);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 1);
        cout << "   " << endl;

        gotoxy(carMY, carMX + 2);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 3);
        cout << "   " << endl;
        // getch();
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // EmptySecondColoum();
        count = 0;

        gotoxy(carLY, carLX);
        cout << " #" << endl;

        gotoxy(carLY, carLX + 1);
        cout << "###" << endl;

        gotoxy(carLY, carLX + 2);
        cout << " #" << endl;

        gotoxy(carLY, carLX + 3);
        cout << "###" << endl;
       // countt = 1;

         EmptySecondColoum();
        FillFirstColoum();
    } 

    
}
void moveCarRight()
{
    
     if (count == 0)
    {
        

        gotoxy(carLY, carLX);
        cout << "  " << endl;

        gotoxy(carLY, carLX + 1);
        cout << "   " << endl;

        gotoxy(carLY, carLX + 2);
        cout << "  " << endl;

        gotoxy(carLY, carLX + 3);
        cout << "   " << endl;
        
          //count1 = 1;
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        

        gotoxy(carMY, carMX);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 1);
        cout << "###" << endl;

        gotoxy(carMY, carMX + 2);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 3);
        cout << "###" << endl;
         count3 = 1;
        EmptyfirstColoum();
        FillSecondColoum();

    }
     else  if (count1 = 1)
    {
        

        gotoxy(carMY, carMX);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 1);
        cout << "   " << endl;

        gotoxy(carMY, carMX + 2);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 3);
        cout << "   " << endl;
        
        count2 = 0;
        //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

        

        gotoxy(carRY, carRX);
        cout << " #" << endl;

        gotoxy(carRY, carRX + 1);
        cout << "###" << endl;

        gotoxy(carRY, carRX + 2);
        cout << " #" << endl;

        gotoxy(carRY, carRX + 3);
        cout << "###" << endl;

        EmptySecondColoum();
        FillThirdColoum();
    }
   
}*/
void moveCarUp()
{
}
void moveCarDown()
{
}
void jumpCar()
{
}
void gotoxy(int x, int y)
{
    COORD coordinates; // coordinates is declared as COORD
    coordinates.X = x; // defining x-axis
    coordinates.Y = y; // defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void EmptyfirstColoum()
{
      track[carLX][carLY] = ' ';
        track[carLX][carLY + 1] = ' ';

        track[carLX + 1][carLY] = ' ';
        track[carLX + 1][carLY + 1] = ' ';
        track[carLX + 1][carLY + 2] = ' ';

        track[carLX + 2][carLY] = ' ';
        track[carLX + 2][carLY + 1] = ' ';

        track[carLX + 3][carLY] = ' ';
        track[carLX + 3][carLY + 1] = ' ';
        track[carLX + 3][carLY + 2] = ' ';
}
void EmptySecondColoum()
{
        track[carMX][carMY] = ' ';
        track[carMX][carMY + 1] = ' ';

        track[carMX + 1][carMY] = ' ';
        track[carMX + 1][carMY + 1] = ' ';
        track[carMX + 1][carMY + 2] = ' ';

        track[carMX + 2][carMY] = ' ';
        track[carMX + 2][carMY + 1] = ' ';

        track[carMX + 3][carMY] = ' ';
        track[carMX + 3][carMY + 1] = ' ';
        track[carMX + 3][carMY + 2] = ' ';
}
void EmptyThirdColoum()
{
        track[carRX][carRY] = ' ';
        track[carRX][carRY + 1] = ' ';

        track[carRX + 1][carRY] = ' ';
        track[carRX + 1][carRY + 1] = ' ';
        track[carRX + 1][carRY + 2] = ' ';

        track[carRX + 2][carRY] = ' ';
        track[carRX + 2][carRY + 1] = ' ';

        track[carRX + 3][carRY] = ' ';
        track[carRX + 3][carRY + 1] = ' ';
        track[carRX + 3][carRY + 2] = ' '; 
}
void FillFirstColoum()
{
       track[carLX][carLY] = ' ';
        track[carLX][carLY + 1] = '#';

        track[carLX + 1][carLY] = '#';
        track[carLX + 1][carLY + 1] = '#';
        track[carLX + 1][carLY + 2] = '#';

        track[carLX + 2][carLY] = ' ';
        track[carLX + 2][carLY + 1] = '#';

        track[carLX + 3][carLY] = '#';
        track[carLX + 3][carLY + 1] = '#';
        track[carLX + 3][carLY + 2] = '#';
}
void FillSecondColoum()
{
        track[carMX][carMY] = ' ';
        track[carMX][carMY + 1] = '#';

        track[carMX + 1][carMY] = '#';
        track[carMX + 1][carMY + 1] = '#';
        track[carMX + 1][carMY + 2] = '#';

        track[carMX + 2][carMY] = ' ';
        track[carMX + 2][carMY + 1] = '#';

        track[carMX + 3][carMY] = '#';
        track[carMX + 3][carMY + 1] = '#';
        track[carMX + 3][carMY + 2] = '#';
}
void FillThirdColoum()
{
       track[carRX][carRY] = '#';
        track[carRX][carRY + 1] = '#';

        track[carRX + 1][carRY] = '#';
        track[carRX + 1][carRY + 1] = '#';
        track[carRX + 1][carRY + 2] = '#';

        track[carRX + 2][carRY] = '#';
        track[carRX + 2][carRY + 1] = '#';

        track[carRX + 3][carRY] = '#';
        track[carRX + 3][carRY + 1] = '#';
        track[carRX + 3][carRY + 2] = '#';   
}
void moveCarLeft(){
    if(count2 ==1){
       gotoxy(carLY, carLX);
        cout << "  " << endl;

        gotoxy(carLY, carLX + 1);
        cout << "   " << endl;

        gotoxy(carLY, carLX + 2);
        cout << "  " << endl;

        gotoxy(carLY, carLX + 3);
        cout << "   " << endl;
        count2 =0;

        gotoxy(carMY, carMX);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 1);
        cout << "###" << endl;

        gotoxy(carMY, carMX + 2);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 3);
        cout << "###" << endl;
        
      EmptyThirdColoum();
      FillSecondColoum();
    }
    else if (carMY != 0 )
    {
       gotoxy(carMY, carMX);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 1);
        cout << "   " << endl;

        gotoxy(carMY, carMX + 2);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 3);
        cout << "   " << endl;
      


       gotoxy(carLY, carLX);
        cout << " #" << endl;

        gotoxy(carLY, carLX + 1);
        cout << "###" << endl;

        gotoxy(carLY, carLX + 2);
        cout << " #" << endl;

        gotoxy(carLY, carLX + 3);
        cout << "###" << endl;
        checkcount();
      // cout<<count;
       //getch();
      EmptySecondColoum();
       FillFirstColoum();
       
}
}
void moveCarRight(){
    
     if(count == 2){
         gotoxy(carLY, carLX);
        cout << "  " << endl;

        gotoxy(carLY, carLX + 1);
        cout << "   " << endl;

        gotoxy(carLY, carLX + 2);
        cout << "  " << endl;

        gotoxy(carLY, carLX + 3);
        cout << "   " << endl;
        count = 0;

      
     gotoxy(carMY, carMX);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 1);
        cout << "###" << endl;

        gotoxy(carMY, carMX + 2);
        cout << " #" << endl;

        gotoxy(carMY, carMX + 3);
        cout << "###" << endl;

      EmptyfirstColoum();
      FillSecondColoum();
     
     }
     else if (carMY != 30 ){ //empty center
       gotoxy(carMY, carMX);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 1);
        cout << "   " << endl;

        gotoxy(carMY, carMX + 2);
        cout << "  " << endl;

        gotoxy(carMY, carMX + 3);
        cout << "   " << endl;

        gotoxy(carRY, carRX);
        cout << " #" << endl;

        gotoxy(carRY, carRX + 1);
        cout << "###" << endl;

        gotoxy(carRY, carRX + 2);
        cout << " #" << endl;

        gotoxy(carRY, carRX + 3);
        cout << "###" << endl;
        count2 = 1;

        EmptySecondColoum();
        FillThirdColoum();
     }  

}
void checkcount()
{
    count = 2;
}