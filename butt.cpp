#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <ctime>
#include <sstream>
#include <fstream>
using namespace std;

char race[30][35];

int carmx = 20; // midcolumn xaxix
int carmy = 14; // y
int count = 0;
int count2 = 0;
int racefx = 20; // firstcolumn xaxis
int racefy = 4;  // y axis

int racetx = 20; // thirscolumn xaxis
int racety = 23; // yaxis
void printroad();
void gotoxy(int x, int y);

void moveCarLeft();
void moveCarRight();
void moveCarUp();
void moveCarDown();

void emptymidcolumn();
void fillmidcolumn();

void fillfirstcolumn();
void emptyfirstcolumn();

void fillthirdcolumn();
void emptythirdcolumn();

void checkcount();

void enemysavemidc();   // mid save ho gae gi
void enemysavetc();     // third
void enemysavefirstc(); // first

void updateValue();

void updatedownValue();

void enemyemptytc();
void enemyemptyfirstc();
void enemyemptymidc();

void clearscreen();

void timetick(int rsult);
void cartouch();   // first
void cartouchh();  // second
void cartouchhh(); // third

void loadTrack();
void storescore();

int co = 5;
int ccheck = 0;
int midccheck = 0;
int result3, carresult;
int checkcar = 0;
int live = 3;

int movemid = 3;
int movefirst = 3;
int Ethirdcolumn = 3;
int lifeonec = 0;      // livesfirst col
int lifesecondcol = 0; // lives 2c olumn
int lifethirdcol = 0;
int dotfirstx = 0;
int dotsecondx = 0;
int dotthirdx = 0;
int nexttime = 0;
int sccount, sccountscol, sccounttcol = 0; // second car count for crash
int nextimemid = 0;
bool check = false;
bool checkmid = false;
bool checkfirst = false;
int firstcheck = 0;
int randcheck = 0;
int secondcarintrack = 0;
int giveScore = 0;
int givelive = 0;

int score = 0;

bool firstcolumn = false;
bool secondcolumn = false;
bool thirdcolumn = false;
bool firstc, secondcolumnlive, thirdcolumnlive = false;    // used in lives
int scarinfirstcol, scarinsecondcol, scarinthirdcol = 3;   // second car move in first hurdle.
bool SEfirstcolumn, SEsecondcolumn, SEthirdcolumn = false; // this will represent rand generate value of second car in same track

HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

