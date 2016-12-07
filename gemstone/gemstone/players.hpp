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

#include <iostream>
#include <sstream>

#include "chain.hpp"
#include "hand.hpp"

using std::istream; using std::ostream; using std::vector;

class Player;

ostream& operator<<( ostream&, const Player& );

class Player
{
    string d_name;
    int d_coin = 0;
    // Default to 2 empty chains.
    // Vector will always hold at least 2 Chain_Base pointers,
    // whether they are of Chain_Base or Chain<T>.
    vector<Chain_Base*> d_chains { new Chain_Base(), new Chain_Base() };

public:
    // Hand public variable
    Hand d_hand;

    // default constructor
    Player(){};

    // constructor
    Player( const string& _name );

    // constructor from istream
    Player( istream&, CardFactory* );

    // destructor
    ~Player();

    // return the name of the player
    string getName() const;

    // return the amount of coins a player has
    int getNumCoins() const;

    // add coins to a player
    Player& operator+=( int _coin );

    // get the max number of chains
    int getMaxNumChains() const;

    // get the number of chains a player has
    int getNumChains() const;

    // return chain a position i
    Chain_Base& operator[](int i);

    //bBuy a third chain if possible
    void buyThirdChain();

    // print top card of full hand of player
    void printHand( ostream& , const bool ) const;

    // insertion operator to print a Player to an ostream
    friend ostream& operator<<( ostream&, const Player& );

    // creates Chain template at given index
    void startChain( const int i, Card* _card );

    // getter for Chain template istream constructor
    Chain_Base* getChainTemplate( const string _type, istream& _is, CardFactory* _cardPool);
};

#endif /* players_hpp */
