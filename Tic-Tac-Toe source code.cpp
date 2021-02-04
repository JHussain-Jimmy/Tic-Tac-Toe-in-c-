#include<iostream.h>
#include<conio.h>

char psbd[9]={'1','2','3','4','5','6','7','8','9'};///global variables which can be used and modified anywhere
int check[9]={0,0,0,0,0,0,0,0,0},f=0,p1=0,p2=0;
void board(char psbd[9])                          /// this function will print current situation of board
{
    cout<<psbd[0]<<" | "<<psbd[1]<<" | "<<psbd[2]<<" | "<<endl;
    cout<<"------------"<<endl;
    cout<<psbd[3]<<" | "<<psbd[4]<<" | "<<psbd[5]<<" | "<<endl;
    cout<<"------------"<<endl;
    cout<<psbd[6]<<" | "<<psbd[7]<<" | "<<psbd[8]<<" | "<<endl;
    cout<<"------------"<<endl;
    
     }
void player(int a)                                 /////this function will switch turns of each player
{    
     char x='X',o='/';
     int psbd1[9]={1,2,3,4,5,6,7,8,9}, b,d,k;    //an array to help in marking desired position at board
     
     if (a==1)                                  // if condition will oscillate the turns b/w player 1 and player 2
     {      
            do                                //do-while loop to prevent over-writing on board
             {
              k=0;  
              do                               ///do-while loop to restrict values currently on board
              {                             
              cout<<"player one's turn"<<endl;
              cin>>b;
              
              } while((b<1) || (b>9));
              
              for (int c=0;c<9;c++)            ///this loop will give index no of some input number, matching array psbd1
             {                                  //---which will help in replacing corresponding index of char array psbd
                  if (psbd1[c]==b)              //---by desired mark
                  {
                           if (check[c]==0)     //check array will prevent over-writing on board
                              { psbd[c]=x;
                                check[c]=1; }
                           else if (check[c]!=0)
                           { k++;
                             break; }    
                    }
                  }
                } while ((k!=0));              ///do-while to ask again if former is causing over-writing
              }        
     else  if (a==2)                             //a controls turns of players
     {        
              do                              ///same function of do-while to prevent over-writing
              {
               k=0;
              do                                 //this set also works same as previous-one did
              {                                 //--afterall it also controls player's turn
              cout<<"player two's turn"<<endl;
              cin>>d;
              } while ((d<1) || (d>9));
              for (int c=0;c<9;c++)
              {
                  if (psbd1[c]==d)
                  {
                         if (check[c]==0)
                                 { psbd[c]=o;
                                  check[c]=1; }
                                  
                        else if (check[c]!=0)
                          {
                             k++;
                             break;
                          }
                   }                       
                  }
              } while ((k!=0));
              
 
     }
}     
void rules ()             //function to show rules that how and when to end game
{                        //since there're eight possiblities in 3 cross 3 tic-tac-toe to win
     char h=3;
    
                           if (((psbd[0]=='/') && (psbd[1]=='/')&& (psbd[2]=='/')) || ((psbd[3]=='/') && (psbd[4]=='/') && (psbd[5]=='/'))
                           ||  ((psbd[6]=='/') && (psbd[7]=='/')&& (psbd[8]=='/')) || ((psbd[0]=='/') && (psbd[3]=='/') && (psbd[6]=='/'))
                           ||  ((psbd[1]=='/') && (psbd[4]=='/')&& (psbd[7]=='/')) || ((psbd[2]=='/') && (psbd[5]=='/') && (psbd[8]=='/'))
                           ||  ((psbd[0]=='/') && (psbd[4]=='/')&& (psbd[8]=='/')) || ((psbd[2]=='/') && (psbd[4]=='/') && (psbd[6]=='/')))
                           {
                               cout<<endl<<h<<h<<h<<"player two wins"<<h<<h<<h<<endl<<endl;
                               f=1;
                               p2++;
                               }   
                      else if (((psbd[0]=='X') && (psbd[1]=='X')&& (psbd[2]=='X')) || ((psbd[3]=='X') && (psbd[4]=='X') && (psbd[5]=='X'))
                           ||  ((psbd[6]=='X') && (psbd[7]=='X')&& (psbd[8]=='X')) || ((psbd[0]=='X') && (psbd[3]=='X') && (psbd[6]=='X'))
                           ||  ((psbd[1]=='X') && (psbd[4]=='X')&& (psbd[7]=='X')) || ((psbd[2]=='X') && (psbd[5]=='X') && (psbd[8]=='X'))
                           ||  ((psbd[0]=='X') && (psbd[4]=='X')&& (psbd[8]=='X')) || ((psbd[2]=='X') && (psbd[4]=='X') && (psbd[6]=='X')))
                           {
                                cout<<endl<<h<<h<<h<<"player one wins"<<h<<h<<h<<endl<<endl;
                                f=2;
                                p1++;
                                }   
     
     }   
     
void grand (int a)  ///this function will in itself work for three different function.so calling 
{                     //this function alone will ease task from not calling three functions separately, each time at each turn
     if (a%2!=0)
     {
              player (1);
              board (psbd);
              rules ();
              
              }
     else if (a%2==0)
     {
             player (2);
             board (psbd);
             rules ();
          
          }
     
     }     
      
         

int main ()
{
  char g;  
 do                         ///to control whether user wanna play again
{  
 cout<<"WELCOME TO TIC-TAC-TOE"<<endl<<endl;
 board (psbd);
 
    cout<<"player 1 will have symbol: X"<<endl;
    cout<<"player 2 will have symbol: /"<<endl;
  
  for (int e=1;e<=10;e++)   ///loop to control grand function which in turns control rest of three functions
  {                        //by grace of odd and even one-by-one turn of each player comes
      
      
    if (f==0)
     {
       if (e==10)     //if all iteration are expired and yet rules function is not undergone
       cout<<"game's draw;both played well!"<<endl;
               
     else if (e%2!=0)  ///it'll give to function grand value if it's odd turn
       grand (e);      //grand function senses odd and even values for performing task for player one and two
  
     else if (e%2==0)  // it'll give grand even value if it's even iteration
      grand (e);
      }
     else           ///if f!=0 which means game's result of winning or losing has been shown
       break; 
      
      }
      
 cout<<"do you wanna play again"<<endl;
 do
 {
 cout<<"press y for playing again\npress n for no and see who has won most"<<endl;
 cin>>g;
 } while ((g!='n') && (g!='N') && (g!='y') && (g!='Y'));//if user is blind and put someother key than is stated
 if ((g=='n') || (g=='N'))
 {
       ///to show also how many times each player has won            
              cout<<"player one won : "<<p1<<" times "<<endl;
              cout<<"player two won : "<<p2<<" times "<<endl;
              break;
              }
       /*to refreshen the values so that if user has seeked to play again
       old values don't bother and everything goes smoothly and fair*/       
 f=0,p1=0,p2=0;  
 psbd[0]='1';psbd[1]='2';psbd[2]='3';psbd[3]='4';psbd[4]='5';psbd[5]='6';psbd[6]='7';
 psbd[7]='8';psbd[8]='9';
 check[0]=0;check[1]=0;check[2]=0;check[3]=0;check[4]=0;check[5]=0;check[6]=0;check[7]=0;check[8]=0;
} while ((g=='y') || (g=='Y'));//if user entered y meaning that he is willing to win or lose again

    
    
    
    cout<<endl;
    system("pause");
    return 0;
    }
