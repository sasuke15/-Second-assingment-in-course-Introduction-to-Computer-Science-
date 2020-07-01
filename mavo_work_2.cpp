
/*
	Assigend by:
    Shay Bach #204263842,61101-7
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once-enter 0,cyclically-enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do {
            for (i = 1; i <= 6; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-6:");
                scanf("%d", &select);
            } while ((select < 0) || (select > 6));
            switch (select) {
            case 1:
                Ex1();
                break;
            case 2:
                Ex2();
                break;
            case 3:
                Ex3();
                break;
            case 4:
                Ex4();
                break;
            case 5:
                Ex5();
                break;
            case 6:
                Ex6();
                break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}

/* ------------------- */
/* Exercise1 */
int numer_of_diffirent_element(int* arry, int n)
{
    int i, counter = 0;
    printf("the diffrent elements that are left are:\n");
    for (i = 0; n > i; i++) //increasing the number of the the element
    {
        if (arry[i] != arry[i - 1]) //verify that the number is not equal to the previous number
        {
            arry[counter] = arry[i]; //restart the array
            printf("%d\t", arry[counter]);
            ++counter;
        }
    }
    for (i = counter; n > i; i++) //changing duplicate number into "x"
    {
        arry[counter] = 88;
        printf("%c\t", arry[counter]);
    }
    printf("\n");
    return counter;
}
void Ex1()
{
    int *arry, n, i, condition = 1, condition2 = 1, result, n_minus;
    printf("please enter the size of the arry\n");
    scanf("%d", &n);
    n_minus = n - 1; //preventing array[i+1] from passing the array size
    arry = (int*)calloc(n, sizeof(int));
    printf("please enter the element/s of the arry,the elements must be in a ascending or Descending order.\n Each element must be higher,equal or lower,equal  to the one before it.\n");
    for (i = 0; n > i; i++) //entering number to the array
        scanf("%d", &arry[i]);
    for (i = 0; n_minus > i; i++) //checking if the array is in ascending order
    {
        if (arry[i] > arry[i + 1]) {
            condition = 0;
            break;
        }
    }
    for (i = 0; n_minus > i; i++) //checking if the array is in descending order
    {
        if (arry[i] < arry[i + 1]) {
            condition2 = 0;
            break;
        }
    }
    if ((condition == 1) || (condition2 == 1)) {
        result = numer_of_diffirent_element(arry, n);
        printf("the number of the elemets that are left is:%d\n", result);
    }
    else
        printf("not possibe you didn't write the elementss acording to the instractions.\n");
    free(arry); //releasing the dynamic memory the array
}

/* Exercise2 */
int pluse_one(int n)
{
    int d;
    if (n > 0) {
        d = (n % 10 + 1) % 10; //modle10 the number,add 1 and then modle10 the number again
        n /= 10;

        if (n == 0)
            return d;

        return d + (pluse_one(n) * 10);
    }
    else
        return 1; //if zero=0 the results will be 1
}
void Ex2()
{
    int n;
    printf("please enter a number(the number must not be negetive)\n");
    scanf("%d", &n);
    if (n >= 0) //preventing the user from entering negative number
        printf("the new number is:%d\n", pluse_one(n));

    else //in case the user enter negative number
        printf("you did not write the number acording to the instractions\n");
}
/* Exercise3 */

