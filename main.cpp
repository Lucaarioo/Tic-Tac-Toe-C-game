#include <iostream>
#include <stdlib.h>
using namespace std;

int board_size,starter=0,count=1;
string player1,player2;
int initial[100],wait;
int board_moves[100];
int inn,complete;
int ph1[100],pv1[100],diagonal1=0;
int ph2[100],pv2[100],diagonal2=0;
void start();
void play();
void winner();
int main()
{
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWelcome To Lucario's Tic Tac Toe Game" << endl;
    for(int i=0;i<948;i++)
        cout<<"_";
    cout <<endl<< "Enter the size of the board you need : ";
    cin >> board_size;
    complete=board_size*board_size;
    start();
    cin >> wait;
}
void start()
{
    cout << "Enter Player 1 Nick Name : ";
    cin >> player1;
    cout << "Enter Player 2 Nick Name : ";
    cin >> player2;
    system("cls");
    //Welcoming Players
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tHello " << player1 << " & " << player2 << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t$$$$$$$ Lets Begin the game $$$$$$$$$$" << endl;
    for(int i=0;i<948;i++)
        cout<<"_";
    for(int i=0;i<board_size;i++)
    {   cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
        for(int j=0;j<board_size;j++)
        {
            cout << "|" << count;
            count++;
        }
        cout << "|" << endl;
    }
    for(int i=0;i<board_size*board_size;i++)
    {
        board_moves[i]=i+1;
    }
  /* Checking for board setup
    for(int i=0;i<board_size*board_size;i++)
    {
        cout << board_moves[i];
    } */
    count=0;
    play();
}
void display()
{
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tLucario's Tic Tac Toe Game" << endl;
    for(int i=1;i<=board_size;i++)
        cout << pv1[i] << pv2[i];
        cout << endl << diagonal1 << diagonal2 << endl;
    for(int i=0;i<948;i++)
        cout<<"_";
        cout<<endl;
    count=0;
    for(int i=0;i<board_size;i++)
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
        for(int j=0;j<board_size;j++)
        {
            if(board_moves[count]==111)
            {
                cout << " | X";
                count++;
            }
            else if(board_moves[count]==222)
            {
                cout << " | O";
                count++;
            }
            else{
                cout << " | " << board_moves[count] ;
                count++;
                }
        }
        cout << " | " << endl;
    }
}
void play()
{
    cout << "Enter the position you want to place" << endl << endl;
    display();
    while(complete!=0)
    {
    if(starter==0)
    {   int ms1=0;
       while(ms1!=1 && complete!=0)
       {
            cout << player1 <<" Turn : " << endl;
            cin >> inn;
            if(board_moves[inn-1]==111 || board_moves[inn-1]==222)
            {
                cout << "Move Already Placed! Try Again" << endl;
            }
            else{
            board_moves[inn-1]=111;
            int cal=inn%board_size;
            ph1[cal]+=1;
            int done=0;
            int pvcount=1;
            for(int i=0;i<board_size;i++)
            {
                for(int j=0;j<board_size;j++)
                {
                 if(inn-1<board_size*pvcount)
                 {
                  pv1[pvcount]+=1;
                  done=1;
                  break;
                 }
                }
                if(done!=1)
                pvcount++;
                else
                    break;
            }
            int first=1;
            for(int i=0;i<board_size;i++)
            {
                if(inn==first){
                 diagonal1+=1;
                 break;
                }
                else
                 first+=board_size+1;
            }
            ms1=1;
            starter=1;
            }
       }
        winner();
        system("cls");
        display();
    }
    else{
            int ms2=0;
      while(ms2!=1 && complete!=0)
       {
        cout << player2 <<" Turn : " << endl;
        cin >> inn;
        if(board_moves[inn-1]==111 || board_moves[inn-1]==222)
        {
            cout << "Move Already Placed! Try Again" << endl;
        }
        else{
        board_moves[inn-1]=222;
        starter=0;
       int cal=inn%board_size;
            ph2[cal]+=1;
        int pvcount=1;
        int done=0;
            for(int i=0;i<board_size;i++)
            {
                for(int j=0;j<board_size;j++)
                {
                 if(inn-1<board_size*pvcount)
                 {
                  pv2[pvcount]+=1;
                  done=1;
                  break;
                 }
                }
                if(done!=1)
                pvcount++;
                else
                    break;
            }
            int first=1;
            for(int i=0;i<board_size;i++)
            {
                if(inn==first){
                 diagonal2+=1;
                 break;
                }
                else
                 first+=board_size+1;
            }
        ms2=1;
        }
        }
        winner();
        system("cls");
        display();
    }
    complete--;
    }
    cout << "Game Over" << endl;

}
void winner()
{
    //Horizontal Checking
    for(int i=0;i<board_size;i++)
    {
        if(ph1[i]==board_size || pv1[i]==board_size || diagonal1==board_size)
        {
            system("cls");
            cout << "Congrats " << player1 << " You won." << endl;
            display();
            exit(0);
        }
        else if(ph2[i]==board_size || pv2[i]==board_size || diagonal2==board_size)
        {
            system("cls");
            cout << "Congrats " << player2 << " You won." << endl;
            display();
            exit(0);
        }
    }

    return;
}
