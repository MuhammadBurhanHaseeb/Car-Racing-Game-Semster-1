#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;

char race[24][34] ={{"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"},
                    {"#         |         |         #"}};

int carmx = 20; //midcolumn xaxix 
int carmy = 14;  // y
int count = 0;
int count2= 0;
int racefx = 20;   //firstcolumn xaxis
int racefy = 4;// y axis

int racetx = 20; // thirscolumn xaxis
int racety = 23;  //yaxis
void printroad();
void gotoxy(int x, int y);
void moveCarLeft();
void moveCarRight(); 
void emptymidcolumn();
void  fillfirstcolumn();
void fillthirdcolumn();
void fillmidcolumn();
void emptyfirstcolumn();
void checkcount();
void enemysavemidc();
void emptythirdcolumn();
void updateValue();
void moveCarUp();
void updatefirstvalue();
void updatelastvalue();
void updatedownValue();
void moveCarDown();
void timetick();
void enemyemptytc();
void  enemysavetc();
void enemysavefirstc();
void enemyemptyfirstc();
void enemyemptymidc();
int array[33];
int co  = 5;
int ccheck =0;
int midccheck =0;
int result ;
int checkcar =0;
int live = 3;
int forlive = 1;
int forlivemid =1;
int forlivefirst =1;
int movemid =3;
int movefirst =3;
int movex = 3;
int nexttime =0;
int nextimemid =0;
bool check = false;
bool checkmid = false;
bool checkfirst = false;
int firstcheck =0;
int randcheck =8;

