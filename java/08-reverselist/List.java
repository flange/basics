public class List {

  private class Node {
    public int value;
    public Node next;

    public Node(int n) {
      this.value = n;
      this.next = null;
    }
  }

  public Node head;
  public Node last;
  public int length;

  public boolean isEmpty() {
    return (head == null);
  }

  public void append(int v) {

    Node n = new Node(v);

    if (isEmpty()) {
      head = n;
      last = n;
      length++;
      return;
    }

    last.next = n;
    last = n;
    length++;

    return;
  }

  public void reverse() {

    if (isEmpty())
      return;

    Node prev = head;
    Node curr = head.next;
    Node next = (head.next).next;

    head.next = null;
    last = head;

    while (next != null) {
      curr.next = prev;
      prev = curr;
      curr = next;
      next = next.next;
    }

    curr.next = prev;
    head = curr;

    return;
  }


  public String toString() {

    if (isEmpty())
      return "[]";

    StringBuilder res = new StringBuilder("[ ");

    Node iter = head;

    while (iter != null) {
      res.append(iter.value + " ");
      iter = iter.next;
    }

    res.append("]");

    return res.toString();
  }



}
