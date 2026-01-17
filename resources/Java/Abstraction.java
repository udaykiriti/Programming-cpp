import java.util.*;

abstract class Bike
{
 // Constructor of the abstract class Bike
 Bike()
 {
  System.out.println("The Street Bob. ");
 }
 
 // Abstract method - no implementation here, 
 // subclasses must provide their own implementation
 abstract void drive();
 
 // Concrete method - has a default implementation
 void weight()
 {
  System.out.println("Light on its feet with a hefty : 630 lbs.");
 }
} 

class HarleyDavidson extends Bike
 {
  // Providing implementation for the abstract method drive()
  void drive()
  {
   System.out.println("Old-school yet relevant.");
  }
 }

public class oops 
 {
  public static void main (String args[])
  {
   /*
    * Abstraction in Java is a process of hiding the implementation details
    * and showing only functionality to the user. It helps to reduce
    * complexity and increase efficiency.
    * 
    * In this example, 'Bike' is an abstract class with an abstract method 'drive()'.
    * This means every subclass of Bike must provide its own implementation of drive().
    * The abstract class can also have concrete methods like 'weight()', which
    * provide common behavior.
    * 
    * The 'HarleyDavidson' class extends Bike and implements the abstract method.
    * This demonstrates abstraction by exposing only the method signatures
    * in the abstract class while hiding the actual implementation.
    */
   
   // Creating an object of HarleyDavidson referenced by Bike type (polymorphism)
   Bike obj = new HarleyDavidson();
   
   // Calls the implemented method in HarleyDavidson
   obj.drive();
   
   // Calls the concrete method in abstract class Bike
   obj.weight();
  }
 }
