class Automotive {

	/* Private variables */
	String name;
	float basePrice;
	OptionSet optionSets[];

	/* Constructors */

	public Automotive(String n, float b, OptionSet[] o) {

		name = n;
		basePrice = b;
		optionSets = o;
	}

	public Automotive(String n) {

		this();
		name = n;
	}

	public Automotive(String n, float b) {

		this();
		name = n;
		basePrice = b;
	}

	public Automotive(String n, OptionSet[] o) {

		this();
		name = n;
		optionSets = o;
	}

	public Automotive(float b) {

		this();
		basePrice = b;
	}

	public Automotive(OptionSet[] o) {

		this();
		optionSets = o;
	}

	public Automotive() {

		name = "";
		basePrice = 0;
		optionSets = new OptionSet[0];
	}

	/* Getter/Setter methods */

	public String GetName() {
		return name;
	}

	public void SetName(String n) {
		name = n;
	}

	public float GetBasePrice() {
		return basePrice;
	}

	public void SetBasePrice(Float b) {
		basePrice = b;
	}

	public OptionSet[] GetOptionSets() {
		return optionSets;
	}

	public void SetOptions(OptionSet[] o) {
		optionSets = o;
	}

	/* Non-static methods */


	/* Static methods */


	/* Print method */
}