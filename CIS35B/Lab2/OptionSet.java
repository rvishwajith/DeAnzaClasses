class OptionSet {

	/* Private variables */
	String name;
	Option[] options;

	/* Constructors */


	/* Getter/Setter methods */
	

	/* Non-static methods */


	/* Static methods */


	/* Print method */
	public String toString() {

		String returnVal = "\tOption Set: (\"" + name + "\",)";

		for(int i = 0; i < options.length; i++) {

			returnVal += options[i];
		}
		return returnVal;
	}
}

class Option {

	/* Private variables */
	String name;
	float price;

	/* Constructors */
	public Option(String n, float p) {
		
		name = n;
		price = p;
	}

	public Option(String n) {
		
		this();
		name = n;
	}

	public Option(Float p) {
		
		this();
		price = p;
	}

	public Option() {

		name = "";
		price = 0;
	}

	/* Getter/Setter methods */
	public String getName() {

		return name;
	}

	public void setName(String n) {
		
		name = n;
	}

	public float getPrice() {
		
		return price;
	}

	public void setPrice(float p) {
		
		price = p;
	}

	/* Non-static methods */


	/* Static methods */


	/* Print method */
	public String toString() {

		return "\t\tOption: (\"" + name + "\", " + price + ")";
	}
}