package lab6;

import java.util.Scanner;

public class Transport implements Cost{
    private double FeetoArrive;
    private double FeetoDepart;
    private String type;
    
    public Transport(){
        FeetoArrive = 0;
        FeetoDepart = 0;
        type = " ";
    }
    
    public Transport(double FtA, double FtD, String type){
        FeetoArrive = FtA;
        FeetoDepart = FtD;
        this.type = type;
    }
    
    public void ReadTransport(){
        Scanner input = new Scanner(System.in);
        
        System.out.println("Type the Fee to Arrive:");
        FeetoArrive = input.nextDouble();
        System.out.println("Type the Fee to Depart:");
        FeetoDepart = input.nextDouble();
        System.out.println("Type the type of transport you used:");
        type = input.next();
        
    }
    
    @Override
    public String toString(){
        return "Fee to Arrive:" + FeetoArrive + "\nFee to Depart:" + FeetoDepart + "Type of Transport:" + type;
    }
    
    @Override
    public double calculateCost(){
        double cost;
        
        cost = FeetoDepart + FeetoArrive;
        
        return cost;
    }
    
    
}
