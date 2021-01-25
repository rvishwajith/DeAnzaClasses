import java.io.*;
import java.util.*;

class Driver {

	public Driver() {

	}
	
	public static void main(String[] args) {

		Driver d = new Driver();
		d.run();

	}

	public void run() {

		String fileName = "Cars.txt";

		try (Scanner in = new Scanner(new FileInputStream(fileName), "UTF-8")) {
	         
	         Automotive[] cars = readData(in);

	         for(int i = 0; i < cars.length; i++) {
	         	System.out.println(cars[i]);
	         }
		}
		catch(IOException e) {
			System.out.println("file could not be found.\n");
		}
	}

	public Automotive[] readData(Scanner in) {

		Automotive[] cars;
		int currentIndex = -1;
		int opIndex = -1;

		/* STEP 1
		-------
		Find the explicitly defined length of the array. Assume the 
		array always has this lneght on the first line since dynamic
		data structures cannot be used.
		*/
		String line1 = in.nextLine();
		int carsLength = Integer.parseInt(line1.substring(line1.lastIndexOf("|") + 1, line1.length()));
		cars = new Automotive[carsLength];

		while(in.hasNext()) {

			String line = in.nextLine();

			if(line.startsWith("|Model|")) {

				currentIndex++;
				opIndex = -1;

				line = line.replace("|Model|", "");

				float price = Float.parseFloat(line.substring(line.indexOf("|") + 1, line.lastIndexOf("|")));
				String name = line.substring(0, line.indexOf("|"));

				OptionSet[] opSet;
				int opLength = Integer.parseInt(line.substring(line.lastIndexOf("|") + 1, line.length()));
				opSet = new OptionSet[opLength];

				System.out.println("Model Found");

				Automotive car = new Automotive(name, price, opSet);
				cars[currentIndex] = car;
			}
			else if(line.startsWith("|Config|")) {

				System.out.println("Config Found");
				
				line = line.replace("|Config|", "");
				opIndex++;

				String configName = line.substring(0, line.indexOf("|"));
				line = line.substring(line.indexOf("|") + 1, line.length());

				String[] optionNames = line.split(",");
				
				for(int i = 0; i < optionNames.length; i++) {
					optionNames[i] = optionNames[i].trim(); // remove whitespace
				}

				Option[] options = new Option[optionNames.length];

				for(int i = 0; i < optionNames.length; i++) {
					options[i] = new Option(optionNames[i], 0);
				}

				OptionSet opSet = new OptionSet(configName, options.length);
				opSet.setAllOptions(options);

				cars[currentIndex].getOptionSets()[opIndex] = opSet;

				System.out.println("opIndex: " + opIndex);

			}
			else if(line.startsWith("|ConfigPrice|")) {

				System.out.println("Config with Price Found");
				
				line = line.replace("|ConfigPrice|", "");
				opIndex++;

				String configName = line.substring(0, line.indexOf("|"));
				line = line.substring(line.indexOf("|") + 1, line.length());

				String[] allContent = line.split(","); // guaranteed to be an even number
				int opLength = allContent.length/2;

				Option[] options = new Option[opLength];

				for(int i = 0; i < allContent.length; i+=2) {

					String opLine = allContent[i].trim();
					String opLine2 = allContent[i+1].trim();
					
					String name = opLine;
					float price = Float.parseFloat(opLine2);

					options[i/2] = new Option(name, price);
				}

				OptionSet opSet = new OptionSet(configName, options.length);
				opSet.setAllOptions(options);
				cars[currentIndex].getOptionSets()[opIndex] = opSet;

				System.out.println("opIndex: " + opIndex);
			}
		}
		return cars;
	}
}

/*
Automotive
-------
Represents a car with a set of configuration options with
additional prices, a base price, and a name representing the model
of the car.
*/
class Automotive {
	
	String name;
	float base;
	OptionSet opSet[];

	public Automotive(String n, float b, OptionSet[] o) {
		name = n;
		base = b;
		opSet = o;
	}

	public OptionSet[] getOptionSets() {
		return opSet;
	}

	public float getBasePrice() {
		return base;
	}

	public String getName() {
		return name;
	}

	public String toString() {

		String line = "";
		line += "\nCar Name: " + name + "\nBase Price: " + base + "\nNumber of Options: " + opSet.length;

		for(int i = 0; i < opSet.length; i++) {

			line += opSet[i].toString();
			System.out.println(i);
		}
		return line;
	}
}

/* 
OptionSet
-------
Represents a set of options in a category. For example, a model
of a car can have a set of colors to choose from as a set of options.
*/	
class OptionSet {

	Option options[];
	String name;

	public OptionSet(String n, int size) {
		
		options = new Option[size];
		name = n;
	}

	/* getOption(int index)
	-------
	Gets the option of a specified index. If the index is invalid,
	returns null.
	*/
	public Option getOption(int index) {

		if(index > 0 && index < options.length) {
			return options[index];
		}

		return null;
	}

	/* getOption(int n)
	-------
	Gets the option of a specified name. If the name is not found,
	returns null.
	*/
	public Option getOption(String n) {

		for(int i = 0; i < options.length; i++) {

			Option option = options[i];

			if(option.name.equals(n)) {
				return option;
			}
		}

		return null;
	}

	/* setOption(Option option, int index)
	-------
	Sets the option at a given index. If the index is invalid,
	nothing happens and false is returned.
	*/
	public boolean setOption(Option option, int index) {

		if(index > 0 && index < options.length) {
			options[index] = option;
			return true;
		}

		return false;
	}

	public boolean setAllOptions(Option[] ops) {

		options = ops;
		return true;
	}

	public boolean setName(String n) {
		name = n;
		return true;
	}

	public String getName() {
		return name;
	}

	public String toString() {

		String line = "\n\tOption Set: " + name;

		for(int i = 0; i < options.length; i++) {
			line += options[i].toString();
		}

		return line;
	}
}

/*
Option
-------
Represents an individual option in a set of options. For example, an
individual color as an option when choosing from a set of colors for
a car.
*/
class Option {

	String name;
	float price;

	public Option (String n, float p) {
		name = n;
		price = p;
	}

	public String getName() {
		return name;
	}

	public boolean setName(String n) {
		name = n;
		return true;
	}

	public float getPrice() {
		return price;
	}

	public boolean setPrice(float p) {
		price = p;
		return true;
	}

	public String toString() {
		String line = "\n\t\tOption: " + name;
		line += "\n\t\t\tPrice = " + price;
		return line;
	}
}