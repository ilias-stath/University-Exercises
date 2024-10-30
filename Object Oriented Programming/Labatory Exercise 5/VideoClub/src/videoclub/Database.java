
package videoclub;

import java.util.ArrayList;
import java.util.Scanner;


public class Database {
    private ArrayList <Item> items = new ArrayList<>();
    
    public Database(){
        items = new ArrayList<Item>();
    }
    
    public void addItem(Item item){
        items.add(item);
    } 
    
    public void print(){
        for(Item i:items){
            System.out.println(i);
        }
    }
    
    public void isMovieAvailable(String title){
        for(Item i:items){
            if(i.getTitle().equals(title) && i.getOwn()){
                System.out.println("\nThe item is available.");
                return;
            }
        }
        System.out.println("\nThe item is anavailable.");
        return;
    }
    
    public void isDirectorAvailable(String director){
        for(Item i:items){
            if(i instanceof DVD){
                if(((DVD) i).getDirector().equals(director) && i.getOwn()){
                    System.out.println(i);
                }
            }
        }
    }

    
    public static void main(String[] args) {
        DVD d1 = new DVD("StarWars",210,"S.King");
        DVD d2 = new DVD("Godzilla",210,"S.King");
        d1.setOwn(true);
        d2.setOwn(true);
        CD c1 = new CD("Beat it",100,"Jackson",10);
        c1.setOwn(true);
        
        Database d = new Database();
        d.addItem(c1);
        d.addItem(d1);
        d.addItem(d2);
        d.print();
        d.isMovieAvailable("StarWars");
        d.isDirectorAvailable("S.King");
        
    }
    
}
