// ==========================================================================
//  Project : gemstone
//  File    : chain.hpp
//  Student : Ali Sanaknaki (7745880)
//  Student : Peter Doan (6842312)
//
//  Github  : http://www.github.com/sanaknaki/gemstone
// ==========================================================================
//  Copyright © 2016 commitCommittee. All rights reserved.
// ==========================================================================

#ifndef chain_h
#define chain_h

#include <stdio.h>
#include <vector>
#include <exception>

#include "gemstones.hpp"
#include "cardfactory.hpp"

using namespace std;

/***********************************************************
 ***********  Chain_Base Class Implementation   ************
 ***********************************************************
*/

class Chain_Base;

ostream& operator<<( ostream&, const Chain_Base& );

class Chain_Base {
protected:
    string d_type; // Chain type
public:
    // virtual functions
    virtual int sell() const {
        cout << "Nothing in Chain!" << endl;
        return 0;
    };
    virtual void print( ostream& _os ) {
        _os << "Empty" << endl;
    };
    // implemented after class template Chain is initialized
    virtual Chain_Base& operator+=( Card* _card );

    friend ostream& operator<<( ostream&, Chain_Base& );

    // new exception named IllegalType
    // followed "Define New Exceptions" in address below
    // https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
    struct IllegalType : public exception {
        const char * what () const throw () {
            return "Chain and Card are not of the same gem type!";
        }
    };
};

ostream& operator<<( ostream& _os, Chain_Base& _chain ) {
    _chain.print( _os );
    return _os;
}


/***************************************************************
 **********  Class Template Chain<T> Implementation  ***********
 ***************************************************************
 */

template <class T>
class Chain : protected Chain_Base {
private:
    // Chain will hold the T type cards by pointer in a vector<T*>
    vector<T*> d_cards;
public:
    // default constructor
    Chain(){};

    // istream constructor
    Chain( istream& _is, CardFactory* _cardPool )
    {
        char card;
        // get individual white space seperated tokens
        while( _is >> card ) {
            d_cards.push( dynamic_cast<T*>( _cardPool->getPtr(card) ) );
        }
    }

    Chain_Base& operator+=( Card* _card )
    {
        T* cardT;
        // try to convert _card to T type card
        try {
            cardT = dynamic_cast<T*>( _card );
            // check if conversion worked
            if ( cardT == 0 ) throw IllegalType();
        } catch ( IllegalType& e ) { // conversion didn't work!
            cout << e.what() << endl;
            return *this;
        }
        // conversion successful!
        d_cards.push_back( cardT );
        return *this;
    }

    // using binary search to determine amount of coins to return
    int sell() const
    {
        int chainLength = d_cards.size();
        // if chain worth less than 2 coins
        if( chainLength < T::getCardsPerCoin(2) ) {
            // if chain worth less than 1 coin
            if( chainLength < T::getCardsPerCoin(1) ) return 0;
            else return 1;
        }
        // chain worth 2 or more coins
        else {
            // if chain worth less than 3 coins
            if( chainLength < T::getCardsPerCoin(3) ) return 2;
            else {
                // if chain worth less than 4 coins
                if( chainLength < T::getCardsPerCoin(4) ) return 3;
                else return 4;
            }
        }
    }

    void print( ostream& _os )
    {
        // print gem type
        _os << d_cards.front()->getName() << "\t";
        for( auto card : d_cards ) {
            card->print( _os );
            _os << " ";
        }
        _os << endl;
    }
};

Chain_Base& Chain_Base::operator+=( Card* _card ) {
    Chain_Base* newChain;
    string type = _card->getName();
    if( type == "Quartz" ) newChain = new Chain<Quartz>();
    else if( type == "Hematite" ) newChain = new Chain<Hematite>();
    else if( type == "Obsidian" ) newChain = new Chain<Obsidian>();
    else if( type == "Malachite" ) newChain = new Chain<Malachite>();
    else if( type == "Turquoise" ) newChain = new Chain<Turquoise>();
    else if( type == "Ruby" ) newChain = new Chain<Ruby>();
    else if( type == "Amethyst" ) newChain = new Chain<Amethyst>();
    else if( type == "Emerald" ) newChain = new Chain<Emerald>();
    return (*newChain) += _card;
}

#endif /* chain_h */
