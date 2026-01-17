import java.util.*;

class Animal 
{
    // Method representing a habit common to animals
    void habit()
    {
        System.out.println("I am nocturnal!! ");
    }
}

class Mammal extends Animal 
{
    // Mammal inherits from Animal, so it gets habit() method as well
    // This method represents a behavior specific to mammals
    void nature()
    {
        System.out.println("I hang upside down!! ");
    }
}

class Bat extends Mammal 
{
    // Bat inherits from Mammal (and indirectly from Animal)
    // This method represents behavior specific to bats
    void hobby()
    {
        System.out.println("I fly !! ");
    }
}

public class Inheritance 
{
    public static void main(String args[])
    {
        /*
         * Inheritance is an OOP concept where a new class (subclass/child)
         * inherits properties and behaviors (fields and methods) from an
         * existing class (superclass/parent).
         * 
         * In this example:
         * - 'Animal' is the superclass with a method 'habit()'.
         * - 'Mammal' inherits from 'Animal' and adds its own method 'nature()'.
         * - 'Bat' inherits from 'Mammal' and adds method 'hobby()'.
         * 
         * This allows 'Bat' to access methods from both Mammal and Animal.
         * 
         * In main, we create an object of Bat and call methods from all three classes,
         * demonstrating inheritance and method reuse.
         */
        
        Bat b = new Bat();
        
        // Calls method from Animal class
        b.habit();
        
        // Calls method from Mammal class
        b.nature();
        
        // Calls method from Bat class
        b.hobby();
    }
}
