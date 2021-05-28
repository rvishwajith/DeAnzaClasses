/*
Rohith Vishwajith
Mr. Goel \ CIS22C
5/20/21

LinkedList.java
 */

public class LinkedList {

    protected Node head = null;
    protected int count = 0;

    public LinkedList() { }

    public LinkedList(Node n) {
        head = n;
        count = 1;
    }

    // appends a node to the back of the list
    public void append(Node data) {
        if(count == 0) {
            head = data;
        }
        else {
            Node last = head;
            for(int i = 0; i < (count-1); i++) {
                last = last.getNext();
            }
            last.setNext(data);
        }
        count++;
    }

    // checks if the list is empty
    public boolean isEmpty() {
        if(count == 0) {
            return true;
        }
        return false;
    }

    // looks for a node given a position
    public Node findAt(int index) {
        Node curr = head;
        if(count == 0 || count < index) {
            System.out.println("Index too large");
            return null;
        }
        for(int i = 0; i < index; i++) {
            curr = curr.getNext();
        }
        return curr;
    }

    // clears the list
    public void empty() {
        head = null;
    }

    // inserts the node at a given position
    public void insertAt(Node data, int loc) {
        int currentLoc = 0;
        if(loc == 0) {
            Node next = head;
            head = data;
            data.setNext(next);
            count++;
        }
        else if(loc > count || loc < 0) {
            System.out.println("Error at insertAt(), index is out of bounds.");
            return;
        }
        else {
            int i = 0;
            Node prev = null;
            Node curr = head;
            while(i < loc) {
                curr = curr.getNext();
                prev = curr;
            }
            Node temp = prev.getNext();
            prev.setNext(data);
            data.setNext(temp);
        }
        System.out.println("Inserted node with value " + data.getData() + " at Index " + loc);
        count++;
    }

    // deletes a node based on its value
    public void delete(Node data) {
        Node curr = head;
        Node prev = null;
        count--;
        if(curr != null && curr.getData().isEqual(data.getData())) {
            head = curr.getNext();
            return;
        }
        while(curr != null && !curr.getData().isEqual(data.getData())) {
            prev = curr;
            curr = curr.getNext();
        }
        if(curr != null) {
            prev.setNext(curr.getNext());
        }
        // no node found
        else {
            count++;
            System.out.println("Node with data " + data.getData() + " not found in delete()");
        }
    }

    // searches for a node based on its value
    public Node find(Node data) {
        Node curr = head;
        Node prev = null;
        int index = 0;
        if(curr != null && curr.getData().isEqual(data.getData())) {
            System.out.println("Node with data " + data.getData() + " found at Index " + index);
            return head;
        }
        while(curr != null && !curr.getData().isEqual(data.getData())) {
            prev = curr;
            curr = curr.getNext();
            index++;
        }
        if(curr != null) {
            System.out.println("Node with data " + data.getData() + " found at Index " + index);
            return curr;
        }
        else {
            System.out.println("Node with data " + data.getData() + " not found in delete()");
            return null;
        }
    }

    // returns the length of the list
    public int getLength() {
        return count;
    }

    // prints the data in the list from front to back
    public void print() {
        Node node = head;
        System.out.print("USD List (Count: " + count + ") ");
        for(int i = 0; i < count; i++) {
            System.out.print(node.getData() + " ");
            node = node.getNext();
        }
        System.out.println();
    }
}
