public class SalesTax {
    public static void main(String[] args) {
        double purchaseAmount = 199.99;
        double taxRate = 0.06;
        double tax = purchaseAmount * taxRate;
        
        System.out.println("Purchase Amount: $" + purchaseAmount);
        System.out.println("Sales Tax: $" + (int)(tax * 100) / 100.0);
    }
}
