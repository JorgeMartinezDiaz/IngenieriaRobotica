import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Queue;

public class Robot {
    private final String name;
    private final Plan plan;

    //Constructor de Robot.
    public Robot(String name, Plan plan){
        this.name = name;
        this.plan  = plan;
    }
    public String getName(){return name;}
    public Plan getPlan(){return plan;}
    public void runPlan(){
        System.out.println("** " + name + " **");
        System.out.println(plan);

        Queue<Movement> movements = plan.getMovements();
        for (Movement movement : movements){
            System.out.println(movement);
        }
    }
    public static void main(String[] args){
        if (args.length != 2){return;}

        String robotName = args[0];
        String fileName = args[1];

        In in = new In(fileName);
        String planId = in.readLine();
        Plan plan = new Plan(planId);

        while (!in.isEmpty()){
            String speedLine = in.readLine();
            if (speedLine == null || speedLine.trim().equals("")) continue;
            if (in.isEmpty()) break;

            String angleLine = in.readLine();
            if (in.isEmpty()) break;

            String durationLine = in.readLine();

            double speed = Double.parseDouble(speedLine.trim());
            double angle = Double.parseDouble(angleLine.trim());
            double duration  = Double.parseDouble(durationLine.trim());

            Movement movement = new Movement(speed, angle, duration);

            if (movement.isValid()) {
                plan.addMovement(movement);
            }
        }
        Robot robot = new Robot(robotName, plan);
        robot.runPlan();
    }
}
