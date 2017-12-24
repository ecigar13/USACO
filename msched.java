import java.util.*;
import java.util.logging.Logger;
import java.io.*;

public class msched {

	public static void main(String[] args) {

		try {
			Scanner input = new Scanner(new File("msched.in"));
			PrintWriter output = new PrintWriter("msched.out");
			int numCows = input.nextInt();

			int quantity[] = new int[numCows];
			int deadline[] = new int[numCows];
			int schedule[] = new int[15];

			for (int i = 0; i < numCows; i++) {
				quantity[i] = input.nextInt();
				deadline[i] = input.nextInt();
			}

			for (int c = 0; c < numCows; c++) {
				int max = 0;
				int maxIndex = 0;

				// find location of max and maxIndex
				for (int i = 0; i < numCows; i++) {
					if (max < quantity[i]) {
						max = quantity[i];
						maxIndex = i;
					}
				}
				quantity[maxIndex] = 0; // save maxIndex and reset its quantity to 0 (remove maxIndex)

				int scheduleIndex = deadline[maxIndex]; // pick deadline of maxIndex

				// pick the largest item on the rest of the list
				// place it
				// on subsequent picks, move the duplicate items forward
				// the idea is leave the largests in their place and reassign their smaller duplicate
				while (schedule[scheduleIndex] > 0) {
					scheduleIndex--;
				}
				
				if (scheduleIndex > 0)
					schedule[scheduleIndex] = max;

			}

			// count the total
			int total = 0;
			for (int i = 1; i < 10001; i++) {
				total += schedule[i];
			}
			output.print(total);

			input.close();
			output.close();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

	}

}
