public class Movement {
    private double speed;
    private double angle;
    private double time;

    public Movement(double speed, double angle, double time) {
        this.speed = speed;
        this.angle = angle;
        this.time = time;
    }
    // Métodos get: Devuelven el valor de las variables.
    public double getSpeed(){return speed;}
    public double getAngle(){return angle;}
    public double getDuration(){return time;}

    //Métodos set: Establecen el valor de cada variable.
    public void setSpeed(double speed){this.speed = speed;}
    public void setAngle(double angle){this.angle = angle;}
    public void setDuration(double duration){this.time = duration;}

    //Para que el movimiento sea valido de estar Speed[-1.5, 1.5]; Angle[-Pi/2. Pi/2] y time>0.
    public boolean isValid(){
        if (speed >= -1.5 && speed <= 1.5 && angle >= -Math.PI && angle <= Math.PI && time > 0){return true;}
        else {return false;}
    }

    // Hacemos la comprobacion de las tres variables de nuestra clase.
    public boolean equals(Object other){
        if (this == other) return true;
        if (other == null) return false;
        if (this.getClass() != other.getClass()) return false;
        Movement otherMovement = (Movement) other;
        if (this.speed != otherMovement.speed) return false;
        if (this.angle != otherMovement.angle) return false;
        if (this.time != otherMovement.time) return false;
        return this.getSpeed() == otherMovement.getSpeed() && this.getAngle() == otherMovement.getAngle() && this.getDuration() == otherMovement.getDuration();
    }
    public String toString(){
        return "[Speed: " + getSpeed() + ", Angle: " + getAngle() + ", Time: " + getDuration() + "]";
    }
}
