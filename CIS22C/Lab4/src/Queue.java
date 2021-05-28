/*
Rohith Vishwajith
Mr. Goel \ CIS22C
5/20/21

Queue.java
 */

public class Queue extends LinkedList {

    public Queue() {
        super();
    }

    // appends a node to the back of the list
    public void enqueue(Node n) {
        append(n);
    }

    // removes a node from the front of the list
    public Node dequeue() {
        Node n = head;
        delete(n);
        System.out.println("Dequeueing node " + n.getData());
        return n;
    }

    // returns the node at the front of the list
    public Node peekFront() {
        if(count <= 0) {
            System.out.println("Cannot peek front of an empty queue.");
            return null;
        }
        else {
            Node n = findAt(0);
            System.out.println("Peeking front - current value: " + n.getData());
            return n;
        }
    }

    // returns the node at the back of the list
    public Node peekRear() {
        if(count <= 0) {
            System.out.println("Cannot peek rear of an empty queue.");
            return null;
        }
        else {
            Node n = findAt(count-1);
            System.out.println("Peeking rear - current value: " + n.getData());
            return n;
        }
    }

    // prints the queue data
    public void print() {
        Node node = head;
        System.out.print("USD Queue (Count: " + count + ") Front -> ");
        for(int i = 0; i < count; i++) {
            System.out.print(node.getData() + " ");
            node = node.getNext();
        }
        System.out.println("<- Back");
    }
}