main(){
     
      
     system("CLS");
      printroad();

      race[carmx][carmy] = ' ';
      race[carmx][carmy+1] = '#';

      race[carmx+1][carmy] = '#';
      race[carmx+1][carmy+1] = '#';
      race[carmx+1][carmy+2] = '#';

      race[carmx+2][carmy] = ' ';
      race[carmx+2][carmy+1] = '#';

      race[carmx+3][carmy] = '#';
      race[carmx+3][carmy+1] = '#';
      race[carmx+3][carmy+2] = '#';


      gotoxy(carmy,carmx);
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+1);
      cout<<"###"<<endl;
 
      gotoxy(carmy,carmx+2);
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+3);
      cout<<"###"<<endl;
      


    bool loop = true;
    while(loop){
        Sleep(300);
        
        if(GetAsyncKeyState(VK_LEFT)){
          moveCarLeft(); // Function call to move Pacman towards left
        }
         if(GetAsyncKeyState(VK_RIGHT)){
         moveCarRight(); // Function call to move Pacman towards right 
        }
        if(GetAsyncKeyState(VK_UP)){
            moveCarUp(); // Function call to move Pacman towards up
        }
       if (GetAsyncKeyState(VK_DOWN)){
            moveCarDown(); // Function call to move Pacman towards down   
        }
      //  if (GetAsyncKeyState(VK_ESCAPE)){
        //    loop = false; // Stop the game
        
        
        if(randcheck == 8){
           srand(time(0));
           result = 1 + (rand() % 4);
           randcheck =0;
           }
           randcheck++;
           timetick();
    }
}
void printroad(){
    for(int i=0; i<24; i++){
        for(int j=0; j<34; j++){
            cout<<race[i][j];
        }
        cout<<endl;
    }
}
void moveCarUp(){
    if(carmx!=0 && racefx !=0 && racetx !=0){
       if(race[carmx][carmy+1] == '#'){
      gotoxy(carmy,carmx);
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+1);
      cout<<"   "<<endl;
 
      gotoxy(carmy,carmx+2);
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+3);
      cout<<"   "<<endl;

      //------------               xaxis 18
      gotoxy(carmy,carmx-1); //17
      cout<<" #"<<endl;

      gotoxy(carmy,carmx);  //18
      cout<<"###"<<endl;
 
      gotoxy(carmy,carmx+1);  //19
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+2);  //20
      cout<<"###"<<endl;
        
      emptymidcolumn();       
      updateValue();
      
      fillmidcolumn();

       }
    else if(race[racefx+1][racefy] == '#'){    
       gotoxy(racefy,racefx);
       cout<<"  "<<endl;

        gotoxy(racefy,racefx+1);
        cout<<"   "<<endl;

        gotoxy(racefy,racefx+2);
        cout<<"  "<<endl;

        gotoxy(racefy,racefx+3);
        cout<<"   "<<endl;
        //----                     //18
        gotoxy(racefy,racefx-1);
        cout<<" #"<<endl;    //incerement 1

        gotoxy(racefy,racefx);
        cout<<"###"<<endl;

        gotoxy(racefy,racefx+1);
        cout<<" #"<<endl;

        gotoxy(racefy,racefx+2);
        cout<<"###"<<endl;
         
        emptyfirstcolumn();
         updateValue();
        
        fillfirstcolumn();
    }
    else if(race[racetx][racety+1] = '#'){
        gotoxy(racety,racetx); // first value of racety and k;   racety or racetx akhri block
        cout<<"  "<<endl;
        gotoxy(racety,racetx+1);
        cout<<"   "<<endl;
        gotoxy(racety,racetx+2);
        cout<<"  "<<endl;
        gotoxy(racety,racetx+3);
        cout<<"   "<<endl;

        //-----------    18
        gotoxy(racety,racetx-1); // 
        cout<<" #";
        gotoxy(racety,racetx);
        cout<<"###";
        gotoxy(racety,racetx+1);
        cout<<" #";
        gotoxy(racety,racetx+2);
        cout<<"###";

        emptythirdcolumn();
        updateValue();
        fillthirdcolumn();
    }
}
}
void  moveCarDown(){
    if(race[23][14] != '#'){
       if(race[carmx][carmy+1] == '#'){
      gotoxy(carmy,carmx);   
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+1);
      cout<<"   "<<endl;
 
      gotoxy(carmy,carmx+2);
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+3);
      cout<<"   "<<endl;
 

      //----       //18
       gotoxy(carmy,carmx+1); //17
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+2);  //18
      cout<<"###"<<endl;
 
      gotoxy(carmy,carmx+3);  //19
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+4);  //20
      cout<<"###"<<endl;
        
      emptymidcolumn();       
      updatedownValue();
      
      fillmidcolumn();

       }
     
    else if(race[racefx+1][racefy] == '#'){
        if(race[23][4] != '#')    {
       gotoxy(racefy,racefx);
       cout<<"  "<<endl;

        gotoxy(racefy,racefx+1);
        cout<<"   "<<endl;

        gotoxy(racefy,racefx+2);
        cout<<"  "<<endl;

        gotoxy(racefy,racefx+3);
        cout<<"   "<<endl;
        //----                     //18
        gotoxy(racefy,racefx+1);
        cout<<" #"<<endl;    //incerement 1

        gotoxy(racefy,racefx+2);
        cout<<"###"<<endl;

        gotoxy(racefy,racefx+3);
        cout<<" #"<<endl;

        gotoxy(racefy,racefx+4);
        cout<<"###"<<endl;
         
        emptyfirstcolumn();
         updatedownValue();
        
        fillfirstcolumn();
    }
     }
    else if(race[racetx][racety+1] = '#'){
        if(race[23][23] != '#')    {
        gotoxy(racety,racetx); // first value of racety and k;   racety or racetx akhri block
        cout<<"  "<<endl;
        gotoxy(racety,racetx+1);
        cout<<"   "<<endl;
        gotoxy(racety,racetx+2);
        cout<<"  "<<endl;
        gotoxy(racety,racetx+3);
        cout<<"   "<<endl;

        //-----------    18
        gotoxy(racety,racetx+1); // 
        cout<<" #"<<endl;
        gotoxy(racety,racetx+2);
        cout<<"###"<<endl;
        gotoxy(racety,racetx+3);
        cout<<" #"<<endl;
        gotoxy(racety,racetx+4);
        cout<<"###"<<endl;

        emptythirdcolumn();
        updatedownValue();
        fillthirdcolumn();
    }

    }
    }
}
void updateValue(){
     carmx--;
     racefx--;
     racetx--;
}
void updatedownValue(){
    carmx++;
    racefx++;
    racetx++;
}

