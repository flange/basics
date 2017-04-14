public class Ex1 {

  public static void main(String[] args) {

/*  Wrong

    Wrong a1 = new Wrong();
    System.out.println("a1.x: " + a1.x);

    Wrong a2 = a1;
    System.out.println("a2.x: " + a2.x);

    a2.x = new Integer(3);
    System.out.println("a1.x: " + a1.x);
    System.out.println("a2.x: " + a2.x);
*/


    Right a1 = new Right(7);
    Integer x = a1.getX();
    x = new Integer(13);

    System.out.println(a1.toString());
    System.out.println(x);

    return;
  }

}
