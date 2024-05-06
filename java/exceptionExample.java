import java.util.Scanner;

class CustomException extends Exception {
    public CustomException (String message) {
        super(message);
    }
}

public class exceptionExample {
    public static void testMethod(int x) throws CustomException {
        if (x < 0) {
            throw new CustomException("Number cannot be negative!");
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a positive number");
        int input = sc.nextInt();
        sc.close();
        try {
            testMethod(input);
        } catch (CustomException e) {
            System.out.println("Custom exception : " + e);
        } finally {
            System.out.println("Program execution complete");
        }
    }    
}
