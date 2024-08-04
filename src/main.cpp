using namespace std;

#include <iostream>
#include "game.hpp"
#include "player.hpp"

class MyType {
public:
    int someMember;
};

class Owner {
public:
    Owner() {
        MyType myType;
        myType.someMember = 42;
        myVector.push_back(myType);
    }
    std::vector<MyType>& getVector() {
        return myVector;
    }

private:
    std::vector<MyType> myVector;
};

class Mutator {
public:
    void mutate(Owner& owner) {
        auto& vector = owner.getVector();
        for (MyType& element : vector) {
            // Modify the element directly
            element.someMember++;
        }
    }
};

int main()
{
    // Owner owner;
    // Mutator mutator;
    // cout << owner.getVector()[0].someMember << endl;
    // mutator.mutate(owner);
    // cout << owner.getVector()[0].someMember << endl;

    Game game;
    game.start();

    return 0;
}
