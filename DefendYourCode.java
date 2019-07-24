import java.sql.SQLOutput;
import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.security.SecureRandom;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.io.PrintWriter;
import java.io.FileReader;


public class DefendYourCode {

    private static Scanner inputFile = null;
    private static PrintStream outputFile = null;

    public static void main(String[] args) throws NoSuchAlgorithmException {
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
            if (values(spare)) {
                firstValue = Long.valueOf(spare);
                done = true;
            }
        }
        done = false;
        while (!done) {
            System.out.println("Enter second number[-2147483648, 2147483647]:");
            spare = kb.nextLine();
            if (values(spare)) {
                secondValue = Long.valueOf(spare);
                done = true;
            }
        }
        done = false;
                
        getInputFileScanner(kb); 
        getOutputFileWritter(kb);  
        writeOutputFile(fname, lname, firstValue, secondValue);


        while (!done) {
            System.out.print("Please enter password: ");
            String password = kb.nextLine();
            done = Password(password, "first");

        }
        done = false;

        while (!done) {
            System.out.print("Please re-enter your password: ");
            String password = kb.nextLine();

            done = Password(password, "second");

        }
    }

    private static boolean Password(String password, String time) throws NoSuchAlgorithmException {

        String passwordFromFile = "";
        String saltFromFile = "";

        if (time.equals("first")) {
        
         Random rand = new Random();
         String str = Integer.toString(rand.nextInt(1000));
         byte[] salt = str.getBytes();
         
         String securePassword = SHA_256(password, salt);

            try (PrintWriter out = new PrintWriter("password.txt")) {
                out.println(securePassword);
                out.println(str);
                return true;
            } catch (IOException ex) {
                ex.printStackTrace();
                return false;
            }
        }

        if (time.equals("second")) {

            try {

                Scanner out = new Scanner(new FileReader("password.txt"));
                passwordFromFile = out.nextLine();
                saltFromFile = out.nextLine();

            } catch (FileNotFoundException e) {

            }
            
             byte[] salt = saltFromFile.getBytes();
             String securePassword = SHA_256(password, salt);
             


            if (passwordFromFile.equals(securePassword)) {

                System.out.println("You Got It Right!");
                return true;

            } else {

                System.out.println("Wrong Password! Try Again!");
                return false;
            }
        }

        return false;

    }
    
    // https://howtodoinjava.com/security/how-to-generate-secure-password-hash-md5-sha-pbkdf2-bcrypt-examples/
    private static String SHA_256(String passwordToHash, byte[] salt) {
        String generatedPassword = null;
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            md.update(salt);
            byte[] bytes = md.digest(passwordToHash.getBytes());
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < bytes.length; i++) {
                sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
            }
            generatedPassword = sb.toString();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        }
        return generatedPassword;
    }

    private static boolean name(String name) {
        return Pattern.matches("\\s*^[a-zA-Z]{2,50}$\\s*", name);
    }

    private static boolean values(String value) {
        try {
            int number = Integer.valueOf(value);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    
    private static void getInputFileScanner(Scanner kb) {
        File file = null;
        boolean isValidFileName = false;        
		
        do {
            System.out.println("Enter the name of the input text file (1-255 charactors), that must already exist in the current directory.");
            String fileName = kb.nextLine();            
            
            if (fileName == null)
                throw new IllegalArgumentException("Error: The file name passed in was null");
            if (fileName.equals(""))
                throw new IllegalArgumentException("Error: The file name passed in was empty");
          
            Pattern pattern_FileName = Pattern.compile("^([A-Za-z0-9\\-\\_]){1,251}.txt$");  
    		Matcher matcher_FileName = pattern_FileName.matcher(fileName);
    		
    		if(matcher_FileName.matches()) {
    			
	            file = new File("./" + fileName);
	            
	            if (!file.exists()) {
	                System.out.println("Error: The input file does not exist!");
	                isValidFileName = false;
	            } else if (!file.canRead()) {
	                System.out.println("Error: Can not read from input file: " + file.getName());
	                isValidFileName = false;
	            } 	
	
	            try {
	                inputFile = new Scanner(file);	                
	                isValidFileName = true;
	            } 
	            catch (FileNotFoundException e) {
	                System.out.println("an exception occurred in openInputFile: " + e.getMessage());
	            }
    		}
    		else
    			System.out.println("Make sure you file name is 1 - 251 character in length and has a .txt file");
        }
        while (!isValidFileName);
    }

    private static void getOutputFileWritter(Scanner kb) {
        boolean isValidFileName = false;
        File file = null;
        
        do {
            System.out.println("Enter the name of the output text file (1-255 charactors), which will be created in the current directory.");
            String fileName = kb.nextLine();

            Pattern pattern_FileName = Pattern.compile("^([A-Za-z0-9\\-\\_]){1,251}.txt$");  
    		Matcher matcher_FileName = pattern_FileName.matcher(fileName);
    		if(matcher_FileName.matches()) {
    			    		
	            if (fileName == null) {
	                System.out.println("Error: The output file name was null");
	                return;
	            }
	            if (fileName.equals("")) {
	                System.out.println("Error: The output file was an empty string");
	                return;
	            }
	
	            file = new File("./" + fileName);
	            try {
	                outputFile = new PrintStream(file);
	                isValidFileName = true;	
	            } 
	            catch (Exception e) {
	                System.out.println("Error: An exception occurred opening the output file named " + fileName);
	            }
    		}
    		else
    			System.out.println("Make sure you file name is 1 - 251 character in length and has a .txt file");
        }
        while (!isValidFileName);
    }

    private static void writeOutputFile(String fname, String lname, long firstValue, long secondValue) {
        outputFile.println(fname + " " + lname);

        outputFile.println(firstValue + " + " + secondValue + " = " + (firstValue + secondValue));
        outputFile.println(firstValue + " x " + secondValue + " = " + (firstValue * secondValue) + "\n");

        while (inputFile.hasNext()) {
            outputFile.println(inputFile.nextLine());
        }

        inputFile.close();
        outputFile.close();

    }

}//end of class
