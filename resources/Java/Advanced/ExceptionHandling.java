// Custom Exception Class
class InsufficientFundsException extends Exception {
    public InsufficientFundsException(String message) {
        super(message);
    }
}

class BankAccount {
    private double balance;

    public BankAccount(double amount) {
        this.balance = amount;
    }

    // Method declaring it might throw a checked exception
    public void withdraw(double amount) throws InsufficientFundsException {
        if (amount > balance) {
            throw new InsufficientFundsException("Insufficient funds. Available: " + balance);
        }
        balance -= amount;
        System.out.println("Withdrawal successful. Remaining balance: " + balance);
    }
}

public class ExceptionHandling {
    public static void main(String[] args) {
        System.out.println("--- Example 1: Basic Try-Catch-Finally ---");
        try {
            int a = 10, b = 0;
            int c = a / b; // This will throw ArithmeticException
            System.out.println("Result: " + c);
        } catch (ArithmeticException e) {
            System.out.println("Error: Cannot divide by zero.");
        } finally {
            System.out.println("This finally block always executes, regardless of errors.");
        }

        System.out.println("\n--- Example 2: Custom Exception & throws ---");
        BankAccount account = new BankAccount(500.00);
        try {
            System.out.println("Attempting to withdraw $600...");
            account.withdraw(600.00);
        } catch (InsufficientFundsException e) {
            System.out.println("Transaction Failed: " + e.getMessage());
        }

        System.out.println("\n--- Example 3: Multiple Catch Blocks ---");
        try {
            int[] numbers = {1, 2, 3};
            System.out.println(numbers[5]); // This throws ArrayIndexOutOfBoundsException
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic error occurred.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Array index is out of bounds.");
        } catch (Exception e) {
            System.out.println("Some generic error occurred: " + e.getMessage());
        }
    }
}
