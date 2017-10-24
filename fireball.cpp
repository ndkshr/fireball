#include<iostream.h>
#include<limits.h>
#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<math.h>>
#include<windows.h>
#include<iomanip.h>
#define INSTR1 "\n\nTHIS GAME IS MEANT TO BE PLAYED LIKE ITS OTHER COUNTER PARTS LIKE D.X BALL etc. \n\n THE BALL IS CONSTANTLY MOVING OBJECT wiz (*)\n\nTHE USER CAN CONTROL THE BAR ( ======= ) \n\n THE BAR CAN BE CONTROLED BY PRESSING THE GIVEN KEYS \n\n\nRIGHT - [Z]  \t LEFT - [M] "
int song=0;
char game[21][15],GCH;
int points=0,boxes=0,max_r=21,max_c=15;
int bar_j=7,bar_i=20;
clock_t left,ahead;
int ball_i=19,ball_j=8;
class split
{
 float spl;
 public:
 split(float n=0.05)
 {
  spl=n;
 }
 float getsplit()
 {
  return spl;
 }
 void setsplit(float n)
 {
  this->spl=n;
 }
};

                                    struct PLAYER
                                    {/////////////////////////////////////////////// player storage
                                     char name[20];
                                     int scr;
                                    }Player;
                                    storeplayer(PLAYER Pl);
                                    void programmer();
                                    void bar_move_right(int x,int y);        						  // } BAR MOVEMENTS
                                    void bar_move_left(int x,int y);          						 // } BAR MOVEMENTS
                                    int SCORES()
                                    {
                                    gotoxy(1,23);
                                     cout<<"\npoints : "<<(boxes*10)<<'\n';
                                     points=((boxes*10));
                                     return points;
                                    }
                                    void credits();
                                    void animate(int);
                                    void main_menu();
                                    void blockbuster(char);
                                    void wait(float seconds);      					  // WAIT
                                    clock_t timer();
                                    void INSTRUCT();                                                 					   // INSTRUCT
                                    int moveball(int);
                                    int left_up_slant();
                                    int left_down_slant();
                                    int right_up_slant();
                                    int right_down_slant();
                                    int up_straight();
                                    int down_straight();
                                    void update(int i,int j,int u,int v);
////////////////////////////////////////////////////////////////////////////////
void initialize_GAME()
{ ahead=clock()+60*CLOCKS_PER_SEC;
 for(int i=0;i<21;i++)
 {
  for(int j=0;j<15;j++)
  {
   if(i<4 && j!=0 && j!=14)
   game[i][j]='B';
   else
   game[i][j]=' ';
  }
 }
 for(int i=0;i<4;i++){game[i][0]='C';game[i][14]='O';}
 for(int j=7,k=49;j<=9;j++,k++)
 game[20][j]=(char)(k);
 game[ball_i][ball_j]='*';                                                          //     *************** put ball  position ***************/
 game[3][1]='C';game[3][13]='O';
}
////////////////////////////////////////////////////////////////////////////////
char MENU_stat(char mch='\0')
{
    clock_t now=clock();
    char ch='\0'; left=timer();
    left=timer();
   gotoxy(54,4);cout<<"--------------------------";
   gotoxy(55,5);cout<<"STATUS    : "<<"PLAYING";
   gotoxy(55,6);cout<<"TIME LEFT : "<<((left/1000)+1)<<" sec(s)";
   gotoxy(54,7);cout<<"--------------------------";
   gotoxy(52,9);cout<<"Press [Enter]: PAUSE / MENU";
   if((int)mch==13)
   { cout<<"\a";
    gotoxy(55,5);cout<<"STATUS    : "<<"PAUSED ";
gotoxy(52,11);cout<<"   RESUME          [Enter]";
gotoxy(52,13);cout<<"   RESTART         [Space]";
gotoxy(52,12);cout<<"INSTRUCTIONS         [I]";
gotoxy(52,14);cout<<"    EXIT            [Esc]";
    ch=getch();
       ahead+=clock()-now;
   }
   else
   {
    gotoxy(52,11);cout<<"                           ";
    gotoxy(52,13);cout<<"                           ";
    gotoxy(52,12);cout<<"                           ";
    gotoxy(52,14);cout<<"                           ";
    gotoxy(54,17);cout<<"                           ";
   }

   switch((int)ch)
   {
    case 32:initialize_GAME();mch=' ';break;
    case 64:INSTRUCT();break;
    case 105:INSTRUCT();break;
    case 27: gotoxy(56,17);cout<<"REALLY EXIT \? : ";char y;y=getche();if(y=='y'){exit(0);}
    default :mch='\0';break;
   }

   return mch;
}

