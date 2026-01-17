package oopdemo;

// Animal.java (Base Class - Encapsulation + Inheritance)

public class Animal {
    private String name; // encapsulated variable

    // Constructor
    public Animal(String name) {
        this.name = name;
    }

    // Getter
    public String getName() {
        return name;
    }

    // Method to be overridden (Polymorphism)
    public void makeSound() {
        System.out.println(name + " makes a sound.");
    }
}
