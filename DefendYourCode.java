import java.util.*;
import java.security.SecureRandom;
public class DefendYourCode {

    public static void main(String[] args) {

        Scanner kb = new Scanner(System.in);

        System.out.print("Please enter password: ");
        String password = kb.nextLine();

        Password(password);
    }

    private static void Password(String password) {

        SecureRandom rand = new SecureRandom();

        String salt = Integer.toString(rand.nextInt(1000));

        System.out.println(password + salt);

    }


}