////////////////////////////////////////////////////////////////////////////////

void INTERFACE()
{
 for(int i=0,y=1;i<max_r;i++,y++)
 {
  for(int j=0,x=2;j<max_c;j++,x=x+3)
  { if(game[i][j]=='B' || game[i][j]=='C'||game[i][j]=='O' ||game[i][j]=='I')
    {gotoxy(x,y);cout<<"";}
   switch(game[i][j])
   {
    case ' ':gotoxy(x,y);cout<<"   ";break;
   }
  }
 }
 gotoxy((bar_j*3),bar_i+1);
 cout<<"=====";
 gotoxy((ball_j*3),ball_i+1);cout<<"";

}
/////////////////////////////////////////////////////////////////////////////////////
                                    void MOVER()
                                    {
                                     gotoxy((bar_j*3)-1,bar_i+1);
                                     cout<<"(=====)";
                                     gotoxy((ball_j*3)-1,ball_i+1);
                                     cout<<"*";

                                     if(wherey()<=4)
                                     INTERFACE();
                                    }
////////////////////////////////////////////////////////////////////////////////
void prn_BAR()
{

}
/*******************************************************************************/
//////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************/
main()                                                                           // { MAIN }
{int anime=1;
 s:
 if(song!=0)song=random(4);
points=0;boxes=0;max_r=21;max_c=15;bar_j=7;bar_i=20;ball_i=19;ball_j=8;
 animate(anime);
 initialize_GAME();
 clrscr();
 split sp;
int funct_no=1;
 initialize_GAME();  for(int y=1;y<=22;y++){gotoxy(1,y);cout<<"|";gotoxy(47,y);cout<<"|";}            // BOUNDARY
 for(int x=1;x<47;x++){gotoxy(x,22);cout<<"";}                                   // DEVIL'S POOL
 GCH='\0';  cin.clear();
 INTERFACE();
  MENU_stat(GCH);
  int cur=boxes;
 for(int i=3;i>=0;i--)
 {gotoxy((22-10),10);cout<<"THE GAME STARTS IN "<<i <<" sec";wait(1);}
 ahead=clock()+60*CLOCKS_PER_SEC;
 while(GCH!=27 && left>=0)
 {
  if(cur!=boxes)
  {cur=boxes;cout<<"";}
  cin.clear();
  INTERFACE();
  GCH=MENU_stat(GCH);
  wait(sp.getsplit());
  funct_no=moveball(funct_no);                                                         ///  move BALL \\\\\\\\\\\\\\\\\\\
 if(kbhit())
 if(kbhit())                                                                        /****************************{accepts entry}***********************/
 {GCH=getch();
  switch(GCH)
  {
   case 'z':bar_move_left(bar_j,bar_i);cin.clear();break;
   case 'Z':bar_move_left(bar_j,bar_i);cin.clear();break;
   case 'm':bar_move_right(bar_j,bar_i);cin.clear();break;
   case 'M':bar_move_right(bar_j,bar_i);cin.clear();break;
   case 'n':sp.setsplit(0.5);
   case 'k':sp.setsplit(0.1);
   case ' ':goto s;;
  }
  }
  if(ball_i>20)
  {
   clrscr();gotoxy((22-6),10);cout<<"GAME OVER ! ";wait(3);int g=0;break;
  }


  SCORES();
}
 wait(2);clrscr();
 Player.scr=SCORES();
 puts(Player.name);cout<<"\nPOINTS : "<<Player.scr;
 storeplayer(Player);
 cout<<"\n\nDARE TO PLAY AGAIN [Y/N]\?  : ";
char nk;cin>>nk;
if(nk=='y' || nk=='Y')
{anime=0;goto s;}
}            																								// END OF MAIN()
/*******************************************************************************/
//////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************/

