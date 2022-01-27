import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class q3 {
    public static void main(String[] args) {
        String[] names = {"", "Mon", "Tue", "Wed", "Thurs", "Fri", "Sat", "Sun"}; // Follows ISO-8601, i.e Mon = 1
        System.out.println(names[LocalDate.of(2010, 8, 9).getDayOfWeek().getValue()]); // getDayOfWeek() gives MONDAY, ...
        System.out.println(ChronoUnit.DAYS.between(LocalDate.of(2010, 8, 9), LocalDate.now()));
    }
}
