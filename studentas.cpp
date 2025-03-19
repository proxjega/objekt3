#include "studentas.h"

bool CompareByName(Student a, Student b) {
    return a.name < b.name;
}

bool CompareBySurname(Student a, Student b) {
    return a.surname < b.surname;
}

bool CompareByVid(Student a, Student b) {
    return a.vid < b.vid;
}

bool CompareByMed(Student a, Student b) {
    return a.median < b.median;
}