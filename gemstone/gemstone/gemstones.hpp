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

#include <iostream>
#include <exception>

using std::string; using std::ostream;

class Card;

ostream& operator<<( ostream&, Card* );

class Card
{
public:
    // Gemstone types
    // enum Gemstone {Q = 0, H = 1, O = 2, M = 3, T = 4, R = 5, A = 6, E = 7};
    // Returns how many cards are needed for the coins
    virtual int getCardsPerCoin(int _coins) const = 0;

    // Returns the name of the card corresponding to its type
    virtual string getName() const = 0;

    // Inserts the first character for the card into the output stream supplied as argument.
    virtual void print(ostream& out) const = 0;

    // destructor
    virtual ~Card(){};

    // global stream insertion operator that prints Card name to ostream
    friend ostream& operator<<( ostream&, const Card& );

    // new exception named IllegalType
    struct IllegalType : public std::exception {
        const char * what () const throw () {
            return "Not the same gem type!";
        }
    };
};

class Quartz : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Quartz(){};
};

class Hematite : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Hematite(){};
};

class Obsidian : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Obsidian(){};
};


class Malachite : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Malachite(){};
};


class Turquoise : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Turquoise(){};
};


class Ruby : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Ruby(){};
};


class Amethyst : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Amethyst(){};
};


class Emerald : public Card
{
public:
    int getCardsPerCoin(int _coins) const;
    string getName() const;
    void print(ostream& out) const;
    ~Emerald(){};
};

#endif /* gemstones_hpp */
