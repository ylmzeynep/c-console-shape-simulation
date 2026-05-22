import com.github.javafaker.Faker;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;

public class FakerUretici {
    public static void main(String[] args) {

        Faker faker = new Faker(new Locale("tr"));

        String dosyaYolu = "../data/kisiler.txt";

        try {
            FileWriter writer = new FileWriter(dosyaYolu, java.nio.charset.StandardCharsets.UTF_8);

            for (int i = 1; i <= 10000; i++) {
                String ad = faker.name().firstName();
                String soyad = faker.name().lastName();
                int yas = faker.number().numberBetween(0, 51);

                writer.write(i + ";" + ad + ";" + soyad + ";" + yas + "\n");
            }

            writer.close();

            System.out.println("10000 kisi kisiler.txt dosyasina yazildi.");

        } catch (IOException e) {
            System.out.println("Dosya yazma hatasi: " + e.getMessage());
        }
    }
}