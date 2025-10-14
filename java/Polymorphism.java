import java.util.*;

class CubeArea 
{
    // Method to calculate surface area of a cube (6 * side^2)
    // Takes one integer parameter 'x' representing the side length
    double area(int x)
    {
        return 6 * x * x;
    }
}

class SphereArea 
{
    // Method to calculate surface area of a sphere (4 * pi * radius^2)
    // Takes one integer parameter 'x' representing the radius
    double area(int x)
    {
        return 4 * 3.14 * x * x;
    }
}

class CylinderArea 
{
    // Method to calculate surface area of a cylinder (approximation)
    // Here it returns x * y, which doesn't actually calculate surface area
    // Typically surface area = 2 * pi * r * (r + h)
    // Takes two integer parameters: x and y
    double area(int x, int y)
    {
        return x * y;
    }
}

public class Overloading
{
    public static void main(String []args)
    {
        /*
         * Method overloading in Java allows multiple methods to have the same name
         * but different parameter lists (different number or types of parameters).
         * 
         * In this example:
         * - Each class has an 'area' method.
         * - CubeArea and SphereArea have 'area' methods with one int parameter.
         * - CylinderArea has an 'area' method with two int parameters.
         * 
         * Although the methods are in different classes, this example demonstrates
         * the principle that method names can be reused as long as their parameter
         * lists differ.
         * 
         * Note: This is more of a simple example showing method overloading concept,
         * but since methods are in different classes, this is also an example of polymorphism
         * at the class level.
         */

        CubeArea ca = new CubeArea();
        SphereArea sa = new SphereArea();
        CylinderArea cia = new CylinderArea();

        System.out.println("Surface area of cube = " + ca.area(1));
        System.out.println("Surface area of sphere= " + sa.area(2));
        System.out.println("Surface area of cylinder= " + cia.area(3, 4));
    }
}
