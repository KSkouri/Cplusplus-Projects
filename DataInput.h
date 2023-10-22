#pragma once
#ifndef DATAINPUT_H
#define DATAINPUT_H

class DataInput {
   public:
       void PrintMenu();
       void DisplayWithoutDeposits();
       void DisplayWithDeposits();

   private:
       double initialInvestment;
       double monthlyDeposit;
       double annualInterest;
       int numYears;
};

#endif