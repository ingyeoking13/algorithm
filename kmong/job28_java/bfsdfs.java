import java.util.*;
import java.io.*;

class Hello
{
	private static LinkedList<LinkedList<Integer>> edge;
	private static boolean[] chk;
	public static void main(String[] args)
	{

		try{
			FileInputStream file = new FileInputStream("input.txt");
			Scanner in = new Scanner(file);

			int n = in.nextInt();
			chk = new boolean[n+1];

			edge = new LinkedList<LinkedList<Integer>>();

			for (int i=0; i<=n; i++)
			{
				edge.add(new LinkedList<Integer>());
			}

			while(true)
			{
				try{
					int u, v;
					u = in.nextInt();
					v = in.nextInt();
					edge.get(u).add(v);
					edge.get(v).add(u);
				}
				catch(Exception e)
				{
					break;
				}
			}

			// DFS 탐색
			Arrays.fill(chk, false);
			System.out.printf("DFS : ");
			dfs(1);
			System.out.printf("\n");


			// BFS 탐색
			Arrays.fill(chk, false);
			Queue<Integer> q = new LinkedList<Integer>();
			System.out.printf("BFS : ");

			q.add(1);
			chk[0]=true;

			while(q.peek() != null)
			{
				int now = q.poll();

				System.out.printf("%d ", now);
				for (int j=0; j<edge.get(now).size(); j++)
				{
					int next = edge.get(now).get(j);
					if (chk[next] == true) continue;

					q.add(next);
					chk[next] = true;
				}
			}
			System.out.printf("\n");
		}
		catch(Exception e)
		{
			System.out.printf("File does not Exists \"input.txt\"\n");
		}
	}

	private static void dfs(int now)
	{
		chk[now] = true;
		System.out.printf("%d ", now);
		for (int i=0; i<edge.get(now).size(); i++)
		{
			int next = edge.get(now).get(i);
			if ( chk[next] == true ) continue;
			dfs(next);
		}
	}
}
