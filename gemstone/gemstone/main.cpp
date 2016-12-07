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

using std::cout; using std::endl; using std::cin;

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
    Table table;
    
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
        playerOne = *new Player(playerOneName);

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
        playerTwo = *new Player(playerTwoName);
        
        // Give both players 5 cards to start.
        for(int i = 0; i < 6; ++i)
        {
            playerOne.d_hand.operator+=(deck.draw());
            playerTwo.d_hand.operator+=(deck.draw());
        }
    }else{
        // LOAD SAVE GAME IN HERE <3
    }
    
    // Game time.
    while(!deck.empty())
    {
        cout << "Game : Here is the table as it stands :" << endl;
        cout << table << endl;
        
        // Keep track of turn.
        if(turn == 1)
        {
            // Chain purchasing.
            if(playerOne.getNumCoins() >= 3 && playerOne.getNumChains() < 3)
            {
                string answer = "";
                cout << "Game : Would you like to buy your third chain " << playerOne.getName() << "?" << endl;
                cout << "[Buy third chain? yes or no]" << endl;
                cout << playerOne.getName() << " : ";
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
                playerOne.d_hand.operator+=(deck.draw());
            }
        }
    }
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
