import java.util.Scanner; // Import the Scanner class

public class GreetingProgram {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter their name
        System.out.print("Enter your name: ");

        // Read the input provided by the user
        String name = scanner.nextLine();

        // Close the scanner to prevent resource leaks
        scanner.close();

        // Greet the user with the entered name
        System.out.println("Hello, " + name + "! Welcome to the Java Greeting Program.");
    }
}