main()
{

    bool gameover = false;
    bool win = false;
    int result, result2;

    system("CLS");
    loadTrack();
     storescore();
    SetConsoleTextAttribute(hc, 0XB);
    cout << R"(                            
                                               ______--~~~~~~~~~~~~~~~~~~--______              
                                          ___ // _-~                        ~-_ \\ ___  
                                      `\__)\/~                              ~\/(__/'          
                                        _--`-___                            ___-'--_        
                                        /~     `\ ~~~~~~~~------------~~~~~~~~ /'     ~\        
                                     | `\   ______`\_      \------/      _/'______   /' |          
                                     |   `\_~-_____\ ~-________________-~ /_____-~_/'   |  
                                      `.     ~-__________________________________-~     .'       
                                       `.      [_______/------|~~|------\_______]      .'
                                       `\--___((____)(________\/________)(____))___--/'           
                                         |>>>>>>||                            ||<<<<<<|)";

    SetConsoleTextAttribute(hc, 0X07);
    int i = 0;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\tPlease wait Your game is loading...... " << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t\t\tLoading ";
    char x = 177;

    for (i = 0; i < 20; i++)
    {
        SetConsoleTextAttribute(hc, 0XB);
        if (x < 10)
        {
            Sleep(200);
        }
        cout << x;
        Sleep(100);
    }

    SetConsoleTextAttribute(hc, 0Xb);
    system("CLS");
    cout << "*************************************************" << endl;
    cout << "\n";
    cout << "              2D CAR RACING GAME                " << endl;
    cout << " ************************************************" << endl;

    cout << " > Press [S] to start the game. " << endl;
    cout << " > Press [Q] for quit. " << endl;
    cout << " > Enter choice ";
    char choice;
    cin >> choice;
    system("CLS");
    if (choice == 'S' || choice == 's')
    {
        gotoxy(2, 10);

        cout << "\n";
        cout << " *** CHOOSE DIFFICULTY LEVEL *** " << endl;
        cout << "\n";

        cout << " 1) PRESS 1 FOR PLAY NORMAL. " << endl;
        cout << " 2) PRESS 2 FOR PLAY HARD. " << endl;
        cout << " YOUR OPTION . ";
        int option;
        cin >> option;

        if (option == 1)
        {
            // set_cursor(false);
            system("CLS");
            gotoxy(50, 0);
            SetConsoleTextAttribute(hc, 0Xd);

            printroad();

            SetConsoleTextAttribute(hc, 0X07);

            race[carmx][carmy] = ' ';
            race[carmx][carmy + 1] = '#';

            race[carmx + 1][carmy] = '#';
            race[carmx + 1][carmy + 1] = '#';
            race[carmx + 1][carmy + 2] = '#';

            race[carmx + 2][carmy] = ' ';
            race[carmx + 2][carmy + 1] = '#';

            race[carmx + 3][carmy] = '#';
            race[carmx + 3][carmy + 1] = '#';
            race[carmx + 3][carmy + 2] = '#';

            SetConsoleTextAttribute(hc, 0Xd);
            gotoxy(0, 2);
            cout << "#";

            SetConsoleTextAttribute(hc, 0X07);
            gotoxy(carmy, carmx);
            cout << " #";

            gotoxy(carmy, carmx + 1);
            cout << "###";

            gotoxy(carmy, carmx + 2);
            cout << " #";

            gotoxy(carmy, carmx + 3);
            cout << "###";

            while (true)
            {
                Sleep(200);
                SetConsoleTextAttribute(hc, 0Xc);
                gotoxy(50, 10);
                cout << " Remaining lives: " << live;

                SetConsoleTextAttribute(hc, 0Xb);
                gotoxy(50, 15);
                cout << " Your Score: " << score;
                SetConsoleTextAttribute(hc, 0X07);
                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveCarLeft(); // Function call to move car towards left
                }
                else if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveCarRight(); // Function call to move car towards right
                }
                else if (GetAsyncKeyState(VK_UP))
                {
                    moveCarUp(); // Function call to move car towards up
                }
                else if (GetAsyncKeyState(VK_DOWN))
                {
                    moveCarDown(); // Function call to move car towards down
                }

                else if (GetAsyncKeyState(VK_END))
                {
                    break; // Stop the game
                }
                if (live == 0)
                {
                    gameover = true;
                    break;
                }
                if (score == 10)
                {
                    win = true;
                    break;
                }
                if (randcheck == 15)
                {
                    srand(time(0));
                    result = 1 + (rand() % 4);
                    randcheck = 0;
                }

                timetick(result);
                randcheck++;

                result = 0;
            }

            if (gameover == true)
            {
                system("CLS");
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"(
__/\\\________/\\\________________________________________/\\\_______________________________________________________        
 _\///\\\____/\\\/________________________________________\/\\\_______________________________________________________       
  ___\///\\\/\\\/__________________________________________\/\\\_______________________________________________________      
   _____\///\\\/__________/\\\\\_____/\\\____/\\\___________\/\\\_________________/\\\\\_____/\\\\\\\\\\_____/\\\\\\\\__     
    _______\/\\\_________/\\\///\\\__\/\\\___\/\\\___________\/\\\_______________/\\\///\\\__\/\\\//////____/\\\/////\\\_    
     _______\/\\\________/\\\__\//\\\_\/\\\___\/\\\___________\/\\\______________/\\\__\//\\\_\/\\\\\\\\\\__/\\\\\\\\\\\__   
      _______\/\\\_______\//\\\__/\\\__\/\\\___\/\\\___________\/\\\_____________\//\\\__/\\\__\////////\\\_\//\\///////___  
       _______\/\\\________\///\\\\\/___\//\\\\\\\\\____________\/\\\\\\\\\\\\\\\__\///\\\\\/____/\\\\\\\\\\__\//\\\\\\\\\\_ 
        _______\///___________\/////______\/////////_____________\///////////////_____\/////_____\//////////____\//////////__
)";
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"( 
   ____      _      __  __  U _____ u       U  ___ u__     __ U _____ u   ____     
U /"___|uU  /"\  uU|' \/ '|u\| ___"|/        \/"_ \/\ \   /"/u\| ___"|/U |  _"\ u  
\| |  _ / \/ _ \/ \| |\/| |/ |  _|"          | | | | \ \ / //  |  _|"   \| |_) |/  
 | |_| |  / ___ \  | |  | |  | |___      .-,_| |_| | /\ V /_,-.| |___    |  _ <    
  \____| /_/   \_\ |_|  |_|  |_____|      \_)-\___/ U  \_/-(_/ |_____|   |_| \_\   
  _)(|_   \\    >><<,-,,-.   <<   >>           \\     //       <<   >>   //   \\_  
 (__)__) (__)  (__)(./  \.) (__) (__)         (__)   (__)     (__) (__) (__)  (__) 
  )";
                SetConsoleTextAttribute(hc, 0X07);
            }
            if (win == true)
            {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xa);
                cout << R"(
               __   __                                     _            
               \ \ / /   ___    _  _      o O O __ __ __  (_)    _ _    
                \ V /   / _ \  | +| |    o      \ V  V /  | |   | ' \   
                _|_|_   \___/   \_,_|   TS__[O]  \_/\_/  _|_|_  |_||_|  
              _| """ |_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""| 
              "`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-' 
)";
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                //   clearscreen();
            }
        }

        //  ------------- FOR PLAY HARD
        else if (option == 2)
        {
            system("CLS");
            gotoxy(50, 0);
            SetConsoleTextAttribute(hc, 0Xd);
            gotoxy(50, 0);
            cout << R"(
                                      _____           ___                                    
                                    / ___/__ _____  / _ \___ ________   ___ ____ ___ _  ___ 
                                   / /__/ _ `/ __/ / , _/ _ `/ __/ -_) / _ `/ _ `/  ' \/ -_)
                                   \___/\_,_/_/   /_/|_|\_,_/\__/\__/  \_, /\_,_/_/_/_/\__/ 
                                                                      /___/                 
)";
            printroad();

            gotoxy(45, 13);
            cout << " *** Press ESCAPE to stop the game. *** ";

            SetConsoleTextAttribute(hc, 0X07);

            race[carmx][carmy] = ' ';
            race[carmx][carmy + 1] = '#';

            race[carmx + 1][carmy] = '#';
            race[carmx + 1][carmy + 1] = '#';
            race[carmx + 1][carmy + 2] = '#';

            race[carmx + 2][carmy] = ' ';
            race[carmx + 2][carmy + 1] = '#';

            race[carmx + 3][carmy] = '#';
            race[carmx + 3][carmy + 1] = '#';
            race[carmx + 3][carmy + 2] = '#';

            gotoxy(0, 2);
            cout << "#";

            gotoxy(carmy, carmx);
            cout << " #";

            gotoxy(carmy, carmx + 1);
            cout << "###";

            gotoxy(carmy, carmx + 2);
            cout << " #";

            gotoxy(carmy, carmx + 3);
            cout << "###";

            while (true)
            {
                Sleep(200);
                SetConsoleTextAttribute(hc, 0Xc);
                gotoxy(50, 10);
                cout << " Remaining lives: " << live;

                SetConsoleTextAttribute(hc, 0Xb);
                gotoxy(50, 15);
                cout << " Your Score: " << score;
                SetConsoleTextAttribute(hc, 0X07);

                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveCarLeft(); // Function call to move Pacman towards left
                }
                else if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveCarRight(); // Function call to move Pacman towards right
                }
                else if (GetAsyncKeyState(VK_UP))
                {
                    moveCarUp(); // Function call to move Pacman towards up
                }
                else if (GetAsyncKeyState(VK_DOWN))
                {
                    moveCarDown(); // Function call to move Pacman towards down
                }

                else if (GetAsyncKeyState(VK_END))
                {
                    break; // Stop the game
                }
                if (live == 0)
                {
                    gameover = true;
                    break;
                }
                if (score == 10)
                {
                    win = true;
                    break;
                }
                if (randcheck == 3) // this will genrate car random position
                {
                    srand(time(0));
                    result = 1 + (rand() % 4);
                    randcheck = 0;
                }

                timetick(result);
                randcheck++;

                result = 0;
            }

            if (gameover == true)
            {
                system("CLS");
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"(
__/\\\________/\\\________________________________________/\\\_______________________________________________________        
 _\///\\\____/\\\/________________________________________\/\\\_______________________________________________________       
  ___\///\\\/\\\/__________________________________________\/\\\_______________________________________________________      
   _____\///\\\/__________/\\\\\_____/\\\____/\\\___________\/\\\_________________/\\\\\_____/\\\\\\\\\\_____/\\\\\\\\__     
    _______\/\\\_________/\\\///\\\__\/\\\___\/\\\___________\/\\\_______________/\\\///\\\__\/\\\//////____/\\\/////\\\_    
     _______\/\\\________/\\\__\//\\\_\/\\\___\/\\\___________\/\\\______________/\\\__\//\\\_\/\\\\\\\\\\__/\\\\\\\\\\\__   
      _______\/\\\_______\//\\\__/\\\__\/\\\___\/\\\___________\/\\\_____________\//\\\__/\\\__\////////\\\_\//\\///////___  
       _______\/\\\________\///\\\\\/___\//\\\\\\\\\____________\/\\\\\\\\\\\\\\\__\///\\\\\/____/\\\\\\\\\\__\//\\\\\\\\\\_ 
        _______\///___________\/////______\/////////_____________\///////////////_____\/////_____\//////////____\//////////__
)";
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xb);
                cout << R"( 
   ____      _      __  __  U _____ u       U  ___ u__     __ U _____ u   ____     
