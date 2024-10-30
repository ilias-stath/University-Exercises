
package account;


public class Account {
    private double amount;
    
    public Account(){
        amount =0;
    }
    public Account(double poso){
        amount = poso;
    }
    
    public double getAmount(){
        return amount;
    }
    public void setAmount(double poso){
        amount = poso;
    }
}
