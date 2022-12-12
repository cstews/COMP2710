/* project2_Stewart_cds0081.cpp
* AUTHOR: Courtney Stewart
* cds0081
* Compiler version: Apple clang version 13.1.6
*
* Utilized Dr. Li's hint on canvas
* Asked Parker in class for clarification on Charlie_shoots method and test
*
*/

#include <iostream> 
#include <stdlib.h> 
#include <assert.h> 
#include <ctime> 
using namespace std; 
/* 
* Input: A_alive indicates Aaron is alive true for alive, false for dead 
*   B_alive indicates Bob is alive 
*   C_alive indicates Charlie is alive 
* Return: true if at least two are alive otherwise return false 
*/ 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive); 
 
/* 
* Call by reference 
* Strategy 1: Everyone shoots to kill the highest accuracy player alive 
* Input: B_alive indicates Bob is alive or dead 
*  C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Aaron_shoots1(bool& B_alive, bool& C_alive); 
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  C_alive indicates Charlie is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change C_alive into false if Charlie is killed 
*/ 
void Bob_shoots(bool& A_alive, bool& C_alive); 
 
/* 
* Call by reference 
* Input: A_alive indicates Aaron is alive or dead 
*  B_alive indicates Bob is alive or dead 
* Return: Change A_alive into false if Aaron is killed 
*    Change B_alive into false if Bob is killed 
*/ 
void Charlie_shoots(bool& A_alive, bool& B_alive); 
 
/* 
* Call by reference 
* Strategy 2: Aaron intentionally misses if both are alive 
* Input: B_alive indicates Bob is alive or dead 
* C_alive indicates Aaron is alive or dead 
* Return: Change B_alive into false if Bob is killed 
* Change C_alive into false if Charlie is killed 
*/ 
void Aaron_shoots2(bool& B_alive, bool& C_alive); 
 
//Simple method to implement pause function in linux 
void Press_any_key(void); 
 
//TEST PROTOTYPES 
void test_at_least_two_alive(void); 
void test_Aaron_shoots1(void); 
void test_Bob_shoots(void); 
void test_Charlie_shoots(void); 
void test_Aaron_shoots2(void); 
bool at_least_two_alive(bool, bool, bool);
 
//VARIABLES 
const int TOTAL_RUNS = 10000;
const int aaronProbability = 33;
const int bobProbability = 50;
 
int main() { 

//VARIABLES 
int aaronWins1 = 0;
int bobWins1 = 0;
int charlieWins1 = 0;
int aaronWins2 = 0;
int bobWins2 = 0;
int charlieWins2 = 0;

bool aaronAlive;
bool bobAlive;
bool charlieAlive;


 //Initializes Random number generator's seed and calls test functions 
 cout << "*** Welcome to Courtney's Duel Simulator ***\n"; 
 srand(time(0)); 
 test_at_least_two_alive(); 
 Press_any_key(); 
 test_Aaron_shoots1(); 
 Press_any_key(); 
 test_Bob_shoots(); 
 Press_any_key(); 
 test_Charlie_shoots(); 
 Press_any_key(); 
 test_Aaron_shoots2(); 
 Press_any_key(); 
  
 //Starts strategy 1 and runs 10,000 times 
 cout << "Ready to test strategy 1 (run 10000 times):\n"; 

 Press_any_key(); 

 for (int i = 0; i < TOTAL_RUNS; i++ ){ 

    aaronAlive = true;
    bobAlive = true;
    charlieAlive = true;

  while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) { 
    //testing to see who makes it out alive
    if (aaronAlive){
        Aaron_shoots1(bobAlive, charlieAlive);
    }

    if (bobAlive) {
        Bob_shoots(aaronAlive, charlieAlive);
    }

    if (charlieAlive) {
        Charlie_shoots(aaronAlive, bobAlive);
    }
  }
    //giving the points to the winner
    if (aaronAlive){
        aaronWins1++;
    }

    if (bobAlive){
        bobWins1++;
    }

    if (charlieAlive){
        charlieWins1++;
    }
  } 