void moveCarLeft(){
    if(count2 ==1){
        gotoxy(racety,racetx); // first value of racety and k;   racety or racetx akhri block
        cout<<"  "<<endl;
        gotoxy(racety,racetx+1);
        cout<<"   "<<endl;
        gotoxy(racety,racetx+2);
        cout<<"  "<<endl;
        gotoxy(racety,racetx+3);
        cout<<"   "<<endl;
        count2 =0;

      gotoxy(carmy,carmx);
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+1);
      cout<<"###"<<endl;
 
      gotoxy(carmy,carmx+2);
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+3);
      cout<<"###"<<endl;
        
      emptythirdcolumn();
      fillmidcolumn();
    }
    else if (carmy != 0 )
    {
      gotoxy(carmy,carmx);
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+1);
      cout<<"   "<<endl;
 
      gotoxy(carmy,carmx+2);
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+3);
      cout<<"   "<<endl;
      


       gotoxy(racefy,racefx);
       cout<<" #"<<endl;

        gotoxy(racefy,racefx+1);
        cout<<"###"<<endl;

        gotoxy(racefy,racefx+2);
        cout<<" #"<<endl;

        gotoxy(racefy,racefx+3);
        cout<<"###"<<endl;
        checkcount();
      // cout<<count;
       //getch();
       emptymidcolumn();
       fillfirstcolumn();
       
}
}
void moveCarRight(){
    
     if(count == 2){
         gotoxy(racefy,racefx);
       cout<<"  "<<endl;

        gotoxy(racefy,racefx+1);
        cout<<"   "<<endl;

        gotoxy(racefy,racefx+2);
        cout<<"  "<<endl;

        gotoxy(racefy,racefx+3);
        cout<<"   "<<endl;
        count = 0;

      
      gotoxy(carmy,carmx);
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+1);
      cout<<"###"<<endl;
 
      gotoxy(carmy,carmx+2);
      cout<<" #"<<endl;

      gotoxy(carmy,carmx+3);
      cout<<"###"<<endl;

      emptyfirstcolumn();
      fillmidcolumn();
     
     }
     else if (carmy != 30 ){ //empty center
      gotoxy(carmy,carmx);
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+1);
      cout<<"   "<<endl;
 
      gotoxy(carmy,carmx+2);
      cout<<"  "<<endl;

      gotoxy(carmy,carmx+3);
      cout<<"   "<<endl;

        gotoxy(racety,racetx); // first value of racety and k;   racety or racetx akhri block
        cout<<" #"<<endl;
        gotoxy(racety,racetx+1);
        cout<<"###"<<endl;
        gotoxy(racety,racetx+2);
        cout<<" #"<<endl;
        gotoxy(racety,racetx+3);
        cout<<"###"<<endl;
        count2 = 1;

        emptymidcolumn();
        fillthirdcolumn();
        

}
}
void timetick(){
   // movex =3
    // special logic agli bar jub ai ga or check kre ga one hi to ni chly ga
    // nexttime means agli bar jub random generate ho ga to ye phla vala bhi jub tk column na ho jai ni chaly ga.
    if(result == 1){
         check = true;
    }
    if(result == 2){
        checkmid = true;
    }
    if(result == 3){
        checkfirst = true;
    }

    
   
    if(check == true){
    if( nexttime!=21 && ccheck !=21){
         gotoxy(23,movex-1);      //3
        cout<<"   "<<endl;

         gotoxy(23,movex-2);
        cout<<"  "<<endl;

         gotoxy(23,movex-3);
        cout<<"   "<<endl;

         gotoxy(23,movex - 4);
         cout<<"  "<<endl;

         enemyemptytc();

        gotoxy(23,movex);  //18
        cout<<"***"<<endl;

         gotoxy(23,movex-1); //17
        cout<<" *"<<endl;

         gotoxy(23,movex-2); //16
        cout<<"***"<<endl;

         gotoxy(23,movex - 3); //15
        cout<<" *"<<endl;
        enemysavetc();
    //    Sleep(300);
         

   if(forlive == 1){
    if( race[movex][23+1] == '*' ){
        if(race[movex+1][23+1] == '#'){
                 live--;
                 forlive =1;
        gotoxy(23,movex);
        cout<<"   "<<endl;

         gotoxy(23,movex-1);
        cout<<"  "<<endl;

         gotoxy(23,movex-2);
        cout<<"   "<<endl;

         gotoxy(23,movex - 3);
         cout<<"  "<<endl;
         //------
         
         enemyemptytc();
        
         ccheck =0;
         nexttime =0;
         movex = 3;
         check = false;
        }
    }
   }      
      /*  gotoxy(23,movex);
        cout<<"   "<<endl;

         gotoxy(23,movex-1);
        cout<<"  "<<endl;

         gotoxy(23,movex-2);
        cout<<"   "<<endl;

         gotoxy(23,movex - 3);
        cout<<"  "<<endl;

        enemyemptytc();*/
        
          movex++;
          ccheck++;
          nexttime++;
        /*  gotoxy(80,80);
          cout<<ccheck;
          getch(); */
          // yaha pe ham ye kar rhy hi ke jub gari 1 chal jai gi to move ni update ho ga so ham ne is liye jub 23 
          // ho ga to is ka matlab pora car chal gai to wapis move 3 or sath hi crash pe bhi 3.
       if(ccheck == 21){
        
         gotoxy(23,movex-1);     
        cout<<"   "<<endl;

         gotoxy(23,movex-2);
        cout<<"  "<<endl;

         gotoxy(23,movex-3);
        cout<<"   "<<endl;

         gotoxy(23,movex - 4);
         cout<<"  "<<endl;

         enemyemptytc();
         movex = 3;
         ccheck = 0;
         nexttime =0;
         check = false;
       }
      
    }
     }
     if(checkmid == true){
    if(nextimemid !=21 && midccheck !=21){
        gotoxy(14,movemid-1);
        cout<<"   "<<endl;

         gotoxy(14,movemid-2);
        cout<<"  "<<endl;

         gotoxy(14,movemid-3);
        cout<<"   "<<endl;

         gotoxy(14,movemid - 4);
        cout<<"  "<<endl;

        enemyemptymidc();

        //---
        gotoxy(14,movemid);
        cout<<"***"<<endl;

         gotoxy(14,movemid-1);
        cout<<" *"<<endl;

         gotoxy(14,movemid-2);
        cout<<"***"<<endl;

         gotoxy(14,movemid - 3);
        cout<<" *"<<endl;
        enemysavemidc();  // save in to array..
   //   Sleep(400);

   // for check the car is crash or not..
    if(forlivemid == 1){
    if( race[movemid][14+1] == '*' ){
        if(race[movemid+1][14+1] == '#'){
                 live--;
                 forlivemid =1;
        gotoxy(14,movemid);
        cout<<"   "<<endl;

         gotoxy(14,movemid-1);
        cout<<"  "<<endl;

         gotoxy(14,movemid-2);
        cout<<"   "<<endl;

         gotoxy(14,movemid - 3);
         cout<<"  "<<endl;

         enemyemptymidc();

         midccheck =0;
         nextimemid =0;
         movemid = 3;
         checkmid = false;
        }
    }
   }      

      /*  gotoxy(14,movemid);
        cout<<"   "<<endl;

         gotoxy(14,movemid-1);
        cout<<"  "<<endl;

         gotoxy(14,movemid-2);
        cout<<"   "<<endl;

         gotoxy(14,movemid - 3);
        cout<<"  "<<endl;

        enemyemptymidc();*/
        
          movemid++;
          midccheck++;
          nextimemid ++;

          if(midccheck == 21){

        gotoxy(14,movemid-1);
        cout<<"   "<<endl;

         gotoxy(14,movemid-2);
        cout<<"  "<<endl;

         gotoxy(14,movemid-3);
        cout<<"   "<<endl;

         gotoxy(14,movemid - 4);
        cout<<"  "<<endl;

           enemyemptymidc();
               midccheck =0;
            nextimemid =0;
               movemid = 3;
             checkmid = false;
          }
    }
     }
     //   ----------------- FIRST COLUMN CAR
    if(checkfirst == true){
      if(firstcheck != 21){
        gotoxy(4,movefirst-1);
        cout<<"   "<<endl;

         gotoxy(4,movefirst-2);
        cout<<"  "<<endl;

         gotoxy(4,movefirst-3);
        cout<<"   "<<endl;

         gotoxy(4,movefirst - 4);
        cout<<"  "<<endl;

       enemyemptyfirstc();
       //---------------
          gotoxy(4,movefirst);
        cout<<"***"<<endl;

         gotoxy(4,movefirst-1);
        cout<<" *"<<endl;

         gotoxy(4,movefirst-2);
        cout<<"***"<<endl;

         gotoxy(4,movefirst - 3);
        cout<<" *"<<endl;
        enemysavefirstc();  // save in to array..
   //    Sleep(400);

   // for check the car is crash or not..
    if(forlivefirst == 1){
    if( race[movefirst][4+1] == '*' ){
        if(race[movefirst+1][4+1] == '#'){
                 live--;
                 forlivefirst = 1;
        gotoxy(4,movefirst);
        cout<<"   "<<endl;

         gotoxy(4,movefirst-1);
        cout<<"  "<<endl;

         gotoxy(4,movefirst-2);
        cout<<"   "<<endl;

         gotoxy(4,movefirst - 3);
         cout<<"  "<<endl;
         enemyemptyfirstc();
         
         firstcheck =0;
         movefirst = 3;
         checkmid = false;
        }
    }
   }      

     /*   gotoxy(4,movefirst);
        cout<<"   "<<endl;

         gotoxy(4,movefirst-1);
        cout<<"  "<<endl;

         gotoxy(4,movefirst-2);
        cout<<"   "<<endl;

         gotoxy(4,movefirst - 3);
        cout<<"  "<<endl;

        enemyemptymidc(); */
        
          movefirst++;
          firstcheck++;
        

          if(firstcheck == 21){
              gotoxy(4,movefirst-1);
        cout<<"   "<<endl;

         gotoxy(4,movefirst-2);
        cout<<"  "<<endl;

         gotoxy(4,movefirst-3);
        cout<<"   "<<endl;

         gotoxy(4,movefirst - 4);
        cout<<"  "<<endl;

       enemyemptyfirstc();
               movefirst = 3;
               firstcheck =0;
             checkfirst = false;
          }
    
      }
    }
     
}
void  enemysavetc(){
    race[movex][23] = '*';
    race[movex][23+1] = '*';
    race[movex][23+2] = '*';

    race[movex-1][23] = ' ';
    race[movex-1][23+1] = '*';

    race[movex-2][23] ='*';
    race[movex-2][23+1] ='*';
    race[movex-2][23+2] = '*';

    race[movex-3][23] = ' ';
    race[movex-3][23+1] = '*';

}
void enemysavemidc(){
     race[movemid][14] = '*';
    race[movemid][14+1] = '*';
    race[movemid][14+2] = '*';

    race[movemid-1][14] = ' ';
    race[movemid-1][14+1] = '*';

    race[movemid-2][14] ='*';
    race[movemid-2][14+1] ='*';
    race[movemid-2][14+2] = '*';

    race[movemid-3][14] = ' ';
    race[movemid-3][14+1] = '*';
}
void enemysavefirstc(){
    race[movefirst][4] = '*';
    race[movefirst][4+1] = '*';
    race[movefirst][4+2] = '*';

    race[movefirst-1][4] = ' ';
    race[movefirst-1][4+1] = '*';

    race[movefirst-2][4] ='*';
    race[movefirst-2][4+1] ='*';
    race[movefirst-2][4+2] = '*';

    race[movefirst-3][4] = ' ';
    race[movefirst-3][4+1] = '*';
}
void enemyemptytc(){
    race[movex][23] == ' ';
    race[movex][23+1] == ' ';
    race[movex][23+2] == ' ';

    race[movex-1][23] == ' ';
    race[movex-1][23+1] == ' ';

    race[movex-2][23] == ' ';
    race[movex-2][23+1] == ' ';
    race[movex-2][23+2] == ' ';

    race[movex-3][23] == ' ';
    race[movex-3][23+1] == ' ';
}
void enemyemptymidc(){
    race[movemid][14] == ' ';
    race[movemid][14+1] == ' ';
    race[movemid][14+2] == ' ';

    race[movemid-1][14] == ' ';
    race[movemid-1][14+1] == ' ';

    race[movemid-2][14] == ' ';
    race[movemid-2][14+1] == ' ';
    race[movemid-2][14+2] == ' ';

    race[movemid-3][14] == ' ';
    race[movemid-3][14+1] == ' ';
}
void enemyemptyfirstc(){
    race[movefirst][4] == ' ';
    race[movefirst][4+1] == ' ';
    race[movefirst][4+2] == ' ';

    race[movefirst-1][4] == ' ';
    race[movefirst-1][4+1] == ' ';

    race[movefirst-2][4] == ' ';
    race[movefirst-2][4+1] == ' ';
    race[movefirst-2][4+2] == ' ';

    race[movefirst-3][4] == ' ';
    race[movefirst-3][4+1] == ' ';
}
void emptymidcolumn(){
    race[carmx][carmy] = ' ';
      race[carmx][carmy+1] = ' ';

      race[carmx+1][carmy] = ' ';
      race[carmx+1][carmy+1] = ' ';
      race[carmx+1][carmy+2] = ' ';

      race[carmx+2][carmy] = ' ';
      race[carmx+2][carmy+1] = ' ';

      race[carmx+3][carmy] = ' ';
      race[carmx+3][carmy+1] = ' ';
      race[carmx+3][carmy+2] = ' ';
}
void  fillfirstcolumn(){
    race[racefx][racefy] = ' ';
    race[racefx][racefy+1] = '#';

    race[racefx+1][racefy] = '#';
    race[racefx+1][racefy+1] = '#';
    race[racefx+1][racefy+2] = '#';

    race[racefx+2][racefy] = ' ';
    race[racefx+2][racefy+1] = '#';

    race[racefx+3][racefy] = '#';
    race[racefx+3][racefy+1] = '#';
    race[racefx+3][racefy+2] = '#';
}
void fillthirdcolumn(){
     race[racetx][racety] = ' ';
     race[racetx][racety+1] = '#';

    race[racetx+1][racety] = '#';
    race[racetx+1][racety+1] = '#';
    race[racetx+1][racety+2] = '#';

    race[racetx+2][racety] = ' ';
    race[racetx+2][racety+1] = '#';

    race[racetx+3][racety] = '#';
    race[racetx+3][racety+1] = '#';
    race[racetx+3][racety+2] = '#';
}
void emptythirdcolumn(){
 race[racetx][racety] = ' ';
     race[racetx][racety+1] = ' ';

    race[racetx+1][racety] = ' ';
    race[racetx+1][racety+1] = ' ';
    race[racetx+1][racety+2] = ' ';

    race[racetx+2][racety] = ' ';
    race[racetx+2][racety+1] = ' ';

    race[racetx+3][racety] = ' ';
    race[racetx+3][racety+1] = ' ';
    race[racetx+3][racety+2] = ' ';
}
void emptyfirstcolumn(){
    race[racefx][racefy] = ' ';
    race[racefx][racefy+1] = ' ';

    race[racefx+1][racefy] = ' ';
    race[racefx+1][racefy+1] = ' ';
    race[racefx+1][racefy+2] = ' ';

    race[racefx+2][racefy] = ' ';
    race[racefx+2][racefy+1] = ' ';

    race[racefx+3][racefy] = ' ';
    race[racefx+3][racefy+1] = ' ';
    race[racefx+3][racefy+2] = ' ';
}
void fillmidcolumn(){
    race[carmx][carmy] = ' ';
      race[carmx][carmy+1] = '#';

      race[carmx+1][carmy] = '#';
      race[carmx+1][carmy+1] = '#';
      race[carmx+1][carmy+2] = '#';

      race[carmx+2][carmy] = ' ';
      race[carmx+2][carmy+1] = '#';

      race[carmx+3][carmy] = '#';
      race[carmx+3][carmy+1] = '#';
      race[carmx+3][carmy+2] = '#';
}
void checkcount(){
    count =2;
   // cout<<count;

}
void gotoxy(int x, int y){
    COORD coordinates; // coordinates is declared as COORD
    coordinates.X = x; // defining x-axis
    coordinates.Y = y; // defining  y-axis
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}