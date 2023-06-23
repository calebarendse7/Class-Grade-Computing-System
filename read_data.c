/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*reads the student data for given file and stores in list*/
void readData(char *fileName, Node **list_head, char **categories){ 
	int i;
	int value;
	
	Node *newNode;
	FILE *input; 
	
	/*open file*/
	input = fopen(fileName, "r");
	
	/*read each category name*/
	for(i = 0; i < 4; i++){
		*(categories + i) = malloc(40 * sizeof(char));
		fscanf(input, "%s", (*(categories + i)));
	}

	/*read each student in file*/
	while(value != EOF){

	/*allocate new node for student*/
	newNode = malloc(sizeof(Node));
	
	/*check if node properly allocated*/
	if(newNode == NULL){
		printf("Error allocating node");
	}else{
		newNode -> next = NULL;

		/*Read student name*/
		value = fscanf(input, " %[^\n]", newNode -> Student.student_name);
		
		if(value != EOF){
			/*Read student ID*/
			fscanf(input, "%i", &(newNode -> Student.student_ID));
			
			/*Read Category Scores*/
			fscanf(input, "%f %f %f", &(newNode -> Student.Cat1.score1), 
			&(newNode -> Student.Cat1.score2), &(newNode -> Student.Cat1.score3));

			fscanf(input, "%f %f %f", &(newNode -> Student.Cat2.score1), 
			&(newNode -> Student.Cat2.score2), &(newNode -> Student.Cat2.score3));

			fscanf(input, "%f %f %f", &(newNode -> Student.Cat3.score1), 
			&(newNode -> Student.Cat3.score2), &(newNode -> Student.Cat3.score3));

			fscanf(input, "%f %f %f", &(newNode -> Student.Cat4.score1), 
			&(newNode -> Student.Cat4.score2), &(newNode -> Student.Cat4.score3));
			
			/*initialize final grade*/
			newNode -> Student.Final_Grade = -1;

			/*calculate grades for new student*/
			calculateGrades(newNode);

			/*add new student to list*/
			insertNode(list_head, newNode);

		}else{
				/*free memory of new student node if no more students*/
				if(newNode != NULL) free(newNode);
		}

		}

	}
	
	/*close file*/
	fclose(input);
}



