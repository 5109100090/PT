#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


class human
{
    private :
        int age;
        int getAge()
        {
            return age;
        }

    public :
        string skinColor;
        string name;
        human *partner;
        int pos;
        human () {}
        human (int age)
        {
            this->age = age;
            pos =0;
        }
        human(string skinColorInput, string nameInput)
        {
            skinColor = skinColorInput;
            name = nameInput;
            age = 0;
        }
        void walk()
        {
            pos++;
        }
        void love(human *someOne)
        {
            string sayName();
        }
        string sayName()
        {
            return name;
        }

};


int main() {

    human man[3];
    human woman("blue","strukdat");
    human *target = new human("green","calculus");

    man[1] = human(10);
    man[2] = human("yellow","orgom");

    man[0].pos = 0;
    man[0].walk();
    cout << "The position of Man[0] should be 1, otherwise you're false" << endl;
    cout << "The position of Man[0] = " << man[0].pos <<endl;

    man[2].love(&woman);
    target = &woman;
    cout << "The name of Human whom man[2] love is " << target->name << endl;

    return 0;
}
