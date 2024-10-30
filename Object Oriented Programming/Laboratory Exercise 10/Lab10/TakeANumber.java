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
public class TakeANumber
{
  private int next = 0;     // Next place in line
  private int serving = 0;  // Next customer to serve

  /**
   * nextNumber() is called by each customer as it enters the bakery. 
   * It returns the customer's "ticket". The first customer will be 
   * get 1. The fact that this method is synchronized means that it 
   * cannot be interrupted by another customer, once it starts 
   * executing. This guarantees that customer's have mutually exclusive 
   * access to the "tickets".
   *
   * @return an int representing a customer's waiting number
   */
  public synchronized int nextNumber()
  {
    next = next + 1;
    return next;
  } // nextNumber()

  /**
   * nextCustomer() is called by the clerk to decide who should 
   * be served next.
   *
   * @return an int representing a customer to be served next
   */
public synchronized int nextCustomer(int clerkId) {
try
    {
      while (next <= serving)
      {
        System.out.println("\nClerk "+ clerkId+" waiting ");
        wait(); 
      }
      ++serving;
      System.out.println("\nClerk  "+ clerkId+" serving ticket " + serving);
      return serving;
    }
    catch (InterruptedException e)
    {
      System.out.println("Exception " + e.getMessage());
      return -1;
    }
  } // nextCustomer()
}