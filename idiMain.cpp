// CS 4318, spring 2018
// Agent Challenge 4: Cricket card game
//
// Here's the main function that plays all agents against each other and
// summarizes the results.

#include "idi.h"

extern const int numAgents;
extern int (*agentFunc[])(Hand, Play, bool, const MatchState &);
extern string agentStr[];

MatchState playIDICardGameMatch(int (*agentA)(Hand, Play, bool, const MatchState &), int (*agentB)(Hand, Play, bool, const MatchState &), int (*agentC)(Hand, Play, bool, const MatchState &), bool printAllDetails);

int main()
{
   IDIStats playerStats[numAgents];
   int i, numLosses[numAgents], numWins[numAgents], k, j, l,
   order[numAgents];//, temp;
   MatchState match;

   srandom(time(0));

   cout << "Final Project: I Doubt It\n"
        << "Iteration results\n";
   for (i = 0; i < numAgents; i += 1)
   {
      numWins[i] = 0;
      numLosses[i] = 0;
   }
   for (i = 0; i < numAgents; i += 1)
   {
      for (j = 0; j < numAgents; j += 1)
      {
		  for (l = 0; l < numAgents; l += 1)
		  {
			for (k = 0; k <= 200; k += 1)
			{
				match = playIDICardGameMatch(agentFunc[i], agentFunc[j], agentFunc[l], k == 0);
			}
		  }
	  }
   }
   
   /*
   for (i = 0; i < numAgents; i += 1)
   {
      for (j = 0; j < numAgents; j += 1)
      {
         if (i != j)
         {
            cout << "\n"
                 << "A = " << agentStr[i] << ", B = " << agentStr[j] << ", C = " << agentStr[j]":"
                 << "\n"
                 << "Exhibition match:\n" << flush;
            for (k = 0; k <= 200; k += 1)
            {
               match = playIDICardGameMatch(agentFunc[i], agentFunc[j], k == 0);
               cout << "   A " << match.getRuns(0) << "-"
                    << match.getWickets(0) << "(" << match.getBalls(0)
                    << "), B " << match.getRuns(1) << "-"
                    << match.getWickets(1) << "(" << match.getBalls(1)
                    << ")";
               switch (match.getResult())
               {
                  case aWin:
                     cout << "   >>> A wins <<<\n";
                     break;
                  case bWin:
                     cout << "   >>> B wins <<<\n";
                     break;
                  case cWin:
                     cout << "   >>> C wins <<<\n";
                     break;
               }
               if (k == 0)
               {
                  cout << "Official matches:\n";
               }
               else
               {
                  switch (match.getResult())
                  {
                     case aWin:
                        numWins[i] += 1;
                        pointsAsA[i] += 4;
                        numLosses[j] += 1;
                        break;
                     case bWin:
                        numLosses[i] += 1;
                        numWins[j] += 1;
                        pointsAsB[j] += 4;
                        break;
                     case draw:
                        numDraws[i] += 1;
                        pointsAsA[i] += 1;
                        numDraws[j] += 1;
                        pointsAsB[j] += 1;
                        break;
                     case tie:
                        numTies[i] += 1;
                        pointsAsA[i] += 2;
                        numTies[j] += 1;
                        pointsAsB[j] += 2;
                        break;
                  }
                  IDIStats[i].runs += match.getRuns(0);
                  IDIStats[i].wickets += match.getWickets(0);
                  IDIStats[i].balls += match.getBalls(0);
                  IDIStats[i].runs += match.getRuns(1);
                  IDIStats[i].wickets += match.getWickets(1);
                  IDIStats[i].balls += match.getBalls(1);
                  IDIStats[j].runs += match.getRuns(1);
                  IDIStats[j].wickets += match.getWickets(1);
                  IDIStats[j].balls += match.getBalls(1);
                  IDIStats[j].runs += match.getRuns(0);
                  IDIStats[j].wickets += match.getWickets(0);
                  IDIStats[j].balls += match.getBalls(0);
               }
            }
         }
      }
   }

   for (i = 0; i < numAgents; i += 1)
   {
      order[i] = i;
   }
   for (i = 0; i < numAgents - 1; i += 1)
   {
      for (j = i + 1; j < numAgents; j += 1)
      {
         if (pointsAsA[order[i]] + pointsAsB[order[i]] < pointsAsA[order[j]] + pointsAsB[order[j]] || (pointsAsA[order[i]] + pointsAsB[order[i]] == pointsAsA[order[j]] + pointsAsB[order[j]] &&
             agentStr[order[i]] > agentStr[order[j]]))
         {
            temp = order[i];
            order[i] = order[j];
            order[j] = temp;
         }
      }
   } */
   cout << "\n\n"
        << "Overall standings:                                    points          batting         bowling\n"
        << "                    points     W     L     D     T  as A  as B      R/W     R/hB    R/W     B/W\n";
   cout << fixed;
   /*for (i = 0; i < numAgents; i += 1)
   {
      cout << setw(20) << left << agentStr[order[i]]
           << " " << setw(5) << right << numWins[order[i]]
           << " " << setw(5) << right << numLosses[order[i]]
           << " " << setprecision(2) << setw(7) << right << playerStats[order[i]].bluffs << "\n";
   } */
   return 0;
}