int tru_or_falls(char* s1, char* s2, char* s, int size_s1, int size_s2, int size_s)
{

    int i, help_arry[26] = { 0 };

    for (i = 0; size_s1 > i; i++)
        help_arry[s1[i] - 97]++;

    for (i = 0; size_s2 > i; i++)
        help_arry[s2[i] - 97]--;

    for (i = 0; size_s > i; i++) {
        if (help_arry[s[i] - 97] > 0)
            help_arry[s[i] - 97]--;
        if (help_arry[s[i] - 97] < 0)
            help_arry[s[i] - 97]++;
    }

    for (i = 0; 26 > i; i++)
        if (help_arry[i] != 0)
            return 0;

    return 1;
}
void Ex3()
{
    char *s1, *s2, *s;
    int size_s1, size_s2, size_s, result;
    printf("please enter the number of letters you want in string s1\n");
    scanf("%d", &size_s1);
    s1 = (char*)malloc((size_s1 + 1) * sizeof(char));
    if (size_s1 > 0) //if there is no size there are no letters in s1
    {
        printf("please enter the letters in s1(without spaces)\n");
        scanf("%s", s1);
    }
    printf("please enter the number of letters you want in string s2\n");
    scanf("%d", &size_s2);
    s2 = (char*)malloc((size_s2 + 1) * sizeof(char));
    if (size_s2 > 0) //if there is no size there are no letters in s2
    {
        printf("please enter the letters in s2(without spaces)\n");
        scanf("%s", s2);
    }
    printf("please enter the number of letters you want in string s\n");
    scanf("%d", &size_s);
    s = (char*)malloc((size_s + 1) * sizeof(char));
    if (size_s > 0) //if there is no size there are no letters in s
    {
        printf("please enter the letters in s(without spaces)\n");
        scanf("%s", s);
    }
    result = tru_or_falls(s1, s2, s, size_s1, size_s2, size_s);
    printf("The ecuotion returned %d\n", result);
    if (result == 1)
        printf("the combination of strings you wrote is true\n");
    else
        printf("the combination of strings you wrote is not true\n");
    free(s); //releasing the dynamic memory of s
    free(s2); //releasing the dynamic memory of s1
    free(s1); //releasing the dynamic memory of s2
}
/* Exercise4 */
void strow(char* arry)
{
    int i, j = 0;
    for (i = 0; arry[i] != '\0'; i++) //checking if the letter is the same previous letter
    {
        if (arry[i] != arry[i - 1]) {
            arry[j] = arry[i];
            ++j;
        }
    }
    arry[j] = 0; //when the letter is 0 the string is ending
    printf("the new string is:\n");
    printf("%s", arry);
    printf("\n");
}
void Ex4()
{
    char* arry;
    int size, i;
    printf("please enter the size of the arry\n");
    scanf("%d", &size);
    arry = (char*)malloc((size + 1) * sizeof(char)); //define arry
    if (size > 0) {
        printf("please enter the letters (space counts as an element)\n");
        rewind(stdin);
        gets(arry);
    }
    else
        arry[size] = 0;
    strow(arry);
    free(arry); //releasing the dynamic memory of array
}
/* Exercise5 */
int amount_of_even_numbers(int* a, int size)
{

    if (size == 0)
        return 0;

    if (a[size - 1] % 2 == 0) //checking if the number is even
        return 1 + amount_of_even_numbers(a, size - 1);

    else
        return amount_of_even_numbers(a, size - 1);
}
void Ex5()
{
    int *arry, size, i, result;
    printf("please enter the size of the arry\n");
    scanf("%d", &size);
    arry = (int*)malloc(size * sizeof(int)); //define array
    printf("please enter the elements of the arry\n");
    for (i = 0; size > i; i++) //add value to elements
        scanf("%d", &arry[i]);
    result = amount_of_even_numbers(arry, size);
    printf("the amount of even numbers is:%d\n", result);
    free(arry); //releasing the dynamic memory of array
}
/* Exercise6 */
void triangle(int* arry, int a)
{
    int i;

    if (a > 0) {
        triangle(arry, a - 1);
        for (i = 0; a > i; i++)
            printf("%d ", arry[i]);
        printf("\n");
    }
}
void Ex6()
{
    int *arry, a, i;
    printf("please enter the size of the arry\n");
    scanf("%d", &a);
    arry = (int*)malloc(a * sizeof(int)); //define array
    printf("please enter the elementss in the arry\n");
    for (i = 0; a > i; i++)
        scanf("%d", &arry[i]); //define the array elements
    printf("\n");
    triangle(arry, a);
    printf("\n");
    free(arry); //releasing the dynamic memory of array
}


