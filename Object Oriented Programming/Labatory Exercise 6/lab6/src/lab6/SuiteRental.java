package lab6;

import java.util.Scanner;

public class SuiteRental extends Rental {
    private int ExtraFee;
    private String comment;
    
    public SuiteRental(){
        super(0,0);
        ExtraFee = 0;
        comment = " ";
    }
    
    public SuiteRental(int days, double ppd, int eF, String comment){
        super(days,ppd);
        ExtraFee = eF;
        this.comment = comment;
    }
    
    public int getExtraFee(){
        return ExtraFee;
    }
    
    public String getComment(){
        return comment;
    }
    
    public void ReadRental(){
        super.ReadRental();
        
        Scanner input = new Scanner(System.in);
        System.out.println("Type the Extra Fee:");
        ExtraFee = input.nextInt();
        System.out.println("Give Comment:");
        comment = input.next();
        
    }
    
    @Override
    public String toString(){
        return super.toString() + "Extra Fee:" + ExtraFee + "\nComment:" + comment + "\n"; 
    }
    
    public double calculateCost(){
        double cost;
        
        if(super.getDays() <= 5){
            //System.out.println("in");
            return  cost = super.calculateCost() + ExtraFee;
        }
        else{
           return cost = (super.calculateCost() + ExtraFee)*0.9 ;
        }
        
        
    }
    
}