void INSTRUCT()                                                                  // INSTRUCT
{
 clrscr();  gotoxy(34,1);
 cout<<" INSTRUCTIONS ";
 cout<<INSTR1;
 cout<<"\n\n";
 char ch='\0';
 while((int)ch!=13)
 {gotoxy(1,16);cout<<"PRESS ENTER....";if(kbhit())ch=getch();wait(0.6);gotoxy(1,16);cout<<"               ";wait(0.6);} clrscr();
 INTERFACE();
}
////////////////////////////////////////////////////////////////////////////////
void bar_move_left(int x, int y=21)                                                             // MOVE BAR TO THE LEFT   [=====]
{if(bar_j>1)
 {gotoxy(2,21);cout<<"                                           ";
  game[y][x]=' ';
  game[y][x+1]=' ';
  game[y][x+2]=' ';
  bar_j--;
  for(int i=bar_j,k=49;i<4;i++,k++)
  game[y][i]=k++;
  }
}
////////////////////////////////////////////////////////////////////////////////
void bar_move_right(int x, int y=21)                                                            // MOVE BAR TO THE LEFT   [=====]
{
 if(bar_j<13)
 {gotoxy(2,21);cout<<"                                           ";
  game[y][x]=' ';
  game[y][x+1]=' ';
  game[y][x+2]=' ';
  bar_j++;
  for(int i=bar_j,k=49;i<4;i++,k++)
  game[y][i]=k++;
  }
}
////////////////////////////////////////////////////////////////////////////////
void wait(float seconds)
{
    clock_t temp;
    temp = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < temp);
}
////////////////////////////////////////////////////////////////////////////////
clock_t timer()
{
 return (ahead-clock());
}
////////////////////////////////////////////////////////////////////////////////
int moveball(int fn)
{
 switch(fn)
 {
 case 1:left_up_slant(); break;
 case 3:left_down_slant();break;                                                                       // move ball      //
 case 2:right_up_slant();break;
 case 4: right_down_slant();break;
 case 6:up_straight();break;
 case 5: down_straight();break;
 }
}
////////////////////////////////////////////////////////////////////////////////
int left_up_slant()
{  int flag=1;
  int u=ball_i--;
  int v=ball_j--;
  update(ball_i,ball_j,u,v);
  char check=game[ball_i-1][ball_j-1];
  if(ball_j==0)return 2;
  if(ball_i==2 && ball_j==1){blockbuster(check);boxes++;game[ball_i][ball_j]=' ';game[ball_i--][ball_j--]='*';update(ball_i,ball_j,u,v);return 3;}
  if(check=='B'&&flag==1)
  { boxes++;
  flag=0; blockbuster(check);
    game[ball_i][ball_j]=' ';
   game[ball_i--][ball_j--]='*';                               update(ball_i,ball_j,u,v);
   update(ball_i,ball_j,u,v);
   return 3;
  }
  if(check=='O'&&flag==1)
  { boxes++;

    game[ball_i][ball_j]=' ';
   game[ball_i--][ball_j--]='*';flag=0;blockbuster(check);update(ball_i,ball_j,u,v);
   update(ball_i,ball_j,u,v);
   return 5;
  }
  if(check=='I'&&flag==1)
  {
    game[ball_i][ball_j]=' ';
   game[ball_i--][ball_j--]='*';flag=0;                   blockbuster(check);  update(ball_i,ball_j,u,v);
   update(ball_i,ball_j,u,v);
   return 4;
  }
  if(ball_i==3 && ball_j==12)                                                    // surprise movement
  return 4;
  return 1;
}
////////////////////////////////////////////////////////////////////////////////
int left_down_slant()
{
  int u=ball_i,flag=1; ball_i++;
  int v=ball_j; ball_j--;
  update(ball_i,ball_j,u,v);
  char check=game[ball_i+1][ball_j-1];
  if(ball_j==0)return 4;
  if(ball_i==bar_i&&ball_j==bar_j)
  {  cout<<"\a"; return 6;  }
  if(ball_i==bar_i&&ball_j==(bar_j+1))
  {  cout<<"\a"; return 1;  }
  if(ball_i==bar_i&&ball_j==(bar_j+2))
  {  cout<<"\a"; return 2;  }
 if(check=='B'||check=='C')
   if(flag==1)
   {
    boxes++;
    flag=0;
    game[ball_i][ball_j]=' ';
   game[ball_i++][ball_j--]='*';flag=0;blockbuster(check);  update(ball_i,ball_j,u,v);
   return 4;
   }
   if(check=='I'&&flag==1)
   {
    boxes++;

    game[ball_i][ball_j]=' ';
   game[ball_i++][ball_j--]='*';flag=0;                      blockbuster(check); update(ball_i,ball_j,u,v);
   return 4;
   }
 return 3;
}
////////////////////////////////////////////////////////////////////////////////
int right_up_slant()
{
  int u=ball_i,flag=1; ball_i--;
  int v=ball_j; ball_j++;
  update(ball_i,ball_j,u,v);
  char check=game[ball_i-1][ball_j+1];
  if(ball_i==0)return 4;
  if(ball_j==15)return 1;
  if(check=='B'&&flag==1)
  {boxes++;
   game[ball_i][ball_j]=' ';
   game[ball_i--][ball_j++]='*';flag=0;   blockbuster(check); update(ball_i,ball_j,u,v);
   return 4;
  }
  if(check=='O'&&flag==1)
  { boxes++;
  game[ball_i][ball_j]=' ';
   game[ball_i--][ball_j++]='*';flag=0;                    blockbuster(check);  update(ball_i,ball_j,u,v);
   update(ball_i,ball_j,u,v);
   return 5;
  }
  if(check=='I'&&flag==1)
  {
     boxes++;
   game[ball_i][ball_j]=' ';
   game[ball_i--][ball_j++]='*';flag=0; blockbuster(check);  update(ball_i,ball_j,u,v);
   update(ball_i,ball_j,u,v);
   return 3;
  }
    if(ball_i==3 && ball_j==12)
  return 3;
 return 2;
}
////////////////////////////////////////////////////////////////////////////////
int right_down_slant()
{  int flag=1;
   int u=ball_i; ball_i++;
  int v=ball_j; ball_j++;
    update(ball_i,ball_j,u,v);
    if(ball_j==15)return 3;
   char check=game[ball_i+1][ball_j+1];
   if(ball_i==bar_i&&ball_j==bar_j)
  { cout<<"\a";  return 1;  }
  if(ball_i==bar_i&&ball_j==(bar_j+1))
  { cout<<"\a";  return 2;  }
  if(ball_i==bar_i&&ball_j==(bar_j+2))
  { cout<<"\a";  return 6;  }
   if(check=='B'||check=='C')
   if(flag==1)
   {
    boxes++;
    flag=0;
    game[ball_i][ball_j]=' ';
   game[ball_i++][ball_j++]='*';flag=0;                   blockbuster(check);update(ball_i,ball_j,u,v);
   return 3;
   }
   if(check=='I'&&flag==1)
   {
    boxes++;
    flag=0;
    game[ball_i][ball_j]=' ';
   game[ball_i++][ball_j++]='*';flag=0;blockbuster(check); update(ball_i,ball_j,u,v);
   return 3;
   }
  return 4;
}
////////////////////////////////////////////////////////////////////////////////
int up_straight()
{   int flag=1;
    int u=ball_i; ball_i--;
    int v=ball_j;
    update(ball_i,ball_j,u,v);
    char check=game[ball_i-1][ball_j];
    if(check=='B'||check=='C')
    if(flag==1)
    {flag=0;
     boxes++;
     game[ball_i][ball_j]=' ';
     game[ball_i--][ball_j]='*';flag=0;blockbuster(check); update(ball_i,ball_j,u,v);
   return 4;
    }
    if(check=='O'&&flag==1)
    {flag=0;
     boxes++;
     game[ball_i][ball_j]=' ';
     game[ball_i--][ball_j]='*';flag=0;blockbuster(check);update(ball_i,ball_j,u,v);
   return 3;
    }
    if(check=='I'&&flag==1)
    {flag=0;
     boxes++;
     game[ball_i][ball_j]=' ';
     game[ball_i--][ball_j]='*';flag=0;blockbuster(check); update(ball_i,ball_j,u,v);
   return 5;
    }
    return 6;
}
////////////////////////////////////////////////////////////////////////////////
int down_straight()
{
     int flag=1;
    int u=ball_i; ball_i++;
    int v=ball_j; ball_j;
    update(ball_i,ball_j,u,v);
    char check=game[ball_i+1][ball_j];
    if(ball_i==bar_i&&ball_j==bar_j)
  {cout<<"\a";   return 1;  }
  if(ball_i==bar_i&&ball_j==(bar_j+1))
  {cout<<"\a";   return 2;  }
  if(ball_i==bar_i&&ball_j==(bar_j+2))
  {cout<<"\a";   return 2;  }
     return 5;
}
////////////////////////////////////////////////////////////////////////////////
void update(int i,int j,int u,int v)
{
   game[u][v-1]=' ';
   game[ball_i][ball_j]='*';
}
////////////////////////////////////////////////////////////////////////////////
void blockbuster(char check)
{
 switch(check)
 {
  case 'B':game[ball_i-1][ball_j+1]='I';game[ball_i-1][ball_j]='I';game[ball_i-1][ball_j-2]='I';break;
  case 'C':game[ball_i-1][ball_j]='I';break;
  case 'O':game[ball_i-1][ball_j-2]='I';break;
  case 'I':game[ball_i-1][ball_j+1]='I';game[ball_i-1][ball_j]='I';game[ball_i-1][ball_j-2]='I';break;
 }
}
////////////////////////////////////////////////////////////////////////////////

