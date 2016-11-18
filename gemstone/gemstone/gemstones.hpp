// ==========================================================================
//  Project : gemstone
//  File    : gemstones.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (#######)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef gemstones_hpp
#define gemstones_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using std::string; using std::ostream;

class Card{
    string d_name;
public:
    //Constructor
    Card();
    Card(int& _name);
    //Gemstone types
    enum Gemstone {Q = 0, H = 1, O = 2, M = 3, T = 4, R = 5, A = 6, E = 7};
    //Returns how many cards are needed for the coins
    virtual int getCardsPerCoin(int _coins);
    //Returns the name of the card corresponding to its type
    virtual string getName();
    //Inserts the first character for the card into the output stream supplied as argument.
    //virtual void print(const ostream& out);
};

#endif /* gemstones_hpp */
