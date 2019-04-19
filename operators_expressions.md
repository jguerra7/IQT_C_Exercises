# Operators and Expressions Lab

### Arithmetic

* Write a program to calculate the hypotenuse of a right triangle
* Use the Pythagorean Theorem \(a^2 + b^2 = c^2\)
* Input the two legs \(A and B\)
* Output the hypotenuse \(C\)
* Add this to your code "shell"
  * \#include &lt;math.h&gt; // Math header contains sqrt\(\)
  * **NOTE: **gcc may require a -lm flag. This tells gcc to link a library \(-l\), specifically the math library \(-m\). 

```c
#include <math.h>
double sqrt(double x);

/* Returns the nonnegative square root of x as double */
/* Returns NaN (Not a number) on most errors */
```

### Relational

* Write a relational expression to appropriately test the user input for leg A and then for leg B

### Logical

* Combine the previous Relational expressions with a logical operator so that both must be True

### Error Checking

* Include the Arithmetic, Relational and Logical code in this shell code as indicated by **/\* insert here \*/**

```c
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void) 
{
    /* insert initialize variables here */
    /* insert input values and assign to variables here */
    if (/*insert logical combo of relational expressions here */)
    {
        /* insert arithmetic hypotenuse calculation here */
        /* insert -Print the hypotenuse here */
    }
    return 0;
}
```
