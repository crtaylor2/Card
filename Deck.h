#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck : public std::vector<Card>
{
    public:
        Card* contains(const Card& card);
        void remove(const Card& card);
};

using Hand = Deck;

#endif
