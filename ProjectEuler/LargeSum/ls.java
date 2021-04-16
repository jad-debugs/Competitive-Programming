import java.math.*;
import java.util.Scanner;

public class ls 
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        String[] data  = new String[100];

        for (int i = 0; i < 100; i++)
            data[i] = input.nextLine();

        BigInteger ans = BigInteger.ZERO;
        for (int i = 0; i < 100; i++) {
            BigInteger tmp = new BigInteger(data[i]);
            ans = ans.add(tmp);
        }
        
        System.out.println();
        System.out.println(ans);
    }
}