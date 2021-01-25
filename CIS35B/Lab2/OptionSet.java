class OptionSet {

	/* Private variables */
	String name;
	Option[] options;

	/* Constructors */


	/* Getter/Setter methods */
	

	/* Non-static methods */


	/* Static methods */


	/* Print method */
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
		price = "";
	}

	/* Getter/Setter methods */
	public String getName() {

		return name;
	}

	public void setName(String n) {
		
		name = n;
	}

	public String getPrice() {
		
		return price;
	}

	public void setPrice(float p) {
		
		price = p;
	}

	/* Non-static methods */


	/* Static methods */

	/* Print method */
	public String toString() {

		System.out.println("Option: (\"" + name + "\", " + price + ")");
	}
}