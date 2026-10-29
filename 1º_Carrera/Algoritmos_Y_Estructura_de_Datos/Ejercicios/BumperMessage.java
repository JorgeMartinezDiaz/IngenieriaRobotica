import java.util.Arrays;

public class BumperMessage extends Message { // Usamos el extend Message para heredar de Message
    //En message tenemos::frame_id y timestamp
    //Creamos nuestra variable de tipo private pq solo la utilizaremos aquí.
    private boolean[] pressed;
    //Este es el constructor del array.
    public BumperMessage(String frame_id) {
        super(frame_id); //Llamamos al constructor de la clase padre.
        pressed = new boolean[3]; //Instanciamos pressed.
    }
    //Aquí devuelve los 3 booleanos que son el estado del bumper
    public void setPressed(boolean[] pressed) {
        if (pressed == null ) {return;}
    this.pressed = new boolean[3];
        for (int i = 0; i < pressed.length && i < 3; i++) {
        this.pressed[i] = pressed[i];
        }
    }
    public boolean[] getPressed() {
        return Arrays.copyOf(pressed, pressed.length);//Con esto lo que hacemos es devolver la copia para evitar errores con cambios en la memoria.
    }
    public boolean equals(Object obj){
        //Utilizamos el instanceof para comprobar si el objeto recibido obj es de tipo bumperMessage
        //Si no es asi devuelve falso
        if(!(obj instanceof BumperMessage)) return false;
        BumperMessage msg = (BumperMessage)obj;  //Hacemos que la variable obj que puede ser de cualquier tipo, sea BumperMessage y lo guardamos en other

        return this.getFrame_id().equals(msg.getFrame_id()) && Arrays.equals(this.pressed, msg.pressed);
    }
    public String toString() {
        return "BumperMessage{frame_id=" + getFrame_id() + ", pressed=" + Arrays.toString(pressed) + '}';
    }
}