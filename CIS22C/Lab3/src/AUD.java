/*
Name: Rohith Vishwajith
Date: 04/19/2021

Project Title: Lab 1
File: AUD.Java
Description: This file contains the extended version of the Dollar
class for USD. The region is specified and the operations are overridden
appropriately.
 */

/*
AUD
A subclass of Dollar with appropriately overridden methods.
 */
class AUD extends Dollar {

    /*
    The region of AUD is Australia.
     */
    public AUD() {
        super(0, 0);
        region = "Australia";
    }

    public AUD(int n, int f) {
        super(n, f);
        region = "Australia";
    }

    public Dollar add(Dollar d2) {
        Dollar newDollar = new USD(getNoteValue() + d2.getNoteValue(), getFractionalValue() + d2.getFractionalValue());
        newDollar.simplifyValues();
        return newDollar;
    }

    public Dollar subtract(Dollar d2) {
        Dollar newDollar = new USD(getNoteValue() - d2.getNoteValue(), getFractionalValue() - d2.getFractionalValue());
        newDollar.simplifyValues();
        if(newDollar.getNoteValue() < 0 || newDollar.getFractionalValue() < 0) {
            return null;
        }
        return newDollar;
    }

    public boolean isEqual(Dollar d2) {
        d2.simplifyValues();
        this.simplifyValues();
        return this.getNoteValue() == d2.getNoteValue() && this.getFractionalValue() == d2.getFractionalValue();
    }

    public boolean isGreater(Dollar d2) {
        d2.simplifyValues();
        this.simplifyValues();
        int value1 = this.getNoteValue() * 100 + this.getFractionalValue();
        int value2 = d2.getNoteValue() * 100 + d2.getFractionalValue();
        return (value1 > value2);
    }
}