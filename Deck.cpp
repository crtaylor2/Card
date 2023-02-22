#include "Deck.h"
#include <algorithm>
#include <random>

//////////////////////////////////////////////////////////////////////
/// Searches for a Card in the Deck
///
/// Returns: Card* to the Card (if found) or nullptr (if not found)
//////////////////////////////////////////////////////////////////////
Card* Deck::contains(const Card& card)
{
    std::vector<Card>::iterator iter = std::find(begin(), end(), card);
    if(iter != end())
        return &(*iter);
    else
        return nullptr;
}

//////////////////////////////////////////////////////////////////////
/// Removes a card from the Deck, if it exists.
///
/// Returns: void
//////////////////////////////////////////////////////////////////////
void Deck::remove(const Card& card)
{
    std::vector<Card>::iterator iter = std::find(begin(), end(), card);
    if(iter != end())
        erase(iter);
}

//////////////////////////////////////////////////////////////////////
/// Loops through a Hand of cards and identifies runs of three or more
/// cards of the same suit.
///
/// Returns: void
//////////////////////////////////////////////////////////////////////
void Deck::searchForRuns()
{
    std::sort(begin(), end(), Card::CompareForRuns);
    for(int idx = 2; idx < size(); ++idx)
    {
        if((at(idx).suit == at(idx - 1).suit && at(idx - 1).suit == at(idx - 2).suit) &&
           (at(idx).value == (at(idx - 1).value + 1) && (at(idx - 1).value + 1) == (at(idx - 2).value + 2)) )
        {
            if(at(idx).meld != Card::SETMELD && at(idx - 1).meld != Card::SETMELD && at(idx - 2).meld != Card::SETMELD)
            {
                at(idx).meld = Card::RUNMELD;
                at(idx - 1).meld = Card::RUNMELD;
                at(idx - 2).meld = Card::RUNMELD;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////
/// Loops through a Hand of cards and identifies sets of three or more
/// cards with the same value
///
/// Returns: void
//////////////////////////////////////////////////////////////////////
void Deck::searchForSets()
{
    std::sort(begin(), end(), Card::CompareForSets);
    for(int idx = 2; idx < size(); ++idx)
    {
        if(at(idx).value == at(idx - 1).value && at(idx - 1).value == at(idx - 2).value)
        {
            if(at(idx).meld != Card::RUNMELD && at(idx - 1).meld != Card::RUNMELD && at(idx - 2).meld != Card::RUNMELD)
            {
                at(idx).meld = Card::SETMELD;
                at(idx - 1).meld = Card::SETMELD;
                at(idx - 2).meld = Card::SETMELD;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////
/// Creates a standard 52 card deck
///
/// Returns: void
//////////////////////////////////////////////////////////////////////
void Deck::createDeck()
{
    for(int s = Card::DIAMOND; s <= Card::SPADE; ++s)
    {
        for(int n = Card::ACE; n <= Card::KING; ++n)
        {
            push_back(Card((Card::Suit)s, (Card::Value)n));
        }
    }
}

//////////////////////////////////////////////////////////////////////
/// Shuffles the deck
///
/// Returns: void
//////////////////////////////////////////////////////////////////////
void Deck::shuffle()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(begin(), end(), g);
}

//////////////////////////////////////////////////////////////////////
/// Sorts by Sets
///
/// Returns: void
//////////////////////////////////////////////////////////////////////
void Deck::sortBySets()
{
    std::sort(begin(), end(), Card::CompareForSets);
}

//////////////////////////////////////////////////////////////////////
/// Sorts by Runs
///
/// Returns: void
//////////////////////////////////////////////////////////////////////
void Deck::sortByRuns()
{
    std::sort(begin(), end(), Card::CompareForRuns);
}
