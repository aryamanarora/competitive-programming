import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);  
    int t = sc.nextInt();
    for (int t_ = 1; t_ <= t; t_++) {
      BigInteger n; int l;
      n = sc.nextBigInteger();
      l = sc.nextInt();

      BigInteger[] b = new BigInteger[l];
      for (int i = 0; i < l; i++) b[i] = sc.nextBigInteger();
      BigInteger[] lis = new BigInteger[l + 1];
      
      int pos = 1;
      for (int i = 1; i < l; i++) {
        if (!b[i].equals(b[i - 1])) {
          pos = i;
          break;
        }
      }

      lis[pos] = b[pos].gcd(b[pos - 1]);
      for (int i = pos + 1; i <= l; i++) {
        lis[i] = b[i - 1].divide(lis[i - 1]);
      }
      for (int i = pos - 1; i >= 0; i--) {
        lis[i] = b[i].divide(lis[i + 1]);
      }

      TreeSet<BigInteger> vals = new TreeSet<>();
      for (int i = 0; i <= l; i++) vals.add(lis[i]);

      System.out.print("Case #");
      System.out.print(t_);
      System.out.print(": ");
      for (int i = 0; i <= l; i++) {
        int p = vals.headSet(lis[i]).size();
        System.out.print((char) ('A' + (char) p));
      }
      if (t_ != t) System.out.println();
    }
    sc.close();
  }
}