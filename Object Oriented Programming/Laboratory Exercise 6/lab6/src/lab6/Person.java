package lab6;

import java.util.ArrayList;
import java.util.Scanner;

public class Person {
    private String name;
    private ArrayList<Cost> costs;
    
    public Person(){
        name = " ";
        costs = new ArrayList<>();
    }
    
    public Person(String name,Cost c){
        this.name = name;
        costs.add(c);
    }
    
    public void ReadPerson(){
        Transport t = new Transport();
        SuiteRental sr = new SuiteRental();
        Scanner input = new Scanner(System.in);
        
        System.out.println("Give the persons name:");
        name = input.next();
        System.out.println("Type the number of trips you have done:");
        int number = input.nextInt();
        for(int i=0; i<number; i++){
            System.out.println("Type the info of Rental expenses for the trip number "+(i+1)+":");
            sr.ReadRental();
            System.out.println("Type info of Transport expenses for the trip number "+(i+1)+":");
            t.ReadTransport();
            costs.add(sr);
            costs.add(t);
        }
        
        
    }
    
    public double calculateTotalFees(){
        double sum=0;
        
        for(Cost c: costs){
            sum += c.calculateCost();
        }
        
       return sum; 
    }
    
}
