
package account;


public class AccountTest {

    
    public static void main(String[] args) {
        
        Account Account1 = new Account();
        Account1.setAmount(500);
        System.out.println("Account1:" + Account1.getAmount());
        
        Account Account2 = new Account(500);
        Account2.setAmount(1500);
        
        if(Account1.getAmount() > Account2.getAmount()){
            System.out.println("The account with the highest balance is the Account1 with balance:" + Account1.getAmount());
        }
        else if(Account1.getAmount() == Account2.getAmount()){
            System.out.println("Both accounts have equal balance at:" + Account1.getAmount());
        }
        else{
            System.out.println("The account with the highest balance is the Account2 with balance:" + Account2.getAmount());
        }
    }
    
}
