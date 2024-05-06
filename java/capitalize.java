import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class capitalize {
    public static void main(String[] args) {
        String filePath = "test.txt";
        String outputFilePath = "output.txt";
        try {
            BufferedReader reader = new BufferedReader(new FileReader(filePath));
            BufferedWriter writer = new BufferedWriter(new FileWriter(outputFilePath));

            StringBuilder str = new StringBuilder();
            String line;

            while ((line = reader.readLine()) != null) {
                str.append(line.toUpperCase());
            } 

            writer.write(str.toString());
            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
