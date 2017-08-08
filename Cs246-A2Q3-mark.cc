#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

const int maxStudents = 20;
const int maxAssignments = 10;

//array to store student userids
string students[maxStudents];

//array to store student final marks
int marks[maxStudents];
/* 
 * Add additional arrays or globals here
 * if needed e.g. to store assignment and exam 
 * max marks, weights etc
 */
int maxmark[maxAssignments+2]; //array to store maxmark of each assignments and exam
int weight[maxAssignments+2]; //array to store weight of each assignments and exam
string course;
int numass=7; // 5 assignments + 2 exam
int valid=0;
/*
 * Reads from standard input the course description
 * Stores this information in some global variables
 */
void readCourseInfo(){
	cout << course << endl;
}
/*
 * Reads from standard input student records.
 * If a student record is invalid, produces desired output
 * If student record is valid, computes and stores student's
 * final mark in the course
 */
void readStudentRecords(){
	while (valid < maxStudents){ //valid record < 20
		string mystr;
		if(!getline(cin,mystr)){//EOF
			break;}
		if(mystr.length() == 0){//empty line
			continue;
		}
		stringstream line(mystr);
		string name;
		int total=0;//total mark
		int mark=0;//mark on this assignment
		int number=0;// number of marks (to test if there is more marks than it should be.
                line >> name;
		while(line >> mark){
			if(number == numass){//more marks than should be
				number++;
				break;
			}
			if(mark <= maxmark[number] && mark >= 0){//valid record
				mark = mark * weight[number] / maxmark[number];
				number++;
				total = total + mark;
			}
			else{//marks > maxmark
				break;
			}
		}
		if(number == numass){
			students[valid] = name;//store in student arr
			marks[valid] = total;//store in marks arr
			valid++;
		}
		else{//output of invalid record
			cout << name << " invalid" << endl;
		}
	}
}
/*
 * Prints the desired output for student's with valid records
*/
void printResults(){
	int ave=0;//average
	cout<< "Valid records: " << valid << endl;//print valid record
	for(int i=0; i< valid; i++){//print valid record
		cout<< students[i] << " " << marks[i]<<endl;
		ave = ave + marks[i];
	}
	if (valid != 0){//print Average
		ave = ave / valid;
		cout <<"Average: " << ave << endl;
	}
	else{//when valid = 0 can't do ave/valid
		cout << "Average: 0" <<endl;
	}
}
  

int main(int argc, char *argv[]) {
	string mystr;
	stringstream ssc (argv[1]);//read course
	ssc >> course;
	if(argc == 3){//has args
	stringstream ssnum (argv[2]);//read args
	ssnum >> numass;
	numass = numass+2;// + two exam
	}
	for(int i=0; i<numass; i++){//read maxmark and weight
		getline(cin,mystr);
		if(mystr.length() == 0){//empty line
			i--;
		}
	stringstream ss(mystr);
	ss >> maxmark[i];
	ss >> weight[i];
       //cout << maxmark[i];
       //cout << weight[i];
	}
	readCourseInfo();
	readStudentRecords();
	printResults();
}