//print statement for strategy 1
 cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins1 << "/10000 duels or " << static_cast<double>(bobWins1) / TOTAL_RUNS * 100 << "%\n" 
      << "Charlie won " << charlieWins1 << "/10000 duels or " << static_cast<double>(charlieWins1) / TOTAL_RUNS * 100 << "%\n" 
      << endl; 
  
 //Reinitializes variables for strategy 2
    aaronAlive = true;
    bobAlive = true;
    charlieAlive = true;

 cout << "Ready to test strategy 2 (run 10000 times):\n"; 
 Press_any_key(); 


 for (int i = 0; i < TOTAL_RUNS; i++ ){ 

    aaronAlive = true;
    bobAlive = true;
    charlieAlive = true;

  while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) { 
 //testing who survives
    if (aaronAlive){
        Aaron_shoots2(bobAlive, charlieAlive);
    }

    if (bobAlive){
        Bob_shoots(aaronAlive, charlieAlive);
    }

    if (charlieAlive){
        Charlie_shoots(aaronAlive, bobAlive);
    }

  } 

 //add points to whoever survived
    if (aaronAlive){
        aaronWins2++;
    }
 
    if (bobAlive) {
    bobWins2++;
    } 
    
     if (charlieAlive) {
    charlieWins2++;
    }
   
 } 

//print statement for strategy 2
 cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins2 << "/10000 duels or " << static_cast<double>(bobWins2) / TOTAL_RUNS * 100 << "%\n" 
      << "Charlie won " << charlieWins2 << "/10000 duels or " << static_cast<double>(charlieWins2) / TOTAL_RUNS * 100 << "%\n" 
      << endl; 
  

 if (aaronWins1 > aaronWins2) { 
  cout << "Strategy 1 is better than strategy 2.\n"; 
    } 

 else { 
  cout << "Strategy 2 is better than strategy 1.\n"; 
    } 
  
 return 0; 
} 
 

//---------
//FUNCTIONS
//---------

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) { 
    //check if A and someone else is alive
 if (A_alive) {
    if (B_alive || C_alive){
        return true;
    }
 }

    //check if B and C are alive
 else if (B_alive){
    if (C_alive){
        return true;
    }
 }
    //if here less than 2 alive
    return false;

} 
 
void test_at_least_two_alive(void) { 
 cout << "Unit Testing 1: Function - at_least_two_alive()\n"; 

 cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n"; 
 assert(true == at_least_two_alive(true, true, true)); 
 cout << "\tCase passed ...\n"; 
  

 cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n"; 
 assert(true == at_least_two_alive(false, true, true)); 
 cout << "\tCase passed ...\n"; 


 cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n"; 
 assert(true == at_least_two_alive(true, false, true)); 
 cout << "\tCase passed ...\n"; 


 cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n"; 
 assert(true == at_least_two_alive(true, true, false)); 
 cout << "\tCase passed ...\n"; 


 cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n"; 
 assert(false == at_least_two_alive(false, false, true)); 
 cout << "\tCase passed ...\n"; 


 cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n"; 
 assert(false == at_least_two_alive(false, true, false)); 
 cout << "\tCase passed ...\n"; 


 cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n"; 
 assert(false == at_least_two_alive(true, false, false)); 
 cout << "\tCase passed ...\n"; 


 cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n"; 
 assert(false == at_least_two_alive(false, false, false)); 
 cout << "\tCase passed ...\n"; 

 
} 
 

//function for who Aaron shoots in strategy 1
void Aaron_shoots1(bool& B_alive, bool& C_alive) { 

 int shootResult = rand() % 100; 

 if (shootResult <= aaronProbability){
    if (C_alive) { 
        C_alive = false;
    } 

 else { 
  B_alive = false;
 } 
} 
}
 
//tests for Aaron shooting
void test_Aaron_shoots1(void) { 
 cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n"; 

 bool bob_a;
 bool charlie_a; 
 
 cout << "\tCase 1: Bob alive, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 bob_a = true;
 charlie_a = true;
 Aaron_shoots1(bob_a, charlie_a); 
 assert(true == bob_a);
  

 bob_a = false; 
 charlie_a = true; 
 cout << "\tCase 2: Bob dead, Charlie alive\n" 
      << "\t\tAaron is shooting at Charlie\n"; 
 Aaron_shoots1(bob_a, charlie_a); 
 assert(false == bob_a);
 

 bob_a = true; 
 charlie_a = false; 
 cout << "\tCase 3: Bob alive, Charlie dead\n" 
      << "\t\tAaron is shooting at Bob\n"; 
 Aaron_shoots1(bob_a, charlie_a); 
 assert(false == charlie_a);

} 
 
 //function of Bob shooting
