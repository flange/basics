public class Main {

  public static void main(String[] args) {

    Point p1 = new Point(new Integer(1), new Integer(3));
    System.out.println(p1.toString());
    System.out.println();


    Point p2 = p1.setX(new Integer(5));
    System.out.println(p1.toString());
    System.out.println(p2.toString());
    System.out.println();


    Point p3 = p2.setY(new Integer(7));
    System.out.println(p1.toString());
    System.out.println(p2.toString());
    System.out.println(p3.toString());
    System.out.println();


    Point p4 = (p1.setX(new Integer(0))).setY(new Integer(2));
    System.out.println(p1.toString());
    System.out.println(p4.toString());






    return;

  }
}
