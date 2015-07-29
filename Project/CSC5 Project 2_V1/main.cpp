/* 
 * File:   main.cpp
 * Author: Alonzo Gomez 
 * Purpose: Blackjack_V2 
 * Created on July 28, 2015, 7:02 PM
 */

//System Library
#include <cstdlib>// srand and rand
#include <iostream>// I/O
#include <ctime>// Generate random numbers
#include <cctype>// Used for lower and upper case letters
#include <iomanip>// setprecision
using namespace std;

//User Libraries 

//Global Constants 

//Function Prototype 

//Assigning cards for player and dealer
void Cards(int &, int &, int &, int &);
//Simulating dealer's turn
int dealer(int &, int &);
// results from dealer's turn
float results(int &, int &,int &, int &, int &);

//Execution Begins Here!

int main(int argc, char** argv) {
//Declare all variables
    int plCard1 = 1;   //Player Card 1
    int plCard2 = 1;   //Player Card 2
    int dlCard1 = 1;    //Dealer Card 1
    int dlCard2 = 1;    //Dealer Card 2
    int playSum;  //Sum of player cards
    int dealSum;  //Sum of dealer cards
    int option;  //Used for main menu
    int plyCard=1;  //Additional card that player gets when he hits
    int dlCard=1;  //dealer hit
    int win=0;  //to count wins
    int lose=0;  //to count losses
    int tie=0;  //to count ties
    char another;  //Another game
    char answer='H';   //Option to hit or stay
    char answ;   //Used for About Blackjack menu
    bool loop=true;  //Used for do-while loop around main menu
    bool menu;   //Used for About Blackjack do-while loop
    bool game=true;  //Used for do-while loop around entire main function
    
    //Output Main Menu
    cout<<"Thank you for choosing Blackjack"<<endl;
    cout<<endl;
    cout<<" What would you like to do?"<<endl;
    cout<<endl;
    cout<<"1. Play Blackjack"<<endl;
    cout<<"2. Blackjack Background"<<endl;
    cout<<"3. Exit"<<endl;
    cin>>option;
    
     //Loop needed to ask if user would like to play again
    do{
        //Loop main menu until told to exit
        do{
	
	if(option == 1){
		//Starting game
        cout<<"Starting Game"<<endl<<endl;
        cout<<setprecision(2)<<fixed<<showpoint;
        
        
        //Call getCards function to generate cards 
        Cards (plCard1, plCard2, dlCard1, dlCard2);
        cout<<"Your cards are "<<plCard1 + 1<<" and "<<plCard2 +1<< " = " << plCard1 + plCard2 + 2 << endl << endl;
        cout<<"The dealer has "<<dlCard1 + 1<<" and "<<"???"<< " = " << dlCard1 + 1<< endl << endl;
		loop=false;//End the loop                
	}
        
	else if(option==2){
			
        //Output About Blackjack Menu
        cout<<"Blackjack Background"<<endl;
        cout<<"1. Rules"<<endl;
        cout<<"2. Vocabulary"<<endl;
	cout<<"3. Exit Menu"<<endl;
	cin>>answ;

		//Initialize menu to keep loop going until told not to
        menu=true;
        do{
    switch(answ){
    case '1'://Rules
          cout<<"The dealer will give you two cards and himself two."<<endl;
          cout<<"Once you have your two cards, you can choose to hit or stay."<<endl;
          cout<<"The goal is to get as close to 21 while having a higher total then"<<endl;
          cout<<"the dealer.If your cards equal 21,(BLACKJACK!) you automatically win."<<endl;
          cout<<"If your sum is greater than the dealers sum, you win."<<endl;
          cout<<"If the dealers sum is greater than your sum you lose."<<endl;
          cout<<"If your sums are equal, then it is a tie."<<endl;
          menu=false;
            break;					
                                               
    case '2'://Vocabulary
          cout<<"Hit: player wants another card."<<endl;
          cout<<"Stand: player okay with cards in hand."<<endl;
          cout<<"Bust: Going over 21."<<endl;
          cout<<"Push: Tie "<<endl;
               menu=false;
			break;
                                                
    case '3'://Back to main menu
          cout<<"Welcome to the game of Blackjack"<<endl;
          cout<<"1. Play Blackjack"<<endl;
          cout<<"2. Blackjack Background"<<endl;
          cout<<"3. Exit"<<endl;
         cin>>option ;
         menu=false;
		break;
		}
	}while(menu==true);
	}
	else {
		cout<<"Ok. Thank you for playing."<<endl;
		loop=false;
        exit(0);//To terminate game
		cout<<endl;	
	}
	}while(loop==true);

	//Calculate player's and dealer's sums
    playSum = plCard1 + plCard2 + 2;
	dealSum = dlCard1 + dlCard2 + 2;

	if(playSum==21)
		cout<<"Congratulations you hit blackjack!"<<endl;
        
	else if(playSum<21){
		do{
            while (playSum < 21){
			cout<<"Would you like to hit or stay? (H/S)"<<endl;
			cin>>answer;
                        
			if(toupper(answer)=='H'){
				
                //Set random number seed
                srand(static_cast<unsigned int>(time(0)));
				plyCard=rand()%10;
				playSum+=plyCard+1;
                                
                //Output new card
				cout<<"Your new card is "<<plyCard+1<<endl;
				cout<<"Your new total is "<<playSum<<endl;
                                
                if(playSum==21){
                    cout<<endl;
                    cout<<"Congratulations you hit blackjack !"<<endl;
                   
                }
                
                else if (playSum > 21)
                {
                    cout<<endl;
                    cout<<"Sorry, you busted."<<endl;
                    cout<<"You lost "<<endl;
                   
                }
                
                else {
                    cout <<' '<<endl;
                }
			}
                        
			else if(toupper(answer)=='S'){
				
                //Output final total
                cout<<"Your final total is "<<playSum<<endl;
				cout<<endl;
                                
                //Dealers turn 
                cout<<"Dealer's Turn."<<endl;
                loop=false;
                
                dealer(dealSum,dlCard);
                
                //Get Results from dealer's turn
                results(dealSum, playSum, win, lose, tie);
                
                                                    
                //Send to showdown to prompt for another hand
                goto shwdwn;
			}
                        
			else
				cout<<endl;
                    }
                    
			}while(playSum<21);
        }
        
	else{
            cout<<endl;
            cout<<"Sorry. You busted."<<endl;
        }
        
        //Label shwdwn to allow goto to come here
        //Prompt user for another hand
        shwdwn: cout<<"Would you like to play another hand? Y/N"<<endl;
        cin>>another;
        
        if(toupper(another)=='Y')
            game=true;
        
        else if (toupper(another)=='N')
        {
            cout<<"Ok. Thank you for playing."<<endl;
            game=false;
            
           
        } 
        
        else
            cout<<' '<<endl;
        
    }while(game==true);

    
    
    return 0;
}

