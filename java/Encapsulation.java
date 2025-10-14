import java.util.*;

// This class demonstrates encapsulation by keeping the data members private
// and providing public getter and setter methods to access and modify them.
class Encapsulate 
{ 
    // Private variables, cannot be accessed directly outside this class
    private String Name; 
    private int Height; 
    private int Weight; 
    
    // Getter method for Height
    public int getHeight()  
    { 
      return Height; 
    } 
   
    // Getter method for Name
    public String getName()  
    { 
      return Name; 
    } 
      
    // Getter method for Weight
    public int getWeight()  
    { 
       return Weight; 
    } 
   
    // Setter method for Weight
    public void setWeight(int newWeight) 
    { 
      Weight = newWeight; 
    } 
   
    // Setter method for Name
    public void setName(String newName) 
    { 
      Name = newName; 
    } 

    // Setter method for Height
    public void setHeight(int newHeight)  
    { 
      Height = newHeight; 
    } 
} 

public class TestEncapsulation 
{     
    public static void main (String[] args)  
    { 
        /*
         * Encapsulation is a fundamental concept in OOP where the internal 
         * state of an object is hidden from the outside. This is done by 
         * declaring variables as private and providing public getter and setter 
         * methods to control access.
         *
         * This helps in:
         * 1. Protecting data from unauthorized access or modification.
         * 2. Controlling how data is accessed or updated.
         * 3. Making code more maintainable and flexible.
         *
         * In this example, Encapsulate class hides its fields (Name, Height, Weight)
         * and exposes getter/setter methods to access or modify those fields.
         */
        
        Encapsulate obj = new Encapsulate(); 
        
        // Setting values using setter methods
        obj.setName("Abi"); 
        obj.setWeight(70); 
        obj.setHeight(178); 
        
        // Accessing values using getter methods
        System.out.println("My name: " + obj.getName()); 
        System.out.println("My height: " + obj.getHeight());  // corrected order here
        System.out.println("My weight: " + obj.getWeight());   // corrected order here
    } 
}
