import java.util.HashMap;
import java.util.Map;

public class Main {

  public static void main(String[] args) {

    Map<String, Integer> m = new HashMap<String, Integer>();

    String s1 = "one";
    Integer i1 = new Integer(1);

    m.put(s1, i1);

    System.out.println(m.get(s1));
    System.out.println(m.get("one"));



    A a1 = new A(i1);
    Map<String, A> m2 = new HashMap<String, A>();

    m2.put(s1, a1);
    System.out.println(m2.get(s1).x);

    a1.x = 13;
    System.out.println(m2.get(s1).x);

//  Map only stores references
//  Dangerous when it's a reference to a mutable object ...


    return;

  }
}