/*******************************************************************************
 ************************Generate Cards*****************************************
 *******************************************************************************
 *Purpose: To get the cards for the player and dealer
 *Input: Random number generator 
 *Output: Two cards for each player && dealer
 */
void Cards( int & plyCard1, int & plyCard2, int & dlCard1, int & dlCard2)
{
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Generate cards for player and dealer
    plyCard1=rand()%11;
    plyCard2=rand()%10;
    dlCard1=rand()%11;
    dlCard2=rand()%10;
}

/*******************************************************************************
 ************************Simulate Dealers Turn**********************************
 *******************************************************************************
 *Purpose: To determine if the dealer should hit || stay
 *Output: Dealers new card sum
 */

int dealer(int &dlSum, int &dlCard)
{    
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Determine if dealer needs to hit
    while (dlSum<17){
        dlCard=rand()%10;
        dlSum+=dlCard+1;
        cout<<"The dealer's new card is "<<dlCard+1<<endl;
        cout<<"The dealer's new total is "<<dlSum<<endl;
    }
    return dlCard, dlSum;
}

/*******************************************************************************
 **************************Result of Dealer turn********************************
 *******************************************************************************
 *Purpose: Compare player and dealer hands
 *Output: Who won the hand of Blackjack
 */

float results(int &dlSum, int &plySum, int &win, int &lose, int &tie){    
    //Output Results of turn
    if(dlSum>21)
    {
        cout<<fixed<<setprecision(2)<<showpoint;
        cout<<endl;
        cout<<"Dealer busted."<<endl;
        cout<<"You won "<<endl;
       
        return win;
    }
    else if(dlSum>plySum)
    {
        cout<<endl;
        cout<<"Sorry. The dealer won."<<endl;
        cout<<"You lost "<<endl;
       
        return lose; 
    }
    else if(plySum>dlSum)
    {
        cout<<endl;
        cout<<"Congratulations!"<<endl;
        cout<<"You won "<<endl;
       
        return win; 
    }
    else if(plySum==dlSum)
    {
        cout<<endl;
        cout<<"It was a tie.(push)"<<endl;
        
        return tie;
    }
    else
        cout<<"Error!"<<endl;
}  
         

