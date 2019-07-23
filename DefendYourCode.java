import java.sql.SQLOutput;
import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.security.SecureRandom;
import java.util.regex.Pattern;


public class DefendYourCode {

	private static Scanner inputFile = null;
	private static PrintStream outputFile = null;
    
    public static void main(String[] args) {
        Scanner kb = new Scanner(System.in);
        boolean done = false;
        String spare = null;
        String fname = null;
        String lname = null;
        long firstValue = 0;
        long secondValue = 0;
        

        while (!done) {
            System.out.println("Enter first name(minimum 2 characters, only letters):");
            fname = kb.nextLine().trim();
            done = name(fname);
        }
        done = false;
        while (!done) {
            System.out.println("Enter last name(minimum 2 characters, only letters):");
            lname = kb.nextLine().trim();
            done = name(lname);
        }
        done = false;
        while (!done) {
            System.out.println("Enter first number[-2147483648, 2147483647]:");
            spare = kb.nextLine();
            if(values(spare)) {
                firstValue = Long.valueOf(spare);
                done = true;
            }
        }
        done = false;
        while (!done) {
            System.out.println("Enter second number[-2147483648, 2147483647]:");
            spare = kb.nextLine();
            if(values(spare)) {
                secondValue = Long.valueOf(spare);
                done = true;
            }
        }
        done = false;
                
        getInputFileScanner(kb); // C:\Users\Jeff\Input_test_file.txt
        getOutputFileWritter(kb);  // C:\Users\Jeff\Output_File.txt
        writeOutputFile(fname, lname, firstValue, secondValue);
                
        
        while(!done) {
            System.out.print("Please enter password: ");
            String password = kb.nextLine();

            Password(password);
        }
    }

    private static void Password(String password) {

        SecureRandom rand = new SecureRandom();

        String salt = Integer.toString(rand.nextInt(1000));

        System.out.println(password + salt);

    }

    private static boolean name(String name) {
        return Pattern.matches("\\s*^[a-zA-Z]{2,50}$\\s*", name);
    }

    private static boolean values(String value) {
        try {
            int number = Integer.valueOf(value);
            return true;
        }
        catch (NumberFormatException e) {
            return false;
        }
    }
    /***
     * 
     * @param kb     * 
     * @return valid file name of a file at exist in the current directory and is not already open.
     */
    private static void getInputFileScanner(Scanner kb) {
    	 File file = null;	     	     
	     boolean isValidFileName = false;
	     
	     do {
	    	 System.out.println("Enter the name of the input text file, that must already exist.");
	    	 String fileName = kb.nextLine();
	    	 
	    	 if (fileName == null)
	 			throw new IllegalArgumentException("Error: The file name passed in was null");
	 		if (fileName.equals(""))
	 			throw new IllegalArgumentException("Error: The file name passed in was empty");
	 		
	 		file = new File(fileName);	
	 		if (!file.exists()){
				System.out.println("Error: The input file does not exist!");
	 		}
	 		else if (!file.canRead()){
	 			System.out.println("Error: Can not read from input file: " + file.getName());	 			
	 		}
	 		
	 		
			try {
				inputFile = new Scanner(file);
				// System.out.println("Debug - the input file was created! ");
				isValidFileName = true;
			}
			catch(FileNotFoundException e){
				System.out.println("an exception occurred in openInputFile: " + e.getMessage());				
			}
	     }
	     while(!isValidFileName);
    }
    
    private static void getOutputFileWritter(Scanner kb) {
    	boolean isValidFileName = false;
	     
	     do {
	    	 System.out.println("Enter the name of the output text file, that must already exist.");
	    	 String fileName = kb.nextLine();
	    	 
	    	 if(fileName == null) {
	 			System.out.println("Error: The output file name was null");
	 			return;
	 		}
	 		if(fileName.equals("") ) {
	 			System.out.println("Error: The output file was an empty string");
	 			return;			
	 		}	 		
	 		
	 		try {
	 			outputFile = new PrintStream(fileName);
	 			isValidFileName = true;
	 			
	 		} catch (Exception e) {
	 			System.out.println("Error: An exception occurred opening the output file named " + fileName);
	 		}
	     }
	     while(!isValidFileName);
    }
 
    private static void writeOutputFile(String fname, String lname, long firstValue, long secondValue) {
    	outputFile.println(fname + " " + lname);
    	 
    	outputFile.println(firstValue + " + " + secondValue + " = " + (firstValue + secondValue) );
    	outputFile.println(firstValue + " x " + secondValue + " = " + (firstValue * secondValue) + "\n");
    	
    	while(inputFile.hasNext()) {        	    
        	outputFile.print(inputFile.nextLine());
        } 
    	
    	inputFile.close();
        outputFile.close();
    	
    }
    
}//end of class