MatchState playIDICardGameMatch(int (*agentA)(Hand, Play, bool, const MatchState &), int (*agentB)(Hand, Play, bool, const MatchState &), int (*agentC)(Hand, Play, bool, const MatchState &), bool printAllDetails)
{
   // Play a match of the cricket card game between given agents.
   Hand hand1, hand2, hand3, tempHand, discardPile;
   Deck startingDeck;
   //int battingPlay, bowlingPlay, lastBowlingCardNumber;
   //int (*agent1)(Hand, Card, bool, const MatchState &);
   //int (*agent2)(Hand, Card, bool, const MatchState &);
   //int (*agent3)(Hand, Card, bool, const MatchState &);
   MatchState match;

   //agent1 = agentA;
   //agent2 = agentB;
   //agent3 = agentC;
   
   
   startingDeck.build();
   startingDeck.shuffle();
   int iter = 0;
   while(startingDeck.getDeckSize() > 1)
   {
	   if(iter == 3)
	   {
		   iter = 0;
	   }
	   switch(iter)
	   {
			case 0:
				hand1.addCard(startingDeck.deal());
				iter++;
				break;
			case 1:
				hand2.addCard(startingDeck.deal());
				iter++;
				break;
			case 2:
				hand3.addCard(startingDeck.deal());
				iter++;
				break;
	   }
   }
   while (match.stillPlaying())
   {
      if (printAllDetails)
      {
         cout << "A's hand: " << hand1.toString()<< " Hand Size: " << hand1.getHandSize() << "\n"
              << "B's hand: " << hand2.toString() << " Hand Size: " << hand2.getHandSize() << "\n"
              << "C's hand: " << hand3.toString() << " Hand Size: " << hand3.getHandSize() << "\n";
      }
      /*lastBowlingCardNumber = bowlingCard.getNumber();
      bowlingPlay = (*bowlingAgent)(bowlingHand, bowlingCard, false, match);
      bowlingCard = bowlingHand.getCard(bowlingPlay);
      
	  if (printAllDetails)
      {
         cout << "      " << (match.isInFirstInnings() ? "B" : "A")
              << " claims they have " << bowlingCard.toString() << "; ";
      }
	  /*
      if (bowlingCard.getNumber() == lastBowlingCardNumber)
      {
         match.scoreRuns(1);
         if (printAllDetails)
         {
            cout << "umpire calls \"wide\" and "
                 << (match.isInFirstInnings() ? "A" : "B") << " scores 1 run.\n";
         }
      }
      else if (bowlingCard.getNumber() == lastBowlingCardNumber + 1)
      {
         match.scoreRuns(numRuns(lastBowlingCardNumber));
         if (printAllDetails)
         {
            cout << "umpire calls \"bye\" and "
                 << (match.isInFirstInnings() ? "A" : "B")
                 << " scores " << numRuns(lastBowlingCardNumber) << " run"
                 << (numRuns(lastBowlingCardNumber) == 1 ? "" : "s")
                 << ".\n";
         }
      }
      else
      {
         battingPlay = (*battingAgent)(battingHand, bowlingCard, true, match);
         battingCard = battingHand.getCard(battingPlay);
         battingHand.randomizeCard(battingPlay);
         if (printAllDetails)
         {
            cout << (match.isInFirstInnings() ? "A" : "B") << " plays "
                 << battingCard.toString() << " and ";
         }
         if (battingCard.getSuit() == bowlingCard.getSuit())
         {
            match.scoreRuns(numRuns(battingCard.getNumber() - bowlingCard.getNumber()));
            if (printAllDetails)
            {
               cout << "scores "
                    << numRuns(battingCard.getNumber() - bowlingCard.getNumber())
                    << " run"
                    << (numRuns(battingCard.getNumber() - bowlingCard.getNumber()) == 1 ? "" : "s")
                    << ".\n";
            }
         }
         else if (battingCard.getNumber() >= bowlingCard.getNumber())
         {
            match.scoreRuns(0);
            if (printAllDetails)
            {
               cout << "scores 0 runs.\n";
            }
         }
         else
         {
            match.takeWicket();
            if (printAllDetails)
            {
               cout << "is out.\n";
            }
         }
      }
      if (!match.isInFirstInnings() && match.getBalls(1) == 0)
      {
         battingAgent = agentB;
         bowlingAgent = agentA;
         tempHand = battingHand;
         battingHand = bowlingHand;
         bowlingHand = tempHand;
      } */
   }

   return match;
}
