import java.util.Scanner;
import java.util.Map;
import java.util.TreeMap;

class Main {
  private static int sortedness(String s) {
    int counter = 0;
    for (int i = 0; i < s.length(); ++i) {
      for (int j = i + 1; j < s.length(); ++j) {
        if (s.charAt(i) > s.charAt(j)) {
          ++counter;
        }
      }
    }
    return counter;
  }
  
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    
    Map<Integer, String> map = new TreeMap<Integer, String>();
    String[] s = new String[m];
    
    for (int i = 0; i < m; ++i) {
      s[i] = scanner.next();
      int points = sortedness(s[i]);
      map.put(points, s[i]);
    }
    
    for (Integer key: map.keySet()) {
      System.out.println(map.get(key));
    }
  }
}
