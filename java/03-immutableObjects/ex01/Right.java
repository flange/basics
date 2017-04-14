public class Right {

  private Integer x;
  private A a;

  public Right(int x) {
    this.x = new Integer(x);
    this.a = new A(x);
  }

  public Integer getX() {
    return this.x; // works because Integer is also immutable
  }

  public A getA() {
    //return this.a; // copy of the reference to something private.. if mutable -> fail

    return (new A(a.x));
  }

  public String toString() {
    return (new String("x: " + x + "    a.x: " + a.x));
  }

}
