#include "course.h"

#include <iostream>

using namespace std;

// TODO
Course::Course(const string &courseName, int quota)
    : courseName(courseName), quota(quota)
{
}

Course::~Course()
{
    cout << courseName << " : "
        << "Enrolled " << getEnrolled()
        << ", Waitlisted " << getWaitlisted()
        << endl;
}

// TODO
string Course::drop(const string &studentName)
{
    for (Node* node = this->studentList.get_head(); node->next; node = node->next) {
        if (node->next->content == studentName) {
            this->studentList.remove(node, node->next);
            return "Successful";
        }
    }

    return "Not existed";
}

// // TODO
string Course::enroll(const string &studentName)
{
    for (Node* node = this->studentList.get_head(); node; node = node->next) {
        if (node->content == studentName) {
            return "Existed";
        }
    }

    this->studentList.insert(this->studentList.get_tail(), new Node(studentName));
    return "Successful";
}

// // TODO
int Course::getWaitlisted()
{
    if (this->studentList.size() <= this->quota) {
        return 0;
    }

    return this->studentList.size() - this->quota;
}

// // TODO
int Course::getEnrolled()
{
    if (this->studentList.size() < this->quota) {
        return this->studentList.size();
    } else {
        return this->quota;
    }
}

// // TODO
string Course::queryStatus(const string &studentName)
{
    int length = -1;
    for (Node* node = this->studentList.get_head(); node; node = node->next) {
        ++length;
        if (node->content == studentName) {
            return length <= quota ? "Enrolled" : "Waitlisted";
        }
    }

    return "Not existed";
}
