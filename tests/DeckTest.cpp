#include "Deck.h"

#include <gtest/gtest.h>

TEST(DeckNotContainsTest, DeckNotContainsTest)
{
    Card c1(Card::DIAMOND, Card::EIGHT);
    Card c2(Card::SPADE, Card::ACE);
    Card c3(Card::CLUB, Card::KING);
    Card c4(Card::HEART, Card::SIX);

    Deck testDeck;
    testDeck.push_back(c1);
    testDeck.push_back(c2);

    EXPECT_EQ(testDeck.contains(c3), nullptr);
    EXPECT_EQ(testDeck.contains(c4), nullptr);
}

TEST(DeckContainsTest, DeckContainsTest)
{
    Card c1(Card::DIAMOND, Card::EIGHT);
    Card c2(Card::SPADE, Card::ACE);
    Card c3(Card::CLUB, Card::KING);
    Card c4(Card::HEART, Card::SIX);

    Deck testDeck;
    testDeck.push_back(c1);
    testDeck.push_back(c2);

    EXPECT_EQ(*testDeck.contains(c1), c1);
    EXPECT_EQ(*testDeck.contains(c2), c2);
}

TEST(SearchForRunsTest, SearchForRuns)
{
    Hand hand;
    hand.push_back(Card(Card::SPADE, Card::ACE)); // Run 1
    hand.push_back(Card(Card::SPADE, Card::TWO)); // Run 1
    hand.push_back(Card(Card::SPADE, Card::THREE)); // Run 1
    hand.push_back(Card(Card::CLUB, Card::FOUR));
    hand.push_back(Card(Card::DIAMOND, Card::FIVE)); // Run 2
    hand.push_back(Card(Card::DIAMOND, Card::SIX)); // Run 2
    hand.push_back(Card(Card::DIAMOND, Card::SEVEN)); // Run 2
    hand.push_back(Card(Card::CLUB, Card::EIGHT));
    hand.push_back(Card(Card::CLUB, Card::NINE));
    hand.push_back(Card(Card::SPADE, Card::TEN)); // Run 3
    hand.push_back(Card(Card::SPADE, Card::JACK)); // Run 3
    hand.push_back(Card(Card::SPADE, Card::QUEEN)); // Run 3
    hand.push_back(Card(Card::SPADE, Card::KING)); // Run 3
    hand.searchForRuns();
    EXPECT_EQ(hand.at(0).meld, Card::RUNMELD); // 5 of Diamonds
    EXPECT_EQ(hand.at(1).meld, Card::RUNMELD); // 6 of Diamonds
    EXPECT_EQ(hand.at(2).meld, Card::RUNMELD); // 7 of Diamonds
    EXPECT_EQ(hand.at(3).meld, Card::NOTMELD); // 4 of Clubs
    EXPECT_EQ(hand.at(4).meld, Card::NOTMELD); // 8 of Clubs
    EXPECT_EQ(hand.at(5).meld, Card::NOTMELD); // 9 of Clubs
    EXPECT_EQ(hand.at(6).meld, Card::RUNMELD); // Ace of Spades
    EXPECT_EQ(hand.at(7).meld, Card::RUNMELD); // 2 of Spades
    EXPECT_EQ(hand.at(8).meld, Card::RUNMELD); // 3 of Spades
    EXPECT_EQ(hand.at(9).meld, Card::RUNMELD); // 10 of Spades
    EXPECT_EQ(hand.at(10).meld, Card::RUNMELD); // Jack of Spades
    EXPECT_EQ(hand.at(11).meld, Card::RUNMELD); // Queen of Spades
    EXPECT_EQ(hand.at(12).meld, Card::RUNMELD); // King of Spades
}

