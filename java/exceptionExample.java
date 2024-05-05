import java.util.Scanner;

class CustomException extends exceptionExample {
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
        try {
            testMethod(-1);
        } catch (CustomException e) {
            System.out.println("Custom exception : " + e);
        }
    }    
}
