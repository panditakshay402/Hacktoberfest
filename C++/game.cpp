#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Player class
class Player {
public:
    string name;
    int health;
    int damage;

    Player(string playerName, int playerHealth, int playerDamage) {
        name = playerName;
        health = playerHealth;
        damage = playerDamage;
    }

    void attack(Player& other) {
        int attackDamage = rand() % damage;
        other.health -= attackDamage;
        cout << name << " attacks " << other.name << " for " << attackDamage << " damage!" << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0));

    // Create players
    Player player("You", 100, 10);
    Player enemy("Dragon", 200, 15);

    cout << "Welcome to the Text-Based RPG!" << endl;

    while (player.health > 0 && enemy.health > 0) {
        player.attack(enemy);
        enemy.attack(player);

        cout << "Your health: " << player.health << " Enemy health: " << enemy.health << endl;

        if (player.health <= 0) {
            cout << "Game Over! You were defeated by the " << enemy.name << "." << endl;
        } else if (enemy.health <= 0) {
            cout << "Congratulations! You defeated the " << enemy.name << "." << endl;
        }
    }

    return 0;
}
