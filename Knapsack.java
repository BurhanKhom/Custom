import java.util.*;
public class Knapsack
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter capacity : ");
		
		int cap = sc.nextInt();
		System.out.print("Enter number of elements : ");
		int n = sc.nextInt();
		int w[] = new int[n];
		int p[] = new int[n];
		double ratio[] = new double[n];
		
		System.out.print("Enter weights : ");
		for(int i=0; i<n; i++)
			w[i] = sc.nextInt();
		
		System.out.print("Enter profits : ");
		for(int i=0; i<n; i++)
		{
			p[i] = sc.nextInt();
			ratio[i] = (double)p[i] / (double)w[i];
		}
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				if(ratio[j] < ratio[j+1])
				{
					double temp = ratio[j];
					ratio[j] = ratio[j+1];
					ratio[j+1] = temp;
					
					int t1 = w[j];
					w[j] = w[j+1];
					w[j+1] = t1;
					
					int t2 = p[j];
					p[j] = p[j+1];
					p[j+1] = t2;
					
				}
			}
		}
		//check
		System.out.println("Ratio\t\tWeight\t\tProfit");
		int i;
		for(i=0; i<n; i++)
			System.out.println(ratio[i]+"\t\t"+w[i]+"\t\t"+p[i]);
		
		int size=cap;
		i=0;
		double profits=0;
		while(size >= w[i])
		{
			profits += p[i];
			size-=w[i++];
			System.out.println("Size : "+size); //check size
		}
		if(i<n)
		{
			double fraction = (double)size / (double)w[i];
			System.out.println("Fraction : "+fraction); //check fraction
			profits += fraction*p[i];
		}
		System.out.println("Total profit : "+profits);
		
		
		
	}
}

