package bank;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Matina
 */

    
public class Clerk extends Thread {
private static int id = 0;
private int myId;
private TakeANumber takeANumber;
/**
* Clerk() constructor gives the clerk a reference to the
* TakeANumber gadget.
*/
public Clerk(TakeANumber gadget) {
takeANumber = gadget;
myId = id++;
}
public void run() {
while (true) {
try {
sleep((int)(Math.random() * 1000));
takeANumber.nextCustomer(myId);
} catch (InterruptedException e) {
System.out.println("Exception: " + e.getMessage() );
}
}
}
}
