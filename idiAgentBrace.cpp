// YOUR NAME: Josh Seymore
//
// CS 4318, spring 2018
// Agent Challenge 4: Cricket card game
//
// Rename this file and the function below.  For example, if your agent name
// is Jones, rename this ccgAgentSmith.cpp file to ccgAgentJones.cpp and the
// ccgAgentSmith function below to ccgAgentJones.  Complete your agent
// function and turn it in on Blackboard.  Random-number generation is not
// allowed; your agent must be entirely deterministic.  Feel free to create
// other agents--each in a separate .cpp file--for yours to play against,
// but turn in only one.  Test your agent(s) with
//
//    nice bash ccgBuild.bash
//
// and then
//
//    nice ./ccgRunSim
//
// Each submitted agent will play each other, batting first and bat
// second an equal number of times, to determine the standings, which will
// be posted soon after the agents are due.

#include "idi.h"
#include "math.h"
#include "iostream"

// Rename and complete this agent function.
Play idiAgentBrace(Hand hand, Card lastBowledCard, bool isBatting, const MatchState &match)
{
   // Your function must end up returning a valid int between 0 and numCardsPerHand - 1.
   // No random-number generation allowed!
   // hand.getCard(0) gives the first card in your hand.
   // hand.getCard(0).getNumber() gives the number of that card, 1 to 11.
   // hand.getCard(0).getSuit() gives the suit of that card.
   // match.getRuns(0) gives the number of runs scored by player A so far.
   // numRuns(d) gives the number of runs scored when the card difference is d.
   // See the definitions of Hand, Card and MatchState for more helpful functions.

   cout << "\njfkalsd;jf;la\n";
   Play myPlay;
   vector<Card> discards;
   myPlay.setCardsPlayed(2, discards, false);
   return myPlay;
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
