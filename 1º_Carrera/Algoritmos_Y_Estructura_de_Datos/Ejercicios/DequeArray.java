import java.util.Iterator;

public class DequeArray<Item> implements Iterable<Item> {

    private Object[] size; // Total array size
    private int n; // Number of Items in to the array

    public DequeArray() {   // Constructor of the deque
        size = new Object[8];
        n = 0;
    }

    public boolean isEmpty() {return n == 0;} // Return true if a is Empty(n=0)
    public int size() {return n;} // Return number of the elements that are in the Deque (n)
    public int mem() {return size.length;} // Return the total size of the Deque

    //Clases push
    // Desplazamos todos los elementos a la derecha para dejar libre la posición 0.
    public void pushLeft(Item item) {
        if(n == size.length) resize (2*size.length);
        for (int i = n; i>0; i--) {
            size[i] = size[i-1]; // Movemos a la derecha (a[i-1] -> a[i])
        }
        size[0] = item;
        n++;
    }
// El extremo derecho siempre va a esta en la posición n, porque el último ocupado es n-1, y n esta libre.
    public void pushRight(Item item) {
        if(n == size.length) resize(2*size.length);
        size[n] = item;
        n++;
    }

    // Clases pop
    public Item popLeft() {
        if(isEmpty()){return null;}
        Item item = (Item) size[0]; // a[0] es la primera posición por la izquierda(La que necesitamos sacar)
        for (int i = 1; i<n-1; i++) {
            size[i] = size[i+1]; // Disminuyes una posición (a[i+1]->a[i])
        }
        n--;
        if(size.length > 8 && n <= size.length/4) resize(size.length/2);
        return item;
    }

    public Item popRight() {
        if(isEmpty()){return null;}
        n--;  // Reducimos primero porque el primer elemento por la derecha esta en n-1 no en n.
        Item item = (Item) size[n];

        if(size.length > 8 && n <= size.length/4) resize(size.length/2);
        return item;
    }

    // Rediseñar el tamaño del array
    public void resize(int newSize) {
        Object[] b = new Object[newSize]; // Creamos un nuevo array con las nuevas dimensiones y en el copiamos el array size
        for(int i=0;i < n ;i++){
            b[i]=size[1];
        }
        size = b;
    }

    //Iterador:
    public Iterator<Item> iterator() {
        return new Iterator<Item>() {
            int i = 0;

            public boolean hasNext() {
                return i < n;
            }

            public Item next() {
                return (Item) size[i++];
            }
        };
    }

    public Iterator<Item> reverseIterator() {
        return new  Iterator<Item>() {
            int i = n -1; //EStart in the last element.
            public boolean hasNext() {
                return i >= 0;
            }
            public Item next() {
                return (Item) size[i--];
            }
        };
    }
     public String toString() {
        String s = "[";
        for(int i = 0;i < n;i++){
            if(i >0) s = s + ",";
            s = s + size[i];
        }
        s += "]";
        return s;
    }

    public static void main(String[] args) {
        DequeArray<Integer> deque = new DequeArray<>();

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

