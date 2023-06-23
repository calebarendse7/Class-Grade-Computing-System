/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*calculates the final grades for each student data stored*/
void calculateFinal(Node **list_head, char **categories){
	float total = 0;
	float grade = 0;
	int k = 0;

	Node *n = *list_head;
	struct Cat_Grade *cat;

	/*go though each student in list*/
	while(n != NULL){
		/*get location of first catagory*/
		cat = &(n-> Student.Cat1);

		/*Generate current grade based off generated cummulative grade*/
		for(k = 0; k < 4; k++){
			/*check if cummulative non zero or set to 100*/
			if((*(cat)).Cumulative > 0){
				grade = (*(cat)).Cumulative;
			}else{
				grade = 0;
			}
			
			/*check which catagory and multiply by correct weight and add to total*/
			if(k == 0){
				total += (grade * 0.15);
			}else if(k == 1){
				total += (grade * 0.30);
			}else if(k == 2){
				total += (grade * 0.20);
			}else if(k == 3){
				total += (grade * 0.35);
			}

		/*Go to next catagory*/
		cat++;
		}


		/*set current grade to generate value*/
		n -> Student.Final_Grade = total;
		total = 0;
		n = n -> next;
	}
	/*recalculate scores and print out*/ 
	recalculateAll(list_head, categories);
}
