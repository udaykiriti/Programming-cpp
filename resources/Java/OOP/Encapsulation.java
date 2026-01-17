class Encapsulate {
    private String name;
    private int height;
    private int weight;

    public int getHeight() {
        return height;
    }

    public String getName() {
        return name;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int newWeight) {
        weight = newWeight;
    }

    public void setName(String newName) {
        name = newName;
    }

    public void setHeight(int newHeight) {
        height = newHeight;
    }
}

public class Encapsulation {
    public static void main(String[] args) {
        Encapsulate obj = new Encapsulate();

        obj.setName("Abi");
        obj.setWeight(70);
        obj.setHeight(178);

        System.out.println("My name: " + obj.getName());
        System.out.println("My height: " + obj.getHeight());
        System.out.println("My weight: " + obj.getWeight());
    }
}