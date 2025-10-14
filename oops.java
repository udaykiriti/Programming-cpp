import java.util.*;

abstract class Bike
{
 Bike()
 {
  System.out.println("The Street Bob. ");
 }
 abstract void drive();
 void weight()
 {
  System.out.println("Light on its feet with a hefty : 630 lbs.");
 }
} 

class HarleyDavidson extends Bike
 {
  void drive()
  {
   System.out.println("Old-school yet relevant.");
  }
 }

public class oops 
 {
  public static void main (String args[])
  {
   Bike obj = new HarleyDavidson();
   obj.drive();
   obj. weight();
  }
 }
