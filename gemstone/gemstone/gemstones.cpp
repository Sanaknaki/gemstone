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

using std::cout; using std::endl; using std::string;

/*
string Card::getName()
{
    return d_title;
}

int Card::getCardsPerCoin(int _nCards)
{
    if(_nCards == 0) // Initial check for card count
    {
        return 0;
    }
    
    if(getTitle() == "Quartz") // Quartz card coin worth
    {
        if(_nCards < 4)                    { return 0; }
        if(_nCards >= 4 && _nCards <= 5)   { return 1; }
        if(_nCards >= 6 && _nCards <= 7)   { return 2; }
        if(_nCards >= 8 && _nCards <= 9)   { return 3; }
        if(_nCards >= 10)                  { return 4; }
        else return 0;
    }
    
    if(getTitle() == "Hematite") // Hematite card coin worth
    {
        if(_nCards < 3)                    { return 0; }
        if(_nCards >= 3 && _nCards <= 5)   { return 1; }
        if(_nCards >= 6 && _nCards <= 7)   { return 2; }
        if(_nCards == 8)                   { return 3; }
        if(_nCards >= 9)                   { return 4; }
        else return 0;
    }
    
    if(getTitle() == "Obsidian") // Obsidian card coin worth
    {
        if(_nCards < 3)                    { return 0; }
        if(_nCards >= 3 && _nCards <= 4)   { return 1; }
        if(_nCards >= 5 && _nCards <= 6)   { return 2; }
        if(_nCards == 7)                   { return 3; }
        if(_nCards >= 8)                   { return 4; }
        else return 0;
    }
    
    if(getTitle() == "Malachite") // Malachite card coin worth
    {
        if(_nCards < 3)                    { return 0; }
        if(_nCards >= 3 && _nCards <= 4)   { return 1; }
        if(_nCards == 5)                   { return 2; }
        if(_nCards == 6)                   { return 3; }
        if(_nCards >= 7)                   { return 4; }
        else return 0;
    }
    
    if(getTitle() == "Turquoise") // Turquoise card coin worth
    {
        if(_nCards < 2)                    { return 0; }
        if(_nCards >= 2 && _nCards <= 3)   { return 1; }
        if(_nCards >= 4 && _nCards <= 5)   { return 2; }
        if(_nCards == 6)                   { return 3; }
        if(_nCards >= 7)                   { return 4; }
        else return 0;
    }
    
    if(getTitle() == "Ruby") // Ruby card coin worth
    {
        if(_nCards < 2)                    { return 0; }
        if(_nCards >= 2 && _nCards <= 3)   { return 1; }
        if(_nCards == 4)                   { return 2; }
        if(_nCards == 5)                   { return 3; }
        if(_nCards >= 6)                   { return 4; }
        else return 0;
    }
    
    if(getTitle() == "Amethyst") // Amethyst card coin worth
    {
        if(_nCards < 2)                    { return 0; }
        if(_nCards == 2)                   { return 1; }
        if(_nCards == 3)                   { return 2; }
        if(_nCards == 4)                   { return 3; }
        if(_nCards >= 5)                   { return 4; }
        else return 0;
    }
    
    if(getTitle() == "Emerald") // Emerald card coin worth
    {
        if(_nCards < 2)                    { return 0; }
        if(_nCards == 2)                   { return 2; }
        if(_nCards >= 3)                   { return 3; }
        else return 0;
    }
    
    else return 0;
}*/

/***** QUARTZ IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Quartz::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 3)      { return 0; }
    else if(_nCards <= 5) { return 1; }
    else if(_nCards <= 7) { return 2; }
    else if(_nCards <= 9) { return 3; }
    else                  { return 4; }
}

// Get the name of the card.
string Quartz::getName()          { return "Quartz"; }

// Print it's 'type' letter.
void Quartz::print(ostream & out) { out << "Q"; }

/***************************************/

/***** HEMATITE IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Hematite::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 2)      { return 0; }
    else if(_nCards <= 5) { return 1; }
    else if(_nCards <= 7) { return 2; }
    else if(_nCards == 8) { return 3; }
    else                  { return 4; }
}

// Get the name of the card.
string Hematite::getName()         { return "Hematite"; }

// Print it's 'type' letter.
void Hematite::print(ostream &out) { out << "H"; }

/*******************************************/

/***** OBSIDIAN IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Obsidian::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 2)      { return 0; }
    else if(_nCards <= 4) { return 1; }
    else if(_nCards <= 6) { return 2; }
    else if(_nCards == 7) { return 3; }
    else                  { return 4; }
}

// Get the name of the card.
string Obsidian::getName()         { return "Obsidian"; }

// Print it's 'type' letter.
void Obsidian::print(ostream &out) { out << "O"; }

/*******************************************/

/***** MALACHITE IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Malachite::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 2)      { return 0; }
    else if(_nCards <= 4) { return 1; }
    else if(_nCards == 5) { return 2; }
    else if(_nCards == 6) { return 3; }
    else                  { return 4; }
}

// Get the name of the card.
string Malachite::getName()         { return "Malachite"; }

// Print it's 'type' letter.
void Malachite::print(ostream &out) { out << "M"; }

/********************************************/

/***** TURQUOISE IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Turquoise::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 1)      { return 0; }
    else if(_nCards <= 3) { return 1; }
    else if(_nCards <= 5) { return 2; }
    else if(_nCards == 6) { return 3; }
    else                  { return 4; }
}

// Get the name of the card.
string Turquoise::getName()         { return "Turquoise"; }

// Print it's 'type' letter.
void Turquoise::print(ostream &out) { out << "T"; }

/********************************************/

/***** RUBY IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Ruby::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 1)      { return 0; }
    else if(_nCards <= 3) { return 1; }
    else if(_nCards == 4) { return 2; }
    else if(_nCards == 5) { return 3; }
    else                  { return 4; }
}

// Get the name of the card.
string Ruby::getName()         { return "Ruby"; }

// Print it's 'type' letter.
void Ruby::print(ostream &out) { out << "R"; }

/****************************************/

/***** AMETHYST IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Amethyst::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 1)      { return 0; }
    else if(_nCards == 2) { return 1; }
    else if(_nCards == 3) { return 2; }
    else if(_nCards == 4) { return 3; }
    else                  { return 4; }
}

// Get the name of the card.
string Amethyst::getName()         { return "Amethyst"; }

// Print it's 'type' letter.
void Amethyst::print(ostream &out) { out << "A"; }

/*******************************************/

/***** EMERALD IMPLEMENTATION (START) *****/

// Return the amount of carsd earned for '_nCards' amount of a card.
int Emerald::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards < 2)       { return 0; }
    else if(_nCards == 2) { return 2; }
    else                  { return 3; }
}

// Get the name of the card.
string Emerald::getName()         { return "Emerald"; }

// Print it's 'type' letter.
void Emerald::print(ostream &out) { out << "E"; }

/******************************************/
