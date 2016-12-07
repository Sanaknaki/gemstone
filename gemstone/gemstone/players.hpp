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

using namespace std;

class Player;

ostream& operator<<( ostream&, const Player& );

class Player {
    string d_name;
    int d_coin = 0; // default
    /*
     *  Default to 2 empty chains.
     *  vector will always hold at least 2 Chain_Base pointers,
     *  whether they are empty or not.
     */
    vector<Chain_Base*> d_chains { new Chain_Base(), new Chain_Base() };
    Hand d_hand;
public:

    // Player has a hand.
    // Hand hand;

    // default constructor
    Player();

    // Constructor.
    Player(string& _name);

    // constructor from istream
    Player( istream&, CardFactory* );

    // destructor
    ~Player();

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
    Chain_Base& operator[](int i);

    // Buy a third chain if possible.
    void buyThirdChain();

    // Print top card of full hand of player.
    void printHand(ostream& , const bool) const;

    // insertion operator to print a Player to an ostream
    friend ostream& operator<<( ostream&, const Player& );

    // creates Chain template
    Chain_Base* startChain( int i, Card* _card );

    // getter for Chain template istream constructor
    Chain_Base* getChainTemplate( string _type, istream& _is, CardFactory* _cardPool);
};

#endif /* players_hpp */
