
package studenttest;

import java.util.Scanner;


public class StudentTest {

    
    public static void main(String[] args) {
        int choice=0,index;
        double MO;
        University u = new University();

        u.readName();
        do{
            choice = PrintMenu();
            switch(choice){
                case 1:
                    u.addStudent();
                    break;
                case 2:
                    u.deleteStudent();
                    break;
                case 3:
                    u.printUniversity();
                    index = u.compareGrades();
                    System.out.println("\nThe student with the highest grade is:");
                    System.out.println(u.getStudent(index));
                    break;
                case 4:
                    u.getStudentWithName();
                    break;
                case 5:
                    index = u.compareGrades();
                    System.out.println("\nThe student with the highest grade is:");
                    System.out.println(u.getStudent(index));
                    break;
                case 6:
                    MO = u.moOfAll();
                    System.out.println("MO:"+MO);
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Error. Wrong choice.\n");
                    break;
            }
            
        }while(choice != 0);
        
    }
    
    private static int PrintMenu(){
        int choice=0;
        
        Scanner input = new Scanner(System.in);
        
        System.out.println("\n-----MENU-----");
        System.out.println("1.Add a new Student");
        System.out.println("2.Delete a Student");
        System.out.println("3.Info of all Students and student with the highest grade");
        System.out.println("4.Give degree based on Name and Surname");
        System.out.println("5.Info student with the highest grade");
        System.out.println("6.Average of all students");
        System.out.println("0.Exit");
        System.out.print("Choice:");
        choice = input.nextInt();
        
        return choice;
    }
}
