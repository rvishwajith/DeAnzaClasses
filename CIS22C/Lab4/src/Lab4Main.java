import java.util.Locale;
import java.util.Scanner;

/*
Rohith Vishwajith
Mr. Goel \ CIS22C
5/20/21

Lab4Main.java
 */

public class Lab4Main {

    public static void main(String[] args) {
        Lab4Main l4m = new Lab4Main();
        l4m.run();
    }

    /*
    NOTE:
    Assuming that input is supposed to be
    procedurally generated rather than user input
     */
    public void run() {
        int count = 7;
        Node[] nodes = new Node[count];
        for(int i = 0; i < count; i++) {
            int dollars = (int)(Math.random() * 1000);
            int cents = (int)(Math.random() * 100);
            USD balance = new USD(dollars, cents);
            nodes[i] = new Node(balance);
        }
        linkedListDemo(nodes);
        stackDemo(nodes);
        queueDemo(nodes);
        System.out.println("\nPROGRAM COMPLETE.");
    }

    // demo for linked list only
    public void linkedListDemo(Node[] nodes) {
        System.out.println("\n---------- LINKED LIST DEMONSTRATION:");
        LinkedList list = new LinkedList();

        System.out.println("\nINSERTING IN RANDOM ORDER:");
        int offset1 = (int)(Math.random() * nodes.length);
        for(int i = 0; i < nodes.length; i++) {
            list.append(nodes[(offset1+i) % nodes.length]);
            list.print();
        }

        System.out.println("\nSEARCHING IN RANDOM ORDER:");
        int offset2 = (int)(Math.random() * nodes.length);
        for(int i = 0; i < (nodes.length+3); i++) {
            list.find(nodes[(offset2+i) % nodes.length]);
        }

        System.out.println("\nDELETING IN RANDOM ORDER:");
        int offset3 = (int)(Math.random() * nodes.length);
        for(int i = 0; i < (nodes.length + 3); i++) {
            int index = (offset3+i) % nodes.length;
            list.print();
            System.out.println("Trying to delete node with value " + nodes[index].getData() + ":");
            list.delete(nodes[index]);
        }
    }

    // demo for stack only
    public void stackDemo(Node[] nodes) {
        System.out.println("\n---------- STACK DEMONSTRATION\nPUSHING IN RANDOM ORDER:");
        Stack stack = new Stack();
        for(int i = 0; i < nodes.length; i++) {
            stack.append(nodes[i]);
            stack.print();
        }
        System.out.println("\nPOPPING AND PEEKING IN RANDOM ORDER:");
        while(!stack.isEmpty()) {
            int rand = (int)(Math.random() * 2);
            if(rand == 0) {
                stack.pop();
            }
            else {
                stack.peek();
            }
            stack.print();
        }
    }

    // demo for queue only
    public void queueDemo(Node[] nodes) {
        System.out.println("\n---------- QUEUE DEMONSTRATION\nENQUEUEING IN RANDOM ORDER:");

        Queue queue = new Queue();
        int offset1 = (int)(Math.random() * nodes.length);
        for(int i = 0; i < nodes.length; i++) {
            queue.enqueue(nodes[(offset1+i) % nodes.length]);
            queue.print();
        }

        System.out.println("\nDEQUEUEING AND PEEKING FRONT/REAR IN RANDOM ORDER:");
        while(!queue.isEmpty()) {
            int rand = (int)(Math.random() * 3);
            if(rand == 0) {
                queue.dequeue();
            }
            else if(rand == 1) {
                queue.peekFront();
            }
            else {
                queue.peekRear();
            }
            queue.print();
        }
    }
}