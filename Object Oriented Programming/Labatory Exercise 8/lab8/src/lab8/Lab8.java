/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package lab8;

/**
 *
 * @author ICTE LAB
 */
public class Lab8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        TaxiCompany t1 = new TaxiCompany();
        Vehicle v1 = new Vehicle();
        Vehicle v2 = new Vehicle();
        Passenger p=null;
        Passenger p1=null;
        
        try{
            p=new Passenger("Papadakis","Karamanli 1", "Tsimiski");
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        
        try{
            p1 = new Passenger("Konos","ermou 23","volou 10");
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        
        t1.addVehicle(v1);
        t1.addVehicle(v2);
        t1.requestPickup(p);
        t1.requestPickup(p1);
    }
    
}
