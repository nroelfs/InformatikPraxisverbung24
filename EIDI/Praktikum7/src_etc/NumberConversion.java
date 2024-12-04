/**
 * Aufgabe: Testat 7.
 */
public class NumberConversion {

    /**
     * Main-Methode.
     * @param args
     */
    public static void main(String[] args) {
        // a)
        final double scientificNotation = 2.93e3;
        System.out.println("2,93e3 in normaler Schreibweise: " + scientificNotation);

        // b)
        final int number = 82434;
        String scientificNotationStr = String.format("%.3e", (double) number);
        System.out.println("82434 in wissenschaftlicher Schreibweise mit "
            + "drei signifikanten Stellen: " + scientificNotationStr);
    }
}
