/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bank;

/**
 *
 * @author Matina
 */
public class Bank {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
      
/*System.out.println( "Starting clerk and customer threads" );
TakeANumber numberGadget = new TakeANumber();
Clerk clerk = new Clerk(numberGadget);
Clerk clerk2 = new Clerk(numberGadget);
clerk.start();
clerk2.start();
for (int k = 0; k < 5; k++) {
Customer cust = new Customer(numberGadget);
Thread customer = new Thread(cust);
customer.start();
}*/

     TakeANumber numberGadget = new TakeANumber();
    Thread clerk1 = new Thread(new Clerk(numberGadget));
    Thread clerk2 = new Thread(new Clerk(numberGadget));
    clerk1.start();
    clerk2.start();
    for (int k = 0; k < 5; k++)
    {
      Thread customer = new Thread(
      new Customer(numberGadget));
      customer.start();
    } 
        
    }
    
}


