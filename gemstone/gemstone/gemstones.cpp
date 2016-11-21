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
Card::Card(){}

Card::Card(int& _name) : d_name("")
{
    if(_name == Gemstone::Q)     { Quartz quartz; quartz.setName("Q"); }
    else if(_name == Gemstone::H){ Hematite hematite; hematite.setName("H"); }
    else if(_name == Gemstone::O){ Obsidian obsidian; obsidian.setName("O"); }
    else if(_name == Gemstone::M){ Malachite malachite; malachite.setName("M"); }
    else if(_name == Gemstone::T){ Turquois turquois; turquois.setName("T"); }
    else if(_name == Gemstone::R){ Ruby ruby; ruby.setName("R"); }
    else if(_name == Gemstone::A){ Amethyst amethyst; amethyst.setName("A"); }
    else                         { Emerald emerald; emerald.setName("E");}
}

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
}
