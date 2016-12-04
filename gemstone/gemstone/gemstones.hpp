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
public:
    // Gemstone types
    // enum Gemstone {Q = 0, H = 1, O = 2, M = 3, T = 4, R = 5, A = 6, E = 7};
    // Returns how many cards are needed for the coins
    virtual int getCardsPerCoin(int _coins) = 0;
    // Returns the name of the card corresponding to its type
    virtual string getName() = 0;
    // Inserts the first character for the card into the output stream supplied as argument.
    virtual void print(ostream& out) = 0;
};

class Quartz : public Card
{
public:
    // Quartz() { Card::d_title = "Quartz"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};

class Hematite : public Card
{
public:
    // Hematite() { Card::d_title = "Hematite"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};

class Obsidian : public Card
{
public:
    // Obsidian() { Card::d_title = "Obsidian"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};


class Malachite : public Card
{
public:
    // Malachite() { Card::d_title = "Malachite"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};


class Turquoise : public Card
{
public:
    // Turquois() { Card::d_title = "Turquoise"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};


class Ruby : public Card
{
public:
    // Ruby() { Card::d_title = "Ruby"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};


class Amethyst : public Card
{
public:
    // Amethyst() { Card::d_title = "Amethyst"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};


class Emerald : public Card
{
public:
    // Emerald() { Card::d_title = "Emerald"; }
    int getCardsPerCoin(int _coins);
    string getName();
    void print(ostream& out);
};

#endif /* gemstones_hpp */
