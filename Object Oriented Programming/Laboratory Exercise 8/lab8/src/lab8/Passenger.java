
package lab8;


public class Passenger {
    private String name;
    private String addressFrom;
    private String addressTo;
    
    public Passenger(String n, String from, String to)throws Exception{
        name=n;
        
        if((from == null) || (to == null)){
            throw new Exception("Not allowed null addresses");
        }
        else{
            addressFrom = from;
            addressTo = to;
        }
    }
    
    public String getName(){
        return name;
    }
    
    public String getAddressFrom(){
        return addressFrom;
    }
    
    public String getAddressTo(){
        return addressTo;
    }
}
