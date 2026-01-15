import java.util.PriorityQueue;
import java.util.Scanner;

public class 2075 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(n);

        for (int i = 0; i < n * n; i++) {
            int num = scanner.nextInt();

        
            if (i < n) {
                minHeap.add(num);
            } else {
                
                if (num > minHeap.peek()) {
                    minHeap.poll(); 
                    minHeap.add(num);  
                }
            }
        }

        System.out.println(minHeap.peek());

        scanner.close();
    }
}
