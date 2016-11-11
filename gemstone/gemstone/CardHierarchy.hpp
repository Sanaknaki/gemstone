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

#ifndef CardHierarchy_hpp
#define CardHierarchy_hpp

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string; using std::ostream;
/**
 * Card type
 */
struct Card
{
    string d_name;  // Card type
    int d_worth;      // Card worth for preciousness
};

class CardHierarchy
{
public:
    virtual int getCardsPerCoin(int coins);
    virtual string getName();
    virtual void print(const ostream& out);
};

class Emerald : public Card
{
public:
    Emerald(string name, int worth) : d_name(name), d_worth(worth)
    {
        
    }
};

#endif /* card_hierarchy_h */
