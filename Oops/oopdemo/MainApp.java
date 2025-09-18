package oopdemo;

public class MainApp {
    public static void main(String[] args) {
        // Create objects
        Animal genericAnimal = new Animal("Generic Animal");
        Dog dog = new Dog("Tommy");

        // Demonstrating Encapsulation + Method Call
        System.out.println("Animal Name: " + genericAnimal.getName());
        genericAnimal.makeSound();

        // Inheritance + Polymorphism
        System.out.println("Dog Name: " + dog.getName());
        dog.makeSound();

        // Polymorphism (upcasting)
        Animal polyAnimal = new Dog("Bruno");
        polyAnimal.makeSound();  // Calls Dog's version
    }
}
