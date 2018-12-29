import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger n = scanner.nextBigInteger();
        int lo = 1, hi = n.toString().length();
        for (int i = n.toString().length(); i >= 0; i--) {
            if (n.divide(BigInteger.valueOf(i)) == i) {
                System.out.println(n.divide(BigInteger.valueOf(i)));
                break;
            }
        }
    }
}