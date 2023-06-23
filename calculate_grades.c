/*
BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.

AUTHOR: Caleb Arendse
*/
#include "lab4.h"

/*calculate the grades for each student*/
void calculateGrades(Node *newNode){
	int i, k;

	float total = 0;
	float divisor = 3;
	float currentGrade = 0;

	float *grade;

	struct Cat_Grade *cat;
 
	/*get location of first catagory*/
	cat = &(newNode -> Student.Cat1);

	/*Process each each catagory to generate the cummulative grade*/
	for(k = 0; k < 4; k++){
		grade = &((*cat).score1);

			/*Process each grade in catagory*/
			for(i = 0; i < 3; i++){
			
				/*add current grade to total or decrement divisor by 1 if -)*/
				if(*grade > 0){
					total += *grade;
	
				}else{
					divisor--;

				}

					grade++;
			}

			/*divide total by correct divisor or set equal to -1*/
			if(divisor > 0){
			total /= divisor;

			}else{
			total = -1;

			}

	/*Set catagory cummulative grade to generate total*/
	(*(cat)).Cumulative = total;

	/*Go to next catagory*/
	cat++;

	/*Reset divisor and total*/
	divisor = 3;
 	total = 0;
	}

	/*reset back to first catagory*/
	cat = &(newNode -> Student.Cat1);
	total = 0; 
	
	/*Generate current grade based off generated cummulative grade*/
	for(k = 0; k < 4; k++){
		/*check if cummulative non zero or set to 100*/
		if((*(cat)).Cumulative > 0){
			currentGrade = (*(cat)).Cumulative;
		}else{
			currentGrade = 100;
		}
		
		/*check which catagory and multiply by correct weight and add to total*/
		if(k == 0){
			total += currentGrade * 0.15;
		}else if(k == 1){
			total += (currentGrade * 0.30);
		}else if(k == 2){
			total += (currentGrade * 0.20);
		}else if(k == 3){
			total += (currentGrade * 0.35);
		}

	/*Go to next catagory*/
	cat++;
	currentGrade = 0;
	}
	
	/*set current grade to generate value*/
	newNode -> Student.Current_Grade = total;

	
	
}
