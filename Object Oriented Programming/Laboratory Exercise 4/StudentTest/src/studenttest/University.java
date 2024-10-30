
package studenttest;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Iterator;

public class University {
    private String name;
    private ArrayList<Student> students = new ArrayList<>();
    
    public void addStudent(){
        Student s = new Student();
        Scanner input = new Scanner(System.in);

        System.out.println("Give student Name:");
        s.setName(input.next());
        System.out.println("Give student Surname:");
        s.setSurname(input.next());
        System.out.println("Give student's grade:");
        s.setGrade(input.nextDouble());
        s.setAM();
        students.add(s);
    }
    
    public void readName(){
        Scanner input = new Scanner(System.in);
        
        System.out.println("Give University name:");
        name = input.next();
    }
    
    public void printUniversity(){
        System.out.println("\nUniversity Name:" + name);
        for(Student s:students){
            System.out.println("\n"+s);
        }
    }
    
    public int compareGrades(){
        double max_num=students.get(0).getDegree();
        int index=0;
        
        for(int i=1; i<students.size(); i++){
            if(students.get(i).getDegree() > max_num){
                max_num = students.get(i).getDegree();
                index = i;
            }
        }
        
        return index;
    }
    
    public void deleteStudent(){
        String Name, Surname;
        Scanner input = new Scanner(System.in);
        
        System.out.println("Give name, Surname.");
        Name = input.next();
        Surname = input.next();
        
        Iterator <Student> it = students.iterator();
        while(it.hasNext()){
            Student temp = it.next();
            if(temp.getName().equals(Name) && temp.getSurname().equals(Surname)){
                it.remove();
                System.out.println("The student was removed.");
                break;
            }
        }
        
    }
    
    public Student getStudent(int i){
        return students.get(i);
    }

    public void getStudentWithName(){
        String Name,Surname;
        Scanner input = new Scanner(System.in);

        System.out.println("Give name, Surname:");
        Name = input.next();
        Surname = input.next();

        for(int i=0; i<students.size(); i++){
            if(students.get(i).getName() == Name && students.get(i).getSurname() == Surname){
                System.out.println("Degree:");
                System.out.println(students.get(i).getDegree());
                break;
            }
        }

    }

    public double moOfAll(){
        double MO=0,sum=0;
        int nuOfStudents=0;

        for(int i=0; i<students.size(); i++){
            sum += students.get(i).getDegree();
            nuOfStudents = i+1;
        }
        MO = sum/nuOfStudents;

        return MO;
    }
}
