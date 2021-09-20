/*
*Program Name: COP 2220 Project 1
*
*Description: GRADE-CALCULATOR
*
*Author: JESSICA JACKSON (N01438472)
*
*Date: SEP 12 21
*/
#include <stdio.h>

int main(void){
    double quiz1Score;
    double quiz2Score;
    double quiz3Score;
    double quiz4Score;
    double quizTotal;
    double midterm1;
    double midterm2;
    double midtermTotal;
    double finalExamgrade;
    const double QUIZ_MAX = 400.00;
    const double MIDTERM_MAX = 200.00;
    const double FINAL_MAX = 100.00;
    const double QUIZ_WEIGHT = 30;
    const double MIDTERM_WEIGHT = 40;
    const double FINAL_WEIGHT = 30;
    double quizPercent;
    double midtermPercent;
    double finalPercent;
    double finalGrade;


    printf("=======QUIZZES=======\n");
    printf("Enter score earned on Quiz 1: ");
    scanf("%lf", &quiz1Score); // getting quiz 1 score

    printf("Enter score earned on Quiz 2: ");
    scanf("%lf", &quiz2Score); // getting quiz 2 score

    printf("Enter score earned on Quiz 3: ");
    scanf("%lf", &quiz3Score); // getting quiz 3 score

    printf("Enter score earned on Quiz 4: ");
    scanf("%lf", &quiz4Score); // getting quiz 4 score

    quizTotal = quiz1Score + quiz2Score + quiz3Score + quiz4Score; // calculating quiz total
    printf("Total score on quizes: %.2lf\n", quizTotal);

    printf("=======MIDTERMS=======\n");
    printf("Enter your score for Midterm 1: ");
    scanf("%lf", &midterm1); // getting midterm 1 score

    printf("Enter your score for Midterm 2: ");
    scanf("%lf", &midterm2); // getting midterm 2 score

    midtermTotal = midterm1 + midterm2; // calculating midterm total

    printf("Total score earned on Midterms: %.2lf\n", midtermTotal);

    printf("=======Final=======\n");
    printf("Enter score in Final exam: ");
    scanf("%lf", &finalExamgrade); // getting final exam grade

    printf("=======Totals=======\n");
    printf("Quiz 1 grade: %12.2lf\n", quiz1Score);
    printf("Quiz 2 grade: %12.2lf\n", quiz2Score);
    printf("Quiz 3 grade: %12.2lf\n", quiz3Score);
    printf("Quiz 4 grade: %12.2lf\n", quiz4Score);
    printf("Quiz Total: %15.2lf\n\n", quizTotal);
    printf("Midterm 1 score: %9.2lf\n", midterm1);
    printf("Midterm 2 score: %9.2lf\n", midterm2);
    printf("Midterm Total: %12.2lf\n\n", midtermTotal);
    printf("Final Exam Grade: %8.2lf\n\n", finalExamgrade);

    quizPercent = (quizTotal / QUIZ_MAX) * QUIZ_WEIGHT; // calculating quiz percent
    midtermPercent = (midtermTotal / MIDTERM_MAX) * MIDTERM_WEIGHT; // calculating midterm percent
    finalPercent = (finalExamgrade / FINAL_MAX) * FINAL_WEIGHT; // calculating final exam percent


    printf("Quiz percentage: %9.2lf%%\n", quizPercent);
    printf("Midterm Percentage: %6.2lf%%\n", midtermPercent);
    printf("Final Percentage: %8.2lf%%\n\n", finalPercent);

    finalGrade = quizPercent + midtermPercent + finalPercent; // calculating final grade

    printf("===Final Grade===\n");
    printf("Your final grade is: %5.2lf%%\n", finalGrade);

    if( finalGrade > 79.999){
        printf("Congrats on the GPA boost!\n");

    }else{
        printf("Better luck next time Friend.\n");
    } // if users grade is above 80 or below 80 it prints one of two statements.

    return 0;
}
