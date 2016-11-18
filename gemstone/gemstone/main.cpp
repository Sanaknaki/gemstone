// ==========================================================================
//  Project : gemstone
//  File    : main.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
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
    cout << "#######################" << endl;
    cout << "# WELCOME TO GEMSTONE #" << endl;
    cout << "#######################" << endl;
    
    string p1Name;
    string p2Name;
    
    cout << "Player 1 name : "; // Player 1 name input
    getline (cin, p1Name);
    
    cout << "Player 2 name : "; // Player 2 name input
    getline (cin, p2Name);
    
    Player playerOne = *new Player(p1Name);
    Player playerTwo = *new Player(p2Name);
    
    CardFactory factory = *new CardFactory();
    Deck deck = factory.getDeck();
    
    Card* drawCard;
    int i = 0;
    
    while(!deck.isEmpty())
    {
        drawCard = deck.draw();
        cout << i << endl;
        cout << "Card drawn : " << drawCard->getName()<< endl;
        i++;
    }
}
