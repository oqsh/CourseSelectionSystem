#pragma once
#ifndef READDATA_H
#define READDATA_H

#include "Administrator.h"
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Operator.h"
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <io.h>
#include <fstream>
#include <direct.h>
using namespace std;


void readTeacher(ifstream&);
void readStudent(ifstream&);
void readCourse(ifstream&);

#endif // !READDATA_H
