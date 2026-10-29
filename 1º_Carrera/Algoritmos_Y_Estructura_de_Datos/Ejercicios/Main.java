import edu.princeton.cs.algs4.BST;
import edu.princeton.cs.algs4.In;
import java.util.ArrayList;
import java.util.Date;
import java.text.SimpleDateFormat;

public class Main {
    public static void main(String[] args){
        if (args.length != 2){
            System.err.println("Data source error\n");
            return;
        }
        int position;

        try{
            position = Integer.parseInt(args[1]);
        }catch (Exception e){System.err.println("Invalid position\n");
        return;
        }
        ArrayList<Student> lista = new ArrayList<>();
        BST<String, Student> bst = new BST<>();

        In in = new In(args[0]);
        while (!in.isEmpty()){
            String line = in.readLine();
            if (line == null || line.trim().isEmpty()) continue;
            Student student = createStudent(line);

            if (student == null){
                System.err.println("Data source error\n");
                return;
            }
            if (bst.contains(student.getId())){
                System.err.println("Duplicate student");
                continue;
            }
            bst.put(student.getId(), student);
            lista.add(student);
        }
        if (position < 1 || position > lista.size()){
            System.err.println("Invalid position\n");
            return;
        }

        System.out.println("Students by alphabetic order:");
        int indice = 1;
        for (String id : bst.keys()){
            System.out.println(indice + "-" + bst.get(id));
            indice++;
        }
        System.out.println("----------------------------------------");
        ordenarPorNota(lista);

        System.out.println("Students sorted by grade:");
        for (int i = 0;i < lista.size();i++ ){
            System.out.println((i + 1) + "-" + lista.get(i));
        }
        System.out.println("----------------------------------------");
        String primerId = bst.min();
        String ultimoId = bst.max();

        System.out.println("* First student in BST (alphabetical):");
        System.out.println(" - " + bst.get(primerId));
        System.out.println("* Last student in BST  (alphabetical):");
        System.out.println(" - " + bst.get(ultimoId));
        ArrayList<Student> alfabetica = new ArrayList<>();

        for (String id : bst.keys()){alfabetica.add(bst.get(id));}

        System.out.println("* BST " + position + "  (alphabetical):");
        System.out.println(" - " + alfabetica.get(position - 1));

        System.out.println("* Grade position " + position + ":");
        System.out.println(" - " + lista.get(position - 1));
    }
    private static Student createStudent(String line){
        String[] campos = line.split(";");

        if (campos.length != 5){return null;}
        String name = campos[0];
        String surname = campos[1];

        if (name.length() < 3 || surname.length() < 3){return null;}
        String[] notasTexto = campos[2].trim().split(" ");

        if (notasTexto.length != 4){return null;}
        double[] grades = new double[4];

        try{
            for (int i = 0; i < 4;i++){grades[i] = Double.parseDouble(notasTexto[i]);}
            SimpleDateFormat formato = new SimpleDateFormat("MM/dd/yyyy");
            formato.setLenient(false);

            Date birthday = formato.parse(campos[3]);
            Date registrationDate = formato.parse(campos[4]);
            return new Student(name, surname,grades, birthday, registrationDate);
        }catch (Exception e){return null;}
    }
    private static void ordenarPorNota(ArrayList<Student> lista){
        lista.sort((s1, s2) -> {
            if(s1.getAverageGrade() > s2.getAverageGrade()) return -1;
            if(s1.getAverageGrade() < s2.getAverageGrade()) return 1;
            return s1.getId().compareTo(s2.getId());
        });
    }
}
