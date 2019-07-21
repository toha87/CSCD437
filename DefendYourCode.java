import java.sql.SQLOutput;
import java.util.*;
import java.security.SecureRandom;
import java.util.regex.Pattern;

public class DefendYourCode {

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
}
