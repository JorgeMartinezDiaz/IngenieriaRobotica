import edu.princeton.cs.algs4.Queue;

public class Plan {
    private final String id;
    private final Queue<Movement> movements;
    public Plan(String id){
        this.id = id;
        this.movements = new Queue<Movement>();
    }
    public void addMovement(Movement movement){
        Movement copy = new Movement(movement.getSpeed(), movement.getAngle(), movement.getDuration());
        movements.enqueue(copy);
    }
    public String getId(){return id;}
    public double getDuration(){
        double total = 0.0;
        for (Movement movement : movements){
            total += movement.getDuration();
        }
        return total;
    }
    public Queue<Movement> getMovements(){
        Queue<Movement> copyQueue = new Queue<Movement>();
        for (Movement movement : movements){
            Movement copy = new Movement(movement.getSpeed(), movement.getAngle(), movement.getDuration());
            copyQueue.enqueue(copy);
        }
        return copyQueue;
    }
    public boolean isValid(){
        for (Movement movement : movements){
            if(!movement.isValid()){
                return false;
            }
        }
        return true;
    }
    public boolean equals(Object other){
        if (this == other) return true;
        if (other == null ) return false;
        if (this.getClass() != other.getClass()) return false;

        Plan otherPlan = (Plan) other;
        Queue<Movement> q1 = this.getMovements();
        Queue<Movement> q2 = otherPlan.getMovements();

        if ( q1.size() != q2.size()) return false;
        while(!q1.isEmpty()){
            if (q1.dequeue().equals(q2.dequeue())) return false;
        }
        return true;
    }
    public String toString(){
        return "[" + id + "]" + movements.size() + " movs - " +  getDuration() + " seconds";
    }
}
