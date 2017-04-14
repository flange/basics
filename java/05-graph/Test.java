import java.util.List;
import java.util.ArrayList;

import java.util.Map;
import java.util.HashMap;


public class Test {

  public static void main(String[] args) {

    Graph g = new Graph();

    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(2, 4);
    g.addEdge(2, 5);

    g.addEdge(3, 5);

    g.addEdge(5, 4);


    g.bfs(1);
    System.out.println("\n");
    g.dfs(1);


  }

}
