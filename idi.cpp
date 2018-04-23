// CS 4318, spring 2018
// Final Project: I Doubt It
//
// Here are the functions available to each agent.

#include "idi.h"

int Card::randomInt(int n)
{
   // Return a random integer between 0 and n - 1.
   int r;
   if (n <= 0)
   {
      return 0;
   }
   do
   {
      r = random();
   }
   while (r >= INT_MAX / n * n);
   return r / (INT_MAX / n);
}

string Card::toString() const
{
   // Convert a card to a convenient string representation.
   stringstream strstr;
   strstr << "[" << number;
   switch (suit)
   {
      case spades:
         strstr << "$]";
         break;
      case clubs:
         strstr << "@]";
         break;
      case hearts:
         strstr << "!]";
         break;
      case diamonds:
         strstr << "*]";
         break;
   }
   return strstr.str();
}

Hand::Hand()
{   
}

string Hand::toString() const
{
   // Convert a hand of cards to a convenient string representation.
   int whichCard;
   string str;
   for (whichCard = 0; whichCard < cards.size(); whichCard += 1)
   {
      str += cards[whichCard].toString();
   }
   return str;
}

MatchState::MatchState()
{
   // Start a new match from scratch.
   stats[0].bluffs = 0;
   stats[0].cardsPossessed = 0;
   stats[1].bluffs = 0;
   stats[1].cardsPossessed = 0;
   stats[2].bluffs = 0;
   stats[2].cardsPossessed = 0;
   result = unfinished;
}

void MatchState::checkForResult()
{
   // Check to see whether the match is finished and update accordingly.
   return;
}



