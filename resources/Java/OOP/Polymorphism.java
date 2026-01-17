class CubeArea {
    double area(int x) {
        return 6 * x * x;
    }
}

class SphereArea {
    double area(int x) {
        return 4 * 3.14 * x * x;
    }
}

class CylinderArea {
    double area(int x, int y) {
        return x * y; // Simplified approximation
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        CubeArea ca = new CubeArea();
        SphereArea sa = new SphereArea();
        CylinderArea cia = new CylinderArea();

        System.out.println("Surface area of cube = " + ca.area(1));
        System.out.println("Surface area of sphere= " + sa.area(2));
        System.out.println("Surface area of cylinder= " + cia.area(3, 4));
    }
}