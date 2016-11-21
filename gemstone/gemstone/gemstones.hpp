// ==========================================================================
//  Project : gemstone
//  File    : gemstones.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
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
protected:
    string d_name;
    string d_title;
public:
    //Constructor
    Card();
    Card(int& _name);
    //Gemstone types
    enum Gemstone {Q = 0, H = 1, O = 2, M = 3, T = 4, R = 5, A = 6, E = 7};
    //Returns how many cards are needed for the coins
    virtual int getCardsPerCoin(int _nCards);
    //Returns the name of the card corresponding to its type
    virtual string getName();
    //Inserts the first character for the card into the output stream supplied as argument.
    //virtual void print(const ostream& out);
    void setName(string _name) { d_name = _name; }
    string getTitle() { return d_title; }
};

class Quartz : public Card
{
public:
    Quartz() { Card::d_title = "Quartz"; }
};

class Hematite : public Card
{
public:
    Hematite() { Card::d_title = "Hematite"; }
};

class Obsidian : public Card
{
public:
    Obsidian() { Card::d_title = "Obsidian"; }
};


class Malachite : public Card
{
public:
    Malachite() { Card::d_title = "Malachite"; }
};


class Turquois : public Card
{
public:
    Turquois() { Card::d_title = "Turquoise"; }
};


class Ruby : public Card
{
public:
    Ruby() { Card::d_title = "Ruby"; }
};


class Amethyst : public Card
{
public:
    Amethyst() { Card::d_title = "Amethyst"; }
};


class Emerald : public Card
{
public:
    Emerald() { Card::d_title = "Emerald"; }
};


#endif /* gemstones_hpp */
