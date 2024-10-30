
package studenttest;


public class Student {
    private int AM;
    private static int count=0;
    private String Name;
    private String Surname;
    private double degree;
    
    public void setName(String Name){
        this.Name = Name;
    }
    
    public void setSurname(String Surname){
        this.Surname = Surname;
    }
    
    public void setGrade(double grade){
        degree = grade;
    }
    
    public void setAM(){
        this.AM = ++count;
    }
    
    public String toString(){
        String s= String.format("Student %d\nName: %s\nSurname: %s\nDegree: %f",this.AM,this.Name,this.Surname,this.degree);
        return s;
    }
    
    public String getName(){
        return this.Name;
    }
    
    public String getSurname(){
        return this.Surname;
    }
    
    public double getDegree(){
        return this.degree;
    }
}
