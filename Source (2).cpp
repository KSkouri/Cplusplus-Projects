/*
 * Kirsten Skouri
 * 9/29/23
 * Module 5, Project 2
 */

#include <iostream>
#include "DataInput.h"
using namespace std;

int main() {
    DataInput user1;

    user1.PrintMenu();

    user1.DisplayWithoutDeposits();

    user1.DisplayWithDeposits();

    return 0;
}