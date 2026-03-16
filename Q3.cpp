#include <iostream>
using namespace std;
class Position {
protected:
    float x, y, z;

public:
    Position(float px = 0.0f, float py = 0.0f, float pz = 0.0f) 
        : x(px), y(py), z(pz) {}
    void displayPosition() const {
        cout << "Position: (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

class Health {
protected:
    int currentHealth;
    int maxHealth;

public:
    
    Health(int ch = 100, int mh = 100) 
        : currentHealth(ch), maxHealth(mh) {}

  
    void displayHealth() const {
        cout << "Health: " << currentHealth << "/" << maxHealth << " HP" << endl;
    }

 
    void takeDamage(int damage) {
        currentHealth -= damage;
        if (currentHealth < 0) currentHealth = 0;
    }

 
    void heal(int amount) {
        currentHealth += amount;
        if (currentHealth > maxHealth) currentHealth = maxHealth;
    }
};

// Derived class: Character (Multiple Inheritance)
class Character : public Position, public Health {
private:
    string characterName;
    int level;

public:
  
    Character(string name, int lvl, float px, float py, float pz, int ch, int mh)
        : Position(px, py, pz), Health(ch, mh), characterName(name), level(lvl) {}

    // Display all character details
    void display() const {
        cout << "\n=== Character Details ===" << endl;
        cout << "Name: " << characterName << endl;
        cout << "Level: " << level << endl;
        displayPosition();
        displayHealth();
    }

    // Move character to new position
    void moveTo(float nx, float ny, float nz) {
        x = nx;
        y = ny;
        z = nz;
        cout << characterName << " moved to (" << x << ", " << y << ", " << z << ")" << endl;
    }
};

int main() {
    Character hero("Aragorn", 15, 10.5f, 5.2f, 3.8f, 150, 150);
    // Display initial state
    hero.display();
    hero.moveTo(20.0f, 10.0f, 8.5f);
    hero.takeDamage(30);
    cout << "After taking 30 damage:" << endl;
    hero.display();
    hero.heal(50);
    cout << "\nAfter healing 50 HP:" << endl;
    hero.display();

    cout << "\n Game engine running smoothly! " << endl;

    return 0;
}
