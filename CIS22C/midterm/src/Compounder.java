import java.util.Scanner;

/*
Name: Rohith Vishwajith
Date: 05/13/2021

Project Title: Midterm
File: Compounder.java
Class: Compounder
 */

public class Compounder {

    final int MAX_WORDS = 32;

    public static void main(String[] args) {
        Compounder c = new Compounder();
        String[] words = c.getWordInput();
        c.printAllCompounds(words);
    }

    public String[] getWordInput() {
        String[] input;
        Scanner in = new Scanner(System.in);
        System.out.print("Please enter a list of up to " + MAX_WORDS + " words -> ");
        input = in.nextLine().split(" ");

        if(input.length > MAX_WORDS) {
            System.out.println("Invalid input. You entered too many words.\n");
        }
        return input;
    }

    public void printAllCompounds(String[] words) {
        String[] duplicates = new String[words.length * words.length];
        int activeWords = 0;
        for(int i = 0; i < words.length; i++) {
            for(int j = 0; j < words.length; j++) {
                if(i != j) {
                    String currWord = words[i] + words[j];
                    boolean duplicate = false;
                    for(int x = 0; x < activeWords; x++) {
                        if(duplicates[x].equals(currWord)) {
                            duplicate = true;
                        }
                    }
                    if(duplicate == false) {
                        duplicates[activeWords] = currWord;
                        activeWords++;
                        System.out.print(currWord + " ");
                    }
                }
            }
        }
    }
}
