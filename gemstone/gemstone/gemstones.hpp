// ==========================================================================
//  Project : gemstone
//  File    : card-hierarchy.hpp
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

enum Gemstone                                                           // Enumerator for the gemstone types
{
    Q,
    H,
    O,
    M,
    T,
    R,
    A,
    E
};

class Card{
private:
    
public:
    virtual int getCardsPerCoin(int coins);                             // Returns how many cards are needed for the coins
    virtual string getName();                                           // Returns the name of the card corresponding to its type
    virtual void print(const ostream& out);                             // Inserts the first character for the card into the output stream supplied as argument.
};

#endif /* gemstones_hpp */
