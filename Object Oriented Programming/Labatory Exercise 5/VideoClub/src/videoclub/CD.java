
package videoclub;


public class CD extends Item {
    private String artist;
    private int numberOfTracks;
    
    public CD(String title, int time, String artist, int numberOfTracks){
        super(title, time);
        this.artist =artist;
        this.numberOfTracks = numberOfTracks;
        
    }
    
    public String getArtist(){return this.artist;}
    
    public int getNuOfTracks(){return this.numberOfTracks;}
    
    @Override
    public String toString(){
        return super.toString() + "\nArtist: " + this.artist + "\nNumber of Tracks: " + 
                this.numberOfTracks;
    }
    
}
