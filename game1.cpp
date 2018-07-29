#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

int createZombie() {
    if (rand() % 65 < 10)
        return 11;

    else
        return rand() % 10 + 1;
}

int main() {
    srand(time(NULL));
    char enter;

    // game stats
    int isAlive = true;
    int pSkill = 9;
    int Score = 1;
    string playerName = "";
    int zedCount = 0;
    int zedsKilled = 0;

    // title
    cout << "Welcome to SurvivorZ." << endl << "Press [ENTER] to start.";
    cin.get();

    // player name
    cout << "Please enter your name: ";
    cin >> playerName;

	cout << "The world is not the same since the outbreak occurred, slowly you try to make your way to gather supplies but you come across a major problem...";

    // ask how many zombies
    cout << "How many zombies do you see? ";
    cin >> zedCount;

    cout << "Get ready to fight for your life, " << playerName << "!" << endl;

    // main game loop
    while (isAlive && zedsKilled < zedCount) {
        // create a random zombie
        int zSkill = createZombie();

        // battle sequence
        if (zSkill > 10) {
            cout << endl << "Here comes a bloater zombie!" << endl;
        }
        else {
            cout << endl << "Here comes zombie " << zedsKilled + 1 << endl;
        }

        cout << "Fighting...but you don't seem to know what you are doing exactly'" << endl;
        sleep(2);

        // zombie killed the player
        if (pSkill < zSkill) {
            isAlive = false;
            cout << "You have died.Good job. Now nothing matters. Time goes on." << endl;
        }

        // player killed the zombie
        else {
            if (pSkill - zSkill > 7) {
                cout << "You wasted the zombie! It's their fault, they should've tried harder to kill you. You don't go out easy.'''" << endl;
                Score = Score * 2;
            }

            else if (pSkill - zSkill > 5) {
                cout << "You decapitated the zombie! Aren't you glad that you get to experience such horror?'" << endl;
                Score = Score * 2;
            }

            else if (pSkill - zSkill > 0) {
                cout << "You killed the zombie! That was someone's family you murderer.'" << endl;
                Score = Score * 2;
            }

            else {
                cout << "You killed the zombie, but suffered injuries. Maybe you weren't destined to live any longer, or maybe it is a sign to try harder.'" << endl;
            }

            zedsKilled++;
        }

        cout << endl;
        sleep(1);
    }

    // end game
    if (zedsKilled == zedCount) {
        // victory
        cout << "You have survived the onslaught! It's only just getting started so don't get too excited. For now though, just bask in the victory of defeating such a small horde. It won't be as easy next time.'''" << endl;
    }
    else {
        // lost
        cout << "You are not a survivor. It was just too much to take on. Your last thoughts were not those you cared about the most, but how you could've survived just a little bit longer. Now everyone who depended on you, no longer they will. What happens now?'" << endl;
    }

    cout << "Zombies killed: " << zedsKilled << endl;
    cout << "Final score: " << Score << endl << endl;
}
