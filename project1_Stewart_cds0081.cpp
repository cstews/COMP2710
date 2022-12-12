/* FILE NAME: project1_Stewart_cds0081.cpp 
 * AUTHOR: Courtney Stewart
 * cds0081
 * Compiler version: Apple clang version 13.1.6
 * 
 * Utilized Project 1 hint given by Dr. Li on Canvas.
 * Used https://www.educba.com/c-plus-plus-setw/ to learn to use setw() function.
 * Asked Caleb in class for help with formatting error (I forgot to recompile 
 * after fixing an error and would just run it again... oops)
 */ 
 

//imports
#include <iostream> 
#include <iomanip>
#include <limits>
using namespace std; 
 
int main() { 
 // VARIABLE INITIALIZATION 
  double loan, interestRate, monthlyPaid, monthlyRate, monthlyInterest, principal, interestTotal = 0;
                
  
 // CURRENCY FORMATTING 
 cout.setf(ios::fixed); 
 cout.setf(ios::showpoint); 
 cout.precision(2); 
  
 // USER INPUT  
 while (true) {
 cout << "\nLoan Amount: "; 
 cin >> loan; 

 //checking to see if load in positive number
if (loan > 0){
break;
}
else {
      cout << "\nLoan amount must be a positive number.\n";
}
}


  while (true) {
 cout << "Interest Rate (% per year): "; 
 cin >> interestRate; 

 //checking to see if interest rate is a positive number
 if (interestRate > 0){
      break;
 }
 else {
      cout << "\nInterest rate must be a positive number.\n";
 }
  }
  
 
 
 // GET PROPER INTEREST RATES FOR CALCULATIONS 
 interestRate /= 12; 
 monthlyRate = interestRate / 100; 

 while (true) {
 cout << "Monthly Payments: "; 
 cin >> monthlyPaid; 

 monthlyInterest = (loan) * (monthlyRate);

//checking to make sure payment is less than loan amount
if (monthlyPaid < loan) {
break;
}
else {
     cout << "Amount paid must be less than loan amount.\n";
 }  
}
   
 cout << endl; 
  
 // AMORTIZATION TABLE 
 cout << "*****************************************************************\n" 
      << "\tAmortization Table\n" 
      << "*****************************************************************\n" 
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 
 
int currentMonth = 0;

//Sets up the first line
cout << currentMonth << setw(8)  << "$" << loan << "\tN/A" << setw(8) << "N/A"
         << setw(8) << "N/A" << setw(17) << "N/A\n";

 while (loan > 0) { 
     currentMonth++;
     interestTotal += monthlyInterest;
     principal = monthlyPaid - monthlyInterest;

     //Check for final payment being less than principle
     if (loan < principal){
          principal = loan;
          monthlyPaid = principal + monthlyInterest;
     }

     loan -= principal;


cout << setw(8) << left << currentMonth;
        cout << "$";
        cout << setw(15) << left << loan;
        cout << "$";
        cout << setw(8) << left << monthlyPaid;
        cout << setw(8) << left << interestRate;
        cout << "$";
        cout << setw(16) << left << monthlyInterest;
        cout << "$";
        cout << principal << "\n";

monthlyInterest = 0.0;
monthlyInterest = (monthlyRate * loan);
 } 


//Final statement
 cout << "****************************************************************\n"; 
 cout << "\nIt takes " << currentMonth << " months to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << interestTotal; 
 cout << endl << endl;  
 return 0; 
} 
