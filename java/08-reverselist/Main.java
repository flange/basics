public class Main {

  public static void main(String[] args) {

    List l = new List();
    System.out.println(l.toString());

    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    System.out.println(l.toString());

    l.reverse();
    System.out.println(l.toString());



  }

}
