/*
Rohith Vishwajith
Mr. Goel \ CIS22C
5/20/21

Stack.java
 */

public class Stack extends LinkedList {

    public Stack() {
        super();
    }

    // appends a node to the back of the list
    public void push(Node node) {
        append(node);
    }

    // returns the node at the back of the list
    public Node peek() {
        if(count <= 0) {
            System.out.println("Cannot peek an empty stack.");
            return null;
        }
        else {
            Node n = findAt(count-1);
            System.out.println("Peeking stack - value: " + n.getData());
            return n;
        }
    }

    // removes and returns the node at the back of the list
    public Node pop() {
        Node n = peek();
        delete(n);
        System.out.println("Popping node " + n.getData());
        return n;
    }

    // prints the stack
    public void print() {
        Node node = head;
        System.out.print("Stack (Count: " + count + ") Bottom -> ");
        for(int i = 0; i < count; i++) {
            System.out.print(node.getData() + " ");
            node = node.getNext();
        }
        System.out.println("<- Top");
    }
}
