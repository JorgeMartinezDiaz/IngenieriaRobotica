import java.util.Arrays;

public class LaserMessage extends Message {

    //Declaramos la variable que vamos a utilizar en este caso un Array de tamaño 8
    //Que llamaremos distances.
    private float[] distances;
    public LaserMessage(String frame_id) {
        super(frame_id);
        distances = new float[8];
    }
    public void setDistances(float[] distances){
        if (distances == null ) {return;}
        this.distances = new float[8];
        for (int i = 0; i < distances.length && i < 8; i++) {
            this.distances[i] = distances[i];
        }
    }
    public float[] getDistances() {return Arrays.copyOf(distances, distances.length);}
    public boolean equals(Object obj){
        //Como obj puede ser cualquier tipo de objetos, comprobamos si es tipo LaserMessage con instanceof
        //Si no lo es return false.
        if(!(obj instanceof LaserMessage)){return false;}
        //Aquí convertimos al tipo LaserMessage
        LaserMessage laser = (LaserMessage)obj;
        return this.getFrame_id().equals(laser.getFrame_id()) && Arrays.equals(this.distances, laser.distances);
    }
    public String toString(){
        return "LaserMessage{frame_id= " + getFrame_id() + ", distances=" + Arrays.toString(distances) + '}';
    }
}