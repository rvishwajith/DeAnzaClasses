import java.util.Locale;
import java.util.Scanner;

public class Lab1Main {

    Wallet wallet;

    public static void main(String[] args) {
        Lab1Main lm = new Lab1Main();
        lm.run();
    }

    public void run() {
        startInputLoop();
        System.out.print("\n\nThank you. Program Exited Successfully");
    }

    public void startInputLoop() {
        wallet = new Wallet();
        Scanner in = new Scanner(System.in);

        while(true) {
            printWalletBalance();
            System.out.println("Please enter a number in the parentheses to choose one of the following.");
            System.out.println("(1) Add Currency\n(2) Subtract Currency\n(3) Compare currency\nType \"EXIT\" to exit.");
            System.out.print("Value -> ");
            String value = in.nextLine();

            if(value.toUpperCase().equals("EXIT")) {
                in.close();
                return;
            }
            else if(value.equals("1")) {
                addCurrency();
            }
            else if(value.equals("2")) {
                subtractCurrency();
            }
            else if(value.equals("3")) {
                compareCurrency();
            }
            else {
                System.out.println("Your input was invalid. Please enter a valid number from 1 - 3 or type \"Exit\" to exit the program.");
            }
        }
    }

    public void addCurrency() {
        System.out.println("\nAdd Currency");
        String currencyType = getCurrencyType();
        System.out.println("\nThe currency you chose was " + currencyType + ".\nHow much " + currencyType + " would you like to add?");

        double amount = getCurrencyAmount();
        int noteVal = (int)amount;
        int fractionalVal = (int)((amount - noteVal) * 100);
        if(currencyType.equals("USD")) {
            wallet.add(new USD(noteVal, fractionalVal));
        }
        else if(currencyType.equals("AUD")) {
            wallet.add(new AUD(noteVal, fractionalVal));
        }
        else if(currencyType.equals("CAD")) {
            wallet.add(new CAD(noteVal, fractionalVal));
        }
        System.out.printf("\nSuccessfully added %.2f %s to your wallet.\n", amount, currencyType);
    }

    public void subtractCurrency() {
        System.out.println("\nSubtract Currency");
        String currencyType = getCurrencyType();
        System.out.println("\nThe currency you chose was " + currencyType + ".\nHow much " + currencyType + " would you like to subtract?");

        double amount = getCurrencyAmount();
        int noteVal = (int)amount;
        int fractionalVal = (int)((amount - noteVal) * 100);
        boolean successful = false;

        if(currencyType.equals("USD")) {
            successful = wallet.subtract(new USD(noteVal, fractionalVal));
        }
        else if(currencyType.equals("AUD")) {
            successful = wallet.subtract(new AUD(noteVal, fractionalVal));
        }
        else if(currencyType.equals("CAD")) {
            successful = wallet.subtract(new CAD(noteVal, fractionalVal));
        }

        if(successful) {
            System.out.printf("\nSuccessfully subtracted %.2f %s to your wallet.\n", amount, currencyType);
        }
        else {
            System.out.println("\nYou can't subtract more from the wallet than your current balance.");
        }
    }

    public void compareCurrency() {
        System.out.println("\nCompare Currency");
        String currencyType = getCurrencyType();
        System.out.println("\nThe currency you chose was " + currencyType + ".\nHow much " + currencyType + " would you like to compare to your balance?");
        double amount = getCurrencyAmount();
        int noteVal = (int)amount;
        int fractionalVal = (int)((amount - noteVal) * 100);

        int isGreater = -1;
        if(currencyType.equals("USD")) {
            isGreater = wallet.compare(new USD(noteVal, fractionalVal));
        }
        else if(currencyType.equals("AUD")) {
            isGreater = wallet.compare(new AUD(noteVal, fractionalVal));
        }
        else if(currencyType.equals("CAD")) {
            isGreater = wallet.compare(new CAD(noteVal, fractionalVal));
        }

        if(isGreater == 3) {
            System.out.println("The amount you entered was less than the amount in your wallet.");
        }
        else if(isGreater == 2) {
            System.out.println("The amount you entered was equal to the amount in your wallet.");
        }
        else if(isGreater == 1) {
            System.out.println("The amount you entered was greater than the amount in your wallet.");
        }
        else {
            System.out.println("There was an error with the comparison.");
        }
    }

    public void printWalletBalance() {
        System.out.printf("\nCurrent wallet balance:\nUSD: $%.2f \nCAD: $%.2f \nAUD: $%.2f\n", wallet.getBalances()[0], wallet.getBalances()[1], wallet.getBalances()[2]);
    }

    public Double getCurrencyAmount() {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a decimal value, such as \"100.00\" or \"100\".");
        while(true) {
            System.out.print("Value -> ");
            String value = in.nextLine();
            try {
                Double currencyAmount = Double.parseDouble(value);
                return currencyAmount;
            }
            catch(NumberFormatException e) {
                System.out.println("You entered an invalid decimal value.");
            }
        }
    }

    public String getCurrencyType() {
        System.out.println("Please choose one of the following currencies to use.\n(1) USD\n(2) CAD\n(3) AUD");
        Scanner in = new Scanner(System.in);
        while(true) {
            System.out.print("Value -> ");
            String value = in.nextLine();
            if(value.equals("1")) {
                return "USD";
            }
            else if(value.equals("2")) {
                return "CAD";
            }
            else if(value.equals("3")) {
                return "AUD";
            }
            else {
                System.out.println("Your input was invalid. Please enter a valid number from 1 - 3.");
            }
        }
    }
}