public class Node {
    private USD data = null;
    private Node next = null;

    public Node() { }

    public Node(USD u) {
        data = u;
    }

    public Node(USD u, Node n) {
        data = u;
        next = n;
    }

    public void setNext(Node n) { next = n; }

    public Node getNext() { return next; }

    public void setData(USD u) { data = u; }

    public USD getData() { return data; }
}
