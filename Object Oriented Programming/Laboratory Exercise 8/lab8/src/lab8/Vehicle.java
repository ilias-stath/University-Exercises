package lab8;


public class Vehicle {
    private Passenger passenger;
    private TaxiCompany taxiCompany;
    
    public Vehicle(){   
    }
    
    public Vehicle(TaxiCompany tC){
        try{
            if(tC == null){
                throw new NullPointerException("Initialize Taxi Company");
            }
            else{
                taxiCompany = tC;
            }
        }
        catch(NullPointerException e){
            System.out.println(e.getMessage());
        }
    }
    
    public void setPassenger(Passenger p){
        passenger = p;
    }
    
    public Passenger getPassenger(){
        return passenger;
    }
    
    public void clearPassenger(){
        passenger = null;
    }
    
    public boolean isFree(){
        
        if(passenger == null){
            return true;
        }
        return false;
    }
}
