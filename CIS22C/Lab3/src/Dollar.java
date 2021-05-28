
/*
Dollar
The abstracted version of the three types of dollar currency. Has methods that are overridden by each of the Dollar subclasses for adding, subtracting, comparing, and checking equality.
 */
abstract class Dollar {

    protected int noteValue;
    protected int fractionalValue;
    protected String region;

    /*
    Constructor
    Default values of $0.00. Region will be unspecified by default.
     */
    public Dollar() {
        noteValue = 0;
        fractionalValue = 0;
        region = "N/A";
    }

    /*
    Constructor
    Accepts custom values for the note and fractional values
    of the object.
     */
    public Dollar(int n, int f) {
        noteValue = n;
        fractionalValue = f;
        region = "N/A";
    }

    /*
    getNoteValue()
    Returns the note value of the Dollar object.
     */
    public int getNoteValue() {
        return noteValue;
    }

    /*
    getFractionalValue()
    Returns the fractional value of the Dollar object
    in the hundredths place.
     */
    public int getFractionalValue() {
        return fractionalValue;
    }

    /*
    add()
    Adds the current Dollar object value and the parameter
    Dollar object value. The result is returned.
     */
    public abstract Dollar add(Dollar d2);

    /*
    subtract()
    Subtracts the second dollar values from the first dollar
    object values. If the result is negative, "null" is returned
    instead.
     */
    public abstract Dollar subtract(Dollar d2);

    /*
    isEqual()
    Checks the equality of two Dollar objects. If the two
    are equal, true is returned. Otherwise, false is returned.
     */
    public abstract boolean isEqual(Dollar d2);

    /*
    isGreater()
    Compares the two Dollar objects' values. If the current
    dollar value ix greater than the parameter value, true
    is returned. Otherwise, false is returned.
     */
    public abstract boolean isGreater(Dollar d2);

    /*
    simplifyValues()
    If the fractional value is greater than 100, any excess
    is converted to an appropriate note value with the remainder
    staying in the fractional value.
     */
    public void simplifyValues() {
        noteValue += getFractionalValue()/100;
        fractionalValue = getFractionalValue()%100;
    }

    public String getRegion() {
        return region;
    }

    public double getDoubleAmount() {
        simplifyValues();
        return getNoteValue() + 0.01 * (getFractionalValue());
    }

    /*
    toString()
    Prints any relevant values.
     */
    public String toString() {
        simplifyValues();
        return ("$" + getNoteValue() + "." + getFractionalValue());
    }
}