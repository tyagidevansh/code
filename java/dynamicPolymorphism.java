interface Shape {
    void draw();
}

class Circle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a circle...");
    }
}

class Square implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing a square...");
    }
}

public class dynamicPolymorphism {
    public static void main (String[] args) {
        Square square = new Square();
        Circle circle = new Circle();
        circle.draw();
        square.draw();
    }
}
