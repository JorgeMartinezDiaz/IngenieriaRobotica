import java.util.Comparator;

public class ComparableRectangle2 {
    private final double x1, y1, x2, y2;

    public ComparableRectangle2(double x1, double y1, double x2, double y2){
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
    public double area(){return (x2 - x1) * (y2 - y1);}
    public double height(){return (y2 - y1);}
    public double width(){return (x2 - x1);}
    public boolean isValid(){
        if (x1 < 0.0 || x1 > 1.0 || y1 < 0.0 || y1 > 1.0 || x2 < 0.0 || x2 > 1.0 || y2 < 0.0 || y2 > 1.0) {return false;}
        if (x2 <= x1 || y2 == y1){return false;}
        return true;
    }
    public String toString(){return x1 + ", " + y1 + ", " + x2 + ", " + y2;}
    public static Comparator<ComparableRectangle2> byArea() {
        return new Comparator<ComparableRectangle2>() {
            public int compare(ComparableRectangle2 rectangle1, ComparableRectangle2 rectangle2) {

                if (rectangle1.area() < rectangle2.area()) return -1;
                if (rectangle1.area() > rectangle2.area()) return 1;
                return 0;
            }
        };
    }
    public static Comparator<ComparableRectangle2> byHeight() {
        return new Comparator<ComparableRectangle2>() {
            public int compare(ComparableRectangle2 r1, ComparableRectangle2 r2) {

                if (r1.height() < r2.height()) return -1;
                if (r1.height() > r2.height()) return 1;
                return 0;
            }
        };
    }
    public static Comparator<ComparableRectangle2> byWidth() {
        return new Comparator<ComparableRectangle2>() {
            public int compare(ComparableRectangle2 r1, ComparableRectangle2 r2) {

                if (r1.width() < r2.width()) return -1;
                if (r1.width() > r2.width()) return 1;
                return 0;
            }
        };
    }
}
