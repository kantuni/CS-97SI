import java.util.Scanner;
import java.util.ArrayList;
import java.util.Map;
import java.util.TreeMap;

class Main {
  private static int sortedness(String s) {
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
      for (int j = i + 1; j < s.length(); j++) {
        if (s.charAt(i) > s.charAt(j)) {
          cnt++;
        }
      }
    }
    return cnt;
  }
  
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    
    Map<Integer, ArrayList<String>> map = new TreeMap<Integer, ArrayList<String>>();
    String[] s = new String[m];
    
    for (int i = 0; i < m; i++) {
      s[i] = scanner.next();
      int points = sortedness(s[i]);
      
      ArrayList<String> listOfSequences = map.get(points);
      if (listOfSequences == null) {
        listOfSequences = new ArrayList<String>();
        map.put(points, listOfSequences);
      }
      listOfSequences.add(s[i]);
    }
    
    for (Integer key: map.keySet()) {
      for (String sequence: map.get(key)) {
        System.out.println(sequence);
      }
    }
  }
}
