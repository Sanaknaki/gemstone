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
int Quartz::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 3)      { return 0; }
    else if(_nCards <= 5) { return 1; }
    else if(_nCards <= 7) { return 2; }
    else if(_nCards <= 9) { return 3; }
    else                  { return 4; }
}

string Quartz::getName()          { return "Quartz"; }
void Quartz::print(ostream & out) { out << "Q"; }
/***************************************/

/***** HEMATITE IMPLEMENTATION (START) *****/
int Hematite::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 2)      { return 0; }
    else if(_nCards <= 5) { return 1; }
    else if(_nCards <= 7) { return 2; }
    else if(_nCards == 8) { return 3; }
    else                  { return 4; }
}

string Hematite::getName()         { return "Hematite"; }
void Hematite::print(ostream &out) { out << "H"; }
/*******************************************/

/***** OBSIDIAN IMPLEMENTATION (START) *****/
int Obsidian::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 2)      { return 0; }
    else if(_nCards <= 4) { return 1; }
    else if(_nCards <= 6) { return 2; }
    else if(_nCards == 7) { return 3; }
    else                  { return 4; }
}

string Obsidian::getName()         { return "Obsidian"; }
void Obsidian::print(ostream &out) { out << "O"; }
/*******************************************/

/***** MALACHITE IMPLEMENTATION (START) *****/
int Malachite::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 2)      { return 0; }
    else if(_nCards <= 4) { return 1; }
    else if(_nCards == 5) { return 2; }
    else if(_nCards == 6) { return 3; }
    else                  { return 4; }
}

string Malachite::getName()         { return "Malachite"; }
void Malachite::print(ostream &out) { out << "M"; }
/********************************************/

/***** TURQUOISE IMPLEMENTATION (START) *****/
int Turquoise::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 1)      { return 0; }
    else if(_nCards <= 3) { return 1; }
    else if(_nCards <= 5) { return 2; }
    else if(_nCards == 6) { return 3; }
    else                  { return 4; }
}

string Turquoise::getName()         { return "Turquoise"; }
void Turquoise::print(ostream &out) { out << "T"; }
/********************************************/

/***** RUBY IMPLEMENTATION (START) *****/
int Ruby::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 1)      { return 0; }
    else if(_nCards <= 3) { return 1; }
    else if(_nCards == 4) { return 2; }
    else if(_nCards == 5) { return 3; }
    else                  { return 4; }
}

string Ruby::getName()         { return "Ruby"; }
void Ruby::print(ostream &out) { out << "R"; }
/****************************************/

/***** AMETHYST IMPLEMENTATION (START) *****/
int Amethyst::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards <= 1)      { return 0; }
    else if(_nCards == 2) { return 1; }
    else if(_nCards == 3) { return 2; }
    else if(_nCards == 4) { return 3; }
    else                  { return 4; }
}

string Amethyst::getName()         { return "Amethyst"; }
void Amethyst::print(ostream &out) { out << "A"; }
/*******************************************/

/***** EMERALD IMPLEMENTATION (START) *****/
int Emerald::getCardsPerCoin(int _nCards)
{
    if(_nCards < 0)       { cout << "Error : Number of cards must be positive!" << endl; return 0; }
    if(_nCards < 2)       { return 0; }
    else if(_nCards == 2) { return 2; }
    else                  { return 3; }
}

string Emerald::getName()         { return "Emerald"; }
void Emerald::print(ostream &out) { out << "E"; }
/******************************************/
