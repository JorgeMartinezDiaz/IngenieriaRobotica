import edu.princeton.cs.algs4.In;
import java.util.ArrayList;
import java.util.Collections;

public class SortRectangles {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Data source error.");
            System.exit(1);
        }

        ArrayList<ComparableRectangle> lista = new ArrayList<>();
        In in = new In(args[0]);

        while (!in.isEmpty()) {
            String line = in.readLine();
            if (line == null || line.trim().isEmpty()) {continue;}

            String[] parts = line.trim().split("\\s+");
            if (parts.length != 4) {
                System.err.println("Data source error.");
                System.exit(1);
            }
            double x1 = Double.parseDouble(parts[0]);
            double y1 = Double.parseDouble(parts[1]);
            double x2 = Double.parseDouble(parts[2]);
            double y2 = Double.parseDouble(parts[3]);

            ComparableRectangle rectangle = new ComparableRectangle(x1 ,y1 ,x2 ,y2 );
            if (rectangle.isValid()) {
                lista.add(rectangle);
            } else {
                System.err.println("Rectangle will not be added to the list.");
            }
        }
        Collections.sort(lista);

        for (ComparableRectangle rectangle : lista) {
            System.out.println(rectangle);
        }
    }
}