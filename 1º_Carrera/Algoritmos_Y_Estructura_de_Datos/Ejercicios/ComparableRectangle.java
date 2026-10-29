public class ComparableRectangle implements Comparable<ComparableRectangle>{
    private final double x1,y1,x2,y2;

    public ComparableRectangle(double x1, double y1, double x2, double y2){
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
    public double area(){return (x2 - x1) * (y2 - y1);}
    public boolean isValid(){
        return (x1 >= 0.0 && x1 <= 1.0 && y1 >= 0.0 && y1 <= 1.0 && x2 >= 0.0 && x2 <= 1.0 && y2 >= 0.0 && y2 <= 1.0 && x2 > x1 && y2 > y1);
    }
    public int compareTo(ComparableRectangle other){return Double.compare(this.area(),other.area());}
    public String toString(){return x1 + ", " + y1 + ", " + x2 + ", " + y2;}
}
