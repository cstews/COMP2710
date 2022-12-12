/* project3_Stewart_cds0081.cpp
* AUTHOR: Courtney Stewart
* cds0081
* Compiler version: Apple clang version 13.1.6
* 
* Utilized Dr. Li's hint on Canvas
*
* Used this https://programmercave0.github.io/blog/2017/08/20/C++-Insertion-Sort-using-STL-(Sorting)
* to find a way to merge the two vectors together in a slightly cleaner way
*
* Caleb from class helped with my read_file method because it wasn't working
*
* John helped me with getting right files to test with thanks g
*/ 
 
#include <fstream> 
#include <iostream> 
#include <vector> 
using namespace std; 

 
//------------------
//defined functions
//------------------

//Checks to see if file exists
bool check_file(string); 
 

//Reads in file using vectors
vector<int> read_file(string); 
 
 
//Writes data to new output value
void write_file(string, vector<int>); 
 
 
//Merges and sorts lists of data
vector<int> merge(vector<int>, vector<int>); 
 

/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/ 
void to_string(string, vector<int>); 
 
 
 
/* 
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/ 
int main() { 
 //variables
 string file1;
 string file2;
 string newFile;

 ifstream inStream1;

 vector<int> nums1;
 vector<int> nums2;
 vector<int> mergedNums;

 int size1;
 int size2;
 int amtMergedNums;

 
 /* Get name of file one. */ 
 do { 

   cout << "*** Welcome to Courtney's sorting program";
   cout << "\nEnter the first input file name: ";
   cin >> file1;

  

 } 
 while (cin.fail() || !check_file(file1)); 
 
 /* Get and display numbers from file one. */ 
 //read in file 1
 nums1 = read_file(file1); 
 size1 = nums1.size();

 //put values into array
 int array1[size1];
 for (int i = 0; i < size1; ++i) {
   array1[i] = nums1[i];
 }

 //print statement for first file
 cout << "The list of " << nums1.size() << " numbers in file " << file1 << " is:\n";
 for (int i = 0; i < size1; ++i) {
   cout << array1[i] << "\n";
 }


 
 /* Get name of file two. */ 
 do { 
   cout << "\nEnter the second input file name: ";
   cin >> file2;


  
 } while (cin.fail() || !check_file(file2)); 
 
 /* Get and display numbers from file two. */ 
 //read in file 2
 nums2 = read_file(file2); 
 size2 = nums2.size();


 //put values into array
 int array2[size2];
 for (int i = 0; i < size2; i++){
   array2[i] = nums2[i];
 }


 //print statement for second file
 cout << "The list of " << nums2.size() << " numbers in file " << file2 << " is:\n";
 for (int i = 0; i < size2; ++i) {
   cout << array2[i] << "\n";
 }
  
 
 /* Combine vectors and display the sorted result. */ 
 mergedNums = merge(nums1, nums2); 

 //assign the amount of merged numbers
 amtMergedNums = size1 + size2;

 //store merged numbers in array
 int array3[amtMergedNums];
 for (int i = 0; i < (amtMergedNums); ++i) {
   array3[i] = mergedNums[i];
 }

 //print statement for merged files
 cout << "The sorted list of " << amtMergedNums << " numbers is: \n";
 for (int i = 0; i < amtMergedNums; ++i) {
   cout << array3[i] << " ";
 }
 
  
 /* Get name of output file. */ 
 do { 
   cout << "\nEnter the output file name: ";
   cin >> newFile;
   
   
 } while (cin.fail()); 
 
 /* Write combined vector to output file. */ 
 write_file(newFile, mergedNums); 

 //print statement for new file
 cout << "*** Please check the new file - " << newFile << " ***\n*** Goodbye. ***" << endl;
 
 return 1; 
} 
 
 
//checks if file exists
bool check_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 
 /* Check whether file exists. */ 
 stream.open(file.c_str()); 
 if (stream.fail()) { 
    cout << "File opening failed. Try again." << endl;
    return false;

   } 
 stream.close(); 
 
 return true; 
} 
 

//store numbers in a vector
vector<int> read_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream inStream1; 
 vector<int> v; 
 
 /* Integer read from file. (int) */ 
 int i; 

 inStream1.open(file.c_str());

 while (inStream1.good()){
  inStream1 >>i;
  v.push_back(i);
 }
 v.pop_back();
 inStream1.close();

 return v;

 }




 //makes output file
void write_file(string file, vector<int> v) { 
 /* Output file stream. (ofstream) */ 
 ofstream outstream;

 unsigned short i;

 outstream.open(file.c_str());
 for (i = 0; i < v.size(); i++) {
    outstream << v.at(i) << "\n";
 }

 outstream << v.at(v.size() -1);
 outstream.close();
 
} 
 

//merges and sorts vector
vector<int> merge(vector<int> v1, vector<int> v2) { 
 
 //new vector holding sorted values
 vector<int> v3;

 //iterator 
 int i;

 //size
 unsigned short s;

 //compare the vectors
 while(v1.size() > 0 && v2.size() > 0) {
 if (v1.at(0) < v2.at(0)) {
			v3.push_back(v1.at(0));
			v1.erase(v1.begin());
		 } 
     else {
			v3.push_back(v2.at(0));
			v2.erase(v2.begin());
		}
 }


 //remaining values in vector 1
 if (v1.size() > 0) {
		s = v1.size();
		for (i = 0; i < s; i++) {
			v3.push_back(v1.at(0));
			v1.erase(v1.begin());
		}
	}
 
 //remaining values in vector 2
 if (v2.size() > 0) {
		s = v2.size();
		for (i = 0; i < s; i++) {
			v3.push_back(v2.at(0));
			v2.erase(v2.begin());
		}
	}
 

 //return sorted vector
 return v3;
    
} 

 
 

void to_string(string file, vector<int> v) { 
 /* Vector interator number. (unsigned short) */ 
 unsigned short i; 
 
 /* Display the numbers contained in a vector. */ 
  
}


 