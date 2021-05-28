import java.util.Scanner;
import java.io.FileWriter;

/*
Name: Rohith Vishwajith
Date: 05/7/2021

Project Title: Lab 3
File: Lab3Main.java
Class: Lab3Main
Description: This class takes a user input for the number
of elements of an array and then takes input for each element
from 1 to 99 (for up to 16 elements).
 */

/*
STEPS:
1. Request/accept input #1 (number of elements)
2. Request/accept type of data to enter (USD/AUD/CAD)
3. Ask for individual data points (validation loop)
4. Create a USD/etc. array

Create a recursive mergesort algorithm (void mergeSort(Dollar arr[], int size))

5. Print out how the array looks after each time the merge sort is called.
6. Print out the final, sorted array.
 */


public class Lab3Main {

    private final int SORT_MAX_SIZE = 16;

    /*
   main()
   Initiates the program by creating an instance of the class.
    */
    public static void main(String[] args) {
        Lab3Main l2m = new Lab3Main();
        int numElements = l2m.getArrayInput();
        Dollar currencyType = l2m.getCurrencyType();
        Dollar[] arr = l2m.getNumberInputs(numElements, currencyType);

        System.out.println("\nEntering merge sort.");
        Dollar[] out = l2m.mergeSort(arr, arr.length);
        l2m.printFinalOutput(out);

    }

    public void printFinalOutput(Dollar[] arr) {
        System.out.println("\nMerge sort complete.\n\nThe sorted " + arr[0].getClass().getName() + " array is:");
        try {
            FileWriter wr = new FileWriter("Output.txt");
            for(int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + ", ");
                wr.write(arr[i] + ", ");
                wr.flush();
            }
            wr.close();
        }
        catch (Exception e) {
            System.err.println("File writing failure.");
        }

    }

    /*
    getCurrencyType()
    prompts the user for a number and validates the input, then returns a
    Dollar object based on the appropriate input.
     */
    public Dollar getCurrencyType() {
        int currencyType = 0;
        Scanner in = new Scanner(System.in);
        boolean validInput = false;

        while(!validInput) {
            try {
                System.out.print("Which currency type would you like to use? \n1. USD\n2. AUD\n3. CAD\nPlease enter a number -> ");
                currencyType = Integer.parseInt(in.next());
                if (currencyType < 1 || currencyType > 3) {
                    System.out.println("Invalid input - number was not between 0 and 3.");
                }
                else {
                    validInput = true;
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input - not a number.");
            }
        }

        if(currencyType == 1) {
            return new USD();
        }
        else if(currencyType == 2) {
            return new AUD();
        }
        else  {
            return new CAD();
        }
    }

    public int getArrayInput() {
        int numElements = 0;
        Scanner in = new Scanner(System.in);

        boolean validInput = false;
        while(!validInput) {
            try {
                System.out.print("Please enter the number of elements you want to use, less than or equal to " + SORT_MAX_SIZE + " -> ");
                numElements = Integer.parseInt(in.next());
                if (numElements < 1 || numElements > SORT_MAX_SIZE) {
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

    public Dollar[] getNumberInputs(int numElements, Dollar dollarType) {
        Scanner in = new Scanner(System.in);
        double inputElement;
        int i = 0;
        System.out.println();

        String type = dollarType.getClass().getName();
        Dollar[] arr = new Dollar[numElements];

        while(i < numElements) {
            System.out.print("[" + (i+1) + "/" + numElements + "] Enter a value for your " + type + " currency, between 1 and 99 -> ");
            try {
                inputElement = Double.parseDouble(in.next());
                if (inputElement < 1 || inputElement > 99) {
                    System.out.println("Invalid input - number was not between 1 and 99.");
                }
                else {
                    Dollar d;
                    if(type.equals("USD")) {
                        d = new USD(0, (int)(inputElement * 100));
                    }
                    else if(type.equals("CAD")) {
                        d = new CAD(0, (int)(inputElement * 100));
                    }
                    else {
                        d = new AUD(0, (int)(inputElement * 100));
                    }
                    arr[i] = d;
                    arr[i].simplifyValues();
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
    mergeSort()
    Takes in a dollar array and sorts it using a divide and conquer algorithm
     */
    public Dollar[] mergeSort(Dollar arr[], int size) {

        System.out.println("\nCurrent array order is:");
        for(int i = 0; i < arr.length; i++) {
            System.out.print("$" + arr[i] + ", ");
        }

        if(size < 2) {
            return arr;
        }

        int midp = size/2;
        Dollar[] left = new Dollar[midp];
        Dollar[] right = new Dollar[size - midp];

        for(int i = 0; i < midp; i++) {
            left[i] = arr[i];
        }

        for(int i = midp; i < size; i++) {
            right[i - midp] = arr[i];
        }

        mergeSort(left, midp);
        mergeSort(right, size - midp);
        recurMergeSort(arr, left, right, midp, size - midp);
        return arr;
    }

    /*
    merge()
    helper function for mergeSort(), checks the sub arrays and merges them into the final array
    merge does the comparison rather than the actual mergeSort() method
     */
    public void recurMergeSort(Dollar[] arr, Dollar[] left, Dollar[] right, int l, int r) {
        int i = 0, j = 0, k = 0;

        while (i < l && j < r) {
            // isGreater()
            if (!left[i].isGreater(right[j])) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
        while (i < l) {
            arr[k++] = left[i++];
        }
        while (j < r) {
            arr[k++] = right[j++];
        }
    }
}
