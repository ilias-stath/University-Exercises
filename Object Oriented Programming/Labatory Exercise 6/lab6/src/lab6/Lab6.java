package lab6;


public class Lab6 {

    
    public static void main(String[] args){
        double cost;
        Person p = new Person();
        p.ReadPerson();
        cost = p.calculateTotalFees();
        
        System.out.println("Total cost:" + cost);
    }
    
}