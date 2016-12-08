// ==========================================================================
//  Project : gemstone
//  File    : gemstones.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "gemstones.hpp"

using namespace std;

/***** QUARTZ IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Quartz::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 4;
        case 2: return 6;
        case 3: return 8;
        case 4: return 10;
		default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Quartz::getName() const { return "Quartz"; }

// Print it's 'type' letter.
void Quartz::print(ostream & out) const { out << "Q"; }

/***************************************/

/***** HEMATITE IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Hematite::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 3;
        case 2: return 6;
        case 3: return 8;
        case 4: return 9;
        default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Hematite::getName() const { return "Hematite"; }

// Print it's 'type' letter.
void Hematite::print(ostream &out) const { out << "H"; }

/*******************************************/

/***** OBSIDIAN IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Obsidian::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 3;
        case 2: return 5;
        case 3: return 7;
        case 4: return 8;
        default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Obsidian::getName() const { return "Obsidian"; }

// Print it's 'type' letter.
void Obsidian::print(ostream &out) const { out << "O"; }

/*******************************************/

/***** MALACHITE IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Malachite::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 3;
        case 2: return 5;
        case 3: return 6;
        case 4: return 7;
        default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Malachite::getName() const { return "Malachite"; }

// Print it's 'type' letter.
void Malachite::print(ostream &out) const { out << "M"; }

/********************************************/

/***** TURQUOISE IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Turquoise::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 6;
        case 4: return 7;
        default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Turquoise::getName() const { return "Turquoise"; }

// Print it's 'type' letter.
void Turquoise::print(ostream &out) const { out << "T"; }

/********************************************/

/***** RUBY IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Ruby::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 2;
        case 2: return 4;
        case 3: return 5;
        case 4: return 6;
        default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Ruby::getName() const { return "Ruby"; }

// Print it's 'type' letter.
void Ruby::print(ostream &out) const { out << "R"; }

/****************************************/

/***** AMETHYST IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Amethyst::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 2;
        case 2: return 3;
        case 3: return 4;
        case 4: return 5;
        default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Amethyst::getName() const { return "Amethyst"; }

// Print it's 'type' letter.
void Amethyst::print(ostream &out) const { out << "A"; }

/*******************************************/

/***** EMERALD IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Emerald::getCardsPerCoin(int _coins) const
{
    switch ( _coins ) {
        case 1: return 2;
        case 2: return 2;
        case 3: return 3;
        case 4: return 7;
        default: break;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Emerald::getName() const { return "Emerald"; }

// Print it's 'type' letter.
void Emerald::print(ostream &out) const { out << "E"; }

/******************************************/

// global stream insertion operator
ostream& operator<<( ostream& _os, const Card& _card )
{
    _card.print( _os );
    return _os;
}
