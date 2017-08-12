import java.util.Scanner;
import java.math.BigDecimal;

public class Main {
  private static void print(String s) {
    // leading zeros should be suppressed
    int start = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (Character.getNumericValue(s.charAt(i)) != 0) {
        start = i;
        break;
      }
    }
    
    // remove trailing zeroes
    int stop = s.length() - 1;
    for (int i = s.length() - 1; i >= 0; --i) {
      if (Character.getNumericValue(s.charAt(i)) != 0) {
        stop = i;
        break;
      }
    }
    
    // don't print the decimal point if s is an integer
    if (s.charAt(stop) == '.') {
      --stop;
    }
    
    System.out.println(s.substring(start, stop + 1));
  }
  
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    while (scanner.hasNext()) {
      String number = scanner.next();
      BigDecimal r = new BigDecimal(number);
      int n = scanner.nextInt();
      print(r.pow(n).toPlainString());
    }
  }
}