U /"___|uU  /"\  uU|' \/ '|u\| ___"|/        \/"_ \/\ \   /"/u\| ___"|/U |  _"\ u  
\| |  _ / \/ _ \/ \| |\/| |/ |  _|"          | | | | \ \ / //  |  _|"   \| |_) |/  
 | |_| |  / ___ \  | |  | |  | |___      .-,_| |_| | /\ V /_,-.| |___    |  _ <    
  \____| /_/   \_\ |_|  |_|  |_____|      \_)-\___/ U  \_/-(_/ |_____|   |_| \_\   
  _)(|_   \\    >><<,-,,-.   <<   >>           \\     //       <<   >>   //   \\_  
 (__)__) (__)  (__)(./  \.) (__) (__)         (__)   (__)     (__) (__) (__)  (__) 
  )";
                SetConsoleTextAttribute(hc, 0X07);
            }
            if (win == true)
            {
                system("CLS");
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hc, 0Xa);
                cout << R"(
               __   __                                     _            
               \ \ / /   ___    _  _      o O O __ __ __  (_)    _ _    
                \ V /   / _ \  | +| |    o      \ V  V /  | |   | ' \   
                _|_|_   \___/   \_,_|   TS__[O]  \_/\_/  _|_|_  |_||_|  
              _| """ |_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""| 
              "`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-' 
)";
                cout << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                //   clearscreen();
            }
        }
        else
        {
            cout << " Invalid option entered." << endl;
        }

        // ---------- END PLAY HARD
    }

    else if (choice == 'q' || choice == 'Q')
    {
        cout << " ";
    }
    else
    {

        cout << " Invalid option entered." << endl;
    }
}

void printroad()
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 34; j++)
        {
            gotoxy(j, i);
            cout << race[i][j];
        }
        cout << endl;
    }
}
void moveCarUp()
{
    if (carmx != 0 && racefx != 0 && racetx != 0)
    {
        if (race[carmx][carmy + 1] == '#')
        {

            gotoxy(carmy, carmx);
            cout << "  ";

            gotoxy(carmy, carmx + 1);
            cout << "   ";

            gotoxy(carmy, carmx + 2);
            cout << "  ";

            gotoxy(carmy, carmx + 3);
            cout << "   ";

            //------------               xaxis 18
            gotoxy(carmy, carmx - 1); // 17
            cout << " #";

            gotoxy(carmy, carmx); // 18
            cout << "###";

            gotoxy(carmy, carmx + 1); // 19
            cout << " #";

            gotoxy(carmy, carmx + 2); // 20
            cout << "###";

            emptymidcolumn();
            updateValue();

            fillmidcolumn();
        }
        else if (race[racefx + 1][racefy] == '#')
        {
            gotoxy(racefy, racefx);
            cout << "  ";

            gotoxy(racefy, racefx + 1);
            cout << "   ";

            gotoxy(racefy, racefx + 2);
            cout << "  ";

            gotoxy(racefy, racefx + 3);
            cout << "   ";
            //----                     //18
            gotoxy(racefy, racefx - 1);
            cout << " #"; // incerement 1

            gotoxy(racefy, racefx);
            cout << "###";

            gotoxy(racefy, racefx + 1);
            cout << " #";

            gotoxy(racefy, racefx + 2);
            cout << "###";

            emptyfirstcolumn();
            updateValue();

            fillfirstcolumn();
        }
        else if (race[racetx][racety + 1] = '#')
        {
            gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
            cout << "  ";
            gotoxy(racety, racetx + 1);
            cout << "   ";
            gotoxy(racety, racetx + 2);
            cout << "  ";
            gotoxy(racety, racetx + 3);
            cout << "   ";

            //-----------    18
            gotoxy(racety, racetx - 1); //
            cout << " #";
            gotoxy(racety, racetx);
            cout << "###";
            gotoxy(racety, racetx + 1);
            cout << " #";
            gotoxy(racety, racetx + 2);
            cout << "###";

            emptythirdcolumn();
            updateValue();
            fillthirdcolumn();
        }
    }
}
void moveCarDown()
{
    if (race[23][14] != '#')
    {
        if (race[carmx][carmy + 1] == '#')
        {
            gotoxy(carmy, carmx);
            cout << "  ";

            gotoxy(carmy, carmx + 1);
            cout << "   ";

            gotoxy(carmy, carmx + 2);
            cout << "  ";

            gotoxy(carmy, carmx + 3);
            cout << "   ";

            //----       //18
            gotoxy(carmy, carmx + 1); // 17
            cout << " #";

            gotoxy(carmy, carmx + 2); // 18
            cout << "###";

            gotoxy(carmy, carmx + 3); // 19
            cout << " #";

            gotoxy(carmy, carmx + 4); // 20
            cout << "###";

            emptymidcolumn();
            updatedownValue();

            fillmidcolumn();
        }

        else if (race[racefx + 1][racefy] == '#')
        {
            if (race[23][4] != '#')
            {
                gotoxy(racefy, racefx);
                cout << "  ";

                gotoxy(racefy, racefx + 1);
                cout << "   ";

                gotoxy(racefy, racefx + 2);
                cout << "  ";

                gotoxy(racefy, racefx + 3);
                cout << "   ";
                //----                     //18
                gotoxy(racefy, racefx + 1);
                cout << " #"; // incerement 1

                gotoxy(racefy, racefx + 2);
                cout << "###";

                gotoxy(racefy, racefx + 3);
                cout << " #";

                gotoxy(racefy, racefx + 4);
                cout << "###";

                emptyfirstcolumn();
                updatedownValue();

                fillfirstcolumn();
            }
        }
        else if (race[racetx][racety + 1] = '#')
        {
            if (race[23][23] != '#')
            {
                gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
                cout << "  ";
                gotoxy(racety, racetx + 1);
                cout << "   ";
                gotoxy(racety, racetx + 2);
                cout << "  ";
                gotoxy(racety, racetx + 3);
                cout << "   ";

                //-----------    18
                gotoxy(racety, racetx + 1); //
                cout << " #";
                gotoxy(racety, racetx + 2);
                cout << "###";
                gotoxy(racety, racetx + 3);
                cout << " #";
                gotoxy(racety, racetx + 4);
                cout << "###";

                emptythirdcolumn();
                updatedownValue();
                fillthirdcolumn();
            }
        }
    }
}
void updateValue()
{
    carmx--;
    racefx--;
    racetx--;
}
void updatedownValue()
{
    carmx++;
    racefx++;
    racetx++;
}

void moveCarLeft()
{
    if (count2 == 1) // right
    {
        Sleep(03);
        if (race[carmx][carmy] == '*')
        {
            live--;
            score--;
            cartouchh();
        }
        else if (race[carmx + 1][carmy] == '*')
        {
            live--;
            score--;
            // cartouchh();
            gotoxy(14, movemid - 1);
            cout << "   ";

            gotoxy(14, movemid - 2);
            cout << "  ";

            gotoxy(14, movemid - 3);
            cout << "   ";

            gotoxy(14, movemid - 4);
            cout << "  ";

            enemyemptymidc();
            midccheck = 0;
            nextimemid = 0;
            movemid = 3;
            score++;
            checkmid = false;
        }
        else if (race[carmx + 2][carmy] == '*')
        {
            live--;
            score--;
            // cartouchh();
            gotoxy(14, movemid - 1);
            cout << "   ";

            gotoxy(14, movemid - 2);
            cout << "  ";

            gotoxy(14, movemid - 3);
            cout << "   ";

            gotoxy(14, movemid - 4);
            cout << "  ";

            enemyemptymidc();
            midccheck = 0;
            nextimemid = 0;
            movemid = 3;
            score++;
            checkmid = false;
        }
        else if (race[carmx + 3][carmy] == '*')
        {
            live--;
            score--;
            //  cartouchh();
            gotoxy(14, movemid - 1);
            cout << "   ";

            gotoxy(14, movemid - 2);
            cout << "  ";

            gotoxy(14, movemid - 3);
            cout << "   ";

            gotoxy(14, movemid - 4);
            cout << "  ";

            enemyemptymidc();
            midccheck = 0;
            nextimemid = 0;
            movemid = 3;
            score++;
            checkmid = false;
        }

        gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
        cout << "  ";
        gotoxy(racety, racetx + 1);
        cout << "   ";
        gotoxy(racety, racetx + 2);
        cout << "  ";
        gotoxy(racety, racetx + 3);
        cout << "   ";
        count2 = 0;

        gotoxy(carmy, carmx);
        cout << " #";

        gotoxy(carmy, carmx + 1);
        cout << "###";

        gotoxy(carmy, carmx + 2);
        cout << " #";

        gotoxy(carmy, carmx + 3);
        cout << "###";

        emptythirdcolumn();
        fillmidcolumn();
    }
    else if (carmy != 0)
    {
        Sleep(03);
        if (race[racefx][racefy] == '*')
        {
            live--;
            score--;
            cartouch();
        }
        else if (race[racefx + 1][racefy] == '*')
        {
            live--;
            score--;
            //  cartouch();
            gotoxy(4, movefirst - 1);
            cout << "   ";

            gotoxy(4, movefirst - 2);
            cout << "  ";

            gotoxy(4, movefirst - 3);
            cout << "   ";

            gotoxy(4, movefirst - 4);
            cout << "  ";

            enemyemptyfirstc();
            movefirst = 3;
            firstcheck = 0;
            score++;
            checkfirst = false;
        }
        else if (race[racefx + 2][racefy] == '*')
        {
            live--;
            score--;
            //  cartouch();
            gotoxy(4, movefirst - 1);
            cout << "   ";

            gotoxy(4, movefirst - 2);
            cout << "  ";

            gotoxy(4, movefirst - 3);
            cout << "   ";

            gotoxy(4, movefirst - 4);
            cout << "  ";

            enemyemptyfirstc();
            movefirst = 3;
            firstcheck = 0;
            score++;
            checkfirst = false;
        }
        else if (race[racefx + 3][racefy] == '*')
        {
            live--;
            score--;
            //  cartouch();
            gotoxy(4, movefirst - 1);
            cout << "   ";

            gotoxy(4, movefirst - 2);
            cout << "  ";

            gotoxy(4, movefirst - 3);
            cout << "   ";

            gotoxy(4, movefirst - 4);
            cout << "  ";

            enemyemptyfirstc();
            movefirst = 3;
            firstcheck = 0;
            score++;
            checkfirst = false;
        }

        gotoxy(carmy, carmx);
        cout << "  ";

        gotoxy(carmy, carmx + 1);
        cout << "   ";

        gotoxy(carmy, carmx + 2);
        cout << "  ";

        gotoxy(carmy, carmx + 3);
        cout << "   ";

        gotoxy(racefy, racefx);
        cout << " #";

        gotoxy(racefy, racefx + 1);
        cout << "###";

        gotoxy(racefy, racefx + 2);
        cout << " #";

        gotoxy(racefy, racefx + 3);
        cout << "###";
        checkcount();
        // cout<<count;
        // getch();
        emptymidcolumn();
        fillfirstcolumn();
    }
}
void moveCarRight()
{

    if (count == 2)
    {
        Sleep(03);
        if (race[carmx][carmy] == '*')
        {
            live--;
            score--;
            // cartouchh();
            gotoxy(14, movemid - 1);
            cout << "   ";

            gotoxy(14, movemid - 2);
            cout << "  ";

            gotoxy(14, movemid - 3);
            cout << "   ";

            gotoxy(14, movemid - 4);
            cout << "  ";

            enemyemptymidc();
            midccheck = 0;
            nextimemid = 0;
            movemid = 3;
            score++;
            checkmid = false;
        }
        else if (race[carmx + 1][carmy] == '*')
        {
            live--;
            score--;
            //  cartouchh();
            gotoxy(14, movemid - 1);
            cout << "   ";

            gotoxy(14, movemid - 2);
            cout << "  ";

            gotoxy(14, movemid - 3);
            cout << "   ";

            gotoxy(14, movemid - 4);
            cout << "  ";

            enemyemptymidc();
            midccheck = 0;
            nextimemid = 0;
            movemid = 3;
            score++;
            checkmid = false;
        }
        else if (race[carmx + 2][carmy] == '*')
        {
            live--;
            score--;
            // cartouchh();
            gotoxy(14, movemid - 1);
            cout << "   ";

            gotoxy(14, movemid - 2);
            cout << "  ";

            gotoxy(14, movemid - 3);
            cout << "   ";

            gotoxy(14, movemid - 4);
            cout << "  ";

            enemyemptymidc();
            midccheck = 0;
            nextimemid = 0;
            movemid = 3;
            score++;
            checkmid = false;
        }
        else if (race[carmx + 3][carmy] == '*')
        {
            live--;
            score--;
            // cartouchh();
            gotoxy(14, movemid - 1);
            cout << "   ";

            gotoxy(14, movemid - 2);
            cout << "  ";

            gotoxy(14, movemid - 3);
            cout << "   ";

            gotoxy(14, movemid - 4);
            cout << "  ";

            enemyemptymidc();
            midccheck = 0;
            nextimemid = 0;
            movemid = 3;
            score++;
            checkmid = false;
        }

        gotoxy(racefy, racefx);
        cout << "  ";

        gotoxy(racefy, racefx + 1);
        cout << "   ";

        gotoxy(racefy, racefx + 2);
        cout << "  ";

        gotoxy(racefy, racefx + 3);
        cout << "   ";
        count = 0;

        gotoxy(carmy, carmx);
        cout << " #";

        gotoxy(carmy, carmx + 1);
        cout << "###";

        gotoxy(carmy, carmx + 2);
        cout << " #";

        gotoxy(carmy, carmx + 3);
        cout << "###";

        emptyfirstcolumn();
        fillmidcolumn();
    }
    else if (carmy != 30)
    { // empty center

        Sleep(03);

        if (race[racetx][racety] == '*')
        {
            live--;
            score--;
            // cout <<"hid"<<racetx<<"y "<<racety;
            cartouchhh();
        }
        else if (race[racetx + 1][racety] == '*')
        {
            live--;
            score--;
            cartouchhh();
        }
        else if (race[racetx + 2][racety] == '*')
        {
            live--;
            score--;
            cartouchhh();
        }
        else if (race[racetx + 3][racety] == '*')
        {
            live--;
            score--;
            cartouchhh();
        }

        gotoxy(carmy, carmx);
        cout << "  ";

        gotoxy(carmy, carmx + 1);
        cout << "   ";

        gotoxy(carmy, carmx + 2);
        cout << "  ";

        gotoxy(carmy, carmx + 3);
        cout << "   ";

        gotoxy(racety, racetx); // first value of racety and k;   racety or racetx akhri block
        cout << " #";
        gotoxy(racety, racetx + 1);
        cout << "###";
        gotoxy(racety, racetx + 2);
        cout << " #";
        gotoxy(racety, racetx + 3);
        cout << "###";
        count2 = 1;

        emptymidcolumn();
        fillthirdcolumn();
    }
}
void timetick(int rsult)
{
    int forlivemid = 1;
    int forlivefirst = 1;
    int forlive = 1;

    if (rsult == 1)
    {
        check = true;
    }
    if (rsult == 2)
    {
        checkmid = true;
    }
    if (rsult == 3)
    {
        checkfirst = true;
    }

    if (check == true)
    {
        if (race[0][24] != '#')
        {

            if (nexttime != 21 && ccheck != 21)
            {
                gotoxy(23, Ethirdcolumn - 1); // 19
                cout << "   ";

                gotoxy(23, Ethirdcolumn - 2);
                cout << "  ";

                gotoxy(23, Ethirdcolumn - 3);
                cout << "   ";

                gotoxy(23, Ethirdcolumn - 4);
                cout << "  ";

                enemyemptytc();

                gotoxy(23, Ethirdcolumn); // 18
                cout << "***";

                gotoxy(23, Ethirdcolumn - 1); // 17
                cout << " *";

                gotoxy(23, Ethirdcolumn - 2); // 16
                cout << "***";

                gotoxy(23, Ethirdcolumn - 3); // 15
                cout << " *";
                enemysavetc();
                //    Sleep(300);

                if (forlive == 1)
                {
                    if (race[Ethirdcolumn][23 + 1] == '*')
                    {
                        if (race[Ethirdcolumn + 1][23 + 1] == '#')
                        {
                            live--;
                            forlive = 1;
                            gotoxy(23, Ethirdcolumn);
                            cout << "   ";

                            gotoxy(23, Ethirdcolumn - 1);
                            cout << "  ";

                            gotoxy(23, Ethirdcolumn - 2);
                            cout << "   ";

                            gotoxy(23, Ethirdcolumn - 3);
                            cout << "  ";
                            //------

                            enemyemptytc();

                            ccheck = 0;
                            nexttime = 0;
                            Ethirdcolumn = 3;
                            check = false;
                        }
                    }
                }

                Ethirdcolumn++;
                ccheck++;
                nexttime++;

                if (ccheck == 21)
                {
                    //  cartouchhh();
                    gotoxy(23, Ethirdcolumn - 1);
                    cout << "   ";

                    gotoxy(23, Ethirdcolumn - 2);
                    cout << "  ";

                    gotoxy(23, Ethirdcolumn - 3);
                    cout << "   ";

                    gotoxy(23, Ethirdcolumn - 4);
                    cout << "  ";

                    enemyemptytc();
                    Ethirdcolumn = 3;
                    ccheck = 0;
                    nexttime = 0;
                    score++;
                    check = false;
                }
            }
        }
    }
    if (checkmid == true)
    {
        if (race[0][15] != '#')
        {
            if (nextimemid != 21 && midccheck != 21)
            {
                gotoxy(14, movemid - 1);
                cout << "   ";

                gotoxy(14, movemid - 2);
                cout << "  ";

                gotoxy(14, movemid - 3);
                cout << "   ";

                gotoxy(14, movemid - 4);
                cout << "  ";

                enemyemptymidc();

                //---
                gotoxy(14, movemid);
                cout << "***";

                gotoxy(14, movemid - 1);
                cout << " *";

                gotoxy(14, movemid - 2);
                cout << "***";

                gotoxy(14, movemid - 3);
                cout << " *";
                //--
                gotoxy(14, movemid);
                cout << "***";

                gotoxy(14, movemid - 1);
                cout << " *";

                gotoxy(14, movemid - 2);
                cout << "***";

                gotoxy(14, movemid - 3);
                cout << " *";
                enemysavemidc(); // save in to array..
                                 //   Sleep(400);

                // for check the car is crash or not..
                if (forlivemid == 1)
                {
                    if (race[movemid][14 + 1] == '*')
                    {
                        if (race[movemid + 1][14 + 1] == '#')
                        {
                            live--;
                            forlivemid = 1;
                            gotoxy(14, movemid);
                            cout << "   ";

                            gotoxy(14, movemid - 1);
                            cout << "  ";

                            gotoxy(14, movemid - 2);
                            cout << "   ";

                            gotoxy(14, movemid - 3);
                            cout << "  ";
                            enemyemptymidc();
                            midccheck = 0;
                            nextimemid = 0;
                            movemid = 3;
                            checkmid = false;
                        }
                    }
                }

                movemid++;
                midccheck++;
                nextimemid++;

                if (midccheck == 21)
                {

                    // cartouchh();
                    gotoxy(14, movemid - 1);
                    cout << "   ";

                    gotoxy(14, movemid - 2);
                    cout << "  ";

                    gotoxy(14, movemid - 3);
                    cout << "   ";

                    gotoxy(14, movemid - 4);
                    cout << "  ";

                    enemyemptymidc();
                    midccheck = 0;
                    nextimemid = 0;
                    movemid = 3;
                    score++;
                    checkmid = false;
                }
            }
        }
    }
    //   ----------------- FIRST COLUMN CAR
    if (checkfirst == true)

    {
        if (race[0][5] != '#')
        {
            if (firstcheck != 21)
            {
                gotoxy(4, movefirst - 1);
                cout << "   ";

                gotoxy(4, movefirst - 2);
                cout << "  ";

                gotoxy(4, movefirst - 3);
                cout << "   ";

                gotoxy(4, movefirst - 4);
                cout << "  ";

                enemyemptyfirstc();
                //---------------
                gotoxy(4, movefirst);
                cout << "***";

                gotoxy(4, movefirst - 1);
                cout << " *";

                gotoxy(4, movefirst - 2);
                cout << "***";

                gotoxy(4, movefirst - 3);
                cout << " *";
                enemysavefirstc(); // save in to array..
                                   //    Sleep(400);

                // for check the car is crash or not..
                if (forlivefirst == 1)
                {
                    if (race[movefirst][4 + 1] == '*')
                    {
                        if (race[movefirst + 1][4 + 1] == '#')
                        {
                            live--;
                            forlivefirst = 1;
                            gotoxy(4, movefirst);
                            cout << "   ";

                            gotoxy(4, movefirst - 1);
                            cout << "  ";

                            gotoxy(4, movefirst - 2);
                            cout << "   ";

                            gotoxy(4, movefirst - 3);
                            cout << "  ";
                            enemyemptyfirstc();

                            firstcheck = 0;
                            movefirst = 3;
                            checkmid = false;
                        }
                    }
                }

                movefirst++;
                firstcheck++;

                if (firstcheck == 21)
                {
                    // cartouch();
                    gotoxy(4, movefirst - 1);
                    cout << "   ";

                    gotoxy(4, movefirst - 2);
                    cout << "  ";

                    gotoxy(4, movefirst - 3);
                    cout << "   ";

                    gotoxy(4, movefirst - 4);
                    cout << "  ";

                    enemyemptyfirstc();

                    movefirst = 3;
                    firstcheck = 0;
                    score++;
                    checkfirst = false;
                }
            }
        }
    }
}
// 3rd column
void cartouchhh()
{
    gotoxy(23, Ethirdcolumn - 1);
    cout << "   ";

    gotoxy(23, Ethirdcolumn - 2);
    cout << "  ";

    gotoxy(23, Ethirdcolumn - 3);
    cout << "   ";

    gotoxy(23, Ethirdcolumn - 4);
    cout << "  ";

    enemyemptytc();
    Ethirdcolumn = 3;
    ccheck = 0;
    nexttime = 0;
    score++;
    check = false;
} // 2nd column
void cartouchh()
{

    gotoxy(14, movemid - 1);
    cout << "   ";

    gotoxy(14, movemid - 2);
    cout << "  ";

    gotoxy(14, movemid - 3);
    cout << "   ";

    gotoxy(14, movemid - 4);
    cout << "  ";

    enemyemptymidc();
    midccheck = 0;
    nextimemid = 0;
    movemid = 3;
    score++;
    checkmid = false;
}
void cartouch()
{
    gotoxy(4, movefirst - 1);
    cout << "   ";

    gotoxy(4, movefirst - 2);
    cout << "  ";

    gotoxy(4, movefirst - 3);
    cout << "   ";

    gotoxy(4, movefirst - 4);
    cout << "  ";

    enemyemptyfirstc();
    movefirst = 3;
    firstcheck = 0;
    score++;
    checkfirst = false;
}
void enemysavetc()
{
    // cout <<Ethirdcolumn;
    // getch();
    Sleep(20);
    race[Ethirdcolumn][23] = '*';
    race[Ethirdcolumn][23 + 1] = '*';
    race[Ethirdcolumn][23 + 2] = '*';

    race[Ethirdcolumn - 1][23] = ' ';
    race[Ethirdcolumn - 1][23 + 1] = '*';

    race[Ethirdcolumn - 2][23] = '*';
    race[Ethirdcolumn - 2][23 + 1] = '*';
    race[Ethirdcolumn - 2][23 + 2] = '*';

    race[Ethirdcolumn - 3][23] = ' ';
    race[Ethirdcolumn - 3][23 + 1] = '*';
}
void enemysavemidc()
{
    // cout << movemid;
    Sleep(20);
    race[movemid][14] = '*';
    race[movemid][14 + 1] = '*';
    race[movemid][14 + 2] = '*';

    race[movemid - 1][14] = ' ';
    race[movemid - 1][14 + 1] = '*';

    race[movemid - 2][14] = '*';
    race[movemid - 2][14 + 1] = '*';
    race[movemid - 2][14 + 2] = '*';

    race[movemid - 3][14] = ' ';
    race[movemid - 3][14 + 1] = '*';
}
void enemysavefirstc()
{ // cout << movefirst ;
    Sleep(20);
    race[movefirst][4] = '*';
    race[movefirst][4 + 1] = '*';
    race[movefirst][4 + 2] = '*';

    race[movefirst - 1][4] = ' ';
    race[movefirst - 1][4 + 1] = '*';

    race[movefirst - 2][4] = '*';
    race[movefirst - 2][4 + 1] = '*';
    race[movefirst - 2][4 + 2] = '*';

    race[movefirst - 3][4] = ' ';
    race[movefirst - 3][4 + 1] = '*';
}
void enemyemptytc()
{
    race[Ethirdcolumn][23] == ' ';
    race[Ethirdcolumn][23 + 1] == ' ';
    race[Ethirdcolumn][23 + 2] == ' ';

    race[Ethirdcolumn - 1][23] == ' ';
    race[Ethirdcolumn - 1][23 + 1] == ' ';

    race[Ethirdcolumn - 2][23] == ' ';
    race[Ethirdcolumn - 2][23 + 1] == ' ';
    race[Ethirdcolumn - 2][23 + 2] == ' ';

    race[Ethirdcolumn - 3][23] == ' ';
    race[Ethirdcolumn - 3][23 + 1] == ' ';
}
void enemyemptymidc()
{
    race[movemid][14] == ' ';
    race[movemid][14 + 1] == ' ';
    race[movemid][14 + 2] == ' ';

    race[movemid - 1][14] == ' ';
    race[movemid - 1][14 + 1] == ' ';

    race[movemid - 2][14] == ' ';
    race[movemid - 2][14 + 1] == ' ';
    race[movemid - 2][14 + 2] == ' ';

    race[movemid - 3][14] == ' ';
    race[movemid - 3][14 + 1] == ' ';
}
void enemyemptyfirstc()
{
    race[movefirst][4] == ' ';
    race[movefirst][4 + 1] == ' ';
    race[movefirst][4 + 2] == ' ';

    race[movefirst - 1][4] == ' ';
    race[movefirst - 1][4 + 1] == ' ';

    race[movefirst - 2][4] == ' ';
    race[movefirst - 2][4 + 1] == ' ';
    race[movefirst - 2][4 + 2] == ' ';

    race[movefirst - 3][4] == ' ';
    race[movefirst - 3][4 + 1] == ' ';
}
void emptymidcolumn()
{
    race[carmx][carmy] = ' ';
    race[carmx][carmy + 1] = ' ';

    race[carmx + 1][carmy] = ' ';
    race[carmx + 1][carmy + 1] = ' ';
    race[carmx + 1][carmy + 2] = ' ';

    race[carmx + 2][carmy] = ' ';
    race[carmx + 2][carmy + 1] = ' ';

    race[carmx + 3][carmy] = ' ';
    race[carmx + 3][carmy + 1] = ' ';
    race[carmx + 3][carmy + 2] = ' ';
}
void fillfirstcolumn()
{
    race[racefx][racefy] = ' ';
    race[racefx][racefy + 1] = '#';

    race[racefx + 1][racefy] = '#';
    race[racefx + 1][racefy + 1] = '#';
    race[racefx + 1][racefy + 2] = '#';

    race[racefx + 2][racefy] = ' ';
    race[racefx + 2][racefy + 1] = '#';

    race[racefx + 3][racefy] = '#';
    race[racefx + 3][racefy + 1] = '#';
    race[racefx + 3][racefy + 2] = '#';
}
void fillthirdcolumn()
{
    race[racetx][racety] = ' ';
    race[racetx][racety + 1] = '#';

    race[racetx + 1][racety] = '#';
    race[racetx + 1][racety + 1] = '#';
    race[racetx + 1][racety + 2] = '#';

    race[racetx + 2][racety] = ' ';
    race[racetx + 2][racety + 1] = '#';

    race[racetx + 3][racety] = '#';
    race[racetx + 3][racety + 1] = '#';
    race[racetx + 3][racety + 2] = '#';
}
void emptythirdcolumn()
{
    race[racetx][racety] = ' ';
    race[racetx][racety + 1] = ' ';

    race[racetx + 1][racety] = ' ';
    race[racetx + 1][racety + 1] = ' ';
    race[racetx + 1][racety + 2] = ' ';

    race[racetx + 2][racety] = ' ';
    race[racetx + 2][racety + 1] = ' ';

    race[racetx + 3][racety] = ' ';
    race[racetx + 3][racety + 1] = ' ';
    race[racetx + 3][racety + 2] = ' ';
}
void emptyfirstcolumn()
{
    race[racefx][racefy] = ' ';
    race[racefx][racefy + 1] = ' ';

    race[racefx + 1][racefy] = ' ';
    race[racefx + 1][racefy + 1] = ' ';
    race[racefx + 1][racefy + 2] = ' ';

    race[racefx + 2][racefy] = ' ';
    race[racefx + 2][racefy + 1] = ' ';

    race[racefx + 3][racefy] = ' ';
    race[racefx + 3][racefy + 1] = ' ';
    race[racefx + 3][racefy + 2] = ' ';
}
void fillmidcolumn()
{
    race[carmx][carmy] = ' ';
    race[carmx][carmy + 1] = '#';

    race[carmx + 1][carmy] = '#';
    race[carmx + 1][carmy + 1] = '#';
    race[carmx + 1][carmy + 2] = '#';

    race[carmx + 2][carmy] = ' ';
    race[carmx + 2][carmy + 1] = '#';

    race[carmx + 3][carmy] = '#';
    race[carmx + 3][carmy + 1] = '#';
    race[carmx + 3][carmy + 2] = '#';
}
void checkcount()
{
    count = 2;
    // cout<<count;
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
            race[x][y] = line[y];
        }
    }
    f.close();
}

void gotoxy(int x, int y)
{
    COORD coordinates; // coordinates is declared as COORD
    coordinates.X = x; // defining x-axis
    coordinates.Y = y; // defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void storescore()
{
    fstream f ;
    f.open("store.txt" , ios :: out);
    {
       f << score;
    }
    f.close();
}