
package videoclub;


public class DVD extends Item{
    private String director;
    
    public DVD(String title, int time, String director){
        super(title, time);
        this.director = director;
    }
    
    public String getDirector(){return this.director;}
    
    @Override
    public String toString(){
        return super.toString() + "\nDirector: " + this.director;
    }
    
}
