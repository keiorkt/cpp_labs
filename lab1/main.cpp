/*
 * main.cpp
 *
 *  Created on: 17 Sep 2019
 *      Author: keitaiwasaki
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX_NUM_BARRIERS = 5;
const int MAX_NUM_ROCKETS = 3;
const int MAX_HEALTH = 4;
enum Player {None = 0, Player1 = 1, Player2 = 2};
enum Hand {Undefined, Rock, Paper, Scissors};

int main() {
	// Game State Variables.
	// Note: We use enum integer value 1 to represent Player1, and integer value 2 to represent Player2.
	int winner = None; // The player who won the game.
	int current_player = None, opponent_player = None; // The current active player, and the opponent player respectively.
	int player_initiative = None; // The player who won the Rock Paper Scissors and goes first for that round.

	int p1_num_barriers = 0, p2_num_barriers = 0;
	int p1_num_rockets = 0, p2_num_rockets = 0;
	int p1_health = MAX_HEALTH, p2_health = MAX_HEALTH;

	// Game Loop.
	while (winner == None) {
		// Rock Paper Scissors Loop.
		/*
		 * Task 1: Implement the Rock Paper Scissors game to determine player initiative.
		 * - Ask Player1 to choose between rock(1), paper(2) or scissor(3).
		 * - If the input is not in range, ask Player1 again.
		 * - Do the same for Player2.
		 * - If it is a draw, ask the Players again.
		 * - Lastly, determine who won and set player_initiative to the corresponding value.
		 */
		int p1_hand_int, p2_hand_int;
    Hand p1_hand = Undefined, p2_hand = Undefined;

    while (player_initiative == None) {
      while (p1_hand == Undefined) {
        cout << "Player1: Please choose between rock(1), paper(2) or scissors(3): ";
        cin >> p1_hand_int;
        if (p1_hand_int > 0 && p1_hand_int < 4) {
          p1_hand = static_cast<Hand>(p1_hand_int);
        } else {
          cout << "Invalid input. Please enter again." << endl;
        }
      }

      while (p2_hand == Undefined) {
        cout << "Player2: Please choose between rock(1), paper(2) or scissors(3): ";
        cin >> p2_hand_int;
        if (p2_hand_int > 0 && p2_hand_int < 4) {
          p2_hand = static_cast<Hand>(p2_hand_int);
        } else {
          cout << "Invalid input. Please enter again." << endl;
        }
      }

      if (p1_hand == p2_hand) {
        cout << "It's a draw. Retry.\n" << endl;
        p1_hand = Undefined; p2_hand = Undefined;
        continue;
      }

      if ((p1_hand == 1 && p2_hand == 3) || (p1_hand == 2 && p2_hand == 1) || (p1_hand == 3 && p2_hand == 2)) {
        player_initiative = Player1;
      } else {
        player_initiative = Player2;
      }
    }

		// Player Actions Loop.
		int input = 0;
		bool invalid_input = false;

		/*
		 * Task 2: Handle both Players' actions for this round.
		 * - The Player who won initiative (by winning the Rock Paper Scissors game) goes first.
		 * - The other Player goes second.
		 * - Use a Loop so that we don't have to duplicate code for both Players.
		 */

    if (player_initiative == Player1) {
      current_player  = Player1;
      opponent_player = Player2;
    } else {
      current_player  = Player2;
      opponent_player = Player1;
    }

		for (int i = 0; i < 2; ++i) {
			cout << '\n' << "--------------------------------------------------" << endl;
			cout << "Player1: Health x " << p1_health << " | Rockets x " << p1_num_rockets << " | Barriers x " << p1_num_barriers << endl;
			cout << "Player2: Health x " << p2_health << " | Rockets x " << p2_num_rockets << " | Barriers x " << p2_num_barriers << endl;
			cout << "--------------------------------------------------" << endl;

			do {
				invalid_input = false;
				cout << '\n' << "Player" << current_player << ", choose any one action below: " << endl;
				cout << "0: Surrender." << endl;
				cout << "1: Build Barriers." << endl;
				cout << "2: Build Rockets." << endl;
				cout << "3. Launch Rockets." << endl;
				cin >> input;

				switch (input) {
					/*
					 * Task 3: Implement case 0.
					 * - If Player1 surrenders, Player2 wins, and vice versa.
					 */
          case 0:
            winner = opponent_player;
            break;

					/*
					 * Task 4: Implement case 1.
					 * - If the Player's number of barriers is already at the maximum, ask them to choose a different action.
					 */

          case 1:
           if (current_player == Player1) {
             if (p1_num_barriers >= MAX_NUM_BARRIERS) {
               cout << "Player1, you can't build any more barriers." << endl;
               continue;
             } else {
               cout << "Player1, you now have " << ++p1_num_barriers << " barriers." << endl;
             }
           } else {
             if (p2_num_barriers >= MAX_NUM_BARRIERS) {
               cout << "Player2, you can't build any more barriers." << endl;
               continue;
             } else {
               cout << "Player2, you now have " << ++p2_num_barriers << " barriers." << endl;
             }
           }
           break;

					/*
					 * Task 5: Implement case 2.
					 * - If the Player's number of rockets is already at the maximum, ask them to choose a different action.
					 */

          case 2:
           if (current_player == Player1) {
             if (p1_num_rockets >= MAX_NUM_ROCKETS) {
               cout << "Player1, you can't build any more rockets." << endl;
               continue;
             } else {
               cout << "Player1, you now have " << ++p1_num_rockets << " rockets." << endl;
             }
           } else {
             if (p2_num_rockets >= MAX_NUM_ROCKETS) {
               cout << "Player2, you can't build any more rockets." << endl;
               continue;
             } else {
               cout << "Player2, you now have " << ++p2_num_rockets << " rockets." << endl;
             }
           }
           break;

					/*
					 * Task 6: Implement case 3.
					 * - If the Player has no rockets, ask them to choose a different action.
					 * - Launch ALL rockets.
					 * - Each rocket will destroy one barrier/health.
					 * - Barriers are destroyed first before health.
					 * - If the Opponent's health reaches 0, the Current Player wins.
					 */

          case 3:
           if (current_player == Player1) {
             if (p1_num_rockets == 0) {
               cout << "Player1, you have no rockets to launch." << endl;
               continue;
             }

             while (p1_num_rockets > 0) {
               --p1_num_rockets;
               if (p2_num_barriers > 0) {
                 --p2_num_barriers;
               } else {
                 --p2_health;
                 if (p2_health == 0) {
                   winner = current_player;
                   break;
                 }
               }
             }
             cout << "Player2 has " << p2_num_barriers << " barriers left." << endl;
             cout << "Player2 has " << p2_health << "/" << MAX_HEALTH << " health left." << endl;
           } else {
             if (p2_num_rockets == 0) {
               cout << "Player2, you have no rockets to launch." << endl;
               continue;
             }

             while (p2_num_rockets > 0) {
               --p2_num_rockets;
               if (p1_num_barriers > 0) {
                 --p1_num_barriers;
               } else {
                 --p1_health;
                 if (p1_health == 0) {
                   winner = current_player;
                   break;
                 }
               }
             }
             cout << "Player1 has " << p1_num_barriers << " barriers left." << endl;
             cout << "Player1 has " << p1_health << "/" << MAX_HEALTH << " health left." << endl;
           }
           break;

					/*
					 * Task 7: Implement the default case.
					 * - Control Flow directed here if the Player inputs an action that is not within the valid range.
					 * - Output the appropriate message and ask the Player to choose a different action.
					 */

          default:
           invalid_input = true;
           cout << "Invalid input. Please enter again." << endl;
				}
			} while (invalid_input);

      if (winner != None) {
        cout << "Congratz! Player" << winner << ". You win!" << endl;
        break;
      }

      if (current_player == Player1) {
        current_player = Player2;
        opponent_player = Player1;
      } else {
        current_player = Player1;
        opponent_player = Player2;
      }
 		}
    current_player = None;
    opponent_player = None;
    player_initiative = None;
	}

	system("pause");
	return 0;
}
