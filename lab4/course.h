#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "linked_list.h"

class Course
{
 public:
    Course(const std::string &courseName, int quota);

    ~Course();

    std::string enroll(const std::string &studentName);

    std::string drop(const std::string &studentName);

    int getWaitlisted();

    int getEnrolled();

    std::string queryStatus(const std::string &studentName);

 private:
    std::string courseName;

    LinkedList studentList;

    int quota;
};

#endif
