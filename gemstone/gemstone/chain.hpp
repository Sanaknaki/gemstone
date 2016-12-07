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

#include "gemstones.hpp"
#include "cardfactory.hpp"

using std::istream; using std::ostream;
using std::vector; using std::string;
using std::cout; using std::endl;

/***********************************************************
 ***********  Chain_Base Class Implementation   ************
 ***********************************************************
*/

class Chain_Base;

ostream& operator<<( ostream&, const Chain_Base& );

class Chain_Base
{
protected:
    // Defaults to true.
    // If derived Chain<T> is created, empty = false
    bool empty = true;

public:
    // default constructor
    Chain_Base(){};

    // constructor with boolean
    Chain_Base( bool _empty ) : empty(_empty) {};

    // counts the number cards in the current chain and returns the number
    // coins according to the function Card::getCardsPerCoin
    virtual int sell() const
    {
        cout << "Nothing in Chain!" << endl;
        return 0;
    };

    // prints the Chain_Base to ostream
    virtual void print( ostream& _os ) const
    {
        _os << "Empty" << endl;
    };

    // Returns true if object is of Chain_Base.
    // Returns false if object is of Chain<T>.
    bool isEmpty() const
    {
        return empty;
    };

    // returns this object because Chain<T> has not been initialized
    virtual Chain_Base& operator+=( Card* _card )
    {
        cout << "Must start Chain!" << endl;
        return *this;
    };

    // insertion operator using "Virtual Friend Function Idiom"
    friend ostream& operator<<( ostream& _os, const Chain_Base& _chain )
    {
        _chain.print( _os );
        return _os;
    };

    // destructor
    virtual ~Chain_Base(){};
};


/***************************************************************
 **********  Class Template Chain<T> Implementation  ***********
 ***************************************************************
 */

template <class T>
class Chain : public Chain_Base
{
    // Chain will hold the T type cards by pointer in a vector<T*>
    vector<T*> d_cards;

public:
    // default constructor
    Chain() : Chain_Base(false) {};

    // istream constructor
    Chain( istream& _is, CardFactory* _cardPool ) : Chain_Base(false)
    {
        char card;
        // get individual white space seperated tokens
        while( _is >> card ) {
            *this += ( _cardPool->getPtr(card) );
        }
    }

    // Adds a Card to the Chain.
    // If the run-time type does not match the template type of the chain,
    // an exception of type IllegalType is raised.
    Chain_Base& operator+=( Card* _card )
    {
        T* cardT;
        cardT = dynamic_cast<T*>( _card );
        // check if conversion worked
        if ( cardT == 0 ) {
            throw Card::IllegalType();
            return *this;
        }
        // conversion successful!
        else {
            d_cards.push_back( cardT );
            return *this;
        }
    }

    // using binary search to determine amount of coins to return
    int sell() const
    {
        int chainLength = d_cards.size(); // store Chain size in temp variable
        T* card = d_cards.front(); // store top card of Chain to determine CardsPerCoin
        // if chain worth less than 2 coins
        if( chainLength < card->getCardsPerCoin(2) ) {
            // if chain worth less than 1 coin
            if( chainLength < card->getCardsPerCoin(1) ) return 0;
            else return 1;
        }
        // chain worth 2 or more coins
        else {
            // if chain worth less than 3 coins
            if( chainLength < card->getCardsPerCoin(3) ) return 2;
            else {
                // if chain worth less than 4 coins
                if( chainLength < card->getCardsPerCoin(4) ) return 3;
                else return 4;
            }
        }
    }

    // prints Chain<T> to ostream
    void print( ostream& _os ) const
    {
        _os << d_cards.front()->getName() << "\t"; // prints Chain type
        for( auto card : d_cards ) { // prints Cards in Chain
            card->print( _os );
            _os << " ";
        }
        _os << endl;
    }

    ~Chain(){}; // default destructor
};

#endif /* chain_h */
