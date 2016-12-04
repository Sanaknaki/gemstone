// ==========================================================================
//  Project : gemstone
//  File    : players.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef players_hpp
#define players_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>

#include "chain.hpp"
#include "hand.hpp"

using std::string; using std::ostream; using std::cout; using std::endl;

class Player;

ostream& operator<<( ostream&, const Player& );

class Player{
    string d_name;
    int d_coin = 0; // default
    int d_chain = 2; // default
    Hand d_hand;
    //Chain chain;
public:

    // Player has a hand.
    // Hand hand;

    // default constructor
    Player();

    // Constructor.
    Player(string& _name);

    // constructor from istream
    Player( istream&, CardFactory* );

    // Return the name of the player.
    string getName() const;

    // Return the amount of coins a player has.
    int getNumCoins() const;

    // Add coins to a player.
    Player& operator+=(int _coin);

    // Get the max number of chains.
    int getMaxNumChains() const;

    // Get the number of chains a player has.
    int getNumChains() const;

    // Return chain a position i.
    Chain<Card>& operator[](int i);

    // Buy a third chain if possible.
    void buyThirdChain();

    // Print top card of full hand of player.
    void printHand(ostream& , const bool) const;

    // insertion operator to print a Player to an ostream
    friend ostream& operator<<( ostream&, Player& );
};

#endif /* players_hpp */
