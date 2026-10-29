import edu.princeton.cs.algs4.In;
import java.util.ArrayList;

public class SortRectangles2 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Data source error.");
            System.exit(1);
        }
        ArrayList<ComparableRectangle2> lista = new ArrayList<>();
        In in = new In(args[0]);

        while (!in.isEmpty()) {
            String line = in.readLine();
            if (line == null || line.trim().isEmpty()) {continue;}

            String[] parts = line.trim().split("\\s+");
            if (parts.length != 4) {
                System.err.println("Data source error");
                System.exit(1);
            }

            double x1 = Double.parseDouble(parts[0]);
            double y1 = Double.parseDouble(parts[1]);
            double x2 = Double.parseDouble(parts[2]);
            double y2 = Double.parseDouble(parts[3]);

            ComparableRectangle2 rectangle = new ComparableRectangle2(x1, y1, x2, y2);
            if(rectangle.isValid()){
                lista.add(rectangle);
            } else{
                System.err.println("Rectangle will not be added to the list.");
            }
        }
        ArrayList<ComparableRectangle2> byArea = new ArrayList<>(lista);
        lista.sort(ComparableRectangle2.byArea());
        System.out.println("BY AREA");
        for (ComparableRectangle2 r : byArea) {
            System.out.println(r + " - area=" + r.area());
        }
        ArrayList<ComparableRectangle2> byHeight = new ArrayList<>(lista);
        lista.sort(ComparableRectangle2.byHeight());
        System.out.println("BY HEIGHT");
        for (ComparableRectangle2 r : byHeight) {
            System.out.println(r + " - height=" + r.height());
        }
        ArrayList<ComparableRectangle2> byWidth = new ArrayList<>(lista);
        lista.sort(ComparableRectangle2.byWidth());
        System.out.println("BY WIDTH");
        for (ComparableRectangle2 r : byWidth) {
            System.out.println(r + " - width=" + r.width());
        }
    }
}



