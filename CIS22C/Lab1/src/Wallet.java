/*
Name: Rohith Vishwajith
Date: 04/19/2021

Project Title: Lab 1
File: Wallet.Java
Description: This file contains the Wallet class, which holds separate
values for USD, CAD, and AUD< which can all be modified or compared.
 */

/*
Wallet
Stores three different dollar objects for USD, CAD, and AUD, which can
be operated on appropriately with only other Dollar objects of the same
region. The subtract() method intentionally has a return type of boolean
to easily check whether the operation was successful.
 */
public class Wallet {

    private Dollar[] dollarObjects;

    /*
    Constructor
    Creates default dollar objects with empty (0) values.
     */
    public Wallet() {
        dollarObjects = new Dollar[] {new USD(), new CAD(), new AUD()};
    }

    /*
    Constructor
    Uses explicit values for each of the dollar objects.
     */
    public Wallet(Dollar d1, Dollar d2, Dollar d3) {
        dollarObjects = new Dollar[] {d1, d2, d3};
    }

    /*
    Returns the correct index based on the region
     */
    public int getIndex(Dollar d2) {
        if(d2.getRegion().equals("the United States of America")) {
            return 0;
        }
        else if(d2.getRegion().equals("Canada")) {
            return 1;
        }
        else if(d2.getRegion().equals("Australia")) {
            return 2;
        }
        return -1;
    }

    /*
    ADD METHODS
     */
    public void add(Dollar d2) {
        int index = getIndex(d2);
        dollarObjects[index] = dollarObjects[index].add(d2);
    }

    /*
    SUBTRACT METHODS
     */
    public boolean subtract(Dollar d2) {
        int index = getIndex(d2);
        if(dollarObjects[index].subtract(d2) == null) {
            return false;
        }
        else {
            dollarObjects[index] = dollarObjects[index].subtract(d2);
        }
        return true;
    }

    /*
    EQUALITY METHODS
     */
    public boolean isEqual(Dollar d2) {
        int index = getIndex(d2);
        return (dollarObjects[index].isEqual(d2));
    }

    /*
    COMPARISON METHODS
     */
    public boolean isGreater(Dollar d2) {
        int index = getIndex(d2);
        return (dollarObjects[index].isGreater(d2));
    }

    public int compare(Dollar d2) {
        int index = getIndex(d2);
        if(dollarObjects[index].isGreater(d2)) {
            return 3;
        }
        else if(dollarObjects[index].isEqual(d2)) {
            return 2;
        }
        else {
            return 1;
        }
    }

    /*
    getBalances()
    Returns the balances of every Dollar object.
     */
    public Double[] getBalances() {
        return new Double[] {dollarObjects[0].getDoubleAmount(), dollarObjects[1].getDoubleAmount(), dollarObjects[2].getDoubleAmount()};
    }

    public Dollar[] getDollars() {
        return dollarObjects;
    }
}
