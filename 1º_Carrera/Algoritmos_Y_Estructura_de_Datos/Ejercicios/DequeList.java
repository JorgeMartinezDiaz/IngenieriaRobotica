import java.util.Iterator;

public class DequeList<Item> implements Iterable<Item> {
    private class Nodo{
        Item value;
        Nodo next;
        Nodo before;
    }

    private Nodo first; // First nodo of the Deque
    private Nodo last; // Last nodo of the Deque
    private int size; // Tamaño de la de Deque

    public DequeList(){
        first = null;
        last = null;
        size = 0;
    }
    public boolean isEmpty(){return size == 0;}
    public int size(){return size;}
    public int mem(){return size;}

    // Clases Push
    public void pushRight(Item item){
        Nodo nuevoDerecho = new Nodo();
        nuevoDerecho.value = item;

        if(isEmpty()){
            first = nuevoDerecho;
            last = nuevoDerecho;
        }else{
            nuevoDerecho.before = last;
            nuevoDerecho.next = nuevoDerecho;
            last = nuevoDerecho;
        }
    size++;
    }
    public void pushLeft(Item item){
        Nodo nuevoIzquierdo = new Nodo();
        nuevoIzquierdo.value = item;

        if(isEmpty()){
            first = nuevoIzquierdo;
            last = nuevoIzquierdo;
        }else{
            nuevoIzquierdo.before = nuevoIzquierdo;
            nuevoIzquierdo.next = first;
            nuevoIzquierdo =  first;
        }
        size++;
    }

    //Clases pop
    public Item popLeft(){
       if(isEmpty()){return null;}

       Item item = first.value;
       first = first.next;

       if(first == null){
           last = null;
       }else{
           first.before = null;
       }
    size--;
    return item;
    }
    public Item popRight(){
        if (isEmpty()){return null;}

        Item item = last.value;
        last = last.next;
        if(last == null){
            first = null;
        }else{
            last.next = null;
        }
        size--;
        return item;
    }

    public Iterator<Item> iterator(){
        return new Iterator<Item>(){
            Nodo actual = first;
            public boolean hasNext(){return actual!=null;}
            public Item next(){
                Item item = actual.value;
                actual = actual.next;
                return item;
            }
        };
    }

    public String toString(){
        String s = "[";
        Nodo actual = first;

        while(!isEmpty()){
            s = s + actual.value;
            if(actual.next != null){
                s = s + ",";
            }
        actual = actual.next;
        }
        s = s + "]";
        return s;
    }

    public static void main(String[] args){
        DequeList<Integer> deque = new DequeList<>();

        deque.pushLeft(1);
        deque.pushLeft(0);
        deque.pushRight(2);
        deque.pushRight(3);

        System.out.println(deque);

        deque.popLeft();
        deque.popRight();

        System.out.println(deque);
    }
}
