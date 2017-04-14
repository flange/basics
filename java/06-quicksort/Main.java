import java.util.Arrays;
import java.util.stream.IntStream;

public class Main {
  public static void main(String[] args) {
    int[] x = { 3, 2, 1, 5, 4 };

    int low = 0;
    int high = x.length - 1;

    quickSort(x, low, high);
  }

  public static int min(int[] arr, int low, int high) {

    int min = Integer.MAX_VALUE;

    for (int i = low; i <= high; i++) {

      if (arr[i] < min)
        min = arr[i];
    }

    return min;
  }

  public static void quickSort(int[] arr, int low, int high) {

    System.out.print("sub array: [ ");
    for (int t = low; t <= high; t++)
      System.out.print(arr[t] + " ");

    System.out.println("]");

    System.out.println("l: " + low + " h: " + high);

    if (arr == null || arr.length == 0)
      return;

    if (low >= high)
      return;

    int middle = low + (high - low) / 2;
    int pivot = min(arr, low, high);

    int i = low, j = high;

    System.out.println("pivot: " + pivot + "\n");

    while (i <= j) {
      System.out.println("     i: " + i + "  j: " + j);

      while (arr[i] < pivot) {
        i++;
      }

      while (arr[j] > pivot) {
        j--;
      }

      System.out.println("     before swap:  i: " + i + " j: " + j);

      if (i <= j) {
        System.out.println("     swap!");
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
      }

      System.out.println("     after swap:   i: " + i + " j: " + j);
      System.out.println("     " + Arrays.toString(arr) + "\n\n");

    }

    // recursively sort two sub parts
    if (low < j)
      quickSort(arr, low, j);

    if (high > i)
      quickSort(arr, i, high);
  }
}
