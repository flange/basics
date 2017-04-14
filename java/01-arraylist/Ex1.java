import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Ex1 {

  public static void print(List<Integer> l) {
    System.out.println(l.toString());

    l.add(7);
  }

  public static void main(String[] args) {

    ArrayList<Integer> al1 = new ArrayList<Integer>();

    al1.add(1);
    al1.add(2);
    al1.add(3);

    print(Collections.unmodifiableList(al1));

    return;
  }
}
