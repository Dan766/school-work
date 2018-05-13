import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

public class PServer {
	static int programNumber;
	static String path;
	public static void main(String[] args) throws IOException, InterruptedException{
		String testerFile = args[0];
		ServerSocket listener = new ServerSocket(9090);
		programNumber = testerFile.toCharArray()[testerFile.length()-5]-48;
		while (true){
			Socket s = listener.accept();
		
			try{
				Runtime rt = Runtime.getRuntime();
				PrintWriter c_output = new PrintWriter(s.getOutputStream(),true);
				BufferedReader c_input = new BufferedReader(new InputStreamReader(s.getInputStream()));
				String name = c_input.readLine(); 
				String std_code_name = c_input.readLine();
				
				System.out.println("Submission received from "+ name +".");
				
				//Move the Student's Code to their records Directory
				path = "256/"+name+"/prog_"+programNumber; 
				
				rt.exec("./moveCode.bash "+name+" "+programNumber+" "+std_code_name);
				int marks=0;
				String Record = "Program "+programNumber+" Test Result:";
				
				//rt.exec("mkdir 212/"+name);
				//Make the File
				rt.exec("./fileSetup.bash " + name);
				
				BufferedReader checkCompile = new BufferedReader(
						new InputStreamReader(rt.exec("./compileCode.bash " + std_code_name)
						.getInputStream()));
				if (checkCompile.readLine().lastIndexOf("N")!=-1){
					Record += "\nFailed to Compile";
					OutputResults(Record,0,name,c_output);
				}
				else{
					Record += "\n\tCompiled Successfuly";
					Process proc = rt.exec("./a.out");
					BufferedReader in = new BufferedReader(new InputStreamReader(proc.getInputStream()));
					PrintWriter out = new PrintWriter(proc.getOutputStream());
					//Set up test case reader
					BufferedReader fileReader = new BufferedReader(new FileReader(testerFile));
					String tester = fileReader.readLine(); 
					
					int count=1;
					while(tester!=null){
						out.println(tester); //Input to program
						out.flush();
						
						tester=fileReader.readLine();
						if (tester.equals("*")){
							tester=fileReader.readLine();//result
							String tested = in.readLine(); 
		
							if (testoutputs(tested, tester)){
								Record += "\n\tTest case "+ count + ": passed";
								marks++;
							}
							else{
								Record += "\n\tTest case "+ count + ": failed";
							}
							//Next test #
							count++;
							tester=fileReader.readLine(); //Read the #
							tester=fileReader.readLine(); //reads either first num of next seq or null
							if (tester == null) break;
							//If tester continues... set up program for next execution
							 proc = rt.exec("./a.out");
							 in = new BufferedReader(new InputStreamReader(proc.getInputStream()));
							 out = new PrintWriter(proc.getOutputStream());
						}
					}
					OutputResults(Record,marks,name,c_output);
				}
			}
			
			finally{
				s.close();
			}
		}
	}//End Of main
		


	private static void OutputResults(String record, int marks, String name, PrintWriter c_in) throws IOException {
		double total = marks;
		total/=2;
		total*=100;
		record+="\nGrade = " + total + "%";
		String path = "256/"+name+"/prog_"+programNumber+"/results.txt";
		System.out.println("Testing Completed Successfully\n");
		PrintWriter std = new PrintWriter(new FileWriter(path));
		std.println(record);
		std.flush();
		std.close();
		c_in.println(record);
		c_in.flush();
	}
	private static boolean testoutputs(String tested, String tester) {
		int size = tester.length();
		if (tested.length()!=tester.length())
			return false;
		tested.toLowerCase().toCharArray();
		tester.toLowerCase().toCharArray();
		for (int i=0;i<size;i++){
			if (tested.toLowerCase().toCharArray()[i]!=tester.toLowerCase().toCharArray()[i])
				return false;
		}
		return true;
	}
}
