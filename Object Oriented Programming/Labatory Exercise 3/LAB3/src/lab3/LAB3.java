
package lab3;


public class LAB3 {

   
    public static void main(String[] args){
        System.out.println("The number of Employees is:" + Employee.getnoofEmployees()); // Μπορώ να την καλέσω με το όνομα της κλάσης επειδή είναι static
        Employee e1 = new Employee();
        Employee e2 = new Employee("Konnos","Kos");
        
        e1.readEmployee();
        
        System.out.println(e1); // To string
        System.out.println(e2.toString());
        
        Employee e3 = new Employee();
        e3.readEmployee();
        
        System.out.println(e3);
        System.out.println("The number of Employees is:" + Employee.getnoofEmployees());
        
        e1.CompareEmployees(e2);
    }
    
    
}


