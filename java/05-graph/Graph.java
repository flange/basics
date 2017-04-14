import java.util.Deque;
import java.util.List;
import java.util.Map;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;



public class Graph {

  private Map<Integer, List<Integer>> adjacencyList = new HashMap<>();

  public void addVertex(Integer v) {
    adjacencyList.putIfAbsent(v, new ArrayList<Integer>());

    return;
  }

  public void addEdge(Integer src, Integer dst) {

    if (!hasNode(src) || !hasNode(dst))
      return;

    adjacencyList.get(src).add(dst);

    return;
  }

  public boolean hasNode(Integer n) {
    return adjacencyList.containsKey(n);
  }

  public void bfs(Integer start) {

    if (!hasNode(start))
      return;

    Map<Integer, Boolean> visited = new HashMap<>();

    Deque<Integer> todo = new LinkedList<>();
    todo.addLast(start);

    while (!todo.isEmpty()) {
      Integer current = todo.removeFirst();

      if (visited.containsKey(current))
        continue;

      visited.put(current, true);

      for (Integer neighbour : adjacencyList.get(current))
        todo.addLast(neighbour);

      System.out.println(current);
    }

    return;
  }

  public void dfs(Integer start) {

    if (!hasNode(start))
      return;

    Map<Integer, Boolean> visited = new HashMap<>();

    Deque<Integer> todo = new LinkedList<>();
    todo.addLast(start);

    while (!todo.isEmpty()) {
      Integer current = todo.removeLast();

      if (visited.containsKey(current))
        continue;

      visited.put(current, true);

      for (Integer neighbour : adjacencyList.get(current))
        todo.addLast(neighbour);

      System.out.println(current);
    }

    return;

  }











  public String toString() {

    StringBuilder res = new StringBuilder();

    res.append("digraph {\n");

    for (Map.Entry<Integer, List<Integer>> entry : adjacencyList.entrySet()) {
      for (Integer neighbour : entry.getValue()) {
        res.append("  " + entry.getKey() + " -> " + neighbour + "\n");
      }
    }

    res.append("}");

    return res.toString();
  }

}
