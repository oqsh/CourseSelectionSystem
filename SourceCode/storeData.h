#pragma once
#ifndef STOREDATA_H
#define STOREDATA_H

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

void writeTeacher(ostream&);
void writeStudent(ostream&);
void writeCourse(ofstream&);
#endif // !STOREDATA_H
