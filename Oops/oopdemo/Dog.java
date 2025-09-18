package oopdemo;

// Dog.java (Subclass - Inheritance + Method Overriding)

public class Dog extends Animal {

    // Constructor calls superclass constructor
    public Dog(String name) {
        super(name);
    }

    // Overridden method (Polymorphism)
    @Override
    public void makeSound() {
        System.out.println(getName() + " barks: Woof! Woof!");
    }
}
