add_library(Card Card.cpp Card.h Deck.cpp Deck.h)
add_subdirectory(tests)
target_include_directories(Card PUBLIC .)
