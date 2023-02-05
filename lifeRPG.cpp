#include <iostream>
#include <string>


using namespace std;

// constructor
class player
{

public:
    player(string name) : name(name)
    {
        money = 0;
        salary = 100;
        stuff = 0;
        day = 0;
    };

    int getSalary()
    {
        return salary;
    }

    void nextDay()
    {
        day++;
    };

    int getDay() { return day; };

    void printStats()
    {
        cout << "\n====================" << endl;
        cout << name << "\tday: " << day
             << "\nmoney: $" << money
             << "\tstuff: $" << stuff
             << "\nsalary: $" << salary;
        cout << "\n====================" << endl;
    };

    void buyStuff()
    {
        money -= salary;
        stuff += salary;
    };

    void work()
    {
        money += salary;
    }

    void salaryChange(int changeAmount)
    {
        salary += changeAmount;
    };

private:
    string name;
    int money, stuff, day;
    int salary;
};

bool gameTurn(player &player)
{
    char decision;

    player.nextDay();

    cout << "Day: " << player.getDay()
         << "\nDo you want to: \n(w)ork (s)hop (q)uit?" << endl;
    cin >> decision;

    if (decision == 'w')
    {
        cout << "you went to work!"
             << "\nyou earned $" << player.getSalary() << endl;
        player.work();
        return true;
    }
    else if (decision == 's')
    {
        cout << "you went shopping!"
             << "\nyou spent $" << player.getSalary() << endl;
        player.buyStuff();
        return true;
    }
    else if (decision == 'q')
    {
        cout << "you quit! game over!" << endl;
        player.printStats();
        return false;
    }

    else
    {
        cout << "invalid input: "
             << "\tyou did nothing." << endl;
        return true;
    }
}

int main()
{
system("clear");
    string inputName;

    cout << "What is your name?" << endl;
    cin >> inputName;
    cout<<endl;

    player gamePlayer(inputName);

    while (gameTurn(gamePlayer))
    {

        gamePlayer.printStats();
        cout<<endl;
    };
    return 0;
}