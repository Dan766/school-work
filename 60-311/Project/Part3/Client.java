import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

public class PClient {
	public static void main(String[] args) throws IOException, InterruptedException{
		String name = args[0];
		String student_code_name = args[1];
		
		Socket s = new Socket( InetAddress.getLocalHost(), 9090);
		BufferedReader s_input = new BufferedReader(new InputStreamReader(s.getInputStream()));
		PrintWriter s_output = new PrintWriter(s.getOutputStream(), true);
		
		s_output.println(name);
		s_output.flush();
		s_output.println(student_code_name);
		s_output.flush();
		
		System.out.println("Submission completed successfully");
		
		while (!s_input.ready()){
			String rec = s_input.readLine();
			System.out.println(rec);
		}
		
		while(s_input.ready()){
			String rec = s_input.readLine();
			System.out.println(rec);
		}
	
	}

}
