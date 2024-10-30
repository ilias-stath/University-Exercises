
package videoclub;


 
public class Item {
    private String title;
    private int playingTime;
    private boolean gotIt;
    private String comments;
    
    public Item(String title, int time){
        this.title = title;
        playingTime = time;
    }
    
    public void setComments(String comments){
        this.comments = comments;
    }
    
    public String getComments(){return this.comments;}
    
    public String getTitle(){return this.title;}
    
    public void setOwn(boolean own){
        gotIt = own;
    }
    
    public boolean getOwn(){return gotIt;}
    
    @Override
    public String toString(){
        return "\nTitle: " + this.title + "\nPlaying Time(mins): " + this.playingTime + 
                "\nAvailable: " + this.gotIt + "\nComments: " + this.comments;
    }
    
}
