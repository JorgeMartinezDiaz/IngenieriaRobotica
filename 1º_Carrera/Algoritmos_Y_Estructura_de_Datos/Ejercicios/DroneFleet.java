import edu.princeton.cs.algs4.In;

public class DroneFleet {
    public static String[][] topDrones(String dronesFile, String flightsFile) {
        double[] ratingDrone = new double[21];
        int[] droneHours = new int[21];
        int[] droneFlights = new int[21];
        int[] firstUsed = new int[21];
        for (int i = 1; i <= 20; i++) {
            firstUsed[i] = -1;
        }
        In entradaDrones = new In(dronesFile);
        //Llenamos el rating con el bucle while, mientras siga habiendo lineas las lee y convierte en int o double.
        //Luego llenamos el string rating dando el valor al raiting de cada Id.
        while (!entradaDrones.isEmpty()) {
            String linea = entradaDrones.readLine();
            if (linea == null|| linea.trim().equals(" ")) continue;
            String[] parts = linea.split(" ");
            int id = Integer.parseInt(parts[0]);
            double rating = Double.parseDouble(parts[1]);
            ratingDrone[id] = rating;
        }
        In entradaFlights = new In(flightsFile);
        int order = 0;
        //Misma estructrura que para asignar anteriormente los raiting, si no hay operadores sale. si no, incrementa las vueltas y las horas.
        //Tambien comprobamos si es el primer vuelo, si es asi asignamos en el orden que esta, e incrementamos 1 para el siguiente Id.
        while (!entradaFlights.isEmpty()) {
            String operator = entradaFlights.readLine();
            if (operator == null) break;
            int id = Integer.parseInt(entradaFlights.readLine());
            int horas = Integer.parseInt(entradaFlights.readLine());
            droneFlights[id]++;
            droneHours[id] += horas;
            if (firstUsed[id] == -1) {
                firstUsed[id] = order;
            }
            order++;
        }
        //Aqui llenamos las veces que cada usuario ha utilizado su Drone.
        int[] usedDrone = new int[20];
        int cantidad = 0;
        for (int id = 1; id <= 20; id++) {
            if (droneFlights[id] > 0) {
                usedDrone[cantidad] = id;
                cantidad++;
            }
        }
        // Filtrado de clasificación: 1ºNúmero de horas, en caso de empate 2º Raiting obtenido, por último 3º por orden de aparición.
        for (int i = 0; i < cantidad - 1; i++) {
            int best = i;
            for (int j = i + 1; j < cantidad; j++) {
                int idFirst = usedDrone[best];
                int idSecondary = usedDrone[j];
                if (droneHours[idSecondary] > droneHours[idFirst]) {
                    best = j;
                } else if (droneHours[idSecondary] == droneHours[idFirst]) {
                    if (ratingDrone[idSecondary] > ratingDrone[idFirst]) {
                        best = j;
                    } else if (ratingDrone[idSecondary] == ratingDrone[idFirst]) {
                        if (firstUsed[idSecondary] < firstUsed[idFirst])
                            best = j;
                    }
                }
            }
            int temporary = usedDrone[i];
            usedDrone[i] = usedDrone[best];
            usedDrone[best] = temporary;
        }
        // Creamos el array final. Primero hacemos el filto de unicamente 10 drones.
        int size = cantidad;
        if (size > 10)
            size = 10;
        String[][] result = new String[size][3];
        for (int i = 0; i < size; i++) {
            int id = usedDrone[i];
            result[i][0] = String.valueOf(id);
            result[i][1] = String.valueOf(droneFlights[id]);
            result[i][2] = String.format("%.1f", ratingDrone[id]);
        }
        return result;
    }
    public static String[] overusedOperators(String flightsFile, int maxHoras) {
        //Hacemos una busqueda de los operadores que han volado mas de lo permitido.
        String[] operators = new String[100];
        int cantidad = 0;
        In inFlights = new In(flightsFile);
        while (!inFlights.isEmpty()) {
            String name = inFlights.readLine();
            if (name == null) break;
            inFlights.readLine();
            int hours = Integer.parseInt(inFlights.readLine().trim());
            if (hours > maxHoras) {
                //Comprobar si el usuario ya existe en la lista
                boolean exist = false;
                for (int i = 0; i < cantidad; i++) {
                    if (operators[i].equals(name)) {
                        exist = true;
                        break;
                    }
                }
                if (!exist) {
                    operators[cantidad] = name;
                    cantidad++;
                }
            }
        }
        String[] result = new String[cantidad];
        for (int i = 0; i < cantidad; i++) {
            result[i] = operators[i];
        }
        return result;
    }
    //Función main. Traemos los resultados trabajados y obtenidos anteriormente en las clases topDrones, overusedOperators. Y los mostramos al usuario
    public static void main(String[] args) {
        if (args.length != 3){
            System.err.println("Uso: DroneFleet <fichero_drones> <fichero_vuerlos> <max_horas>");
            return;
        }
        String dronesFile = args[0];
        String flightsFile = args[1];
        int maxHours = Integer.parseInt(args[2]);

        System.out.println("=== Top 10 drones ===");
        String[][] top = topDrones(dronesFile, flightsFile);
        for (int i = 0; i < top.length; i++) {
            System.out.println("Drone " + top[i][0] + ": " + top[i][1] + " flights, rating: " + top[i][2]);
        }
        System.out.println();
        System.out.println("=== Operadores con exceso de horas (" + maxHours + ")===");
        String[] ops = overusedOperators(flightsFile, maxHours);
        for (int i = 0; i < ops.length; i++) {
            System.out.println("Operator " + ops[i]);
        }
    }
}