
package lab3;

import java.util.Scanner;

public class Employee {
    private String firstName;
    private String lastName;
    private final int id;
    private static int noofEmployees=0;
    
    public Employee(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
        noofEmployees++;
        id = noofEmployees;
    }
    
    public Employee(){
        noofEmployees++;
        id = noofEmployees;
    }
    
    public String toString(){
       
        return "First Name:" + firstName + "\nLast Name:" + lastName + "\nID:" + id; 
    }
    
    public void readEmployee(){
        Scanner input = new Scanner(System.in);
        System.out.print("Employee\n" + "First Name:");
        firstName = input.next();
        System.out.print("Last Name:");
        lastName = input.next();
        System.out.println("---------------");
    }
    
    public static int getnoofEmployees(){
        
        return noofEmployees;
    }
    
    public void CompareEmployees(Employee e1){
        if(id > e1.id){
            System.out.println("The oldest employee is the employee with Name:" + e1.firstName + "Last:" + e1.lastName);
        }
        else{
            System.out.println("The oldest employee is the employee with Name:" + firstName + " Last:" + lastName + " ID:" + id);
        }
        
    }
    
}
