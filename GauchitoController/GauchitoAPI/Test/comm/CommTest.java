import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class CommTest {

	static byte[] buffer;
	static DatagramSocket data;
	
	public static void main(String[] args) throws Exception {
                System.out.println("CommTest started.");
                System.out.println("Waiting for connection...");
		try {
			data = new DatagramSocket(12345);
			buffer = new byte[1024];
			
			DatagramPacket in = new DatagramPacket(buffer, 1024);
			while (true) {
				receive(in);
			}
		} catch (Exception ex) {
			ex.printStackTrace();	
		}
	}
	
	private static void receive(DatagramPacket in) throws IOException {
		data.receive(in);
		String inMessage = new String(in.getData(), 0, in.getLength());
		System.out.println(String.format("Received: %s - from:[%s | %s]", inMessage, in.getAddress(), in.getPort()));
	}
	
}
