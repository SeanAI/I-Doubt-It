// YOUR NAME: Josh Seymore
//
// CS 4318, spring 2018
// Final Project: I Doubt It

#include "idi.h"
#include "math.h"
#include "iostream"
#include "iomanip"
bool seymoreCheckIfBluffing(Play oppPlay, Hand myHand, int discardSize, int oppHandSize);

// Rename and complete this agent function.
Play idiAgentSeymore(Hand hand, Play oppLastPlay, int nextNumUp, int discardSize, int handSizes[],  const MatchState &match)
{
   // Your function must end up returning a valid int between 0 and numCardsPerHand - 1.
   // No random-number generation allowed!
   // hand.getCard(0) gives the first card in your hand.
   // hand.getCard(0).getNumber() gives the number of that card, 1 to 13.
   // hand.getCard(0).getSuit() gives the suit of that card.
   // match.getRuns(0) gives the number of runs scored by player A so far.
   // numRuns(d) gives the number of runs scored when the card difference is d.
   // See the definitions of Hand, Card and MatchState for more helpful functions.

   Play myPlay;
   int quality = 0;
   vector<Card> discards;
   bool claimBluff;
   
   for(int i = 0; i < hand.getHandSize(); i++)
   {
      if(hand.getCard(i).getNumber() == nextNumUp)
      {
         discards.push_back(hand.getCard(i));
      }
   }
   switch(discards.size())
   {
		case 0: quality +=0;
				break;
		case 1: quality += 250; 
				break;
		case 2: quality += 300; 
				break;
		case 3: quality += 500;
				break;
		case 4: quality += 1000;
				break;
   }
   
   for(int i = 0; i < discardSize; i++)
   {
		quality -= i * 2;
   }
   
   if(discards.size() == 1 && quality > 0)
   {
		int num[13], card;
		card = 4;
		for(int i = 0; i < hand.getHandSize(); i++)
		{
			for(int j = 0; j < 13; j++)
			{
				if(hand.getCard(i).getNumber() == (j+1))
				{
					num[j] += 1;
				}
			}
		}
		
		for(int i = 0; i < 13; i++)
		{
			if(num[i] < card && num[i] != 0)
			{
				card = i;
			}
		}
		
	   for(int i = 0; i < hand.getHandSize(); i++)
	   {
		  if(hand.getCard(i).getNumber() == card)
		  {
			 discards.push_back(hand.getCard(i));
			 break;
		  }
	   }
   }
   
   if(discards.size() < 1)
   {
      discards.push_back(hand.getCard(0));
   }
   
   claimBluff = seymoreCheckIfBluffing(oppLastPlay, hand, discardSize, handSizes[1]);
   
   if(claimBluff && quality < 200)
   {
      myPlay.setCardsPlayed(discards.size(), nextNumUp, discards, true);
   }
   else
   {
      myPlay.setCardsPlayed(discards.size(), nextNumUp, discards, false);
   }
   return myPlay;
}

bool seymoreCheckIfBluffing(Play oppPlay, Hand myHand, int discardSize, int oppHandSize)
{
   int claim, numNeeded, iHave;
   double prob;
   
   claim = oppPlay.getNumCards();
   numNeeded = oppPlay.getCardType();
   iHave = 0;
   prob = 0;
   
   for(int i = 0; i < myHand.getHandSize(); i++)
   {
      if(numNeeded == myHand.getCard(i).getNumber())
      {
         iHave++;
      }
   }

   if(iHave > 0)
   {
	   prob += ((static_cast<double>(claim) / static_cast<double>(oppHandSize)) * (static_cast<double>(oppHandSize) / 52.0) - (static_cast<double>(claim) / iHave));
   }
   else
   {
	   prob += ((static_cast<double>(claim) / static_cast<double>(oppHandSize)) * (static_cast<double>(oppHandSize) / 52));
   }
  
   if(prob < 0 && !oppPlay.getClaim())
   {
      return true;
   }
   else
   {
      return false;
   }
   
}

/*

 - First, carefully comment your code above.
 - Here, describe your approach and why you expect it to do well against the
   other submitted agents.
 - Also make a note here if you talked about the assignment with anyone or gave
   or received any kind of help.
   
   For the second iteration of this assignment, I tried to do the same ideas as I did for 
   the last assignment but make some improvements. 
   
   First off, I fixed the holes in my batter to make sure that my agent avoids giving the batter
   free runs from Wides and Byes. I'm not sure how much not having these holes in the first iteration would
   have helped. However, I did see a number of them in my results from last time, so I think that's fixed.
   
   I did the same attempt at using genetic development of my agent by using the best numbers from each generation.
   That being said, I decided to revert back to the numbers that I had from the previous generation. No matter how
   I changed the numbers this time, the original numbers always performed better than the other dummy agents that I used
   to test the generations.
   
   One thing I also implemented was losing condition for my hand at the end of my batting section. At the end of the decision to bat,
   I check if the round is impossible to win. If it's not, then I decide to throw away the lowest valued card. One thing I noticed in some 
   of the other player's agents was that they tended to do drop their lower value cards more often, so I decided to implement something 
   like that in my code. After the implementation, my current agent performed better than the other copies, so I decided to run with this
   agent.
*/
