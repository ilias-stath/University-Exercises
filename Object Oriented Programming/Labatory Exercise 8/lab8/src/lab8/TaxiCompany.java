package lab8;

import java.util.ArrayList;
import java.util.Iterator;

public class TaxiCompany {
    private ArrayList<Vehicle> vehicles;
    
    public TaxiCompany(){
        vehicles = new ArrayList();
    }
    
    public void addVehicle(Vehicle v){
        vehicles.add(v);
    }
    
    public Vehicle scheduleVehicle(){
        Iterator<Vehicle> it = vehicles.iterator();
        
        while(it.hasNext()){
            Vehicle ve = it.next();
            if(ve.isFree()){
                return ve;
            }
        }
        
        return null;
    }
    
    public void requestPickup(Passenger p){
        Vehicle ve = scheduleVehicle();
        
        try{
            if(ve == null)
                throw new Exception("Taxi not available.");
            ve.setPassenger(p);
            System.out.println("Taxi is coming.");
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }      
    }
    
    public void clearTaxi(String n){
        for(Vehicle v:vehicles){
            if(v.getPassenger().equals(n)){
                v.clearPassenger();
                break;
            }
        }
    }
}
