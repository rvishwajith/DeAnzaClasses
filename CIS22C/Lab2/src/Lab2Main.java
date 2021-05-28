import java.util.Locale;
import java.util.Scanner;

/*
Name: Rohith Vishwajith
Date: 04/30/2021

Project Title: Lab 2
File: Lab2Main.java
Class: Lab2Main
Description: This class takes a user input for the number
of elements of an array and then takes input for each element
from 1 to 99 (for up to 16 elements).
The program generates an array from the input and checks whether it is
prime recursively and iteratively.
 */

public class Lab2Main {

    final int SORT_MAX_SIZE = 16;

    /*
    main()
    Initiates the program by creating an instance of the class.
     */
    public static void main(String[] args) {
        Lab2Main l2m = new Lab2Main();
        int numElements = l2m.getArrayInput();
        int[] arr = l2m.getNumberInputs(numElements);
        l2m.isArrayPrime(arr);
        System.out.println("\nProgram complete.");
    }

    public int getArrayInput() {
        int numElements = 0;
        Scanner in = new Scanner(System.in);

        boolean validInput = false;
        while(!validInput) {
            try {
                System.out.print("Please enter the number of elements you want to generate, less than or equal to " + SORT_MAX_SIZE + " -> ");
                numElements = Integer.parseInt(in.next());
                if (numElements < 1 || numElements > 16) {
                    System.out.println("Invalid input - number was not between 0 and " + SORT_MAX_SIZE + ".");
                }
                else {
                    validInput = true;
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input - not a number.");
            }
        }
        return numElements;
    }

    /*
    getNumberInputs()
    Gets inputs for each element of the array in a user validation
    loop. Rejects input if the number is not in the given range or
    not a valid number entry.
     */
    public int[] getNumberInputs(int numElements) {
        Scanner in = new Scanner(System.in);
        int inputElement;
        int i = 0;
        System.out.println();
        int[] arr = new int[numElements];

        while(i < numElements) {
            System.out.print("[" + (i+1) + "/" + numElements + "] Enter a value, between 1 and 99 -> ");
            try {
                inputElement = Integer.parseInt(in.next());
                if (inputElement < 1 || inputElement > 99) {
                    System.out.println("Invalid input - number was not between 1 and 99.");
                }
                else {
                    arr[i] = inputElement;
                    i++;
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input - not a number.");
            }
        }
        in.close();
        return arr;
    }

    /*
    isArrayPrime()
    The overhead method for checking whether the function is prime
    either recursively or iteratively. The results should be the same
    for each check.
     */
    public void isArrayPrime(int[] arr) {
        System.out.println("\nChecking if the array is prime:\n");
        boolean isPrimeIter = isArrayPrimeIter(arr);
        if(isPrimeIter) {
            System.out.println("Prime Array using iteration");
        }
        else {
            System.out.println("Not a Prime Array using iteration");
        }
        System.out.println();
        boolean isPrimeRecur = isArrayPrimeRecur(arr, 0);
        if(isPrimeRecur) {
            System.out.println("Prime Array using recursion");
        }
        else {
            System.out.println("Not a Prime Array using recursion");
        }
    }

    /*
    isArrayPrimeIter()
    Checks if an array is prime iteratively (using loops)
     */
    public boolean isArrayPrimeIter(int[] arr) {
        System.out.println("Entering isArrayPrimeIter()");
        for(int i = 0; i < arr.length; i++) {
            if(!isNumPrime(arr[i], 2)) {
                System.out.println("Leaving isArrayPrimeIter()");
                return false;
            }
        }
        System.out.println("Leaving isArrayPrimeIter()");
        return true;
    }

    /*
    isArrayPrimeRecur()
    Checks if an array is prime recursively (no loops)
     */
    public boolean isArrayPrimeRecur(int[] arr, int index) {
        System.out.println("Entering isArrayPrimeRecur()");
        if(index == arr.length) {
            return true;
        }
        else {
            if(!isNumPrime(arr[index], 2)) {
                System.out.println("Leaving isArrayPrimeRecur()");
                return false;
            }
        }
        System.out.println("Leaving isArrayPrimeRecur()");
        return isArrayPrimeRecur(arr, index+1);
    }

    /*
    isNumPrime()
    Given an integer, checks if the integer is prime recursively
    The divisor starts at 2 which is the smallest possible
    positive divisor to check for a prime number.
    NOTE: assuming that the iterative method allows for checking
    if a number is prime recursively

    Adapted from C++:
    https://www.geeksforgeeks.org/recursive-program-prime-number/
     */
    public boolean isNumPrime(int num, int divisor) {
        if(num < 2 || num % 2 == 0 || num % divisor == 0) {
            return false;
        }
        else if(divisor * divisor > num) {
            return true;
        }
        return isNumPrime(num, divisor + 1);
    }
}
