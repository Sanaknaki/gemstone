// ==========================================================================
//  Project : gemstone
//  File    : main.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include <stdio.h>
#include <iostream>

#include "gemstones.hpp"
#include "cardfactory.hpp"
#include "deck.hpp"
#include "discard_pile.hpp"
#include "table.hpp"
#include "trade_area.hpp"
#include "hand.hpp"
#include "players.hpp"

using std::cout; using std::endl; using std::cin; using std::ostream;

int main(void)
{
    // Variable creation/initialization at startup.
    Player playerOne;                               // Player one
        string playerOneName;                       // Player one name
    Player playerTwo;                               // Player two
        string playerTwoName;                       // Player two name
    CardFactory cardFactory = *new CardFactory();   // Create the instance of cardfactory
    Deck deck = cardFactory.getDeck();              // Deck, taken from factory
    int gameType = 0;                               // 0 = new new, 1 = new, 2 = loadup
    int turn = 1;                                   // 1 = p1, 2 = p2
    int chainNumber = -1;                           // 1 = chain 1, 2 = chain 2
    Table table;
    Card* topCard;
    
    cout << "#################################################" << endl;
    cout << "#              WELCOME TO GEMSTONE              #" << endl;
    cout << "#################################################" << endl;
    
    // Load from save file or nah?
    while(gameType == 0)
    {
        cout << "Game : Would you like to start a new game [1], or load from save file [2]?" << endl;
        cout << "You : ";
        cin >> gameType;
        
        // Check to make sure the user inputs the right input.
        if(gameType < 1 || gameType > 2)
        {
            cout << endl;
            cout << "Game : Please enter the proper inputs to continue .." << endl;
        }
    }
    
    //======================== CREATE A NEW GAME ========================
    if(gameType == 1)
    {
        // Player one name input.
        cout << "Game : What is your name Player 1?" << endl;
        cout << "Player one : ";
        cin >> playerOneName;
        
        // If player one is trying to be smart.
        if(playerOneName == "")
        {
            cout << "Game : I guess I shall assign you a name .. 'Player One'" << endl;
            playerOneName = "Player One";
        }
    
        // Player one is made.
        table.d_p1 = *new Player(playerOneName);

        // Player two name input.
        cout << "Game : What is your name Player 2?" << endl;
        cout << "Player one : ";
        cin >> playerTwoName;
    
        // If player two is trying to be smart.
        if(playerTwoName == "")
        {
            cout << "Game : I guess I shall assign you a name .. 'Player Two'" << endl;
            playerTwoName = "Player Two";
        }
        
        // Player two is made.
        table.d_p2 = *new Player(playerTwoName);
        
        // Give both players 5 cards to start.
        for(int i = 0; i < 5; ++i)
        {
            table.d_p1.d_hand.operator+=(deck.draw());
            table.d_p2.d_hand.operator+=(deck.draw());
        }
    }else{
        // LOAD SAVE GAME IN HERE <3
    }
    
    // Game time.
    //while(!deck.empty())
    //{
        cout << "Game : Here is the table as it stands :" << endl;
        cout << endl;
        cout << "############## GAME TABLE ##############" << endl;
        cout << table << endl;
        cout << "########################################" << endl;
        cout << endl;
    
        // Keep track of turn.
        if(turn == 1)
        {
            // Chain purchasing.
            if(table.d_p1.getMaxNumChains() < 3)
            {
                string answer = "";
                cout << "Game : Would you like to buy your third chain " << table.d_p1.getName() << "?" << endl;
                cout << "[Buy third chain? yes or no]" << endl;
                cout << table.d_p1.getName() << " : ";
                cin >> answer;
                
                if(answer != "yes")
                {
                    cout << "Game : You did not say yes, therefore you are not buying the chain this turn!" << endl;
                }else
                {
                    // Buy a third chain <3
                }
            }
            
            // Player draws a card.
            if(!deck.empty())
            {
                cout << "Game : Draw a card before continuing!" << endl;
                Card* drawCard = deck.draw();
                cout << "[You draw " + drawCard->getName() + "]" << endl;
                table.d_p1.d_hand.operator+=(deck.draw());
            }
            
            if(table.d_tradeArea.numCards() != 0)
            {
                cout << "Trade area is not empty!" << endl;
            }
            cout << endl;
            
            // Play topmost card
            cout << "Top card : ";
            table.d_p1.printHand(cout ,false);
            cout << endl;
            topCard = table.d_p1.d_hand.top();
            
            
            //for(;;)
            //{
                cout << "Game : Please choose a chain to add your card to!" << endl;
                
                cout << table.d_p1.getName() << " : " ; cin >> chainNumber;
                
                Chain_Base chosenChain = table.d_p1[chainNumber];
                
                if(chosenChain.isEmpty())
                {
                    table.d_p1.startChain(chainNumber, table.d_p1.d_hand.play());
                    cout << table << endl;
                }else{
                    try{
                        chosenChain += (topCard);
                    }
                    catch(Card::IllegalType& e)
                    {
                        string answer;
                        cout << "Game : Card types do not match, would you like to sell this chain?" << endl;
                        cout << table.d_p1.getName() << " : "; cin >> answer;
                        
                        if(answer == "yes" || answer == "Yes")
                        {
                            table.d_p1 += (chosenChain.sell());
                            delete &chosenChain;
                            
                            table.d_p1.startChain(chainNumber, table.d_p1.d_hand.play());
                        }
                    }
                }
            
                for(int i = 0; i < 3; ++i)
                {
                    table.d_tradeArea += (deck.draw());
                }
            
                cout << endl; cout << endl;
                cout << table << endl;
            //}
        }
    //}
}

    // GIVE PLAYERS 5 CARDS AT THE START
    /*for(int i = 0; i < 5; ++i)
    {
        drawCard = deck.draw();
        playerOne.hand.operator+=(drawCard);
        drawCard = deck.draw();
        playerTwo.hand.operator+=(drawCard);
    }*/

    
    
    
    /*while(!deck.empty())
    {
        drawCard = deck.draw();
        cout << i << endl;
        cout << "Card drawn : " << drawCard->getName() << endl;

        for(int j = 0; j < 11; ++j)
        {
            cout << "Card worth at [" << j << "] :" << drawCard->getCardsPerCoin(j) << endl;
        }

        i++;
    }*/