void Bob_shoots(bool& A_alive, bool& C_alive) { 

    int shootResult = rand() % 100; 

    if (shootResult <= bobProbability){
    if (C_alive) { 
        C_alive = false;
    } 

    else { 
    A_alive = false;
        } 
    } 
}

//tests for Bob shooting
void test_Bob_shoots(void) { 
 bool aaron_A;
 bool charlie_A;

 cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

 cout << "\tCase 1: Aaron alive, Charlie alive\n";
 cout << "\t\tBob is shooting at Charlie\n";
 aaron_A = true;
 charlie_A = true;
 Bob_shoots(aaron_A, charlie_A);
 assert(true == aaron_A);


 cout << "\tCase 2: Aaron dead, Charlie alive\n";
 cout << "\t\tBob is shooting at Charlie\n";
 aaron_A = false;
 charlie_A = true;
 Bob_shoots(aaron_A, charlie_A);
 assert(false == aaron_A);


 cout << "\tCase 3: Aaron alive, Charlie dead\n";
 cout << "\t\tBob is shooting at Aaron\n";
 aaron_A = true;
 charlie_A = false;
 Bob_shoots(aaron_A, charlie_A);
 assert(false == charlie_A);

} 
  



//function of Charlie shooting
void Charlie_shoots(bool& A_alive, bool& B_alive) { 

     if (B_alive) { 
        B_alive = false;
     } 

     else { 
     A_alive = false;
        } 
    } 

 

 //test for Charlie shooting
 void test_Charlie_shoots(void) { 


 cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

 bool aaron_A;
 bool bob_A;

 cout << "\tCase 1: Aaron alive, Bob alive\n";
 cout << "\t\tCharlie is shooting at Bob\n";
 aaron_A = true;
 bob_A = true;
 Charlie_shoots(aaron_A, bob_A);
 assert(true == aaron_A);
 assert(false == bob_A);
 
 cout << "\tCase 2: Aaron dead, Bob alive\n";
 cout << "\t\tCharlie is shooting at Bob\n";
 aaron_A = false;
 bob_A = true;
 Charlie_shoots(aaron_A, bob_A);
 assert(false == aaron_A);
 assert(false == bob_A);

 cout << "\tCase 3: Aaron alive, Bob dead\n";
 cout << "\t\tCharlie is shooting at Aaron\n";
 aaron_A = true;
 bob_A = false;
 Charlie_shoots(aaron_A, bob_A);
 assert(false == aaron_A);
 assert(false == bob_A);
 } 


//function of Aaron shooting a second time
void Aaron_shoots2(bool& B_alive, bool& C_alive) { 
 int shootResult = rand() % 100; 

if (!B_alive || !C_alive) {
    if (shootResult <= aaronProbability){
        if (C_alive){
            C_alive = false;
        }
        else {
            B_alive = false;
        }
    }
}

} 
 
//test for Aaron shooting the second time
void test_Aaron_shoots2(void) { 

 cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

 bool bob_A;
 bool charlie_A;


 cout << "\tCase 1: Bob alive, Charlie alive\n";
 cout << "\t\tAaron intentionally missed his first shot\n";
 cout << "\t\tBoth Bob and Charlie are alive\n";
 bob_A = true;
 charlie_A = true;
 Aaron_shoots2(bob_A, charlie_A);
 assert(true == bob_A);
 assert(true == charlie_A);


 cout << "\tCase 2: Bob dead, Charlie alive\n";
 cout << "\t\tAaron is shooting at Charlie\n";
 bob_A = false;
 charlie_A = true;
 Aaron_shoots2(bob_A, charlie_A);
 assert(false == bob_A);


 cout << "\tCase 2: Bob alive, Charlie dead\n";
 cout << "\t\tAaron is shooting at Bob\n";
 bob_A = true;
 charlie_A = false;
 Aaron_shoots2(bob_A, charlie_A);
 assert(false == charlie_A);

} 
 
 //function to continue
void Press_any_key(void) { 
 cout << "Press any key to continue..."; 
 cin.ignore().get();  
}