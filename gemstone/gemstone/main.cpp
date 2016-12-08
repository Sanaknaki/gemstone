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
#include <fstream>

#include "gemstones.hpp"
#include "cardfactory.hpp"
#include "deck.hpp"
#include "discard_pile.hpp"
#include "table.hpp"
#include "trade_area.hpp"
#include "hand.hpp"
#include "players.hpp"

using std::cout; using std::endl; using std::cin; using std::ostream;
using std::ifstream; using std::ofstream;

void addToChain(Player& _player, Table& table, int chainNumber, Card* topCard)
{
        cout << "Game : Please choose a chain to add " << topCard->getName() << " to." << endl;

        while(chainNumber < 0 || chainNumber >= _player.getMaxNumChains())
        {
            cout << _player.getName() << " : " ; cin >> chainNumber;
        }

        Chain_Base* chosenChain = &_player[chainNumber];

        if(chosenChain->isEmpty())
        {
            _player.startChain(chainNumber, topCard);
        }else{
            try{
                *chosenChain += (topCard);
            }
            catch(Card::IllegalType& e)
            {
                string answer;
                cout << "Game : Card types do not match, would you like to sell this chain?" << endl;
                cout << _player.getName() << " : "; cin >> answer;

                if(answer == "yes" || answer == "Yes")
                {
                    _player += (chosenChain->sell());
                    _player.startChain(chainNumber, topCard);
                }else{
                    addToChain(_player, table, -1, topCard);
                }
            }
    }
}

void saveGame( const Table& _table )
{
    string answer;
    cout << "Would you like to save the game to file?" << endl;
    cin >> answer;

    if( answer == "yes" || answer == "Yes")
    {
        string fn{"gemstones_save.txt"};
        // open file
        ofstream out(fn);
        if( !out ) {
            cout << "ERROR: unable to open " << fn << endl << endl;
            saveGame( _table );
            return;
        }

        // print table contents to file
        _table.print( out );

        // close file
        out.close();
    }
}

Table* loadGame ( CardFactory* _cardPool )
{
    string fn;
    cout << "Enter file name : "; cin >> fn;
    // open file
    ifstream in(fn);
    if( !in ) {
        cout << "ERROR: unable to open " << fn << endl << endl;
        return loadGame( _cardPool );
    }

    // read contents from file
    return new Table( in, _cardPool );
}

