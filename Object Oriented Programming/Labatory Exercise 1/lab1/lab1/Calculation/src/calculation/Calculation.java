/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculation;
import java.util.Scanner;
/**
 *
 * @author ICTE LAB
 */
public class Calculation {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int num,min=0,max=0,count=0,sum=0;
        Scanner input = new Scanner(System.in);
        
        
        do{
            System.out.println("Type a negative integer.");
            num = input.nextInt();
            if(num >= 0)
                continue;
            else{
                count++;
                sum += num;
                if(count == 1){
                    min = num;
                    max = num;
                }
                else{
                    if(num > max){
                        max = num; 
                    }
                    else if(num < min){
                        min = num;
                    }
                    else{
                        continue;
                    }
                }
            }
            
        }while(num != 555);
        
        if(count == 0){
            System.out.println("The Average is 0 because you didn't give any negative ineteger");
        }
        else{
            System.out.println("Average=" + (float)sum/count);
            System.out.println("Min=" + min);
            System.out.println("Max=" + max);
        }
 
    }
        
    
}
