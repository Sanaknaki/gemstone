// ==========================================================================
//  Project : gemstone
//  File    : players.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================
#ifndef players_hpp
#define players_hpp

#include <stdio.h>
#include <iostream>

#include "chain.hpp"

using std::string; using std::ostream; using std::cout; using std::endl;

class Player{
    string d_name;
    int d_coin;
    int d_chain;
public:
    Player(string& _name);                                              // Player constructor
    string getName();                                                   // Return name of player
    int getNumCoins();                                                  // Return amount of coins
    Player& operator+=(int _coin);                                      // Add coins to player
    int getMaxNumChains();                                              // Get max number of chains
    int getNumChains();                                                 // Get number of chains you have
    Chain<Card>& operator[](int i);                                     // Return chain at pos i
    void buyThirdChain();                                               // Buy a third chain if allowed
    void printHand(ostream& , bool);                                    // print top card or full hand of player
};

#endif /* players_hpp */
