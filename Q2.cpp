#include <iostream>
#include <string>
using namespace std;

// Base class: Character
class Character {
protected:
    int health;
    int damage;

public:
    // Constructor
    Character(int h, int d) : health(h), damage(d) {}

    // Display function
    virtual void display() const {
        cout << "=== Character Stats ===" << endl;
        cout << "Health: " << health << " HP" << endl;
        cout << "Damage: " << damage << " DMG" << endl;
    }

    virtual ~Character() {}
};

// Derived class: Enemy
class Enemy : public Character {
private:
    string enemyType;

public:
    // Constructor
    Enemy(int h, int d, string type) 
        : Character(h, d), enemyType(type) {}

    // Display function
    void display() const override {
        cout << "\n=== Enemy Stats ===" << endl;
        cout << "Enemy Type: " << enemyType << endl;
        cout << "Health: " << health << " HP" << endl;
        cout << "Damage: " << damage << " DMG" << endl;
    }
};

// Derived class: Player
class Player : public Character {
protected:
    string playerName;
    int level;

public:
    // Constructor
    Player(int h, int d, string name, int lvl) 
        : Character(h, d), playerName(name), level(lvl) {}

    // Display function
    void display() const override {
        cout << "\n=== Player Stats ===" << endl;
        cout << "Name: " << playerName << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << " HP" << endl;
        cout << "Damage: " << damage << " DMG" << endl;
    }
};

// Derived class: Wizard (inherits from Player)
class Wizard : public Player {
private:
    int magicPower;
    string spells;

public:

    Wizard(int h, int d, string name, int lvl, int mp, string s)
        : Player(h, d, name, lvl), magicPower(mp), spells(s) {}
    void display() const override {
        cout << "\n=== Wizard Stats ===" << endl;
        cout << "Name: " << playerName << endl;
        cout << "Level: " << level << endl;
        cout << "Health: " << health << " HP" << endl;
        cout << "Damage: " << damage << " DMG" << endl;
        cout << "Magic Power: " << magicPower << " MP" << endl;
        cout << "Spells: " << spells << endl;
    }
};

int main() {
    Wizard myWizard(100, 25, "Gandalf", 10, 150, "Fireball, Teleport, Invisibility");
    myWizard.display();

    cout << "\n The magic has been conjured! " << endl;

    return 0;
}