TEST(SearchForRunsTest, SearchForRunsNoResetMeld)
{
    Hand hand;
    hand.push_back(Card(Card::SPADE, Card::ACE));
    hand.push_back(Card(Card::SPADE, Card::TWO));
    hand.back().meld = Card::SETMELD;
    hand.push_back(Card(Card::SPADE, Card::THREE));
    hand.push_back(Card(Card::CLUB, Card::FOUR));
    hand.push_back(Card(Card::DIAMOND, Card::FIVE));
    hand.push_back(Card(Card::DIAMOND, Card::SIX));
    hand.back().meld = Card::SETMELD;
    hand.push_back(Card(Card::DIAMOND, Card::SEVEN));
    hand.push_back(Card(Card::CLUB, Card::EIGHT));
    hand.push_back(Card(Card::CLUB, Card::NINE));
    hand.push_back(Card(Card::SPADE, Card::TEN)); // Run
    hand.push_back(Card(Card::SPADE, Card::JACK)); // Run
    hand.push_back(Card(Card::SPADE, Card::QUEEN)); // Run
    hand.push_back(Card(Card::SPADE, Card::KING)); // Run
    hand.searchForRuns();
    EXPECT_EQ(hand.at(0).meld, Card::NOTMELD); // 5 of Diamonds
    EXPECT_EQ(hand.at(1).meld, Card::SETMELD); // 6 of Diamonds
    EXPECT_EQ(hand.at(2).meld, Card::NOTMELD); // 7 of Diamonds
    EXPECT_EQ(hand.at(3).meld, Card::NOTMELD); // 4 of Clubs
    EXPECT_EQ(hand.at(4).meld, Card::NOTMELD); // 8 of Clubs
    EXPECT_EQ(hand.at(5).meld, Card::NOTMELD); // 9 of Clubs
    EXPECT_EQ(hand.at(6).meld, Card::NOTMELD); // Ace of Spades
    EXPECT_EQ(hand.at(7).meld, Card::SETMELD); // 2 of Spades
    EXPECT_EQ(hand.at(8).meld, Card::NOTMELD); // 3 of Spades
    EXPECT_EQ(hand.at(9).meld, Card::RUNMELD); // 10 of Spades
    EXPECT_EQ(hand.at(10).meld, Card::RUNMELD); // Jack of Spades
    EXPECT_EQ(hand.at(11).meld, Card::RUNMELD); // Queen of Spades
    EXPECT_EQ(hand.at(12).meld, Card::RUNMELD); // King of Spades
}

TEST(SearchForSetsTest, SearchForSets)
{
    Hand hand;
    hand.push_back(Card(Card::CLUB, Card::ACE));
    hand.push_back(Card(Card::SPADE, Card::ACE));
    hand.push_back(Card(Card::HEART, Card::ACE));
    hand.push_back(Card(Card::DIAMOND, Card::SEVEN));
    hand.push_back(Card(Card::CLUB, Card::KING));
    hand.push_back(Card(Card::SPADE, Card::KING));
    hand.push_back(Card(Card::DIAMOND, Card::KING));
    hand.searchForSets();
    EXPECT_EQ(hand.at(0).meld, Card::SETMELD); // Ace of Clubs
    EXPECT_EQ(hand.at(1).meld, Card::SETMELD); // Ace of Spades
    EXPECT_EQ(hand.at(2).meld, Card::SETMELD); // Ace of Hearts
    EXPECT_EQ(hand.at(3).meld, Card::NOTMELD); // 7 of Diamonds
    EXPECT_EQ(hand.at(4).meld, Card::SETMELD); // King of Clubs
    EXPECT_EQ(hand.at(5).meld, Card::SETMELD); // King of Spades
    EXPECT_EQ(hand.at(6).meld, Card::SETMELD); // King of Diamonds
}

TEST(SearchForSetsTest, SearchForSetsNoResetMeld)
{
    Hand hand;
    hand.push_back(Card(Card::CLUB, Card::ACE));
    hand.push_back(Card(Card::HEART, Card::ACE));
    hand.push_back(Card(Card::SPADE, Card::ACE));
    hand.back().meld = Card::RUNMELD;
    hand.push_back(Card(Card::DIAMOND, Card::SEVEN));
    hand.push_back(Card(Card::CLUB, Card::KING));
    hand.push_back(Card(Card::SPADE, Card::KING));
    hand.push_back(Card(Card::DIAMOND, Card::KING));
    hand.searchForSets();
    EXPECT_EQ(hand.at(0).meld, Card::NOTMELD); // Ace of Clubs
    EXPECT_EQ(hand.at(1).meld, Card::NOTMELD); // Ace of Hearts
    EXPECT_EQ(hand.at(2).meld, Card::RUNMELD); // Ace of Spades
    EXPECT_EQ(hand.at(3).meld, Card::NOTMELD); // 7 of Diamonds
    EXPECT_EQ(hand.at(4).meld, Card::SETMELD); // King of Clubs
    EXPECT_EQ(hand.at(5).meld, Card::SETMELD); // King of Spades
    EXPECT_EQ(hand.at(6).meld, Card::SETMELD); // King of Diamonds
}
