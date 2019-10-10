#include "course.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int rand()
{
    static int seed = 233;
    seed = (1ll * seed * 37 + 47) % 998244353;
    return seed;
}

std::vector<std::string> getNameRoster(int len)
{
    std::vector<std::string> ret;

    for (int i = 0; i < len; i++) {
        int nameLen = rand() % 6 + 1;
        while (true) {
            std::string name;
            for (int j = 0; j < nameLen; j++) {
                char c = 'a' + rand() % 26;
                name = name + c;
            }
            bool existed = false;
            for (int j = 0; j < i; j++) {
                if (name == ret[j]) {
                    existed = true;
                }
            }
            if (!existed) {
                ret.push_back(name);
                break;
            }
        }
    }

    return ret;
}

int main()
{
    // Task 1
    cout << "Task 1" << endl << endl;
    cout << "Create a list of 4 people" << endl;
    LinkedList* ll = new LinkedList;
    ll->push_back("Ann"); Node* Ann{ll->get_tail()};
    ll->push_back("Bob"); Node* Bob{ll->get_tail()};
    ll->push_back("Charlie"); Node* Charlie{ll->get_tail()};
    ll->push_back("David"); Node* David{ll->get_tail()};
    for (Node* it=ll->get_head()->next; it!=nullptr; it=it->next) {
        cout << it->content << endl;
    }
    cout << endl;

    cout << "Remove Ann" << endl;
    ll->remove(ll->get_head(), Ann);
    for (Node* it=ll->get_head()->next; it!=nullptr; it=it->next) {
        cout << it->content << endl;
    }
    cout << endl;

    cout << "Remove Charlie" << endl;
    ll->remove(Bob, Charlie);
    for (Node* it=ll->get_head()->next; it!=nullptr; it=it->next) {
        cout << it->content << endl;
    }
    cout << endl;

    cout << "Remove David" << endl;
    ll->remove(Bob, David);
    for (Node* it=ll->get_head()->next; it!=nullptr; it=it->next) {
        cout << it->content << endl;
    }
    cout << endl;

    cout << "Insert Emma before Bob" << endl;
    ll->insert(ll->get_head(), new Node{"Emma"});
    for (Node* it=ll->get_head()->next; it!=nullptr; it=it->next) {
        cout << it->content << endl;
    }
    cout << endl;

    // cout << "Create a copy of the list" << endl;
    // LinkedList* ll2 = new LinkedList{*ll};
    // cout << "Delete the original list" << endl;
    delete ll;
    // cout << "Print the new list" << endl;
    // for (Node* it=ll2->get_head()->next; it!=nullptr; it=it->next) {
    //     cout << it->content << endl;
    // }
    // cout << endl;
    // delete ll2;

    // Task 2
    cout << "Task 2" << endl << endl;
    std::vector<std::string> roster;

    int trial = 1000;

    Course *course = new Course("COMP2012Honors", 50);

    roster = getNameRoster(100);

    while (trial--) {

        int op = rand() % 6;
        std::string name = roster[rand() % 100];

        if (op < 2) {
            std::cout << "Enroll " << name << ": "
                      << course->enroll(name)
                      << std::endl;
        }

        if (op == 2) {
            std::cout << "Drop " << name << ": "
                      << course->drop(name)
                      << std::endl;
        }

        if (op == 3) {
            std::cout << "Waitlist: "
                      << course->getWaitlisted()
                      << std::endl;
        }

        if (op == 4) {
            std::cout << "Enrolled: "
                      << course->getEnrolled()
                      << std::endl;
        }

        if (op == 5) {
            std::cout << "Status of " << name << ": "
                      << course->queryStatus(name)
                      << std::endl;
        }
    }

    delete course;

    return 0;
}
