public class Point {
  private Integer x;
  private Integer y;

  public Point(Integer x, Integer y) {
    this.x = x;
    this.y = y;
  }

  public Integer getX() {
    return this.x;
  }

  public Integer getY() {
    return this.y;
  }

  public Point setX(Integer n) {
    return (new Point(n, this.y));
  }

  public Point setY(Integer n) {
    return (new Point(this.x, n));
  }

  public String toString() {
    return ("x: " + x + "   y: " + y);
  }
}
