/* project4_Stewart_cds0081.cpp
* AUTHOR: Courtney Stewart
* cds0081
* Compiler version: Apple clang version 13.1.6
* 
* Utilized Dr. Li's hint on Canvas
* Utilized this link to figure out why suddenly my import statements weren't working https://apple.stackexchange.com/questions/254380/why-am-i-getting-an-invalid-active-developer-path-when-attempting-to-use-git-a
* Caleb from class helped me with switching between the debug version and the user input version
*/



//Libary imports.
#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>


using namespace std;



//Structure for creating a linked list that holds a trivia question,answer and point amount.
struct trivia_node {
       string question;
       string answer;
       int point;
       trivia_node *next;
};


//creates the initial questions as linked nodes
void initialQuestionList(trivia_node &n1, trivia_node &n2, trivia_node &n3) {
       n1.question = "How long was the shortest war on record? (Hint: how many minutes)";
       n1.answer = "38";
       n1.point = 100;
       n1.next = &n2;

       n2.question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)?";
       n2.answer = "Bank of Italy";
       n2.point = 50;
       n2.next = &n3;

       n3.question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
       n3.answer = "Wii Sports";
       n3.point = 20;
       n3.next = NULL;
}


//adds the user input question
void addUserQuestion(trivia_node *head) {
       string cont;
       do {
              //sets question node
              trivia_node *next = new trivia_node;
              while (next->question == "") {
                     cout << "Enter a question: ";
                     getline(cin, next->question);
              }
              //sets answer node
              while (next->answer == "") {
                     cout << "Enter an answer: ";
                     getline(cin, next->answer);
              }
              //sets point node
              cout << "Enter award points: ";
              cin >> next -> point;
              //if not valid point value
              while (cin.fail()) {
                     cin.clear();
                     cin.ignore();
                     cout << "Please enter an integer value." << endl;
                     cin >> next->point;
              }

              cin.ignore();

              //set next node to null
              next->next = NULL;

              if (head->question == ""){
                     *head = *next;
              }

              //temporary node
              else{
                     trivia_node *temp = head;

                     while (temp->next != NULL) {
                     temp = temp->next;
               }
                     temp->next = next;
              }

              //prompt user for new question
              cout << "Continue? (Yes/No): ";
              getline(cin, cont);
              transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
              while (cont != "yes" && cont != "no"){
                     cout << "Please enter \"Yes\" or \"No\"" << endl;
                     getline(cin, cont);
                     transform(cont.begin(), cont.end(), cont.begin(), ::tolower);
              }

       } while(cont == "yes");

}

//see how many questions there are
int numberOfQuestions(trivia_node *head) {
       int length = 0;
       trivia_node *current = head;
       while (current != NULL) {
              length++;
              current = current->next;
       }
       return length;
}

//asks player the question and gives points
int askQuestion(trivia_node *head, int number) {
       int playerPoints = 0;
       //check corner cases
       if (head == NULL){
              return 0;
       }
       if (number < 1) {
              cout << "Warning - the number of trivia to be asked must be equal to or larger than 1";
       }
       else if (numberOfQuestions(head) < number) {
              cout << "Warning - there is only " << numberOfQuestions(head) << " trivia questions in the list.";
       }
       //typical case
       else {
              string playerAnswer;
              trivia_node *cur_ptr = head;
              for (int i = 0; i < number; i++) {
                     cout << "Question: " << cur_ptr->question << endl;
                     cout << "Type Your Answer: ";
                     getline(cin, playerAnswer);
                     if (playerAnswer.compare(cur_ptr->answer) == 0) {
                          cout << "Correct! You are awarded " << cur_ptr->point << " points." << endl;
                             playerPoints += cur_ptr->point;
                     }
               else {
                cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
              }
            cur_ptr = cur_ptr->next;
            cout << "Your total points: " << playerPoints << "\n" << endl;
        }
       }
       return playerPoints;
}

//unit test for test cases
void Unit_Test(){
       //instantiate variables
       int totalPoints = 0;
       trivia_node n1, n2, n3;
       initialQuestionList(n1, n2, n3);

       cout << "*** This is a debugging version ***\n";

       //test case 1
       cout << "Unit test case 1: Ask no question. The program should give a warning message." << endl;
       askQuestion(&n1, 0);
       cout << "\nCase 1 Passed\n\n";

       //test case 2.1
       cout << "Unit Test Case 2.1: Ask 1 question in the linked list.  The tester enters an incorrect answer." << endl;
       totalPoints = askQuestion(&n1, 1);
       assert(totalPoints == 0);
       cout << "\nCase 2.1 Passed\n\n";

       //test case 2.2
       cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
       totalPoints = askQuestion(&n1, 1);
       assert(totalPoints != 0);
       cout << "Case 2.2 Passed\n\n";

       //test case 3
       cout << "Unit Test Case 3: Ask all of the questions of the last trivia in the linked list." << endl;
       totalPoints = askQuestion(&n1, 3);
       assert(totalPoints != 0);
       cout << "Case 3 Passed\n\n";

       //test case 4
       cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
       totalPoints = askQuestion(&n1, 5);
       assert(totalPoints == 0);
       cout << "Case 4 Passed\n\n";

       //end of debug
       cout << "\n\n*** End of the Debugging Version ***\n";
}



//main for running program
//to switch between testing mode and normal mode must comment or uncomment the lines specified below
int main() {

       /*------------------------------------------
       *comment this out to toggle off testing mode
       ------------------------------------------*/
       //#define UNIT_TESTING

        #ifdef UNIT_TESTING
        Unit_Test();
        return 0;

       /*------------------------------------------------
       * comment this out too if want to play normal game
       -------------------------------------------------*/
       //#endif


       /*------------------------------------------
       *comment this out for testing mode
       *uncomment for normal mode
       ------------------------------------------*/
       #else

       string input;
       int numberQuestions = 3;
       trivia_node n1, n2, n3;
       initialQuestionList(n1, n2, n3);

       cout << "*** Welcome to Courtney's trivia quiz game ***\n";


       
       cout << "Would you like to add a question? (Yes/No)" << endl;
       getline(cin, input);


       //add user input question
       if (input == "Yes" || "yes"){
              addUserQuestion(&n1);
              numberQuestions++;
       }

       //ask the questions for the game
       askQuestion(&n1, numberQuestions);
       cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";

       return 0;

       /*
       * don't forget this one too
       */
       #endif
 }