int main(void)
{
    // Variable creation/initialization at startup.
    Player playerOne;										// Player one
    string playerOneName;									// Player one name
    Player playerTwo;										// Player two
    string playerTwoName;									// Player two name
	Player* players[2];
    CardFactory cardFactory = *CardFactory::getFactory();   // Create the instance of cardfactory
    int gameType = 0;										// 0 = new new, 1 = new, 2 = loadup
    int turn = 1;											// 1 = p1, 2 = p2
    int chainNumber = -1;									// 1 = chain 1, 2 = chain 2
    Table* table;
    Card* topCard;
    string answer;
    int choice;
    string winner = "";

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
		table = new Table();
        // Player one name input.
        cout << "Game : What is your name Player 1?" << endl;
        cout << "Player One : ";
        cin >> playerOneName;

        // If player one is trying to be smart.
        if(playerOneName == "")
        {
            cout << "Game : I guess I shall assign you a name .. 'Player One'" << endl;
            playerOneName = "Player One";
        }

        // Player one is made.
		players[0] = new Player(playerOneName);
		table->d_p1 = *players[0];

        // Player two name input.
        cout << "Game : What is your name Player 2?" << endl;
        cout << "Player Two : ";
        cin >> playerTwoName;

        // If player two is trying to be smart.
        if(playerTwoName == "")
        {
            cout << "Game : I guess I shall assign you a name .. 'Player Two'" << endl;
            playerTwoName = "Player Two";
        }

        // Player two is made.
		players[1] = new Player(playerTwoName);
		table->d_p2 = *players[1];

		// Deck, taken from factory
		table->d_deck = cardFactory.getDeck();

        // Give both players 5 cards to start.
        for(int i = 0; i < 5; ++i)
        {
            table->d_p1.d_hand.operator+=(table->d_deck.draw());
            table->d_p2.d_hand.operator+=(table->d_deck.draw());
        }
    }else{
		// load from file
        table = loadGame( cardFactory.getFactory() );
    }


    // Game time.
    while(!table->win(winner))
    {
        cout << "Game : Here is the table as it stands :" << endl;
        cout << endl;
        cout << "############## GAME TABLE ##############" << endl;
        cout << *table;
        cout << "########################################" << endl;
        cout << endl;

        saveGame( *table );

        // Keep track of turn.
        if(turn == 1)
        {
            // Chain purchasing.
            if(table->d_p1.getMaxNumChains() < 3)
            {
                string answer = "";
                cout << "Game : Would you like to buy your third chain " << table->d_p1.getName() << "?" << endl;
                cout << "[Buy third chain? yes or no]" << endl;
                cout << table->d_p1.getName() << " : ";
                cin >> answer;

                if(answer == "yes")
                {
                    table->d_p1.buyThirdChain();
                }
            }

            // Player draws a card.
            if(!table->d_deck.empty())
            {
                cout << "Game : Draw a card before continuing!" << endl;
                Card* drawCard = table->d_deck.draw();
                cout << "[You draw " + drawCard->getName() + "]" << endl;
                table->d_p1.d_hand.operator+=(drawCard);

                table->d_p1.printHand(cout, true);
            }

            if(table->d_tradeArea.numCards() != 0)
            {
                for(auto iter = table->d_tradeArea.d_types.begin(); iter != table->d_tradeArea.d_types.end(); iter = table->d_tradeArea.d_types.erase(iter))
                {
                    cout << endl;
                    cout << "Game : Do you want to add " << *iter << " to a chain?" << endl;
                    cout << table->d_p1.getName() << " : "; cin >> answer;

                    Card* cardInTrade = table->d_tradeArea.trade(*iter);

                    while(cardInTrade != nullptr)
                    {
                        if(answer == "yes" || answer == "Yes")
                        {
                            addToChain(table->d_p1, *table, -1, cardInTrade);
                        }else{
                            table->d_discardPile += cardInTrade;
                        }

                        cardInTrade = table->d_tradeArea.trade(*iter);
                    }
                }
            }
            cout << endl;

            // Play topmost card
            cout << "Top card : ";
            table->d_p1.printHand(cout ,false);
            cout << endl;
            topCard = table->d_p1.d_hand.play();

            addToChain(table->d_p1, *table, chainNumber, topCard);

            cout << "Top card : ";
            table->d_p1.printHand(cout, false);
            cout << endl;

            cout << "Game : Do you wish to add your top card to a chain?" << endl;
            cout << table->d_p1.getName() << " : "; cin >> answer;

            if(answer == "yes" || answer == "Yes")
            {
                topCard = table->d_p1.d_hand.play();
                addToChain(table->d_p1, *table, chainNumber, topCard);
            }

            cout << "Game : Would you like to discard a card from your hand?" << endl;
            cout << table->d_p1.getName() << " : "; cin >> answer;

            if(answer == "yes" || answer == "Yes")
            {
                table->d_p1.printHand(cout, true); cout << endl;

                cout << "Game : What card would you like to discard?" << endl;

                for(;;)
                {
                    cout << table->d_p1.getName() << " : "; cin >> choice;
                    Card* discardCard = table->d_p1.d_hand[choice];


                    if(discardCard != nullptr)
                    {
                        table->d_discardPile += discardCard;
                        cout << table->d_p1.getName() << " hand : "; table->d_p1.printHand(cout, true); cout << endl;
                        break;
                    }
                }
            }
            // Place 3 cards into the trade area.
            for(int i = 0; i < 3 && !table->d_deck.empty(); ++i)
            {
                table->d_tradeArea += (table->d_deck.draw());
            }

            //for all the cards in the trade area, compare top card
            while(table->d_discardPile.top() != nullptr && table->d_tradeArea.legal(table->d_discardPile.top()))
            {
                table->d_tradeArea += (table->d_discardPile.pickUp());
            }

            cout << endl;
            cout << "Trade Area : "; cout << table->d_tradeArea << endl;

            if(table->d_tradeArea.numCards() != 0)
            {
                for(auto iter = table->d_tradeArea.d_types.begin(); iter != table->d_tradeArea.d_types.end();)
                {
                    cout << "Game : Do you want to add " << *iter << " to a chain?" << endl;
                    cout << table->d_p1.getName() << " : "; cin >> answer;

                    if(answer == "yes" || answer == "Yes")
                    {
                        Card* cardInTrade = table->d_tradeArea.trade(*iter);

                        while(cardInTrade != nullptr)
                        {
                            addToChain(table->d_p1, *table, -1, cardInTrade);
                            cardInTrade = table->d_tradeArea.trade(*iter);
                        }

                        iter = table->d_tradeArea.d_types.erase(iter);
                    } else {
                         ++iter;
                    }
                }
            }
            if( !table->d_deck.empty() ) {
                table->d_p1.d_hand += table->d_deck.draw();
                table->d_p1.d_hand += table->d_deck.draw();
            }
            turn = 2;
        }

        cout << "Game : Here is the table as it stands :" << endl;
        cout << endl;
        cout << "############## GAME TABLE ##############" << endl;
        cout << *table;
        cout << "########################################" << endl;
        cout << endl;


        // Keep track of turn.
        if(turn == 2)
        {
            // Chain purchasing.
            if(table->d_p2.getMaxNumChains() < 3)
            {
                string answer = "";
                cout << "Game : Would you like to buy your third chain " << table->d_p2.getName() << "?" << endl;
                cout << "[Buy third chain? yes or no]" << endl;
                cout << table->d_p2.getName() << " : ";
                cin >> answer;

                if(answer == "yes")
                {
                    table->d_p2.buyThirdChain();
                }
            }

            // Player draws a card.
            if(!table->d_deck.empty())
            {
                cout << "Game : Draw a card before continuing!" << endl;
                Card* drawCard = table->d_deck.draw();
                cout << "[You draw " + drawCard->getName() + "]" << endl;
                table->d_p2.d_hand.operator+=(drawCard);

                table->d_p2.printHand(cout, true);
            }

            if(table->d_tradeArea.numCards() != 0)
            {
                for(auto iter = table->d_tradeArea.d_types.begin(); iter != table->d_tradeArea.d_types.end(); iter = table->d_tradeArea.d_types.erase(iter))
                {
                    cout << endl;
                    cout << "Game : Do you want to add " << *iter << " to a chain?" << endl;
                    cout << table->d_p2.getName() << " : "; cin >> answer;

                    Card* cardInTrade = table->d_tradeArea.trade(*iter);

                    while(cardInTrade != nullptr)
                    {
                        if(answer == "yes" || answer == "Yes")
                        {
                            addToChain(table->d_p2, *table, -1, cardInTrade);
                        }else{
                            table->d_discardPile += cardInTrade;
                        }

                        cardInTrade = table->d_tradeArea.trade(*iter);
                    }
                }
            }
            cout << endl;

            // Play topmost card
            cout << "Top card : ";
            table->d_p2.printHand(cout ,false);
            cout << endl;
            topCard = table->d_p2.d_hand.play();

            addToChain(table->d_p2, *table, chainNumber, topCard);

            cout << "Top card : ";
            table->d_p2.printHand(cout, false);
            cout << endl;

            cout << "Game : Do you wish to add your top card to a chain?" << endl;
            cout << table->d_p2.getName() << " : "; cin >> answer;

            if(answer == "yes" || answer == "Yes")
            {
                topCard = table->d_p2.d_hand.play();
                addToChain(table->d_p2, *table, chainNumber, topCard);
            }

            cout << "Game : Would you like to discard a card from your hand?" << endl;
            cout << table->d_p2.getName() << " : "; cin >> answer;

            if(answer == "yes" || answer == "Yes")
            {
                table->d_p2.printHand(cout, true); cout << endl;

                cout << "Game : What card would you like to discard?" << endl;

                for(;;)
                {
                    cout << table->d_p2.getName() << " : "; cin >> choice;
                    Card* discardCard = table->d_p2.d_hand[choice];


                    if(discardCard != nullptr)
                    {
                        table->d_discardPile += discardCard;
                        cout << table->d_p2.getName() << " hand : "; table->d_p2.printHand(cout, true); cout << endl;
                        break;
                    }
                }
            }
            // Place 3 cards into the trade area.
            for(int i = 0; i < 3 && !table->d_deck.empty(); ++i)
            {
                table->d_tradeArea += (table->d_deck.draw());
            }

            //for all the cards in the trade area, compare top card
            while(table->d_discardPile.top() != nullptr && table->d_tradeArea.legal(table->d_discardPile.top()))
            {
                table->d_tradeArea += (table->d_discardPile.pickUp());
            }

            cout << endl;
            cout << "Trade Area : "; cout << table->d_tradeArea << endl;

            if(table->d_tradeArea.numCards() != 0)
            {
                for(auto iter = table->d_tradeArea.d_types.begin(); iter != table->d_tradeArea.d_types.end();)
                {
                    cout << "Game : Do you want to add " << *iter << " to a chain?" << endl;
                    cout << table->d_p2.getName() << " : "; cin >> answer;

                    if(answer == "yes" || answer == "Yes")
                    {
                        Card* cardInTrade = table->d_tradeArea.trade(*iter);

                        while(cardInTrade != nullptr)
                        {
                            addToChain(table->d_p2, *table, -1, cardInTrade);
                            cardInTrade = table->d_tradeArea.trade(*iter);
                        }

                        iter = table->d_tradeArea.d_types.erase(iter);
                    } else {
                         ++iter;
                    }
                }
            }
            if( !table->d_deck.empty() ) {
                table->d_p2.d_hand += table->d_deck.draw();
                table->d_p2.d_hand += table->d_deck.draw();
            }
            turn = 1;
        }
    }

	if (winner == "Tie") cout << "Congratulations to the both of you!" << endl;
	else cout << "Congratulations " << winner << ". You've won!" << endl;

	delete table;
	delete players[0];
	delete players[1];

	return 0;
}