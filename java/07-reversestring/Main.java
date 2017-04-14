public class Main {

  public static String reverse(String s) {

    if (s == null)
      return null;

    if (s.equals(""))
      return null;

    char[] arr = s.toCharArray();

    int i = 0;
    int j = arr.length - 1;

    while (i != j) {

      char tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      i++;
      j--;
    }

    return new String(arr);
  }

  public static void main(String[] args) {

    System.out.println(reverse("abc"));

    return;
  }

}
