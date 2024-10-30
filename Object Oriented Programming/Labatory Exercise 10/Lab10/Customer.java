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
public class Customer implements Runnable
{
  private static int number = 1000;      // Initial ID number
  private int id;
  private TakeANumber takeANumber;

  /**
   * Customer() constructor gives each customer a reference to the 
   * shared TakeANumber gadget and gives each an id number.
   */
  public Customer(TakeANumber gadget)
  {
    id = ++number;
    takeANumber = gadget;
  }

  /**
   * run() is the main algorithm for the customer thread. It just takes 
   * a number when it enters the bakery and then waits to be served 
   * until the clerk calls its number.
   */
  public void run()
  {
    try
    {
      Thread.sleep((int) (Math.random() * 200));
      takeANumber.nextNumber();
    }
    catch (InterruptedException e)
    {
      System.out.println("Exception: " + e.getMessage());
    }
  } // run()
}