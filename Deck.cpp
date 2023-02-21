#include "Deck.h"
#include <algorithm>

Card* Deck::contains(const Card& card)
{
    std::vector<Card>::iterator iter = std::find(begin(), end(), card);
    if(iter != end())
        return &(*iter);
    else
        return nullptr;
}
