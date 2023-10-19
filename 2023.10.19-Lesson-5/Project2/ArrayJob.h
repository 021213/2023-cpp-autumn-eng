#pragma once
#ifndef ARRAY_JOB_H
#define ARRAY_JOB_H

void expandArray(int*& arr, int& len);
void contractArray(int*& arr, int& len);
void appendElement(int*& arr, int& len, int element);
bool indexValid(int index, int len);
int extractElementByIndex(int*& arr, int& len, int index);

#endif // ARRAY_JOB_H
//TODO: implement "#pragma twice" with the help of "#ifndef" "#ifdef" and "#define"