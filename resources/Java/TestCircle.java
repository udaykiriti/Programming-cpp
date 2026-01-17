public class TestCircle{
    public static void main(String[] args) {
        Circle circle1 = new Circle();
        System.out.println(circle1.radius +" "+circle1.getArea());  
        Circle circle2 = new Circle(25);
        System.out.println(circle2.radius+" "+circle2.getArea());  
        Circle circle3 = new Circle(125);
        System.err.println(circle3.radius+" "+circle3.getArea());   
        Circle circle4 = new Circle(100);
        System.err.println(circle4.radius+" "+circle4.getArea());
    }
}

class Circle{
    double radius;
    public Circle() {
        radius=1;
    }
    public Circle(double radius) {
        this.radius = radius;
    } 
    double getArea(){
        return radius*radius*Math.PI;
    }
    double getPerimeter(){
        return 2 * Math.PI*radius;
    }
    void setRadius(double newRadius){
        radius=newRadius;
    }
}