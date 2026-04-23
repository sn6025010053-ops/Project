public class Doctor {
    private String name;
    private int age;
    private String specialist;
    private double hourlyRate;

    public Doctor(String name, int age, String specialist, double hourlyRate) {
        this.name = name;
        this.age = age;
        this.specialist = specialist;
        this.hourlyRate = hourlyRate;
    }

    // Getters
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getSpecialist() {
        return specialist;
    }

    public double getHourlyRate() {
        return hourlyRate;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setSpecialist(String specialist) {
        this.specialist = specialist;
    }

    public void setHourlyRate(double hourlyRate) {
        this.hourlyRate = hourlyRate;
    }
}