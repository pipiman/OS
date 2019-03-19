import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.core.Mat;


public class Dcolor{

    /* static {
	System.load("/home/pipiman/libopencv_java401.so");
       	System.load("/home/pipiman/dcres/dcolorlib.so");
	}*/

    public native Mat process(Mat src, float rad, float h, float v);
    /*    public static void main(String[] args){

		Mat image = Imgcodecs.imread("1.jpg");
	
		String filename = "test.jpg";
	
		Imgcodecs.imwrite(filename, image);

		return;
		}*/
    
}
