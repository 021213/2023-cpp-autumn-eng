#pragma once
#ifndef ARRAY_INPUT_PROC_H
#define ARRAY_INPUT_PROC_H

void printMenu();
void printInterface(int* arr, int len);
void readInput(int& choice);
void printArray(int* arr, int len);

void processInput(int*& arr, int& len, bool& exit, int choice);
void appendElementProc(int*& arr, int& len);
void extractElementProc(int*& arr, int& len);
void exitProc(bool& exit);
void printProc(int* arr, int len);
void defaultProc();

#endif // !ARRAY_INPUT_PROC_H
