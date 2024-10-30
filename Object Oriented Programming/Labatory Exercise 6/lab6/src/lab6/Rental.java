package lab6;

import java.util.Scanner;

public abstract class Rental implements Cost{
    private int days;
    private double payperday;
    
    public Rental(){
        days = 0;
        payperday = 0;
    }
    
    public Rental(int days, double ppd){
        this.days = days;
        this.payperday = ppd;
    }
    
    public void ReadRental(){
        Scanner input = new Scanner(System.in);
        
        System.out.println("Type the number of days:");
        days = input.nextInt();
        
        System.out.println("Type the pay per day:");
        payperday = input.nextDouble();
        
    }
    
    public int getDays(){
        return days;
    }
    
    public double getpayperDay(){
        return payperday;
    }
    
    @Override
    public String toString(){
        return "Days:" + days + "\nPay per Day:" + payperday + "\n";
    }
    
    @Override
    public double calculateCost(){
        double cost;
        
        cost = days*payperday;
        
        return cost;
    }
    
    
}
