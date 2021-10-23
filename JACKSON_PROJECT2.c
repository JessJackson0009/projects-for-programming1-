/*
*Program Name: COP 2220 Project 2
*
*Description: MORTGAGE-CALCULATOR
*
*Author: JESSICA JACKSON (N01438472)
*
*Date: OCT 25 21
*/
#include <stdio.h>
#include <math.h>

double UserInputLoan(double maxLoan, double minLoan)
{ //getting input and checking ranges of oan amount
    
    double loanAmount;
    
    printf("Enter loan amount (ZERO TO QUIT): ");
    scanf("%lf", &loanAmount);
    while(loanAmount < minLoan || loanAmount > maxLoan){
        if(loanAmount == 0){
        printf("quit\n");
        printf("Enter loan amount (ZERO TO QUIT): ");
        scanf("%lf", &loanAmount);
    }
    else{
        printf("Invalid amount. Valid between 5000 - 2000000\n");
        printf("Enter loan amount (ZERO TO QUIT): ");
        scanf("%lf", &loanAmount);
    }
}
return loanAmount;
}
double UserInputInterest(double minInterest, double maxInterest)
{ //getting input and checking ranges on interest

double annualInterestRate;

    printf("Enter annual interest rate (ZERO TO QUIT): ");
    scanf("%lf", &annualInterestRate);
    while(annualInterestRate < minInterest || annualInterestRate > maxInterest){
        if(annualInterestRate == 0){
            printf("quit\n");
            printf("Enter annual interest rate (ZERO TO QUIT): ");
            scanf("%lf", &annualInterestRate);
        }
        else{
            printf("Invalid amount. Valid between 1 - 20\n");
            printf("Enter annual interest rate (ZERO TO QUIT): ");
            scanf("%lf", &annualInterestRate);
        }
    }
return annualInterestRate;
}
int UserInputYears(int minYears, int maxYears)
{ //getting input and checking ranges of time

    int years;

    printf("Enter years on loan (ZERO TO QUIT): ");
    scanf("%d", &years);
    while(years < minYears || years > maxYears){
        if(years == 0){
            printf("quit\n");
            printf("Enter years on loan (ZERO TO QUIT): ");
            scanf("%d", &years);
        }
        else{
            printf("Invalid amount. Valid between 2 - 40\n");
            printf("Enter years on loan (ZERO TO QUIT): ");
            scanf("%d", &years);
        }
    }
return years;
}

double FixedMonthlyPymts(double annualInterest, double loan, double time)
{ // finding the fixed monthly payments

double monthlypayments;
double monthlyInterest;
int paymentPeriods;
monthlyInterest = annualInterest / 100 / 12;
double onePlusMonthlyInterest = 1 + monthlyInterest;
paymentPeriods = time * 12;
monthlypayments = (loan * monthlyInterest) * (pow(onePlusMonthlyInterest, paymentPeriods)) / (pow(onePlusMonthlyInterest, paymentPeriods) - 1);

printf("Loan monthly payments: %.2lf\n", monthlypayments);


return monthlypayments;
}

double MonthlyInterestPayments(double loanTotal, double Interest)
{ // finding monthly interest pymts

    double monthInterestRate = Interest / 100 / 12;
    double interestOnLoan = loanTotal * monthInterestRate;

    return interestOnLoan;
}
double MonthlyPrinciple(double monthInt, double fixed)
{// finding monthly principle pymts
    double principle;

    principle = fixed - monthInt;
        
return principle;
}
double PrincBalance(double monthInt, double principle, double loanamount)
{// calculating new principle

     double newBalance = loanamount - principle;

return newBalance;
}

void PrintTable(double principle, double newBalance, double loanAmount, double monthInt, double fixed, int payPeriods, double rate)
{// printing table

    int i;
    int months = payPeriods;
    double allTotal;
    double allInterest;
    double allPrinciple;

    allPrinciple = loanAmount;

    printf("\n\n|Mnt|  | Old blnc ||  Mnthly  || Interest ||  Princp  ||   New    |\n");

    for(i = 1; i <= months; ++i)
    {

        principle = MonthlyPrinciple(monthInt, fixed);
        newBalance = PrincBalance(monthInt, principle, loanAmount);
        monthInt = MonthlyInterestPayments(loanAmount, rate);

        allTotal += fixed;

        printf("\n%4d|  |%10.2f||%10.2f||%10.2f||%10.2f||%10.2f|", i, loanAmount, fixed, monthInt, principle, newBalance);

        loanAmount = newBalance;
        monthInt = newBalance * ( rate / 100 / 12 );
        allInterest = allTotal - allPrinciple;

    }

    printf("\n\n");
    printf("Total amount paid on loan: $%.2lf\n", allTotal);
    printf("Total in Interest paid on loan: $%.2lf\n", allInterest);
    printf("Total Principle paid on loan: $%.2lf\n", allPrinciple);
}



int main(){
    const double MINLOAN = 5000;
    const double MAXLOAN = 2000000;
    const double MININTEREST = 1;
    const double MAXINTEREST = 20;
    const int MINYEARS = 2;
    const int MAXYEARS = 40;
    double loanAmount = UserInputLoan(MAXLOAN, MINLOAN);
    double annualInterestRate = UserInputInterest(MININTEREST, MAXINTEREST);
    int years = UserInputYears(MINYEARS, MAXYEARS);
    int payPeriods = years * 12;
    int i;


    const double FIXEDPYMT = FixedMonthlyPymts(annualInterestRate, loanAmount, years); 
    double monthInterest = MonthlyInterestPayments(loanAmount, annualInterestRate); 
    double principle = MonthlyPrinciple(monthInterest, FIXEDPYMT); 
    double newBalance = PrincBalance(monthInterest, principle, loanAmount);

    PrintTable(principle, newBalance, loanAmount, monthInterest, FIXEDPYMT, payPeriods, annualInterestRate);



    return 0;
}
