// ==========================================================================
//  Project : gemstone
//  File    : players.cpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#include "players.hpp"

using namespace std;

// constructor
Player::Player( const string& _name ) : d_name( _name ) {}

// destructor
Player::~Player()
{
    for( auto chain : d_chains ) delete chain;
}

// return the name of the player
string Player::getName() const
{
    return d_name;
}

// return the amount of coins a player has
int Player::getNumCoins() const
{
    return d_coin;
}

// add coins to a player
Player& Player::operator+=( int _coin )
{
    this->d_coin += _coin;
    return *this;
}

// get the max number of chains
int Player::getMaxNumChains() const
{
    return d_chains.size();
}

// Get the number of chains a player has.
// Counts how many chain_Base are not empty in d_chains.
// Execution takes O(1) time
int Player::getNumChains() const
{
    int numChains = 0;
    for( auto chainRef : d_chains ) {
        if( !chainRef->isEmpty() ) ++numChains;
    }
    return numChains;
}

// Return chain at position i.
// Vector throws out_of_bounds exception if invalid index is given.
Chain_Base& Player::operator[]( int i )
{
    return *( d_chains.at(i) );
}

// buy a third chain if possible
void Player::buyThirdChain()
{
    if( d_coin >= 3 && d_chains.size() == 2 ) {
        d_coin -=3;
        d_chains.push_back( new Chain_Base() ); // push empty Chain to d_chains
        cout << this->d_name << " has bought their 3rd chain!" << endl;
    }
    else if(d_coin < 3) {
        cout << "ERROR : Not enough coins to buy the chain!" << endl;
    }
    else if (d_chains.size() == 3) {
        cout << "ERROR : You already have 3 chains!" << endl;
    }
}

// print top card or full hand of player
void Player::printHand( ostream& _os, const bool fullHand ) const
{   // prints top card only
    if( !fullHand ) {
        Card* topCard = d_hand.top();
        topCard->print( _os );
    }
    else _os << d_hand; // prints all of d_hand
}

/*
 *  Insertion operator to print a Player to an ostream.
 *  The player's name, the number of coins in the player's possession and each
 *  of the chains (2 or 3, some possibly empty) should be printed. Note that the
 *  Hand is printed with a separate function above.
 */
ostream& operator<<( ostream& _os, const Player& _p )
{   // print name and number of coins
    _os << _p.d_name << " " << _p.d_coin << " coin";
    if( _p.d_coin != 1 ) _os << "s";
    _os << endl;
    // print chains
    _os << "Chains" << endl;
    int i = 0;
    for( auto chain : _p.d_chains ) _os << *chain;
    _os << endl;
    return _os;
}

// constructor which accepts an istream and reconstructs the Player from file
Player::Player( istream& _is, CardFactory* _cardPool ) : d_chains{}
{
    _is >> d_name >> d_coin; // line containing name and # of coins
    string temp, token, line;
    _is >> temp; // remove "coin(s)" from _is
    while( getline( _is, line ) ) { // lines containing chain and hand
        istringstream streamLine(line);
        while( streamLine >> token ) {
            // if Hand is read, build Hand with streamLine
            if( token == "Hand" ) {
                d_hand = Hand( streamLine, _cardPool ); break;
            }
            // if Empty is read, build Chain_Base
            else if( token == "Empty" ) {
                d_chains.push_back( new Chain_Base() ); break;
            }
            // otherwise, Chain is read with type stored in token and cards in streamLine
            else d_chains.push_back( getChainTemplate( token, streamLine, _cardPool ) ); break;
        }
        if( token == "Hand" ) break;
    }
}

// starts a Chain at given index i
void Player::startChain( const int i, Card* _card )
{
    // delete empty Chain_Base
    delete d_chains[i];
    // get Chain type
    string type = _card->getName();
    // return Chain template
    Chain_Base* newChain;
    if( type == "Quartz" ) newChain = new Chain<Quartz>();
    else if( type == "Hematite" ) newChain = new Chain<Hematite>();
    else if( type == "Obsidian" ) newChain = new Chain<Obsidian>();
    else if( type == "Malachite" ) newChain = new Chain<Malachite>();
    else if( type == "Turquoise" ) newChain = new Chain<Turquoise>();
    else if( type == "Ruby" ) newChain = new Chain<Ruby>();
    else if( type == "Amethyst" ) newChain = new Chain<Amethyst>();
    else newChain = new Chain<Emerald>();
    // add Card to returning Chain template
    (*newChain) += _card;
    d_chains[i] = newChain;
    cout << "New Chain: " << *newChain << endl;
    cout << *d_chains[i] << endl;
}

// getter for Chain template istream constructor
Chain_Base* Player::getChainTemplate( const string _type, istream& _is, CardFactory* _cardPool )
{
    if( _type == "Quartz" ) return new Chain<Quartz>( _is, _cardPool );
    else if( _type == "Hematite" ) return new Chain<Hematite>( _is, _cardPool );
    else if( _type == "Obsidian" ) return new Chain<Obsidian>( _is, _cardPool );
    else if( _type == "Malachite" ) return new Chain<Malachite>( _is, _cardPool );
    else if( _type == "Turquoise" ) return new Chain<Turquoise>( _is, _cardPool );
    else if( _type == "Ruby" ) return new Chain<Ruby>( _is, _cardPool );
    else if( _type == "Amethyst" ) return new Chain<Amethyst>( _is, _cardPool );
    else return new Chain<Emerald>( _is, _cardPool );
}
