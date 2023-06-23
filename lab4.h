/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cat_Grade{
	float score1;
	float score2;
	float score3;
	float Cumulative;
};

struct Data{
	char student_name[40];
	int student_ID;

	struct Cat_Grade Cat1;
	struct Cat_Grade Cat2;
	struct Cat_Grade Cat3;
	struct Cat_Grade Cat4;

	float Current_Grade;
	float Final_Grade;
};

typedef struct Node{
        struct Data Student;
	struct Node *next; 
}Node;

/*reads student data from given file and stores in list*/
void readData(char *fileName, Node **list_head, char **categories);

/*calculates the grade for given student*/
void calculateGrades(Node *newNode);

/*prints out student data formatted*/
void printStudent(Node *list_head, char **categories);

/*prints out all student data in list*/
void printGradebook(Node **list_head, char **categories);

/*prints out student grades when recalculated*/
void printNewGrades(Node *data, char **categories);

/*recalculates the grades of all students in list*/
void recalculateAll(Node **list_head, char **categories);

/*updates score for student based on user input*/
void updateScore(Node **data, char **categories);

/*adds student to list in increasing student ID # order*/
void insertNode(Node **list_head, Node *newNode);

/*manually adds student to list based on user input*/
void addStudent(Node **list_head, char **categories);

/*remove student from list*/
void deleteStudent(Node **list_head);

/*calculate the final grade for students in list*/
void calculateFinal(Node **list_head, char **categories);

/*gets the student node based on student ID #*/
void printStudentID(Node **list_head, char **categories);

/*gets the student node based on last name*/
void printLastName(Node **list_head, char **categories);

/*saves list data to file */
void saveData(Node *list_head, char **categories, char *outputName);

/*recalculate the grades of one student*/
void recalculateOne(Node **list_head, char **categories);
