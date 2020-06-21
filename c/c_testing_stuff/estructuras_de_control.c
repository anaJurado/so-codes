// ESTRUCTURAS DE CONTROL
// https://www.programiz.com/c-programming/c-goto-statement
/* IF ELSE */
	if (test expression1) {
	   // statement(s)
	}
	else if(test expression2) {
	   // statement(s)
	}
	else if (test expression3) {
	   // statement(s)
	}
	.
	.
	else {
	   // statement(s)
	}


// Program to relate two integers using =, > or < symbol
#include <stdio.h>
int main() {
    int number1, number2;
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);
    //checks if the two integers are equal.
    if(number1 == number2) {
        printf("Result: %d = %d",number1,number2);
    }
    //checks if number1 is greater than number2.
    else if (number1 > number2) {
        printf("Result: %d > %d", number1, number2);
    }
    //checks if both test expressions are false
    else {
        printf("Result: %d < %d",number1, number2);
    }
    return 0;
}

// Nested if else
#include <stdio.h>
int main() {
    int number1, number2;
    printf("Enter two integers: ");
    scanf("%d %d", &number1, &number2);
    if (number1 >= number2) {
      if (number1 == number2) {
        printf("Result: %d = %d",number1,number2);
      }
      else {
        printf("Result: %d > %d", number1, number2);
      }
    }
    else {
        printf("Result: %d < %d",number1, number2);
    }
    return 0;
}

/* FOR */

	for (initializationStatement; testExpression; updateStatement)
	{
	    // statements inside the body of loop
	}

# Print numbers from 1 to 10
#include <stdio.h>
int main() {
  int i;
  for (i = 1; i < 11; ++i)
  {
    printf("%d ", i);
  }
  return 0;
}

// Program to calculate the sum of first n natural numbers
// Positive integers 1,2,3...n are known as natural numbers
#include <stdio.h>
int main()
{
    int num, count, sum = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    // for loop terminates when num is less than count
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }
    printf("Sum = %d", sum);
    return 0;
}

/* WHILE */

	while (testExpression) 
	{
	    // statements inside the body of the loop 
	}

// Print numbers from 1 to 5
#include <stdio.h>
int main()
{
    int i = 1;
    
    while (i <= 5)
    {
        printf("%d\n", i);
        ++i;
    }
    return 0;
}

/* DO WHILE */

// Program to add numbers until the user enters zero
#include <stdio.h>
int main()
{
    double number, sum = 0;
    // the body of the loop is executed at least once
    do
    {
        printf("Enter a number: ");
        scanf("%lf", &number);
        sum += number;
    }
    while(number != 0.0);
    printf("Sum = %.2lf",sum);
    return

/* SWITCH CASE */



/* BREAK */

// Program to calculate the sum of a maximum of 10 numbers
// If a negative number is entered, the loop terminates
# include <stdio.h>
int main()
{
    int i;
    double number, sum = 0.0;
    for(i=1; i <= 10; ++i)
    {
        printf("Enter a n%d: ",i);
        scanf("%lf",&number);
        // If the user enters a negative number, the loop ends
        if(number < 0.0)
        {
            break;
        }
        sum += number; // sum = sum + number;
    }
    printf("Sum = %.2lf",sum);
    
    return 0;
}

/* CONTINUE */

// Program to calculate the sum of a maximum of 10 numbers
// Negative numbers are skipped from the calculation
# include <stdio.h>
int main()
{
    int i;
    double number, sum = 0.0;
    for(i=1; i <= 10; ++i)
    {
        printf("Enter a n%d: ",i);
        scanf("%lf",&number);
        if(number < 0.0)
        {
            continue;
        }
        sum += number; // sum = sum + number;
    }
    printf("Sum = %.2lf",sum);
    
    return 0;
}

/* GO TO */

	Syntax of goto Statement
	goto label;
	... .. ...
	... .. ...
	label: 
	statement;


// Program to calculate the sum and average of positive numbers 
// If the user enters a negative number, the sum and average are displayed.
# include <stdio.h>
int main()
{
    const int maxInput = 5;
    int i;
    double number, average, sum=0.0;
    
    for(i=1; i<=maxInput; ++i)
    {
        printf("%d. Enter a number: ", i);
        scanf("%lf",&number);
        if(number < 0.0)
            goto jump;
        sum += number;
    }
    jump:
    average=sum/(i-1);
    printf("Sum = %.2f\n", sum);
    printf("Average = %.2f", average);
    return 0;
}
