/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*program that creates linked list from student data with options to modify list*/
int main(int argc, char **argv){
	int i;
	int count = 0; 
	int choice, value;

	/*capture input and output file names*/
	char *inputName = *(argv + 1);
	char *outputName = *(argv + 2);

	char **categories; 
	
	/*create list head and traverse pointer*/
	Node *list_head = NULL;
	Node *n = NULL;
	Node *current = NULL;
	
	
	/*array containing functions*/
	void (*fp[7])(Node **, char **) = {printStudentID, printLastName, printGradebook, recalculateOne, recalculateAll, updateScore, calculateFinal};

	/*allocate categories*/
	categories = malloc(4 * sizeof(char *));

	/*read in student data from file*/
	readData(inputName, &list_head, categories);

	/*count students in list*/
	n = list_head;
	while(n != NULL){
		count ++;
		n = n -> next;		
	}
	
	printf("Student data read in successfully, saved %i students.\n", count);
	
	/*menu for options*/
	while(value != 1){
		/*print options*/
		printf("Options:\n");
		printf("1: Print single student record using ID \n2: Print single student record using last name");
	 	printf("\n3: Print all student records\n4: Recalculate single student grades");
		printf("\n5: Recalculate all student scores\n6: Insert new score for student");
		printf("\n7: Calculate final grades\n8: Add new student\n9: Delete student\n10: Exit \n"); 

		printf("Choose from the following options: ");
		scanf("%i", &choice);
		
		/*call correct function based on choice*/
		switch(choice){
			case 1: 
				fp[0](&list_head, categories);
			break;
			case 2:
				fp[1](&list_head, categories);
			break;
			case 3: 
				fp[2](&list_head, categories);
			break;
			case 4:
				fp[3](&list_head, categories);
			break;
			case 5:
				fp[4](&list_head, categories);
			break;
			case 6:
				fp[5](&list_head, categories);
			break;
			case 7:
				fp[6](&list_head, categories);
			break;
			case 8: 
				addStudent(&list_head, categories);
			break;
			case 9: 
				deleteStudent(&list_head);
			break;	
			case 10:
				value = 1;
			break;	
			default:
				printf("ERROR: Invalid Selection.\n");
			break;
		}

	}
	n = list_head;
count = 0;
	while(n != NULL){
		count ++;
		n = n -> next;		
	}
	
	printf("Student data read in successfully, saved %i students.\n", count);
	
	if(outputName != NULL){
		saveData(list_head, categories, outputName);
	}

	/*free nodes in list*/
	n = list_head;

	while(n != NULL){
		current = n;
		n = n -> next;
		free(current);
	}
	
	/*free categories*/
	for(i = 0; i < 4; i++){
		if(*(categories + i) != NULL) free(*(categories+i));
	}
	if(categories != NULL) free(categories);
	
	return(0);
}
