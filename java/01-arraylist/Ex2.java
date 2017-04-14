import java.util.*;

public class Ex2 {

  public static void main(String[] args) {

    ArrayList<Integer> al = new ArrayList<Integer>();

    al.add(1);
    al.add(2);
    al.add(3);

    System.out.println(al.toArray().getClass().getComponentType());

    Object o = al.get(0);
    System.out.println(o.getClass().getName());

    return;
  }

}
