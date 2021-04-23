import java.math.BigInteger;

class PowerDigitSum {
    public static void main(String[] args) {
        BigInteger big = new BigInteger("2");

        for (int i = 1; i < 1000; i++)
            big = big.multiply(BigInteger.valueOf(2));
        String digits = big.toString();
        int ans = 0;
        for (int i = 0; i < digits.length(); i++)
            ans += (int)(digits.charAt(i) - '0');
        System.out.println(ans);
    }
    
}