void animate(int an)
{ clock_t op;
 clrscr();
if(an==1)
{
 if(!song)
{
  PlaySound(TEXT("C:\\Users\\ANSYS\\Desktop\\the dark knight rises -theme.wav"), NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
  op=clock()+16*CLOCKS_PER_SEC;
}
 gotoxy(27,10);cout<<" _____________________________";
 for(int i=11;i<13;i++){gotoxy(27,i);cout<<"||                           ||";}
 gotoxy(27,13);                      cout<<"||___________________________||";
 for(int i=0;i<=100;i++)
 {gotoxy(30,12); cout<<"    LOADING  >>>  "<<i<<" %  ";if(i==100){clrscr();break;}wait(0.16);gotoxy(30,12);cout<<"                        ";if(op<=clock()){i=99;}}
 float f(1.15);
 cout<<" _____ \n";
 cout<<"( ____)\n";
 cout<<"( )__    \n";
 cout<<"( ___)\n";
 cout<<"( )    \n";
 cout<<"(_)    ";

  wait(f);
 gotoxy(10,1);

  cout<<" _\n";gotoxy(10,2);
 cout<<"( )\n";gotoxy(10,3);
 cout<<"( )\n";gotoxy(10,4);
 cout<<"( )\n";gotoxy(10,5);
 cout<<"( )\n"; gotoxy(10,6);
 cout<<"(_)";gotoxy(10,7);

   wait(f);
 gotoxy(16,1);

 cout<<" _____\n";     gotoxy(16,2);
 cout<<"(     )\n";    gotoxy(16,3);
 cout<<"(  D )\n";   gotoxy(16,4);
 cout<<"(   /\n";       gotoxy(16,5);
 cout<<"(   \\\n";    gotoxy(16,6);
 cout<<"(_) \\_)";      gotoxy(16,7);

    wait(1.25);
 gotoxy(26,1);

cout<<" _____\n";     gotoxy(26,2);
 cout<<"( ____)\n";    gotoxy(26,3);
 cout<<"( )__\n";   gotoxy(26,4);
 cout<<"(  __)\n";       gotoxy(26,5);
 cout<<"( )___\n";    gotoxy(26,6);
 cout<<"(_____) ";      gotoxy(26,7);

     wait(f);
 gotoxy(36,4);

cout<<"B A L L";

gotoxy(1,8);cout<<"=============================================";
}

gotoxy(27,10);cout<<" _____________________________";
 for(int i=11;i<13;i++){gotoxy(27,i);cout<<"||                           ||";}
 gotoxy(27,13);                      cout<<"||___________________________||";
 gotoxy(30,12);cout<<"NAME : ";gets(Player.name);
main_menu();
}


//////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

void main_menu()
{ m:
  clrscr();

 cout<<" _____ \n";
 cout<<"( ____)\n";
 cout<<"( )__    \n";
 cout<<"( ___)\n";
 cout<<"( )    \n";
 cout<<"(_)    ";


 gotoxy(10,1);

  cout<<" _\n";gotoxy(10,2);
 cout<<"( )\n";gotoxy(10,3);
 cout<<"( )\n";gotoxy(10,4);
 cout<<"( )\n";gotoxy(10,5);
 cout<<"( )\n"; gotoxy(10,6);
 cout<<"(_)";gotoxy(10,7);


 gotoxy(16,1);

 cout<<" _____\n";     gotoxy(16,2);
 cout<<"(     )\n";    gotoxy(16,3);
 cout<<"(  D )\n";   gotoxy(16,4);
 cout<<"(   /\n";       gotoxy(16,5);
 cout<<"(   \\\n";    gotoxy(16,6);
 cout<<"(_) \\_)";      gotoxy(16,7);


 gotoxy(26,1);

cout<<" _____\n";     gotoxy(26,2);
 cout<<"( ____)\n";    gotoxy(26,3);
 cout<<"( )__\n";   gotoxy(26,4);
 cout<<"(  __)\n";       gotoxy(26,5);
 cout<<"( )___\n";    gotoxy(26,6);
 cout<<"(_____) ";      gotoxy(26,7);


 gotoxy(36,4);

cout<<"B A L L";

gotoxy(1,8);cout<<"=============================================";
  wait(0.5);
  gotoxy(60,12);   cout<<"   M E N U    ";
  gotoxy(60,14);  cout<<"    PLAY    ";
  gotoxy(60,16);  cout<<"INSTRUCTIONS    ";
  gotoxy(60,18);  cout<<"   CREDITS    ";
  gotoxy(60,20);  cout<<"    EXIT    ";

  gotoxy(1,19); cout<<"NAVIGATION : \n\nUP    => press [A]   \nDOWN   => press [Z] \nSELECT => press [Enter]\nTRACK  => press [T]";
  int n=14;char ch='\0';
   goto skip;
   songchange:
   switch(song)
{
 case 0:PlaySound(TEXT("C:\\Users\\ANSYS\\Desktop\\the dark knight rises -theme.wav"), NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);break;
 case 1: PlaySound(TEXT("C:\\Users\\ANSYS\\Desktop\\Burn It To The Ground.wav"), NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);break;
 case 2: PlaySound(TEXT("C:\\Users\\ANSYS\\Desktop\\linkin park - numb lyrics.wav"), NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);break;
 case 3: PlaySound(TEXT("C:\\Users\\ANSYS\\Desktop\\003 Taekwondo Best Knockouts.wav"), NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);break;
 case 4: PlaySound(TEXT("C:\\Users\\ANSYS\\Desktop\\waiting for the end.wav"), NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);break;
}  skip:
  do
  {
   wait(0.4);
   gotoxy(58,n);cout<<"";
  gotoxy(60,14);  cout<<"    PLAY    ";
  gotoxy(60,16);  cout<<"INSTRUCTIONS    ";
  gotoxy(60,18);  cout<<"   CREDITS    ";
  gotoxy(60,20);  cout<<"    EXIT    ";
   switch(n)
   {
    case 14:gotoxy(60,14);  cout<<"    PLAY    ";break;
    case 16:  gotoxy(60,16);  cout<<"INSTRUCTIONS    ";break;
    case 18:gotoxy(60,18);  cout<<"   CREDITS    ";break;
    case 20:gotoxy(60,20);  cout<<"    EXIT    ";break;
   }wait(0.4);
    switch(n)
   {
    case 14:gotoxy(58,14);  cout<<"             ";break;
    case 16:  gotoxy(58,16);  cout<<"                 ";break;
    case 18:gotoxy(58,18);  cout<<"               ";break;
    case 20:gotoxy(58,20);  cout<<"             ";break;
   }
   if(kbhit() && n>13 && n<21)
   {
    ch=getch();
    switch(ch)
    {
     case 'a':if(n>14)n=n-2;break;
     case 'z':if(n<20)n=n+2;break;
     case 'A':if(n>14)n=n-2;break;
     case 'Z':if(n<20)n=n+2;break;
     case 'N':programmer();clrscr();goto m;
     case 't':if(song<=4 && song>=0)song++; else song=0; goto songchange;
    }
   }
  }while((int)ch!=13);

  char c;
  switch(n)
  {
   case 14:break;
   case 16:INSTRUCT();  break;
   case 18:credits();   break;
   case 20:exit(0);
  }

  if(n!=14 && n!=20 && c!='y' && c!='Y' )
  {clrscr();goto m;}
}
///////////////////////////////////////////////////////////////////////////////
void credits()
{char ch('\0');int ly=25-11,flag=1;
 while((int)ch!=13)
 {clrscr();
 gotoxy(25,ly);
 ly--;
 if(flag==1)
 {
 cout<<"\n\n\t                        CREATED BY :               \n\n";
 cout<<"\t           _   _     __   __              _____\n";
 cout<<"\t          | \\ | |   |  | /  /            ( ____) \n";
 cout<<"\t          |  \\| |   |   /  /         _   ( )___ \n";
 cout<<"\t          |     |ANDA  <  <ISHOR    (_)  (____ )\n";
 cout<<"\t          |_|\\  |   |  | \\__\\             ___( )\n";
 cout<<"\t              \\ |   | /                  (_____)\n";
 cout<<"\t               \\|   |/    \n\n				  \n"; }
  if(wherey()==1)
  flag=0;
 gotoxy(1,24);cout<<"PRESS ENTER....";if(kbhit())ch=getch();wait(0.2);gotoxy(1,24);cout<<"               ";wait(0.1);
 }
 clrscr();
}
void programmer()
{PLAYER P;
 int code=0,no;char ch;
 for(int i=3;i>-1;i--)
 {
   ch=getch();
   no=(int)ch-48;
   if(isdigit(ch))
   code=code+(no*pow(10,i));
 }
 if(code==2414)
 {
 clrscr();
 ifstream p("player_fireball.dat",ios::in|ios::binary|ios::ate);
 p.seekg(0,ios::end);

 cout<<"ACCESS GRANTED  :  PROGRAMMER WELCOME \n\n";
 cout<<"STATISTICS  =>\n\n";
 cout<<"NO OF USERS =>"<<(p.tellg()/sizeof(PLAYER)+1)<<"\n";
 
 p.seekg(0); int no=1;
 cout<<"THE OTHER PLAYERS WHO HAVE BEEN FREQUENT ARE\n\n";
 while(!p.eof())
 {
   p.read((char*)&P,sizeof(P));
   cout<<"( "<<no++<<" )  "<<"\t NAME : "<<P.name<<"\tPOINTS    "<<P.scr<<"\n";
 }
 p.close();
 int O=wherey();
 O=O+5;
 while((int)ch!=13)
 {gotoxy(1,O);cout<<"PRESS ENTER....";if(kbhit())ch=getch();wait(0.6);gotoxy(1,O);cout<<"               ";
 wait(0.6);} clrscr();
 }
 else
 {clrscr();cout<<"ACCESS DENIED";}
 getch();

}
///////////////////////////////////////////////////////////////////////////////
storeplayer(PLAYER Pl)
{
 ofstream p("player_fireball.dat",ios::out|ios::binary|ios::app);
 p.seekp(0,ios::end);
 p.write((char*)&Pl,sizeof(Pl));
 p.close();
}
/////////////////////////////////////////////////////////////////////////////////
