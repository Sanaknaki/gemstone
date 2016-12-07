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
int Quartz::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 1: return 4; break;
        case 2: return 6; break;
        case 3: return 8; break;
        case 4: return 10; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Quartz::getName()          { return "Quartz"; }

// Print it's 'type' letter.
void Quartz::print(ostream & out) { out << "Q"; }

/***************************************/

/***** HEMATITE IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Hematite::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 1: return 3; break;
        case 2: return 6; break;
        case 3: return 8; break;
        case 4: return 9; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Hematite::getName()         { return "Hematite"; }

// Print it's 'type' letter.
void Hematite::print(ostream &out) { out << "H"; }

/*******************************************/

/***** OBSIDIAN IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Obsidian::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 1: return 3; break;
        case 2: return 5; break;
        case 3: return 7; break;
        case 4: return 8; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Obsidian::getName()         { return "Obsidian"; }

// Print it's 'type' letter.
void Obsidian::print(ostream &out) { out << "O"; }

/*******************************************/

/***** MALACHITE IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Malachite::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 1: return 3; break;
        case 2: return 5; break;
        case 3: return 6; break;
        case 4: return 7; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Malachite::getName()         { return "Malachite"; }

// Print it's 'type' letter.
void Malachite::print(ostream &out) { out << "M"; }

/********************************************/

/***** TURQUOISE IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Turquoise::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 1: return 2; break;
        case 2: return 4; break;
        case 3: return 6; break;
        case 4: return 7; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Turquoise::getName()         { return "Turquoise"; }

// Print it's 'type' letter.
void Turquoise::print(ostream &out) { out << "T"; }

/********************************************/

/***** RUBY IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Ruby::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 1: return 2; break;
        case 2: return 4; break;
        case 3: return 5; break;
        case 4: return 6; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Ruby::getName()         { return "Ruby"; }

// Print it's 'type' letter.
void Ruby::print(ostream &out) { out << "R"; }

/****************************************/

/***** AMETHYST IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Amethyst::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 1: return 2; break;
        case 2: return 3; break;
        case 3: return 4; break;
        case 4: return 5; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Amethyst::getName()         { return "Amethyst"; }

// Print it's 'type' letter.
void Amethyst::print(ostream &out) { out << "A"; }

/*******************************************/

/***** EMERALD IMPLEMENTATION (START) *****/

// Return minimum amount of cards needed to earn given amount of coins.
int Emerald::getCardsPerCoin(int _coins)
{
    switch ( _coins ) {
        case 2: return 2; break;
        case 3: return 3; break;
        default: cout << "Invalid coin entry!" << endl;
    }
    return 0; // default returns 0
}

// Get the name of the card.
string Emerald::getName()         { return "Emerald"; }

// Print it's 'type' letter.
void Emerald::print(ostream &out) { out << "E"; }

/******************************************/

// global stream insertion operator
ostream& operator<<( ostream& _os, Card* _card )
{
    _os << ( _card->getName() );
    return _os;
}
